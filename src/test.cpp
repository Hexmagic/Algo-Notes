#include <map>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    map<TreeNode *, TreeNode *> parent;
    TreeNode *treeMin(TreeNode *node)
    {
        if (node->left == NULL)
        {
            return node;
        }
        else
        {
            return treeMin(node->left);
        }
    }
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (p == NULL)
        {
            return NULL;
        }
        inOrder(root);
        if (p->right != NULL)
        {
            return treeMin(p->right);
        }
        else
        {
            TreeNode *P = parent[p];
            while (P != NULL && P->right == p)
            {
                p = P;
                P = parent[P];
            }
            return P;
        }
    }
    void inOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            if (root->left != NULL)
            {
                parent[root->left] = root;
                inOrder(root->left);
            }
            if (root->right != NULL)
            {
                parent[root->right] = root;
                inOrder(root->right);
            }
        }
    }
};