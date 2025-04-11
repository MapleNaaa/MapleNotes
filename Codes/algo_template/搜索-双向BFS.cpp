#include<bits/stdc++.h>
using namespace std;

int bibfs(int a, int b, vector<vector<int>>& g) {
	if (a == b) return 0;

	queue<int> qs{ {a} }, qb{ {b} };
	unordered_map<int, int> vis_s{ {a,0} }, vis_b{ {b,0} };

	while (!qs.empty() && !qb.empty()) {
		if (qs.size() > qb.size()) {
			swap(qs, qb);
			swap(vis_s, vis_b);
		}

		int n = qs.size();
		for (int i = 0; i < n; i++) {
			int cur = qs.front();
			qs.pop();

			for (auto next : g.at(cur)) {
				if (vis_b.count(next)) {
					return vis_s[cur] + 1 + vis_b[next];
				}

				if (!vis_s.count(next)) {
					vis_s[next] = vis_s[cur] + 1;
					qs.push(next);
				}
			}

		}
	}
	return -1;
}

int bibfs2(int a, int b, vector<vector<int>>& g) {
	if (a == b) return 0;

	queue<int> q;
	unordered_map<int, pair<int,int>> vis;
	q.push(a);
	q.push(b);
	vis[a] = { 1,0 };
	vis[b] = { 2,0 };

	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; i++) {
			int cur = q.front();
			q.pop();

			pair<int, int> info = vis[cur];
			int dir = info.first, step = info.second;

			for (int next : g[cur]) {
				if (vis.count(next)) {
					pair<int, int> tmp = vis[next];
					if (tmp.first != dir)
						return step + 1 + tmp.second;
				}
				else {
					vis[next] = { dir,step + 1 };
					q.push(next);
				}
			}
		}
	}
	return -1;
}