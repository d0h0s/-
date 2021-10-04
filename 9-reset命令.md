#reset命令：前进或者后退历史版本  
用git reflog查看日志，会在首行返回以下内容：  

    历史索引 （HARD -> master） HEAD@{0}: commit: 注释  
          (代表指针指在这个版本上) （回退版本所需步数）  


HARD相当于指针名。  

    git reset --hard 索引  

可以往前也可以往后跳转指针。  

>复制：在终端中选中就是复制了  
粘贴： 右键：paste