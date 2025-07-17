# Atcoder Docker環境

このDocker環境は、Atcoderの競技プログラミングで使用するC++とPythonの実行環境を提供します。

## 含まれる環境

Docker環境には以下の言語が含まれています：
- **C++ 23 (gcc 12.2)**: Atcoder Library付き
- **Python (PyPy 3.10-v7.3.12)**: 高速なPython実装
- **Rust 1.70.0**: AtCoderで使用されるRustバージョン

## セットアップ

### 0. 事前準備

#### macOSユーザーの場合
Docker Desktopがインストールされていない場合は、[Docker Desktop for Mac](https://www.docker.com/products/docker-desktop/)をインストールしてください。

初回起動時やDockerが起動していない場合は、以下のコマンドでDocker Desktopを起動してください：
```bash
open -a Docker
```

Docker Desktopの起動には数分かかる場合があります。起動完了後、以下のコマンドで確認できます：
```bash
docker info
```

### 1. 初回セットアップ（権限付与）

初回使用時は、スクリプトファイルに実行権限を付与する必要があります：

```bash
# runディレクトリに移動
cd run

# start_docker.shに実行権限を付与
chmod +x start_docker.sh

# compile_run_cpp.shに実行権限を付与（存在する場合）
chmod +x compile_run_cpp.sh

# compile_run_rust.shに実行権限を付与
chmod +x compile_run_rust.sh
```

### 1. Docker環境の起動

```bash
./start_docker.sh
```

または手動で：

```bash
# イメージをビルドしてコンテナを起動
docker-compose up -d --build

# コンテナに入る
docker-compose exec atcoder bash
```

### 2. コンテナの停止

```bash
docker-compose down
```

## 使用方法

### C++の実行

コンパイル & 実行
```bash
sh compile_run_cpp.sh
```

### Pythonの実行

```bash
# PyPyで実行（in.txtから入力）
pypy3 test_run.py < in.txt
```

### Rustの実行

```bash
# Rustでコンパイル & 実行
sh compile_run_rust.sh test_run.rs
```

## 便利なコマンド

- `run <file.cpp>`: C++ファイルをコンパイルして実行
- `run <file.py>`: PythonファイルをPyPyで実行
- `sh compile_run_rust.sh <file.rs>`: Rustファイルをコンパイルして実行
- `g++`: C++23 + Atcoder Libraryでコンパイル
- `pypy3`: PyPyでPythonを実行
- `rustc`: Rustコンパイラ

## ファイル構成

- `Dockerfile`: Dockerイメージの定義
- `docker-compose.yml`: Docker Compose設定
- `start_docker.sh`: 環境起動スクリプト
- `test_run.cpp`: テスト用C++ファイル
- `test_run.py`: テスト用Pythonファイル
- `test_run.rs`: テスト用Rustファイル
- `compile_run_rust.sh`: Rustコンパイル・実行スクリプト
- `in.txt`: 入力ファイル
- `ac-library/`: Atcoder Library

## 注意事項

- コンテナ内の`/workspace`ディレクトリは、ホストの現在のディレクトリと同期されます
- 既存の`ac-library`ディレクトリがコンテナ内で使用されます
- `in.txt`ファイルがある場合、自動的に入力として使用されます

## 実際の使用方法（権限問題解決済み）

### 1. コンテナの起動（sudoが必要）
```bash
sudo docker-compose up -d --build
```

### 2. コンテナに入る
```bash
sudo docker-compose exec atcoder bash
```

### 3. コードの実行例
C++の実行
```bash
run test_run.cpp
```

Python (PyPy)の実行
```bash
pypy3 test_run.py < in.txt
```

Rustの実行
```bash
sh compile_run_rust.sh test_run.rs
```

### 4. コンテナの停止
```bash
sudo docker-compose down
```

### 権限問題の解決

WSL環境では、Docker Composeに`sudo`が必要です：
```bash
# 権限エラーが発生する場合
sudo docker-compose up -d --build
sudo docker-compose exec atcoder bash
```

## トラブルシューティング

### Dockerが起動しない場合

#### macOSの場合
```bash
# エラーメッセージ例:
# Cannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?

# Docker Desktopが起動しているか確認
docker info

# Docker Desktopが起動していない場合、起動
open -a Docker

# 起動まで少し待つ（10-30程度）
sleep10# 再度確認
docker info
```

#### Linux/WSLの場合
```bash
# Dockerサービスが起動しているか確認
sudo systemctl status docker

# Dockerサービスを起動
sudo systemctl start docker
```

### 権限エラーが発生する場合

#### スクリプトファイルの権限エラー
```bash
# エラー: zsh: permission denied: ./start_docker.sh
# 解決方法: 実行権限を付与
chmod +x start_docker.sh
chmod +x compile_run_cpp.sh
```

#### Docker権限エラー
```bash
# ユーザーをdockerグループに追加
sudo usermod -aG docker $USER

# ログアウトして再ログイン
```

### コンテナが起動しない場合

```bash
# ログを確認
docker-compose logs

# コンテナを再作成
docker-compose down
docker-compose up -d --build
```

### Docker Composeが動作しない場合
```bash
# 権限エラーの場合
sudo docker-compose up -d --build

# コンテナの状態確認
sudo docker-compose ps

# ログの確認
sudo docker-compose logs
```

### コンテナ内での実行
```bash
# コンテナに入る
sudo docker-compose exec atcoder bash

# コンテナ内でのコマンド実行
run test_run.cpp
run test_run.py
sh compile_run_rust.sh test_run.rs
g++ --version
pypy3 --version
rustc --version
```

### ContainerConfigエラーが発生する場合

古いDocker Composeバージョン（1.29.2など）と新しいDockerイメージの互換性問題で発生するエラーです。

#### エラーメッセージ例
```
ERROR: for atcoder  'ContainerConfig'
KeyError: 'ContainerConfig'
```

#### 解決方法
```bash
# 1. 既存コンテナとボリュームを完全削除
docker-compose down --volumes --remove-orphans

# 2. Dockerシステムをクリーンアップ
docker system prune -f

# 3. 環境を再構築
docker-compose up -d --build
```

#### 詳細説明
このエラーは、Docker Compose 1.29.2などの古いバージョンが、新しいDockerイメージのメタデータ構造に対応していないために発生します。上記の手順で既存のコンテナとイメージを完全に削除し、新しく再構築することで解決できます。
