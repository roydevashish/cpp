/*
Title: Print 2D Array

Problem statement
Given a 2D integer array with n rows and m columns. Print the 0th row from input n times, 1st row 
n-1 times…..(n-1)th row will be printed 1 time.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : No of rows (n) and no of columns (m) (separated by single space)
Line 2 : Row 1 elements (separated by space)
Line 3 : Row 2 elements (separated by space)
Line 4 : and so on

Sample Input 1:
3 3
1 2 3
4 5 6
7 8 9

Sample Output 1 :
1 2 3
1 2 3
1 2 3
4 5 6
4 5 6
7 8 9
*/

#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int input_array[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> input_array[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n - i; k++) {
            for(int j = 0; j < m; j++) {
                cout << input_array[i][j] << " "; 
            }
            cout << endl;
        }
    }

    return 0;
}