#include "bst.hpp"

void morris(TreeNode<int> *cur){
    /**
     * @brief morris order
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