# Atcoder Docker環境

このDocker環境は、Atcoderの競技プログラミングで使用するC++とPythonの実行環境を提供します。

## 含まれる環境

Docker環境には以下の言語が含まれています：
- **C++ 23 (gcc 12.2)**: Atcoder Library付き
- **Python (PyPy 3.10-v7.3.12)**: 高速なPython実装

## セットアップ

### 0. 初回セットアップ（権限付与）

初回使用時は、スクリプトファイルに実行権限を付与する必要があります：

```bash
# runディレクトリに移動
cd run

# start_docker.shに実行権限を付与
chmod +x start_docker.sh

# compile_run.shに実行権限を付与（存在する場合）
chmod +x compile_run.sh
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
sh compile_run.sh
```

### Pythonの実行

```bash
# PyPyで実行（in.txtから入力）
pypy3 test_run.py < in.txt
```

## 便利なコマンド

- `run <file.cpp>`: C++ファイルをコンパイルして実行
- `run <file.py>`: PythonファイルをPyPyで実行
- `g++`: C++23 + Atcoder Libraryでコンパイル
- `pypy3`: PyPyでPythonを実行

## ファイル構成

- `Dockerfile`: Dockerイメージの定義
- `docker-compose.yml`: Docker Compose設定
- `start_docker.sh`: 環境起動スクリプト
- `test_run.cpp`: テスト用C++ファイル
- `test_run.py`: テスト用Pythonファイル
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
chmod +x compile_run.sh
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
g++ --version
pypy3 --version
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
