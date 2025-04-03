//#include <iostream>
//#include <algorithm>
//#include <random>
//#include <ctime>
//
//using namespace std;
//
//
//int getMaxBytes(int* arr, int len) {
//    int Max = INT_MIN;
//    for (int i = 0; i < len;i++) {
//        if (Max < arr[i]) Max = arr[i];
//    }
//    int bit = 1;
//    while (Max >>= 1) {
//        bit += 1;
//    }
//    return bit;
//}
//
//void bucketSort(int* arr, int len) {
//    int** buckets = new int* [2];
//    buckets[0] = new int[len];
//    buckets[1] = new int[len];
//
//    int maxbit = getMaxBytes(arr, len);
//    int div = 1;
//    for (int b = 0; b < maxbit;b++) {
//        int ptr0 = 0, ptr1 = 0;
//        for (int i = 0; i < len; i++) {
//            if ((arr[i] & div) == 0) {
//                buckets[0][ptr0++] = arr[i];
//            }
//            else {
//                buckets[1][ptr1++] = arr[i];
//            }
//        }
//        for (int i = 0; i < ptr0;i++) {
//            arr[i] = buckets[0][i];
//        }
//        for (int i = 0; i < ptr1;i++) {
//            arr[i + ptr0] = buckets[1][i];
//        }
//        div *= 2;
//    }
//    delete[] buckets[0];
//    delete[] buckets[1];
//    delete[] buckets;
//}
//
//// ����������飨��������ָ�룬��ͨ�����÷������鳤�ȣ�
//int* generateRandomArray(int maxSize, int maxValue, int& outSize) {
//    static default_random_engine e(time(0));
//    uniform_int_distribution<int> sizeRand(0, maxSize);
//    uniform_int_distribution<int> valueRand(0, maxValue);
//
//    outSize = sizeRand(e);
//    int* arr = new int[outSize];
//    for (int i = 0; i < outSize; ++i) {
//        arr[i] = valueRand(e);
//    }
//    return arr;
//}
//
//// ��ȷ�㷨��ʾ������׼������
//void correctMethod(int* arr, int size) {
//    sort(arr, arr + size);
//}
//
//// �������㷨��ʾ������ʵ�֣��滻Ϊ����㷨��
//void myMethod(int* arr, int size) {
//    // ʵ������㷨...
//    bucketSort(arr, size);
//}
//
//// �����֤��
//bool isEqual(int* a, int aSize, int* b, int bSize) {
//    if (aSize != bSize) return false;
//    for (int i = 0; i < aSize; ++i) {
//        if (a[i] != b[i]) return false;
//    }
//    return true;
//}
//
//// ��ӡ����
//void printArray(int* arr, int size) {
//    for (int i = 0; i < size; ++i) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    // ���Բ�������
//    const int TEST_TIMES = 10000;
//    const int MAX_SIZE = 1000;
//    const int MAX_VALUE = 10000;
//
//    for (int i = 0; i < TEST_TIMES; ++i) {
//        int size;
//        int* originalArr = generateRandomArray(MAX_SIZE, MAX_VALUE, size);
//
//        // �������Ը���
//        int* arr1 = new int[size];
//        int* arr2 = new int[size];
//        copy(originalArr, originalArr + size, arr1);
//        copy(originalArr, originalArr + size, arr2);
//
//        // ִ���㷨
//        myMethod(arr1, size);
//        correctMethod(arr2, size);
//
//        // ��֤���
//        if (!isEqual(arr1, size, arr2, size)) {
//            cout << "Error Case:" << endl;
//            cout << "Original (" << size << " elements): ";
//            printArray(originalArr, size);
//            cout << "Your Result: ";
//            printArray(arr1, size);
//            cout << "Expected: ";
//            printArray(arr2, size);
//
//            // �ͷ��ڴ�
//            delete[] originalArr;
//            delete[] arr1;
//            delete[] arr2;
//            return 0;
//        }
//
//        // �ͷ��ڴ�
//        delete[] originalArr;
//        delete[] arr1;
//        delete[] arr2;
//    }
//
//    cout << "All " << TEST_TIMES << " test cases passed!" << endl;
//    return 0;
//}