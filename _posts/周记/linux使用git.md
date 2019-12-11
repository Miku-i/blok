# linux使用git

# 1.准备

### 1.1安装git

* ubuntu：`sudo apt-get install git`https://git-scm.com/download/linux

## 1.2全局配置

当安装完 Git 应该做的第一件事就是设置你的用户名称与邮件地址。 这样做很重要，因为每一个 Git 的提交都会使用这些信息，并且它会写入到你的每一次提交中，不可更改：

```console
$ git config --global user.name "miku"
$ git config --global user.email 1375696279@qq.com
```

如果想要检查你的配置，可以使用 `git config --list` 命令来列出所有 Git 当时能找到的配置。

你可以通过输入 `git config `： 来检查 Git 的某一项配置

```console
$ git config user.name
```

### 1.3帮助

若你使用 Git 时需要获取帮助，有三种方法可以找到 Git 命令的使用手册：

```console
$ git help <verb>
$ git <verb> --help
$ man git-<verb>
```

例如，要想获得 config 命令的手册，执行

```console
$ git help config
```

## 2.Git基础

### 2.1获取仓库

#### 2.1.1在现有目录中初始化仓库

如果你打算使用 Git 来对现有的本地项目进行管理，你只需要进入该项目目录并输入：

```console
$ git init
```

该命令将创建一个名为 `.git` 的子目录，这个子目录含有你初始化的 Git 仓库中所有的必须文件，这些文件是 Git 仓库的骨干。

#### 2.1.2获取github或者码云上的git仓库

克隆仓库的命令格式是 `git clone [url]` 。 比如，要克隆 Git 的可链接库 libgit2，可以用下面的命令：

```console
$ git clone https://github.com/libgit2/libgit2
```

这会在当前目录下创建一个名为 “libgit2” 的目录，并在这个目录下初始化一个 `.git` 文件夹，从远程仓库拉取下所有数据放入 `.git` 文件夹，然后从中读取最新版本的文件的拷贝。

自定义本地仓库的名字，你可以使用如下命令：

```console
$ git clone https://github.com/libgit2/libgit2 mylibgit
```

这将执行与上一个命令相同的操作，不过在本地创建的仓库名字变为 `mylibgit`。

### 2.2记录更新到仓库

#### 2.2.1检查当前文件状态

要查看哪些文件处于什么状态，可以用 `git status` 命令。 如果在克隆仓库后立即使用此命令，会看到类似这样的输出：

```console
$ git status
On branch master
nothing to commit, working directory clean
```

`git status`给出的信息非常详细，想要看简洁的可以使用`git status -s`，其中：

> A -- 新提交到暂存区的文件
>
> M -- 文件被修改但是还未放入暂存区
>
> ?? -- 工作区新添加的文件，但未添加到暂存区

#### 2.2.2添加到缓存区

使用命令 `git add` 开始跟踪一个文件。 所以，要跟踪 README 文件，运行：

```console
$ git add README
```

此时再运行 `git status` 命令，会看到 README 文件已被跟踪，并处于暂存状态。

如果有多个文件被修改，想要全部添加，可以用`git add *`。

#### 2.2.3忽略文件

有一些文件我们不希望他总出现在为跟踪文件列表，比如日志文件，或者编译过程中创建的临时文件等。

我们可以创建一个名为 `.gitignore` 的文件，列出要忽略的文件模式。 来看一个实际的例子：

```console
$ cat >.gitignore  //这一行是linux脚本命令，创建一个名为.gitignore的文件
*.a                             //这下面是在这个文件中添加的内容，这行的是以.a结尾的文件
```

文件 `.gitignore` 的格式规范如下：

-  所有空行或者以 `＃` 开头的行是注释，都会被 Git 忽略。
-  以斜杠“/”开头表示目录；
-  以星号“*”通配多个字符；
-  以问号“?”通配单个字符以方括号“[]”包含单个字符的匹配列表；
-  以叹号“!”表示不忽略(跟踪)匹配到的文件或目录；

被过滤掉的文件就不会出现在git仓库中（gitlab或github）了，当然本地库中还有，只是push的时候不会上传。
需要注意的是，gitignore还可以指定要将哪些文件添加到版本管理中：
1）!*.zip
2）!/mtk/one.txt

唯一的区别就是规则开头多了一个感叹号，Git会将满足这类规则的文件添加到版本管理中。
为什么要有两种规则呢？想象一个场景：假如我们只需要管理/mtk/目录中的one.txt文件，这个目录中的其他文件都不需要管理，那么我们就需要使用：
1）/mtk/
2）!/mtk/one.txt

因此一定要养成在项目开始就创建.gitignore文件的习惯，否则一旦push，处理起来会非常麻烦。

在里面输入.gitignore可以忽略它自己本身

#### 2.2.4尚未暂存的改动

`git diff` 将通过文件补丁的格式显示具体哪些行发生了改变。

此命令比较的是工作目录(Working tree)和暂存区域快照(index)之间的差异，也就是修改之后还没有暂存起来的变化内容。

`git diff --cached`
`git diff --staged`
查看已经暂存起来的文件(staged)和上次提交时的快照之间(HEAD)的差异
显示的是下一次commit时会提交到HEAD的内容(不带-a情况下)

