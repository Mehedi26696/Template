
#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

// recursive binary search

int binarySearchRecursive(int arr[], int start, int end, int key) {
    if (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, end, key);
        } else {
            return binarySearchRecursive(arr, start, mid - 1, key);
        }
    }
    return -1;
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int result = binarySearch(arr, n, key);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }

    int result2 = binarySearchRecursive(arr, 0, n - 1, key);
    if (result2 == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << result2 << endl;
    }
    return 0;
}