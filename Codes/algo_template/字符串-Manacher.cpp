//#include <bits/stdc++.h>
//using namespace std;
//
//string manacher(string s) {
//	string t = "#";
//	for (char ch : s) t += (ch + '#');
//
//	int n = t.length();
//	vector<int> p(n,0);
//
//	for (int i = 0, c = 0, r = 0; i < n; i++) {
//		int len = (r > i) ? min(p[2 * c - i], r - i) : 1;
//
//		while (i - len >= 0 && i + len < n && t[i - len] == t[i + len]) len++;
//
//		if (i + len > r) {
//			c = i;
//			r = i + len;
//		}
//		p[i] = len;
//	}
//
//	int len = 0, center = 0;
//	for (int i = 0; i < n; i++) {
//		if (p[i] > len) {
//			len = p[i];
//			center = i;
//		}
//	}
//	int start = (center - len + 1) / 2;
//	len -= 1;
//	return s.substr(start, len);
//}