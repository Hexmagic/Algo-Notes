/*

线段树是一种二叉搜索树，什么叫做二叉搜索树，首先满足二叉树，每个结点度小于等于二，即每个结点最多有两颗子树，何为搜索，我们要知道，线段树的每个结点都存储了一个区间，也可以理解成一个线段，而搜索，就是在这些线段上进行搜索操作得到你想要的答案

## 线断树的性质
1. 线段树主要可以看做伪完全二叉树，可以用数组表示。即使节点不存在也要占用空间
对于n个节点的区间构造线断树需要4*n的空间
2. 线段树把一个长度为 的区间分成不超过2 L 条线段

## 线断树的构造

设数列A 包含 N 个元素，则线段树的根节点表示整个区间A[1,N]，左孩子表示区间A[1,(1+N)/2]，右孩子表 
示区间A[(1+N)/2+1,N]，不断递归，直到叶子节点，叶子节点只包含一个元素

对于节点K的有左子树位置K<<1,右子树位置K<<1|1

线断树一般查询和更新功能(对于区间和问题不需要更新的话一般前缀数组就可以解决)

		 0-3
       /     \
	  0-1    2-3
	 /  \    /  \
	0    1  2    3

	对于数组arr [3,4,8,3]有上面的线段数，可以知道当线段树中的节点的范围对应同一个数i的时候
	，线段树该节点的值对应原数组对应位置的值。
	由线段数的定义可以指上面的范围对应到数组中的位置的树如下所示
		  0
		/   \
	   1     2
      / \   / \
	 3   4  5  6

	由上面的知识知道，递归由下向上构建线段数组segs
	```
	segs[3] = arr[0] #3 
	segs[4] = arr[1] #4
	segs[1] = segs[3]+segs[4] #7

	segs[5] = arr[2] # 8
	segs[6] = arr[3] # 3
	segs[2] = segs[5]+segs[6] # 11

	segs[0] = segs[1]+segs[2] # 18
	```
	对应下面的结果
	     0-3(18）
        /     \
	  0-1(7)  2-3(11)
	 /  \     /  \
	0    1   2    3 
   (3)  （4）(8)  (3)	
*/
#include <vector>
#include <cassert>
using namespace std;

class Segment {
public:
	vector<int> segs;
	vector<int> nums;
	Segment(vector<int>& arr) {
		segs.resize(arr.size() * 4);
		nums = arr;
		build(0, 0, arr.size()-1);
	}
	void build(int i, int l, int r) {
		if (l == r) {
			segs[i] = nums[l];
		}
		else {
			int mid = (l + r) >> 1;
			int il = (i << 1) + 1;
			int ir = (i << 1) + 2;
			build(il, l, mid);
			build(ir, mid + 1, r);
			segs[i] = segs[il] + segs[ir];
		}
	}
	int search(int i,int l, int r,int L,int R) {
		if (r < l)
			return 0;
		if (l == L && r == R)
			return segs[i];
		int mid = (L+R) >> 1;
		return search((i << 1) + 1, l, min(mid, r), L, mid) + search((i << 1) + 2, mid + 1, r, mid + 1, R);
	}

	void update(int i,int ind,int val,int L,int R) {
		if (L == R)
			segs[i] = val;
		else {
			int l = (i << 1) + 1;
			int r = (i << 1) + 2;
			int mid = (L + R) >> 1;
			if (mid >= ind) {
				update(l, ind,val, L, mid);
			}else {
				update(r, ind,val, mid + 1, R);
			}
			segs[i] = segs[l] + segs[r];
		}
	}


};


int main(int argc,char **argv) {
	vector<int> arr = { 3,4,8,3 };
	Segment seg(arr);
	int ans = seg.search(0,0, 2,0,3);
	assert(ans == 15);
	ans = seg.search(0, 0, 3, 0, 3);
	assert(ans == 18);
	ans = seg.search(0, 1, 2, 0, 3);
	assert(ans == 12);
	seg.update(0, 1, 9, 0, 3);
	ans = seg.search(0, 1, 2, 0, 3);
	assert(ans == 17);
	return 0;
}