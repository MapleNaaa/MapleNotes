//#include<bits/stdc++.h>
//using namespace std;
//
//// g 为邻接表，ins 为入度
//vector<int> topoSort(int n, vector<vector<int>>& g, vector<int>& ins) {
//	queue<int> q;
//	vector<int> res;
//
//	for (int i = 0; i < ins.size();i++)
//		if (ins[i] == 0) q.push(i);
//
//	while (!q.empty()) {
//		int a = q.front();
//		res.push_back(a);
//		q.pop();
//
//		for (int b : g[a]) {
//			ins[b]--;
//			if (ins[b] == 0) {
//				q.push(b);
//			}
//		}
//	}
//
//	return res;
//}
