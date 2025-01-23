/*
Title: Insertion Sort

Problem statement
You are given an integer array 'arr' of size 'N'.

Note:
Change in the input array itself. You don't need to return or print the elements.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an integer 'N' representing the size of the array.
The second line contains 'N' single space-separated integers representing the elements of the array.

Output Format :
Print the array elements in sorted order, separated by a single space.

Constraints :
0 <= N <= 10^3
0 <= arr[i] <= 10^5

Time Limit: 1 sec

Sample Input 1:
5
9 3 6 2 0

Sample Output 1:
0 2 3 6 9

Sample Input 2:
4
4 3 2 1

Sample Output 2:
1 2 3 4
*/

#include<iostream>
using namespace std;

void InsertionSort(int array[], int size) {
    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(array[j] < array[j-1]) {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cin >> size;

    int array[size];
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }

    InsertionSort(array, size);

    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}