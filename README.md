# my_acl
My AtCoder Library

このリポジトリは、AtCoderの問題を解くためのC++とPyPyの実行環境とライブラリを管理するプロジェクトです。

## セットアップ

### 1. ac-libraryのダウンロード

AtCoder Library（ac-library）を公式からダウンロードして配置してください：

```bash
# runディレクトリに移動
cd run

# ac-libraryをダウンロード
git clone https://github.com/atcoder/ac-library.git

# または、最新版をダウンロードする場合
wget https://github.com/atcoder/ac-library/archive/refs/heads/master.zip
unzip master.zip
mv ac-library-master ac-library
```

### 2. 実行環境の準備

#### C++の場合
- g++コンパイラが必要です
- `compile_run.sh`スクリプトを使用してコンパイル・実行できます

#### PyPyの場合
- PyPy3がインストールされている必要があります
- `sample.py`を参考にコードを実行できます

## 使用方法

### C++コードの実行
```bash
cd run
./compile_run.sh your_code.cpp
```

### PyPyコードの実行
```bash
cd run
pypy3 your_code.py
```

## ディレクトリ構造

- `cpp/`: C++のアルゴリズム実装
- `run/`: 実行環境とスクリプト
- `sample/`: サンプルコード（ABC、ARC等）
