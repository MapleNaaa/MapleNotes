//#pragma once
//#include<iostream>
//using namespace std;
//
//class SortClass
//{
//	static void _swap(int* arr, int i, int j) {
//		int tmp = arr[i];
//		arr[i] = arr[j];
//		arr[j] = tmp;
//	}
//
//
//	static void insertSort(int* arr, int len) {
//		for (int i = 1; i < len; i++) {
//			for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
//				_swap(arr, j, j + 1);
//		}
//	}
//
//		int* help = new int[right - left + 1];
//	int ptr1 = left;
//	int ptr2 = mid + 1;
//	int idx = 0;
//	
//	while(ptr1 <= mid && ptr2 <= right){
//		help[i++] = arr[ptr1] < arr[ptr2] ? arr[ptr1++] : arr[ptr2++];
//	}
//
//	while(ptr1 <= mid) help[i++] = arr[ptr1++];
//	while(ptr2 <= right) help[i++] = arr[ptr2++];
//
//	for(int i = 0; i < right - left + 1 ;i++) arr[left + i] = help[i];
//
//	delete[] help;
//
//	static pair<int, int> partition(int* arr, int left, int right) {
//		int ptr = left;
//		int less = left - 1;
//		int tar = arr[right];
//		int more = right;
//
//		while (ptr < more) {
//			if (arr[ptr] < tar) {
//				_swap(arr, ++less, ptr++);
//			}
//			else if (arr[ptr] == tar) {
//				ptr++;
//			}
//			else if (arr[ptr] > tar) {
//				_swap(arr, --more, ptr);
//			}
//		}
//		_swap(arr, more, right);
//		// 此时 more代表 =区 的右边界， less + 1 代表 =区 的左边界
//		return { less, more + 1 };
//	}
//};
//
