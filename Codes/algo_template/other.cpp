#include<bits/stdc++.h>
using namespace std;

int main() {
	while (true) {
		string a;
		int b;
		cin >> a >> b;
		int r = 0;
		vector<int> c;
		for (int i = 0; i < a.size(); i++) {
			r = r * 10 + (a[i] - '0');
			c.push_back(r / b);
			r %= b;
		}
		reverse(c.begin(), c.end());
		while (c.size() > 1 && c.back() == 0) c.pop_back();
		reverse(c.begin(), c.end());

		for (int i = 0; i < c.size(); i++)
			cout << c[i];
		cout << "бнбн" << r << endl;
	}
	return 0;
}