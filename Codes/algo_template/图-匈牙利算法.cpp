#include<bits/stdc++.h>
using namespace std;

bool dfs(int u , vector<vector<int>>& g, vector<bool>& visited,vector<int>& matchs) {
	for (int v : g[u]) {
		if (visited[v])  continue;
		visited[v] = true;
		if (matchs[v] == -1 || dfs(matchs[v], g, visited, matchs)) {
			matchs[v] = u;
			return true;
		}
	}
	return false;
};

// g н╙аз╫с╠М
int hungarian(vector<vector<int>>& g,int m) {
	int res = 0;
	vector<int> matchs(m, -1);
	vector<bool> visited;
	for (int u = 0; u < g.size(); u++) {
		visited.assign(m, false);
		if (dfs(u,g,visited,matchs)) {
			res++;
		}
	}
	return res;
}


