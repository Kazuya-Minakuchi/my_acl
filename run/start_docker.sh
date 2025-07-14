#!/bin/bash

# Atcoder Docker環境を起動するスクリプト

echo "Atcoder Docker環境を起動しています..."

# Docker Composeでビルドと起動
docker-compose up -d --build

# コンテナに入る
echo "コンテナに入ります..."
docker-compose exec atcoder bash

echo "コンテナから抜けました。"
