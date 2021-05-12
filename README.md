# git_of_study
### 入门教程

#### windows

```
git config --global user.name "lshenhe"
git config --global user.email "792409563@qq.com"

ssh-keygen -t rsa -C "792409563@qq.com" 
把C:\Users\79240\.ssh\id_rsa.pub 的内容拷贝到https://github.com/settings/keys
```

#### Linux

```
git config --global user.name "lshenhe"
git config --global user.email "792409563@qq.com"

ssh-keygen -t rsa -C "792409563@qq.com" 
把/home/sam/.ssh/id_rsa.pub 的内容拷贝到https://github.com/settings/keys
```

### 常用命令

```
git status
git add .
git commit -m "xxx"
git push origin master
```

### 常见问题

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


