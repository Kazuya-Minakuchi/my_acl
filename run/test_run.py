#!/usr/bin/env pypy3

import sys

# Atcoder用のPythonサンプル
# PyPy 3.10-v7.3.12で実行

def main():
    # 入力の読み込み
    N, L, R = map(int, input().split())
    print(f"N = {N}, L = {L}, R = {R}", file=sys.stderr)

    X = []
    Y = []
    for _ in range(N):
        x, y = map(int, input().split())
        X.append(x)
        Y.append(y)
    
    # print(f"X = {X}", file=sys.stderr)
    # print(f"Y = {Y}", file=sys.stderr)

    ans = 0
    for i in range(N):
        if X[i] <= L and R <= Y[i]:
            ans += 1
    
    print(ans)
    

if __name__ == "__main__":
    main()
