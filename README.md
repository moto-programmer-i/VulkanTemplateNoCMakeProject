# CMakeを使用しないVulkanテンプレートプロジェクト（Visual Studio 2022）

[推奨のCMakeを使ったVulkanプロジェクト](https://github.com/moto-programmer-i/VulkanTemplateProject)では1行変えるたびにビルドに時間がかかり、
CMakeを使わない場合はどうなるか試したかったので作成。他の環境で動くかどうかは未確認です。

このプロジェクトでは適切にモジュール分けをしているので、ちゃんと変更した分だけコンパイルされます。

私の環境では.cppを1行変更→実行が、CMakeを使った場合では15秒ほどかかっていましたが、1秒もかからないようになりました。

[PropertySheet.props](/PropertySheet.props)にVULKAN_SDKのパスを定義しているので、環境に合わせて変更してください。

### 動作確認済み環境
- Windows10
- Visual Studio 2022


# 前提
以下をインストール

- [Vulkan SDK](https://vulkan.lunarg.com/)

（詳細は[公式の環境構築チュートリアル](https://docs.vulkan.org/tutorial/latest/02_Development_environment.html)にも書いてありますが、最小限ではない上に、一部非推奨な機能も使用している[チュートリアルプロジェクト](https://github.com/KhronosGroup/Vulkan-Tutorial)
のクローンをしていることが前提となっており、分かりづらいと思います）



# 注意点
- [PropertySheet.props](/PropertySheet.props)は環境依存なので、修正してください。<br>（<b>Vulkan SDKのインストール場所を指定する</b>必要があります）
- GLFWはモジュール化したため[glfw_window](/glfw_window/)フォルダ以下にあります。
- VulkanのチュートリアルにあるHelloTriangleApplication.cppはモジュール化したため、[VulkanTutorial.ixx](/vulkan/VulkanTutorial.ixx)に移動しました。<br>GLFWのモジュール化に伴い、構成が一部変わっています。
- VulkanはCMakeの使用を推奨しているため、不測の問題が発生する場合が十分にあります