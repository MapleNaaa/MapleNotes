#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& g, vector<int>& color, int idx , int c) {
	color[idx] = c;
	for (int v : g[idx]) {
		if (color[v] == -1) {
			if (!dfs(g, color, v, c ^ 1)) {
				return false;
			}
		}
		else if (color[v] == color[idx]) {
			return false;
		}
	}
	return true;
} // ∑µªÿ «∑ÒŒﬁ≥ÂÕª

bool isBiPart(vector<vector<int>>& g) {
	int n = g.size();
	vector<int> color(n, -1);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1 && !dfs(g,color,i,0)) {
			return false;
		}
	}
	return true;
}