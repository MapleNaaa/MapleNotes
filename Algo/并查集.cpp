//#include<iostream>
//#include<vector>
//using namespace std;
//
//class UnionSet {
//private:
//	vector<int> ft, size;
//	int n;
//public:
//	UnionSet(int _n) {
//		n = _n;
//		size.resize(n, 1);
//		ft.resize(n);
//		for (int i = 0; i < n;i++) {
//			ft[i] = i;
//		}
//	}
//
//	int find(int x) {
//		if (ft[x] == x) return x;
//
//		ft[x] = find(ft[x]);
//		return ft[x];
//	}
//
//	bool unionSet(int x, int y) {
//		int fx = ft[x], fy = ft[y];
//		if (fx == fy) return false;
//		if (size[fx] < size[fy]) swap(fx, fy);
//		size[fx] += size[fy];
//		ft[fy] = fx;
//		return true;
//	}
//};