//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//struct Next {
//	int b, w;
//	Next(int b, int w) :b(b), w(w) {};
//	bool const operator<(const Next& other) const {
//		return w < other.w;
//	}
//	bool const operator>(const Next& other) const {
//		return w > other.w;
//	}
//};
//
//// g 中默认值为 INT_MAX / 2;
//vector<int> dijkstra(int n, int k, vector<vector<Next>> g) {
//	vector<int> dis(n + 1, INT_MAX / 2);
//	vector<bool> done(n + 1, false);
//
//	dis[k] = 0;
//	priority_queue<Next, vector<Next>, greater<>> pq;
//	pq.emplace(k, 0);
//
//	while (!pq.empty()) {
//		Next n = pq.top();
//		pq.pop();
//		int b = n.b, w = n.w;
//
//		if (w > dis[b]) continue;
//
//
//		if (x < 0) break;
//		if (dis[x] == INT_MAX / 2) break;
//
//		done[x] = true;
//		for (int y = 1; y <= n;y++) {
//			dis[y] = min(dis[y], dis[x] + g[x][y]);
//		}
//	}
//	return dis;
//}