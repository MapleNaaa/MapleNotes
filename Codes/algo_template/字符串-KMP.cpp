//#include<bits/stdc++.h>
//using namespace std;
//
//vector<int> nextArray(string& p) {
//	int n = p.length();
//	vector<int> next(n, 0);
//	next[0] = -1;
//
//	int i = 2, cn = 0;
//	while (i < n) {
//		if (p[i - 1] == p[cn]) next[i++] = ++cn;
//		else if (cn > 0) cn = next[cn];
//		else next[i++] = 0;
//	}
//}
//
//int kmp(string& s, string& p) {
//	int n = s.length(), m = p.length();
//	int a = 0, b = 0;
//	vector<int> next = nextArray(p);
//
//	while (a < n && b < m) {
//		if (s[a] == p[b]) {
//			a++;
//			b++;
//		}
//		else if (b == 0)  a++;
//		else b = next[b];
//	}
//	return b == m ? a - b : -1;
//}