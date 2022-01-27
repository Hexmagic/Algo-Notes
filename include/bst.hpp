#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    TreeNode *left, *right;
    T x;
    TreeNode(T x) : x(x), left(nullptr), right(nullptr){};
    ~TreeNode()
    {
        delete left;
        delete right;
    }
    void insert(int k)
    {
        if (this->x == k)
            return;
        if (k < this->x)
        {
            if(this->left == nullptr){
                this->left = new TreeNode (k);
            }else{
                this->left->insert(k);
            }
        }
        else
        {
            if(this->right == nullptr)
                this->right = new TreeNode(k);
            else
                this->right->insert(k);
        }
    }
    void inOrder(){
        if(this->left!=nullptr){
            this->left->inOrder();
        }
        cout<<this->x<<endl;
        if(this->right!=nullptr){
            this->right->inOrder();
        }
    }
};
