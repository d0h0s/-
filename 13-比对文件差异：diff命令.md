#比对文件差异：diff命令  
*diff即different*  
  
【1】先创建一个文件Test3.txt，内容是“aaaa”添加到暂存区，再提交到本地库  
【2】更改工作区中Test3.txt中内容，增加内容，即“aaaabbb”  
导致：工作区 和 暂存区 不一致，比对： 

    $ git diff Test3.txt  
    输出：
    -aaaa         Git是按照行为单位管理数据  
    +aaaabbb      所以：删除一行，添加一行  

**总结：  git diff [文件名]**  
将工作区中的文件和暂存区中文件进行比较  

##多个文件的比对：  

    $ git diff  

比较工作区中和暂存区中所有文件的差异  

##比较暂存区与本地库的差异  
将添加过“bbb”的文件添加到暂存区之后，比较暂存区与本地库的差异

    $ git diff HEAD Test3.txt  
              (HEAD指当前指针对应的版本)  

##将历史版本(暂存区)与工作区中的文件进行比对  

    $ git diff [索引号] Text3.txt

