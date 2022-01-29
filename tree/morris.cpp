#include "bst.hpp"

void morris(TreeNode<int> *cur){

    /**
    ## 线索二叉树
    二叉树中存在很多空指针，可以利用这些空指针，指向其前驱或者后继。这种利用起来的空指针称为线索，这种改进后的二叉树称为线索二叉树,

    ## Morris遍历
    我们知道，实现二叉树的前序、中序、后序遍历有两个常用的方法，一是递归，二是栈。这两种方法都是O(N)的空 间复杂度。而Morris 遍历只需要O(1)的空间复杂度。这种算法跟线索二叉树很像，不过 一边建线索，一边访问数据，访问完后销毁线索，保持二叉树不变 (下面的实现会破坏原来的结构)
    
    ## Morris中序遍历
     *  1. 若当前节点Cur左节点L有右节点 ，使L的最右节点Mr->right = cur;  让cur移动到cur->left 消除cur和cur->left的联系
     * 2. 若当前节点cur的左节点无右节点， 让cur移动到cur->left 消除cur和cur->left的联系
     * 3. 若当前节点cur无左节点输出当前节点
     * > 获取下一个节点统一用cur->right
     */
     while(cur){
         if(cur->left){
             auto cL = cur->left;
             if(cL){
                 while(cL->right){
                     cL = cL->right;
                 }                 
             }
             auto cpyCur=cur;
             cL->right=cur;
             cur=cur->left;
             cpyCur->left=nullptr;
             
         }else{
             cout<<cur->x<<endl;
             cur=cur->right;             
         }
     }
}
int main(int argc, char **argv){
    TreeNode<int> root(3);
    root.insert(2);
    root.insert(1);
    root.insert(4);
    root.insert(5);
    morris(&root);
    return 0;
}