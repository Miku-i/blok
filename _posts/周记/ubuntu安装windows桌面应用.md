# ubuntu安装windows应用

资料：https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu

安装deepin-wine

```
git clone https://gitee.com/wszqkzqk/deepin-wine-for-ubuntu.git
```

解压后切换到解压文件目录，在终端中运行（授予可执行权限后）： `./install.sh`

KDE或其他按照普通安装方式安装后运行出现X错误的桌面环境执行 `./KDE-install.sh`  ）。

###  （2）使用说明

下载并安装所需要的deepin-wine容器 *（建议在终端下使用dpkg -i安装容器，否则容易误报依赖错误）*

可使用deepin发布的最新版容器安装包：

1. [QQ](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im/)
2. [TIM](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.office/)
3. [QQ轻聊版](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.qq.im.light/)
4.  [微信](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.wechat/) 如果出现依赖错误，请下载[这个版本](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb) 
5. [Foxmail](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.foxmail/)
6. [百度网盘](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.baidu.pan/)
7. [360压缩](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.cn.360.yasuo/)
8. [WinRAR](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.cn.com.winrar/)
9. [迅雷极速版](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.thunderspeed/)
10. [千牛卖家工作台](https://mirrors.aliyun.com/deepin/pool/non-free/d/deepin.com.taobao.aliclient.qianniu/)

其它deepin-wine容器：[阿里云镜像下载](https://mirrors.aliyun.com/deepin/pool/non-free/d/)

####  若版本不兼容，可选择下载安装以下旧版包文件：

1. [QQ](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.qq.im_9.1.8deepin0_i386.deb)
2. [TIM](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.qq.office_2.0.0deepin4_i386.deb)
3. [QQ轻聊版](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.qq.im.light_7.9.14308deepin8_i386.deb)
4. [微信](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.wechat_2.6.8.65deepin0_i386.deb)
5. [Foxmail](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.foxmail_7.2deepin3_i386.deb)
6. [百度网盘](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.baidu.pan_5.7.3deepin0_i386.deb)
7. [360压缩](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.cn.360.yasuo_4.0.0.1060deepin3_i386.deb)
8. [WinRAR](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.cn.com.winrar_5.3.0deepin2_i386.deb)
9. [迅雷极速版](https://gitee.com/wszqkzqk/deepin-wine-containers-for-ubuntu/raw/master/deepin.com.thunderspeed_7.10.35.366deepin18_i386.deb)

注意：**1.目前基本适配最新版KDE，但测试可能不足(已测试可用：最新版KDE neon、Kubuntu 18.04/18.0.1/18.0.2)，欢迎大家测试反馈（建议将KDE升级到最新版）** **2.部分桌面环境无法正常使用视频通话功能！**