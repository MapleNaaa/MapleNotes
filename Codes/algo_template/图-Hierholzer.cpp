#include<bits/stdc++.h>
using namespace std;

void dfs(int u, unordered_map<int, vector<int>>& g, vector<int>& path) {
	while (!g[u].empty()) {
		int v = g[u].back();
		g[u].pop_back();
		dfs(v, g, path);
	}
	path.push_back(u);
}

vector<int> hierholzer(unordered_map<int, vector<int>>& g) {
	int u = g.begin()->first;
	vector<int> path;
	dfs(u, g, path);
	reverse(path.begin(), path.end());
	return path;
}