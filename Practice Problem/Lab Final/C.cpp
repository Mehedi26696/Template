//13
//13
//13


// You will be given a list of integers in sorted order and a list of queries. You have to find
// the number of integers in the list less than or equal to the query. You may assume that
// the query exists in the list of integers.
// Input:
// First line: n, a number. (1<=n<=10^6)
// Next n lines: an integer v (-2147483648<=v <=2147483647), the numbers in the list
// Next line: m, a number (1<=m<=10^5), the number of keys.
// Next m lines: an integer q (-2147483648<= q <=2147483647), the queries.
// Output:
// m lines, each containing the number of integers in the list less than or equal to the
// query.
// Sample Case:
// Input Output
// 71112234223
// 56
#include <bits/stdc++.h>
 
using namespace std;

// Function to perform binary search
int countLessThanOrEqual(int arr[], int n, int key) {
    int left = 0, right = n - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= key) {
            result = mid;  // Update result
            left = mid + 1;  // Move to the right to find the last occurrence
        } else {
            right = mid - 1;  // Move to the left
        }
    }

    return result + 1;  // Return count of elements less than or equal to the key
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];

    // Read the sorted list of integers
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    // Process each query
    int res[m];
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

        // Output the result for the query
        res[i] = countLessThanOrEqual(arr, n, q);
    }

    for (int i = 0; i < m; i++) {
        cout << res[i] << endl;
    }

    return 0;
}
