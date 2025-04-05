#include<iostream>
#include<vector>
using namespace std;

// g 中默认值为 INT_MAX / 2;
vector<int> dijkstra(int n, int k, vector<vector<int>> g) {
	vector<int> dis(n + 1, INT_MAX / 2);
	vector<bool> done(n + 1, false);
	dis[k] = 0;

	while (true) {
		int x = -1;
		for (int i = 1; i <= n;i++) {
			if (!done[i] && (x < 0 || dis[i] < dis[x])) {
				x = i;
			}
		}

		if (x < 0) break;
		if (dis[x] == INT_MAX / 2) break;

		done[x] = true;
		for (int y = 1; y <= n;y++) {
			dis[y] = min(dis[y], dis[x] + g[x][y]);
		}
	}
	return dis;
}