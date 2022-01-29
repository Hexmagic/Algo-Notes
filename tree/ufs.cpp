/*
并查集本质是构造多颗多叉树，将连通的节点指向同一根节点，通常用来查询两个节点是否属于同一连通域或者用来统计图中连通域的数量

可以参考![算法学习笔记(1) : 并查集](https://zhuanlan.zhihu.com/p/93647900/)


并查集提供两个操作：合并和查询,构建并查集的一般操作

    1. 初始化每个节点的父节点指向自己,一般用数组表示父节点列表

    2. 查询父节点：
        查询当前节点的父节点是否是根节点，是的话直接返回根，不是的话递归向上查找，并把当前节点的父节点指向当前父节点的父节点（parent[x]=parent[parent[x]])

    3. 合并两个节点A和B：
        查询A的父节点Pa和B的父节点Pb;
        若Pa!=Pb，将B的父节点指向Pa(将A的父节点指向Pb);

>  简单的并查集默认节点是连续的序列，例如0,1..n。

*/
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class UFS{
    public:
        vector<int> parent;
        UFS(int n):parent(n){
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
        int find(int x){
            while(x!=parent[x]){
                parent[x]=parent[parent[x]];
                x=parent[x];
            }
            return x;
        }
        void union_(int a,int b){
            int pa = find(a);
            int pb = find(b);
            if(pa!=pb)
                parent[pb]=pa;
        }

};

/**
 * @brief 病毒感染者
 *

## Question:
 一个学校有n 个社团，一个学生能同时加入不同的社团。由于社团内的同学们交往频繁，如果 
一个学生感染了病毒，该社团的所有学生都会感染病毒。现在 号学生感染了病毒，问一共有多少 
个人感染了病毒

例如有4个社团，学生编号0~99,其中一些学生加入了4个社团，每个社团的人员如下

社团1: 1 2
社团2: 10 11 12 13 14
社团3: 0 1           
社团4: 99 2
 * 
 */
int main(){
    unordered_set<int> students;
    vector<vector<int>> orgnizations = {
        {1,2},
        {10,11,12,13,14},
        {0,1},
        {2,99}
    };
    UFS ufs(100);
    for(auto org: orgnizations){
        students.insert(org[0]);
        for(int i=1;i<org.size();i++){
            ufs.union_(org[0],org[i]);
            students.insert(org[i]);
        }
    }
    int p=ufs.find(0);
    int ans = 0;
    for(auto stu:students){
        if(ufs.find(stu)==p)
                ans++;
    }
    std::cout<<ans<<" 学生感染病毒"<<std::endl;
    return ans;    
}