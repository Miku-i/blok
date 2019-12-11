# ubuntu装可视化数据库管理工具navicat

## DBServer （免费）

第一个是 DbServer，只不过装的时候好像要装 java 环境，不然运行不了。这里我就不讲安装方法了。

## Workbench（免费）

> 下载地址：workbench_mysql_64位
> 下载成功后，执行命令

sudo dpkg -i  mysql-workbench-community-6.3.9-1ubuntu16.04-amd64.deb
1

> 如果安装不成功的提示，可以输入以下命令: 

1. 安装依赖
2. sudo apt-get -f install
3. 然后重复上一个命令
4. sudo dpkg -i  mysql-workbench-community-6.3.9-1ubuntu16.04-amd64.deb

## Navicat （收费）

下载地址：[navicat120_premium_cs_64位](https://sn9.us/file/15082937-219532242)
下载成功后解压。

> 1. tar -zxvf ~/Downloads/navicat120_premium_cs_x64.tar.gz 
>    运行
>

1. cd navicat120_premium_cs_x64/
2. ./start_navicat 

PS: 由于是试用版的，这里有破解方案

**第一种**
第一次执行 start_navicat 时，会在用户主目录下生成一个名为 .navicat64 的隐藏文件夹。

1. cd ~/.navicat64/

2. 此文件夹下有一个 system.reg 文件

3. rm system.reg

4. rm user.reg



**第二种**
用 win 破解后，直接替换文件
删除 navicat120_premium_cs_x64/Navicat 里面的文件。

区别

> 第一种方案是 临时的每 15 天就要执行一次。
> 第二种方案是永久的。不过比较繁琐。这里我直接破解了。并放上下载地址了。你们直接解压替换里面文件就好了。
> 下载地址：[Win_Navicat_64位 破解](https://sn9.us/file/15082937-219535727) (Win 系统下可以直接使用)



————————————————
版权声明：本文为CSDN博主「Per丶逸侨」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_39904777/article/details/77967688



**汉化**

五、解决navicat界面显示乱码的问题

运行./start_navicat前，用vim编辑器打开start_navicat，将export LANG="en_US.UTF-8" 更改为export LANG="zh_CN.UTF-8"，重新启动，界面显示正常

原文链接：https://blog.csdn.net/qq_25135655/article/details/89843202

**放进全部应用程序**

1.打开文本编辑器输入如下代码保存为（“navicat.desktop”）

```
[Desktop Entry]

Encoding=UTF-8

Name=Navicat Premium

Comment=The Smarter Way to manage dadabase

Exec=/bin/sh "/home/wangzj/Computer/navicat/navicat120_premium_cs_x64/start_navicat"

Icon=/home/wangzj/Computer/navicat/navicat120_premium_cs_x64/Navicat/navicat.png

Categories=Application;Database;MySQL;navicat

Version=1.0

Type=Application

Terminal=0
Name[zh_CN]=navicat.desktop
```

注意其中exec是你的start_navicat的路径

icon是你要显示的图标的路径(这里提供一个网络上的图标[img](https://img-blog.csdn.net/20170727100040539?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvd3VfbGlhbl9uYW4=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast))

2.在navicat.destop所在目录打开终端输入

`sudo chmod 777 navicat.desktop`或者`sudo chmod +x navicat.desktop`

赋予运行权限

3.将这个文件移动到`/usr/share/applications`目录下

