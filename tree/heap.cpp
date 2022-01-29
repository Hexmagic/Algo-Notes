#include <iostream>
#include <algorithm>
#include <vector>

/*

堆是一棵完全二叉树，不过一般使用数组进行表示

# 堆的性质
      1
   2     3
 4  5   6  7

一般有小顶堆和大顶堆
对于小顶堆，对于堆的每个节点i，其值总是小于其左子树(i*2+1)和右子树(i*2+2)
对于大顶堆，对于堆的每个节点，其值总是大于其左子树(i*2+1)和右子树(i*2+2)

# 建堆

1. 建堆的过程是自底向上的
2. 根据堆的分类，对于小顶堆的某个节点O，若当前节点不满足小顶堆的性质（左子树或右子树的值小于O），交换最小子树和当前节点，检查最小值子树是否符合小顶堆的性质。

# 应用

一般用来解决topk的问题，复杂度 O(N*log N)
其中一次调整堆的过程的复杂度为O(log N)
空间复杂度 O(N)
*/

void heapfy(std::vector<int> &arr, int i, int end, bool(*comp)(int,int))
{
    int left = (i << 1) + 1;
    int right = (i << 1) + 2;
    int select_i = i;
    if(left<end&&comp(arr[left],arr[select_i]))
        select_i = left;
    if(right<end&&comp(arr[right],arr[select_i]))
        select_i = right;
    if (select_i!=i){
        std::swap(arr[select_i],arr[i]);
        heapfy(arr,select_i,end,comp);
    }
        
}

void make_heap(std::vector<int> &arr, bool(*comp)(int,int))
{
    int N = arr.size();
    for (int i = N / 2; i >= 0; i--)
    {
        heapfy(arr, i, N, comp);
    }
}

void heap_sort(std::vector<int>&heap,bool(&cmp)(int,int)){
    int N=heap.size();
    for(int i=N-1;i>=0;i--){
        std::swap(heap[0],heap[i]);
        heapfy(heap,0,i,cmp);
    }
}

bool greater(int a, int b)
{
    return a >= b;
}

bool less(int a, int b)
{
    return a <= b;
}

int main()
{
    std::vector<int> nums = {3, 1, 4, 1, 5, 9};
    make_heap(nums,greater);
    heap_sort(nums,greater);
    for(auto&num:nums)
        std::cout<<num<<" ";
    std::cout<<"\n";
}