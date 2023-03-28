# ament_example

本レポジトリは [ROS2 自律走行実現に向けて～次世代ロボット開発フレームワークROS2のビルドシステム徹底理解～](https://speakerdeck.com/fixstars/autonomous-driving-realization-by-ros2) セミナーで発表した事項のサンプルコードとなっている。

本サンプルコードは ROS2 humble においてビルド/実行可能なのを確認している。本サンプルコードは以下のサブディレクトリにわかれている。それぞれの内容についてはサブディレクトリの README を参照のこと。

- [ament_cmake](./ament_cmake/): ament_cmake のサンプル
- [ament_cmake_advanced](./ament_cmake_advanced/): plugin 作成および ament 拡張のサンプル
- [ament_cmake_auto](./ament_cmake_auto/): ament_cmake_auto のサンプル
- [ament_python](./ament_python/): ament_python のサンプル

# ビルド方法

本サンプル以下の手順でビルドできる。

```bash
git clone <TBD>
colcon build
```
