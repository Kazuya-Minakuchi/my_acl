#!/bin/bash

# Atcoder Docker環境を起動するスクリプト

echo "Atcoder Docker環境を起動しています..."

# エラー解消関数
cleanup_and_rebuild() {
    echo "エラーが発生しました。自動的にクリーンアップと再構築を行います..."
    
    # 既存コンテナとボリュームを完全削除
    echo "既存のコンテナとボリュームを削除中..."
    docker-compose down --volumes --remove-orphans 2>/dev/null
    
    # Dockerシステムをクリーンアップ
    echo "Dockerシステムをクリーンアップ中..."
    docker system prune -f 2>/dev/null
    
    # 環境を再構築
    echo "環境を再構築中..."
    docker-compose up -d --build
    
    # 再構築後の状態確認
    if [ $? -eq 0 ]; then
        echo "再構築が完了しました！"
        return 0
    else
        echo "再構築に失敗しました。手動で確認してください。"
        return 1
    fi
}

# 初回起動試行
echo "Docker環境を起動中..."
if docker-compose up -d --build; then
    echo "Docker環境が正常に起動しました！"
else
    echo "初回起動に失敗しました。エラーを確認中..."
    
    # エラーログを確認
    if docker-compose logs 2>&1 | grep -q "ContainerConfig\|KeyError"; then
        echo "ContainerConfigエラーを検出しました。自動修復を開始します..."
        if cleanup_and_rebuild; then
            echo "自動修復が完了しました！"
        else
            echo "自動修復に失敗しました。手動で確認してください。"
            exit 1
        fi
    else
        echo "不明なエラーが発生しました。手動で確認してください。"
        docker-compose logs
        exit 1
    fi
fi

# コンテナの状態確認
echo "コンテナの状態を確認中..."
if docker-compose ps | grep -q "Up"; then
    echo "コンテナが正常に動作しています。"
else
    echo "コンテナが正常に起動していません。再試行します..."
    if cleanup_and_rebuild; then
        echo "再試行が成功しました！"
    else
        echo "再試行に失敗しました。手動で確認してください。"
        exit 1
    fi
fi

# コンテナに入る
echo "コンテナに入ります..."
docker-compose exec atcoder bash

echo "コンテナから抜けました。"
