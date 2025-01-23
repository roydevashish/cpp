/*
Title: Second Largest in Array

Problem statement
You have been given a random integer array/list(ARR) of size N. You are required to find and return 
the second largest element present in the array/list.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an integer 'N' representing the size of the array/list.
The second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
Return the second largest element in the array/list.

Constraints :
0 <= N <= 10^2
1<=arr[i]<=10^3

Time Limit: 1 sec

Sample Input 1:
5
4 3 10 9 2

Sample Output 1:
9

Sample Input 2:
7
13 6 31 14 29 44 3

Sample Output 2:
31
*/

#include<iostream>
using namespace std;

int FindSecondLargest(int array[], int size) {
    int largest_1 = INT_MIN;
    int largest_2 = INT_MIN;

    for(int i = 0; i < size; i++) {
        if(array[i] >= largest_1) {
            largest_2 = largest_1;
            largest_1 = array[i];
        } else if(array[i] >= largest_2) {
            largest_2 = array[i];
        }
    }

    return largest_2;
}

int main() {
    int size;
    cin >> size;

    int array[size];
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << FindSecondLargest(array, size) << endl;
    return 0;
}