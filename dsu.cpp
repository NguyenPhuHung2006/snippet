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

template<class T = int, class S = int>
class DSU
{
private:
	vector<T> Parent;
	vector<S> Size;
public:
	DSU(int n)
	{
		Parent.resize(n);
		Size.resize(n, static_cast<S>(1));
		iota(Parent.begin(), Parent.end(), static_cast<T>(0));
	}

	T find(T u)
	{
		if(u != Parent[u])
			Parent[u] = find(Parent[u]);
		return Parent[u];
	}

	void unite(T u, T v)
	{
		u = find(u);
		v = find(v);
		if(u == v)
			return;

		if(Size[u] < Size[v])
			swap(u, v);

		Parent[v] = u;
		Size[u] += Size[v];
	}

	bool same(T u, T v)
	{
		return find(u) == find(v);
	}

	S size(T u)
	{
		return Size[find(u)];
	}
};

int main()
{

}