显示工作版本(Working tree)和HEAD的差别
 ` git diff HEAD`

#### 2.2.5提交更新

`git commit -m "这是自己输入的提交信息"`将暂存区的文件上传至仓库，完成提交。

#### 2.2.6删除文件

如果只是简单地从工作目录中手工删除文件，运行 `git status` 时就会在 “Changes not staged for commit” 部分（也就是 *未暂存清单*）看到此次变动。此时有两种情况

1. 是误删，可以从版本库中恢复`git checkout -- 误删文件`

> 需要注意的是，如果误删掉的文件还没有被添加到版本库，无法恢复

2. 确实要删除，那么要在版本库中也将他删除

   ``````
   git rm 文件名
   rm "文件名"
   ``````

   然后向版本库提交本次操作。

#### 2.2.6改名

git的改名可以这样来完成`git mv oldname newname`

这样就将oldname改成了newname

其实，运行 `git mv` 就相当于运行了下面三条命令：

```console
$ mv oldname newname
$ git rm oldname
$ git add newname
```

### 2.3版本信息

`git log`查看各个版本信息

`git log -p`查看各个版本的修改信息
git log有很多参数，可以指定查询范围，例如作者时间等，需要上网查阅。

`git log --author="名字"`指定作者

`git log -2`最近两次提交

`git log --since=2.weeks`进两周的提交,这个命令可以在多种格式下工作，比如说具体的某一天 `"2008-01-15"`，或者是相对地多久以前 `"2 years 1 day 3 minutes ago"`。

### 2.4重新提交

#### 2.4.1重新提交

如果提交之后发现刚刚提交的版本少了一些东西，或者提交信息写错了，那么可以重新提交，使用命令

`git commit --amend`这个命令会让你重新提交暂存区的东西，然后重新写提交信息。

#### 2.4.2取消暂存文件。

如果某一个文件不想提交到暂存区但是不小心`git add *`了，

那么可以使用`git reset HEAD 1.txt`来取消1.txt的暂存。

再次使用git status 则可看见1.txt未暂存。

#### 2.4.3撤销对文件的修改

如果修改了某个文件内容，又想将他车回到上次提交时候的状态

可以使用`git checkout -- 1.txt`这样1.txt已经回到了上一个版本的样子

### 2.5远程仓库

#### 2.5.1查看远程库列表

`git remote`可以列出你指定的每一个远程库的简写

`git remote -v`可以列出每一个远程库的简写及地址。

#### 2.5.2添加远程库连接和简写

`git remote add origin url `url是你的远程库地址，这个地址的简写就是origin。

#### 2.5.3从远程仓库中抓取与拉取

就如刚才所见，从远程仓库中获得数据，可以执行：

```console
$ git fetch [remote-name]
```

这个命令会访问远程仓库，从中拉取所有你还没有的数据。 执行完成后，你将会拥有那个远程仓库中所有分支的引用，可以随时合并或查看。

如果你使用 `clone` 命令克隆了一个仓库，命令会自动将其添加为远程仓库并默认以 “origin” 为简写。 所以，`git fetch origin` 会抓取克隆（或上一次抓取）后新推送的所有工作。 必须注意 `git fetch` 命令会将数据拉取到你的本地仓库——它并不会自动合并或修改你当前的工作。 当准备好时你必须手动将其合并入你的工作。

如果你有一个分支设置为跟踪一个远程分支（阅读下一节与 [Git 分支](https://git-scm.com/book/zh/v2/ch00/ch03-git-branching) 了解更多信息），可以使用 `git pull` 命令来自动的抓取然后合并远程分支到当前分支。 这对你来说可能是一个更简单或更舒服的工作流程；默认情况下，`git clone` 命令会自动设置本地 master 分支跟踪克隆的远程仓库的 master 分支（或不管是什么名字的默认分支）。 运行 `git pull` 通常会从最初克隆的服务器上抓取数据并自动尝试合并到当前所在的分支。

#### 2.5.4推送到远程仓库

当你想分享你的项目时，必须将其推送到上游。 这个命令很简单：`git push [remote-name] [branch-name]`。 当你想要将 master 分支推送到 `origin` 服务器时（再次说明，克隆时通常会自动帮你设置好那两个名字），那么运行这个命令就可以将你所做的备份到服务器：

```console
$ git push origin master
```

#### 2.5.5查看某一个远程仓库

如果想要查看某一个远程仓库的更多信息，可以使用 `git remote show [remote-name]` 命令。 如果想以一个特定的缩写名运行这个命令，例如 `origin`。

可以看到如下：

```
wangzj@wangzj-virtual-machine:~/Computer/GitTest$ git remote show origin
远程 origin
获取地址：git@github.com:Wang-Zejin/GitTest.git
推送地址：git@github.com:Wang-Zejin/GitTest.git
HEAD 分支：master
远程分支：
  master 已跟踪
为 'git push' 配置的本地引用：
  master 推送至 master (最新)
wangzj@wangzj-virtual-machine:~/Computer/GitTest$
```

#### 2.5.6远程仓库的移除与重命名

```console
git remote rename oldname newname      //将oldname变为newname
```

```console
git remote rm paul       //将命为paul的远程链接删除了。
```

### 2.6加版本标签

