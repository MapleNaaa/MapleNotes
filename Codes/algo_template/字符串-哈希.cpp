//#include<bits/stdc++.h>
//using namespace std;
//#define ULL unsigned long long
//
//const ULL P = 13331;
//const int N = 1e6 + 10;
//ULL preh[N], p[N];
//
//void initHash(string& s) {
//    p[0] = 1;
//    preh[0] = 0;
//    for (int i = 1; i <= s.length(); i++) {
//        p[i] = p[i - 1] * P;
//        preh[i] = preh[i - 1] * P + s[i];
//    }
//}
//
//ULL getHash(int l, int r) {
//    return preh[r] - preh[l - 1] * p[r - l + 1];
//}