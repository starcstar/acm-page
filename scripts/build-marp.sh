#!/bin/bash

# 指定搜索的根目录
SEARCH_DIR="2024fall"
# 指定输出的根目录
OUTPUT_DIR="public"

# 查找所有名为slide.md的文件
find "$SEARCH_DIR" -type f -name "slide.md" | while read -r file; do
    # 获取文件的相对路径
    relative_path="${file#$SEARCH_DIR/}"
    # 获取文件所在的目录
    dir_path=$(dirname "$relative_path")
    # 创建对应的输出目录
    mkdir -p "$OUTPUT_DIR/$dir_path"
    # 编译成PDF并放在对应的输出目录
    npx @marp-team/marp-cli@latest "$file" --pdf --output "$OUTPUT_DIR/$relative_path.pdf"
done