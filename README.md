# git_of_study
### git入门教程

#### windows安装

```
git config --global user.name "lshenhe"
git config --global user.email "792409563@qq.com"

ssh-keygen -t rsa -C "792409563@qq.com" 
把C:\Users\79240\.ssh\id_rsa.pub 的内容拷贝到https://github.com/settings/keys
```

#### Linux安装

```
git config --global user.name "lshenhe"
git config --global user.email "792409563@qq.com"

ssh-keygen -t rsa -C "792409563@qq.com" 
把/home/sam/.ssh/id_rsa.pub 的内容拷贝到https://github.com/settings/keys
```

#### git常用命令

```
git status
git add .
git commit -m "xxx"
git push origin master
```

#### git常见问题

```
git push解决办法： ! [remote rejected] master -> master (pre-receive hook declined)
git push不上去的原因在于所push的分支权限为protected,
只有项目的管理员或者项目的管理员指派的具有相应权限的人才能进行push,要进行项目的push,有如下两种方法：

1.将所要push的内容所在的分支的protected权限关闭
(1)进入所在项目的settings

(2)点击进入Protected branches,点击unprotected将master分支的权限改变，即关闭master的protected权限

2.新建其它分支，将项目push到新建的分支上，后期再进行merge
(1)新建分支

git branch 分支名
(2)切换分支

git checkout 分支名
(3)进行项目上传

git add .

git commit -m "提交的信息"

git remote add origin 远程仓库地址

git push -u origin 分支名

从远程仓库把分支拉到本地
git clone -b 分支名 仓库地址
```

### cmake入门教程

#### Linux安装

```
输入网址：https://cmake.org/download/
下载cmake-3.20.2.tar.gz

sudo apt install libssl-dev
tar -xvf cmake-3.14.5.tar
cd cmake-3.14.5
./bootstrap 
make
make install

检查cmake是否安装成功
执行cmake --version
```

### zmq入门教程

#### ubuntu zmq安装及基础测试

```
sudo apt install libtool pkg-config build-essential autoconf automake

编译安装zmq核心库
git clone git clone git://github.com/zeromq/libzmq
./autogen.sh
./configure && make check
sudo make install
sudo ldconfig
cd ..

安装zmq使用的加密库
输入网址：https://doc.libsodium.org/下载libsodium-1.0.18.tar.gz

tar -zxf libsodium-1.0.18-stable.tar.gz 
cd libsodium-stable/
./configure && make check
sudo make install 
sudo ldconfig 
cd ..

编译安装zmq的c绑定
git clone git://github.com/zeromq/czmq.git
cd czmq
./autogen.sh
./configure && make check
sudo make install
sudo ldconfig
cd ..

编译安装zmqc++绑定
git clone git@github.com:zeromq/cppzmq.git
cd cppzmq
sudo cp zmq.hpp /usr/local/include/
cd ..

学习zmq
根据zmq官网的guide学习
git clone git@github.com:booksbyus/zguide.git
cd zguide/examples/C
sudo apt install uuid-dev 
./build all

T1输入：
./hwserver
T2输入：
./hwclient

```

