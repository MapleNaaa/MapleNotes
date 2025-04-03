#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& g, vector<int>& color, int idx , int c) {
	color[idx] = c;
}

bool isBiPart(vector<vector<int>>& g) {
	int n = g.size();
	vector<int> color(n, -1);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1 && !dfs()) {
			return false;
		}
	}
	return true;
}