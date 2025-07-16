#!/bin/bash

# Rustコードのコンパイルと実行スクリプト
# 使用方法: ./compile_run_rust.sh [ファイル名]

if [ $# -eq 0 ]; then
    echo "使用方法: $0 [Rustファイル名]"
    echo "例: $0 test_run.rs"
    exit 1
fi

RUST_FILE=$1
EXECUTABLE_NAME="${RUST_FILE%.*}"

echo "=== Rustコードのコンパイルと実行 ==="
echo "ファイル: $RUST_FILE"
echo "実行ファイル: $EXECUTABLE_NAME"
echo ""

# コンパイル
echo "コンパイル中..."
rustc -O "$RUST_FILE" -o "$EXECUTABLE_NAME"

if [ $? -eq 0 ]; then
    echo "コンパイル成功！"
    echo ""
    
    # 実行
    echo "実行中..."
    echo "入力ファイル: in.txt"
    echo "---"
    ./"$EXECUTABLE_NAME" < in.txt
    echo "---"
    echo "実行完了"
    
    # 実行ファイルの削除
    rm "$EXECUTABLE_NAME"
else
    echo "コンパイルエラーが発生しました"
    exit 1
fi 