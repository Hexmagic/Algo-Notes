/*
 如果字典树的某个节气只有一个子节点，可以将自节点和当前节点合并，合并后的字典树成为压缩字典树

后缀树是一棵压缩字典树，与前缀树不同，后缀树对于一个单词给出该单词的所有后缀。例如ABC
    
      $
    C C C
   B  B
      A
## 后缀树的应用
   后缀树提出的目的是用来支持有效的字符串匹配和查询。例如
## 后缀树的构造
   简单的后缀树构造可以先构造字典，然后进行压缩，比较简单复杂度相对较高. 下面我们学习多路插入：
   这里要明白一些概念：
   显示节点： 后缀树中的节点
   隐式节点： 出现在字典树但是没有在后缀树中的点（被压缩的点）
   尾部链表： 连接当前尾部节点
   

*/