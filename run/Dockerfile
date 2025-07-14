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

# PyPy 3.10-v7.3.12のインストール
RUN wget https://downloads.python.org/pypy/pypy3.10-v7.3.12-linux64.tar.bz2 \
    && tar -xjf pypy3.10-v7.3.12-linux64.tar.bz2 \
    && mv pypy3.10-v7.3.12-linux64 /opt/pypy3.10 \
    && ln -s /opt/pypy3.10/bin/pypy3 /usr/local/bin/pypy3 \
    && rm pypy3.10-v7.3.12-linux64.tar.bz2

# 作業ディレクトリの設定
WORKDIR /workspace

# Atcoder Libraryのダウンロード
RUN git clone https://github.com/atcoder/ac-library.git /workspace/ac-library


# # コンパイル用スクリプトの作成
# RUN echo '#!/bin/bash\n\
# if [[ $1 == *.cpp ]]; then\n\
#     g++ -std=c++23 -I /opt/ac-library -O2 -Wall -Wextra "$1" -o "${1%.cpp}"\n\
#     if [ $? -eq 0 ]; then\n\
#         echo "Compilation successful!"\n\
#         if [ -f "in.txt" ]; then\n\
#             echo "Running with in.txt..."\n\
#             ./"${1%.cpp}" < in.txt\n\
#         else\n\
#             echo "Running..."\n\
#             ./"${1%.cpp}"\n\
#         fi\n\
#     else\n\
#         echo "Compilation failed!"\n\
#     fi\n\
# elif [[ $1 == *.py ]]; then\n\
#     if [ -f "in.txt" ]; then\n\
#         echo "Running Python with in.txt..."\n\
#         pypy3 "$1" < in.txt\n\
#     else\n\
#         echo "Running Python..."\n\
#         pypy3 "$1"\n\
#     fi\n\
# else\n\
#     echo "Usage: $0 <cpp_file> or $0 <py_file>"\n\
# fi' > /usr/local/bin/run_atcoder && chmod +x /usr/local/bin/run_atcoder

# # エイリアスの設定
# RUN echo 'alias g++="g++ -std=c++23 -I /workspace/ac-library -O2 -Wall -Wextra"' >> /root/.bashrc \
#     && echo 'alias python="pypy3"' >> /root/.bashrc \
#     && echo 'alias run="run_atcoder"' >> /root/.bashrc

# # サンプルファイルの作成
# RUN echo '#include <bits/stdc++.h>\n\
# #include <atcoder/all>\n\
# \n\
# using namespace std;\n\
# using mint = atcoder::modint998244353;\n\
# \n\
# int main() {\n\
#     int N;\n\
#     cin >> N;\n\
#     cout << "Hello Atcoder! N = " << N << endl;\n\
#     return 0;\n\
# }' > /workspace/sample.cpp

# RUN echo 'N = int(input())\n\
# print(f"Hello Atcoder! N = {N}")' > /workspace/sample.py

# RUN echo '5' > /workspace/in.txt

# # ヘルプファイルの作成
# RUN echo 'Atcoder Docker Environment\n\
# \n\
# Available commands:\n\
# - run <file.cpp> : Compile and run C++ file with in.txt\n\
# - run <file.py> : Run Python file with in.txt\n\
# - g++ <file.cpp> : Compile C++ file with Atcoder Library\n\
# - pypy3 <file.py> : Run Python file with PyPy\n\
# \n\
# Sample files:\n\
# - sample.cpp : C++ sample\n\
# - sample.py : Python sample\n\
# - in.txt : Input file\n\
# \n\
# Example:\n\
#   run sample.cpp\n\
#   run sample.py' > /workspace/README.md

# デフォルトコマンド
CMD ["/bin/bash"]
