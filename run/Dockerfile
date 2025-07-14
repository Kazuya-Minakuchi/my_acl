# Atcoder用のDocker環境
# C++ 23 (gcc 12.2) と Python (PyPy 3.10-v7.3.12) を含む

FROM ubuntu:22.04

# 環境変数の設定
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Tokyo

# 必要なパッケージのインストール
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-12 \
    g++-12 \
    python3 \
    python3-pip \
    wget \
    curl \
    git \
    vim \
    nano \
    && rm -rf /var/lib/apt/lists/*

# gcc-12をデフォルトに設定
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-12 120 \
    --slave /usr/bin/g++ g++ /usr/bin/g++-12 \
    --slave /usr/bin/gcov gcov /usr/bin/gcov-12

# PyPy 3.10-v7.3.12のインストール（マルチアーキテクチャ対応）
RUN apt-get update && apt-get install -y software-properties-common \
    && add-apt-repository ppa:pypy/ppa \
    && apt-get update \
    && apt-get install -y pypy3 pypy3-dev \
    && ln -s /usr/bin/pypy3 /usr/local/bin/pypy3 \
    && rm -rf /var/lib/apt/lists/*

# 作業ディレクトリの設定
WORKDIR /workspace

# Atcoder Libraryのダウンロード
RUN git clone https://github.com/atcoder/ac-library.git /workspace/ac-library


# デフォルトコマンド
CMD ["/bin/bash"]
