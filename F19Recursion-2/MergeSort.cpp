/*
Title: Merge Sort

Problem statement
You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.
You must sort the elements between 'l' and 'r'.

Note:
Change in the input array itself. So no need to return or print anything.
Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an integer <em>**'N'**</em> representing the size of the array/list.
The second line contains 'N' single space-separated integers representing the elements in
the array/list.

Output format :
You don't need to return anything. In the output, you will see the array after you do the
modification.

Sample Input 1:
7
2 13 4 1 3 6 28

Sample Output 1:
1 2 3 4 6 13 28

Explanation of Sample Output 1:
After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].

Sample Input 2:
5
9 3 6 2 0

Sample Output 2:
0 2 3 6 9

Explanation of Sample Output 2:
After applying 'merge sort' on the input array, the output is [0 2 3 6 9].

Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
*/

#include <iostream>
using namespace std;

void Merge(int array[], int l, int mid, int r) {
    int left_size = (mid - l) + 1;
    int right_size = (r - mid);

    int array_left[left_size];
    int array_right[right_size];

    for (int i = 0; i < left_size; i++) {
        array_left[i] = array[l + i];
    }

    for (int i = 0; i < right_size; i++) {
        array_right[i] = array[mid + 1 + i];
    }

    int idx_left = 0;
    int idx_right = 0;
    int idx_array = l;

    while (idx_left < left_size && idx_right < right_size) {
        if (array_left[idx_left] <= array_right[idx_right]) {
            array[idx_array++] = array_left[idx_left++];
        } else {
            array[idx_array++] = array_right[idx_right++];
        }
    }

    while (idx_left < left_size) {
        array[idx_array++] = array_left[idx_left++];
    }

    while (idx_right < right_size) {
        array[idx_array++] = array_right[idx_right++];
    }
}

void MergeSort(int array[], int l, int r) {
    if (r - l < 1) {
        return;
    }

    int mid = (l + r) / 2;
    MergeSort(array, l, mid);
    MergeSort(array, mid + 1, r);
    Merge(array, l, mid, r);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSort(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}