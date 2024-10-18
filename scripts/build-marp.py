import os
import subprocess
from glob import glob
import argparse

# 解析命令行参数
parser = argparse.ArgumentParser(description='Compile Markdown files to PDF and HTML using Marp.')
parser.add_argument('--delete', action='store_true', help='Delete original Markdown files after conversion')
args = parser.parse_args()

# 指定搜索的根目录
SEARCH_DIR = '2024fall'
# 指定输出的根目录
OUTPUT_DIR = os.path.join('public', SEARCH_DIR)

# 查找所有名为slide.md的文件
files = glob(f'{SEARCH_DIR}/**/slide.md', recursive=True)

def compile_file(file, output_dir, format):
    output_file_path = os.path.join(output_dir, f'slide.{format}')
    # 读取frontmatter yaml
    with open(file, 'r') as f:
        lines = f.readlines()
        if lines[0].startswith('---'):
            frontmatter_end = lines.index('---\n', 1)
            frontmatter = ''.join(lines[:frontmatter_end + 1])
            lines = lines[frontmatter_end + 1:]
        else:
            frontmatter = ''
        # 解析theme的值
        theme = 'default'
        for line in frontmatter.split('\n'):
            if line.startswith('theme:'):
                theme = line.split(':')[-1].strip()
                break
    if theme == 'default':
        command = f'npx @marp-team/marp-cli@latest "{file}" -o "{output_file_path}"'
    else:
        command = f'npx @marp-team/marp-cli@latest --theme ./marp-themes/{theme}.css "{file}" -o "{output_file_path}"'
    print(f'Running command: {command}')
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode != 0:
        print(f'Error converting {file} to {format.upper()}: {result.stderr}')
    else:
        print(f'Successfully converted {file} to {output_file_path}')

for file in files:
    # 获取文件的相对路径
    relative_path = os.path.relpath(file, SEARCH_DIR)
    # 获取文件所在的目录
    dir_path = os.path.dirname(relative_path)
    # 创建对应的输出目录
    output_dir = os.path.join(OUTPUT_DIR, dir_path)
    os.makedirs(output_dir, exist_ok=True)

    compile_file(file, output_dir, 'pdf')
    compile_file(file, output_dir, 'html')
    
    # 如果命令行参数中包含 --delete，则删除原始的 Markdown 文件
    if args.delete:
        os.remove(file)
        print(f'Deleted original file: {file}')