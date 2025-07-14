# Atcoder 競技プログラミング環境

## 通常のコンパイル方法

### C++でコンパイル & 実行
```bash
sh compile_run.sh
```

## Docker環境について

Docker環境を使用する場合は、`DOCKER_README.md`を参照してください。

## ファイル構成

- `Dockerfile`: Dockerイメージの定義
- `docker-compose.yml`: Docker Compose設定
- `start_docker.sh`: 環境起動スクリプト
- `compile_run.sh`: C++コンパイル・実行スクリプト
- `test_run.cpp`: テスト用C++ファイル
- `sample.py`: テスト用Pythonファイル
- `in.txt`: 入力ファイル
- `ac-library/`: AtCoder Library
- `DOCKER_README.md`: Docker環境の詳細説明


## 実際の動作確認結果

### ✅ 成功した環境
- **C++ 23 (gcc 12.3.0)**: 正常にコンパイル・実行
- **Python (PyPy 7.3.12)**: 正常に実行
- **AtCoder Library**: 利用可能
