# Vulkanテンプレートプロジェクト（Visual Studio 2022）

[Vulkan](https://www.vulkan.org/)の[チュートリアル](https://github.com/KhronosGroup/Vulkan-Tutorial/tree/main/attachments)に、
最小限のテンプレートプロジェクトがなかったため作成。他の環境で動くかどうかは未確認です。


しかし、[CMakeLists.txt](/CMakeLists.txt)の内容だけでも価値はあると思います。

### 動作確認済み環境
- Windows10
- Visual Studio 2022


# 前提
以下をインストール

- [vcpkg](https://github.com/microsoft/vcpkg)
- [Vulkan SDK](https://vulkan.lunarg.com/)

（詳細は[公式の環境構築チュートリアル](https://docs.vulkan.org/tutorial/latest/02_Development_environment.html)にも書いてありますが、最小限ではない上に、一部非推奨な機能も使用している[チュートリアルプロジェクト](https://github.com/KhronosGroup/Vulkan-Tutorial)
のクローンをしていることが前提となっており、分かりづらいと思います）


# 公式のプロジェクトからの変更点
1. [CMakePresets.json](/CMakePresets.json)で CMAKE_TOOLCHAIN_FILEを指定
1. C++20が前提であることをCMakeLists.txtに定義
1. CMakeLists.txt内のプロジェクト名を\$\{PROJECT_NAME\}に置換
1. vcpkgの依存を最小限に
1. Vulkan SDKのリンクをtarget_include_directoriesのみに<br>（ここに関しては正しいのかどうか不明）


# 注意点
- [CMakeUserPresets.json](/CMakeUserPresets.json)は環境依存なので、修正してください。<br>（<b>vcpkgとVulkan SDKのインストール場所を指定する</b>必要があります）
- このプロジェクトをクローンしてそのまま確認できることを目指したため、CMakeUserPresets.jsonがGit管理に含まれています。<br>ここから開発をする場合は[.gitignore](/.gitignore)で管理外にしてください。