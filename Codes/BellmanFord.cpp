#include<iostream>
#include<vector>
using namespace std;

struct Edge {
	int a, b, w;
	Edge(int a, int b, int w) :a(a), b(b), w(w) {};
};

vector<int> bellmanFord(int n, int k, vector<Edge> edges) {
	vector<int> dis(n + 1, INT_MAX / 2);
	dis[k] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < edges.size();j++) {
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			if (dis[b] > dis[a] + w) {
				dis[b] = dis[a] + w;
			}
		}
	}
	return dis;
}