#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
vector<int> ins;
vector<int> outs;

void dfs(int u, int p,vector<vector<int>>& g) {
	ins[u] = ++cnt;
	for (int v : g[u]) {
		if (v != p) {
			dfs(v, u, g);
		}
	}
	outs[u] = cnt;
}

/*
int main() {
    // ʾ�����������ṹ���£�1Ϊ����
    //     1
    //    / \
    //   2   3
    //      /
    //     4
    const int n = 4; // �ڵ���
    ins.resize(n + 1, -1);
    outs.resize(n + 1, -1);
    vector<vector<int>> tree(n + 1); // �ڵ���1~n

    // �����ڽӱ�����ߣ�
    tree[1].push_back(2); // 1-2
    tree[2].push_back(1);
    tree[1].push_back(3); // 1-3
    tree[3].push_back(1);
    tree[3].push_back(4); // 3-4
    tree[4].push_back(3);

    vector<int> in(n + 1), out(n + 1); // �洢ʱ���
    int timestamp = 0; // ʱ�����ʼ��

    // �Ӹ��ڵ�1��ʼDFS������-1��ʾ�޸��ڵ�
    dfs(1, -1, tree);
    return 0;
}*/