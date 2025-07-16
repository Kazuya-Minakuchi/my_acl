# my_acl
My AtCoder Library

このリポジトリは、AtCoderの問題を解くためのC++とPyPyの実行環境とライブラリを管理するプロジェクトです。

## 概要

このプロジェクトには以下の要素が含まれています：

- **C++アルゴリズム実装**: `cpp/`ディレクトリに基本的なアルゴリズムの実装
- **実行環境**: `run/`ディレクトリにDocker環境とローカル実行環境
- **サンプルコード**: `sample/`ディレクトリにABC、ARC等の解答例

## ディレクトリ構造

```
my_acl/
├── cpp/                    # C++のアルゴリズム実装
│   ├── binary_search.cpp
│   ├── bit_dp.cpp
│   ├── breadth_first_search.cpp
│   ├── depth_first_search.cpp
│   ├── dijkstra.cpp
│   ├── ford_fulkerson.cpp
│   ├── longest_increasing_sequence.cpp
│   ├── minimum_spanning_tree.cpp
│   └── union_find.cpp
├── run/                    # 実行環境とスクリプト
│   ├── ac-library/         # AtCoder Library
│   ├── compile_run_cpp.sh  # C++コンパイル・実行スクリプト
│   ├── docker-compose.yml  # Docker環境設定
│   ├── Dockerfile          # Dockerイメージ定義
│   ├── start_docker.sh     # Docker環境起動スクリプト
│   └── readme.md           # 実行環境の詳細説明
└── sample/                 # サンプルコード
    ├── ABC/                # AtCoder Beginner Contest解答例
    └── ARC/                # AtCoder Regular Contest解答例
```

## 使用方法

実行方法の詳細については、[run/readme.md](run/readme.md)を参照してください。

## 含まれるアルゴリズム

`cpp/`ディレクトリには以下の基本的なアルゴリズムが実装されています：

- 二分探索 (Binary Search)
- ビットDP (Bit DP)
- 幅優先探索 (BFS)
- 深さ優先探索 (DFS)
- ダイクストラ法 (Dijkstra)
- フォード・ファルカーソン法 (Ford-Fulkerson)
- 最長増加部分列 (LIS)
- 最小全域木 (MST)
- Union-Find

## ライセンス

このプロジェクトは個人的な学習目的で作成されています。
