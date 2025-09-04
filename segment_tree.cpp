#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <limits>
using namespace std;

template<class T>
class SegmentTree
{
private:
	vector<T> tree;
	int N;
public:
	SegmentTree(const vector<T>& a) : N(a.size())
	{
		tree.resize(2 * N);
		for(int i = 0; i < N; i++)
			tree[N + i] = a[i];

		for(int i = N - 1; i >= 1; i--)
			tree[i] = T::combine(tree[i << 1], tree[i << 1 | 1]);
	}

	void update(int i, T val)
	{
		tree[N + i] = val;
		for(int j = (N + i) >> 1; j >= 1; j >>= 1)
			tree[j] = T::combine(tree[j << 1], tree[j << 1 | 1]);
	}

	T query(int l, int r)
	{
		T res;
		for(l += N, r += N; l <= r; l >>= 1, r >>= 1)
		{
			if(l & 1)
				res = T::combine(res, tree[l++]);
			if(!(r & 1))
				res = T::combine(res, tree[r--]);
		}
		return res;
	}

};

struct Node
{
	int val, idx;
	Node(int val, int idx) : val(val), idx(idx) {}
	Node() : val(-1e4), idx(-1) {}
	static Node combine(const Node& a, const Node& b)
	{
		if(a.val >= b.val)
			return a;
		return b;
	}
	int get()
	{
		return idx;
	}
};

int main() 
{
	vector<int> a = {1, 2, 3, 4};
	vector<Node> A;
	for(int i = 0; i < a.size(); i++)
		A.emplace_back(a[i], i);

	SegmentTree<Node> sgm(A);

	cout << sgm.query(0, 3).get();
}

