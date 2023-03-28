# ament_cmake

本ディレクトリは ament_cmake 使用例のサンプルを提供する。本ディレクトリでは以下のサンプルを提供する。

## 基本的なパッケージ

以下は基本的なパッケージの設定例となっている。

- [simple_library](./simple_library/): CMake のみでのライブラリ設定
- [simple_library_ament](./simple_library_ament/): ament_cmake でのライブラリ設定
- [simple_node](./simple_node/): 上記を使用するノード作成

![基本的なパッケージクラス図](doc/images/simple_example.png)

## メッセージ定義

以下のパッケージはメッセージ定義のサンプルとなっている。

- [simple_message](./simple_message/): ユーザーメッセージ定義
- [simple_publisher](./simple_publisher/): 上記メッセージを publish するノード

## リソース登録

以下のパッケージはリソース (launch ファイル/パラメータファイル) 登録のサンプルとなっている。

- [node_with_resources](./node_with_resources/)

## テスト

以下のパッケージはテスト設定のサンプルとなっている。

- [ament_test_example](./ament_test_example/)