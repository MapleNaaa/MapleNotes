//#include<iostream>
//#include<vector>
//#include<algorithm>
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
//
//struct Edge {
//	int a, b, w;
//	Edge(int a, int b, int w) :a(a), b(b), w(w) {};
//};
//
//int kruskal(int n, vector<Edge>& edges) {
//	sort(edges.begin(), edges.end(), [](Edge a, Edge b)-> bool {return a.w < b.w;});
//	UnionSet ust(n);
//	int ret = 0, num = 1; // num = 1 当前点开始
//	for (auto& e : edges) {
//		int a = e.a, b = e.b, w = e.w;
//		if (ust.unionSet(a, b)) {
//			ret += w;
//			num++;
//			if (num == n) break;
//		}
//	}
//	return ret;
//}