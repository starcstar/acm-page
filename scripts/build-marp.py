import os
import subprocess
from glob import glob
import argparse

# 解析命令行参数
parser = argparse.ArgumentParser(
    description="Compile Markdown files to PDF and HTML using Marp."
)
parser.add_argument(
    "--delete",
    action="store_true",
    help="Delete original Markdown files after conversion",
)
args = parser.parse_args()

# 指定搜索的根目录
SEARCH_DIRS = ["2024fall", "2025wcamp"]
# 指定输出的根目录
OUTPUT_DIR = "public"

# 查找所有名为slide.md的文件
files = []
for search_dir in SEARCH_DIRS:
    files.extend(glob(f"{search_dir}/**/slide.md", recursive=True))


def compile_file(file, output_dir, format):
    output_file_path = os.path.join(output_dir, f"slide.{format}")
    output_file_path = os.path.abspath(output_file_path)
    
    # 检查文件是否已经存在
    if os.path.exists(output_file_path):
        print(f"Skipping {file}, {format.upper()} already exists.")
        return
    
    # 读取frontmatter yaml
    with open(file, "r") as f:
        lines = f.readlines()
        if lines[0].startswith("---"):
            frontmatter_end = lines.index("---\n", 1)
            frontmatter = "".join(lines[: frontmatter_end + 1])
            lines = lines[frontmatter_end + 1 :]
        else:
            frontmatter = ""
        # 解析theme的值
        theme = "default"
        for line in frontmatter.split("\n"):
            if line.startswith("theme:"):
                theme = line.split(":")[-1].strip()
                break

    file_name = os.path.basename(file)
    file_path = os.path.dirname(file)
    if theme == "default":
        command = f'npx @marp-team/marp-cli@latest "{file_name}" -o {output_file_path} --allow-local-files'
    else:
        css_file_path = os.path.join("./marp-themes", f"{theme}.css")
        css_file_path = os.path.abspath(css_file_path)
        command = f'npx @marp-team/marp-cli@latest --theme {css_file_path} "{file_name}" -o {output_file_path} --allow-local-files'
    print(f"Running command: {command}")
    result = subprocess.run(
        command, shell=True, capture_output=True, text=True, cwd=file_path
    )
    if result.returncode != 0:
        print(f"Error converting {file} to {format.upper()}: {result.stderr}")
    else:
        print(f"Successfully converted {file} to {output_file_path}")


print(f"Found {len(files)} Markdown files to convert")
print("Files found:")
for file in files:
    print(f"  {file}")

for file in files:
    # 获取文件的相对路径
    relative_path = os.path.relpath(file)
    # 获取文件所在的目录
    dir_path = os.path.dirname(relative_path)
    # 创建对应的输出目录
    output_dir = os.path.join("public", dir_path)
    print(f"Creating output directory: {output_dir}")
    # input("Press Enter to continue...")
    os.makedirs(output_dir, exist_ok=True)

    compile_file(file, output_dir, "pdf")
    compile_file(file, output_dir, "html")

    # 如果命令行参数中包含 --delete，则删除原始的 Markdown 文件
    if args.delete:
        os.remove(file)
        print(f"Deleted original file: {file}")

pdf_files = []
for search_dir in SEARCH_DIRS:
    pdf_files.extend(glob(f"{search_dir}/**/*.pdf", recursive=True))

print(f"Found {len(pdf_files)} PDF files")
print("PDF files found:")
for file in pdf_files:
    print(f"  {file}")

# 拷贝源代码目录的 PDF 文件到 public 目录
for file in pdf_files:
    relative_path = os.path.relpath(file)
    output_path = os.path.join(OUTPUT_DIR, relative_path)
    output_dir = os.path.dirname(output_path)
    print(f"Creating output directory: {output_dir}")
    os.makedirs(output_dir, exist_ok=True)
    print(f"Copying {file} to {output_path}")
    os.replace(file, output_path)
