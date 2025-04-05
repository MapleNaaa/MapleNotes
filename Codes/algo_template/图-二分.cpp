//#include <iostream>
//using namespace std;
//
//int bsearch(int val, int left, int right) {
//	int l = left, r = right;
//
//	while (l < r) {
//		int m = l + (r - l) / 2;
//		if (m == val) return m;
//		else if (m < val) l = m + 1;
//		else r = m;
//	}
//
//	return -1;
//}
//
//int main() {
//	while (true) {
//		int n;
//		cin >> n;
//		cout << bsearch(n, 0, INT_MAX) << endl;
//		cout << "----" << endl;
//	}
//	return 0;
//}