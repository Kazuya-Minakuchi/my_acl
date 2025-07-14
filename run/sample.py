#!/usr/bin/env pypy3

# Atcoder用のPythonサンプル
# PyPy 3.10-v7.3.12で実行

def main():
    # 入力の読み込み
    N, M = map(int, input().split())
    
    # 配列の読み込み例
    A = list(map(int, input().split()))
    
    print(f"N = {N}, M = {M}")
    print(f"A = {A}")
    
    # 合計を計算
    total = sum(A)
    print(f"Sum = {total}")
    
    # 最大値を計算
    max_val = max(A)
    print(f"Max = {max_val}")

if __name__ == "__main__":
    main()
