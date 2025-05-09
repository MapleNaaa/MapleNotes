#include<bits/stdc++.h>
using namespace std;
// �yԇ朽� : https://leetcode.cn/problems/kth-largest-element-in-an-array/
int first, last;

int findKthLargest(vector<int>& nums, int k) {
	return randomizedSelect(nums, nums.size() - k);
}

int randomizedSelect(vector<int>& arr, int i) {
	int ans = 0;
	int l = 0, r = arr.size() - 1;
	while (l <= r) {
		partition(arr, l, r, arr[l + (rand() % (r - l + 1))]);

		if (i < first)
			r = first - 1;
		else if (i > last)
			l = last + 1;
		else {
			ans = arr[i];
			break;
		}
	}
	return ans;
}

void partition(vector<int>& arr, int l, int r,int val) {
	int less = l - 1;
	int more = r + 1;
	int ptr = l;

	while (ptr < more) {
		if (arr[ptr] == val) {
			ptr++;
		} else if (arr[ptr] < val) {
			swap(arr, ptr++, ++less);
		} else {
			swap(arr, ptr, --more);
		}
	}
	first = less + 1;
	last = more - 1;
}

void swap(vector<int>& arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
