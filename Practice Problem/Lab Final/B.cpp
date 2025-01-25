//13
//13
//13
//13
//13
//13
//13
//13
#include <bits/stdc++.h>
using namespace std;

struct Student {
    int id;
    int marks;
};

// Function to merge two sorted arrays
void merge(Student arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    Student L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].marks <= R[j].marks) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// sort
void mergeSort(Student arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int n;
    cin >> n;

    // Use an array of Student structs to store students with marks as the key
    Student students[n];
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].marks;
    }

    // Merge sort
    mergeSort(students, 0, n - 1);

    // Print the sorted student IDs
    for (int i = 0; i < n; i++) {
        cout << students[i].id << endl;
    }

    return 0;
}

 
