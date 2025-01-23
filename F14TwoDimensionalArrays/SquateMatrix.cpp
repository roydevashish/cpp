/*
Title: Square Matrix

Problem statement
You are given a 2D array of integers ‘A’ of length ’N’x’M’, where ‘N’ is the number of rows and ‘M’ 
is the number of columns. Check if the given array forms a square matrix and returns its diagonal 
elements.

A Square matrix is one that has an equal number of rows and columns.

Example:
Input:
3 3
1 2 3
4 5 6 
7 8 9

Output: 
YES
1 5 9

Explanation:
The number of rows and columns is equal, so the given array forms a square matrix.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of the input contains an integer 'T’, Denoting the number of test cases.
The first line of each test case contains two integers ‘N’ and ‘M’ separated by space.
The next ’N’ lines in each test contain ‘M’ integers separated by space.

Output format:
Return a pair of strings and an array, If the matrix is a square matrix, return ‘YES’with the array 
containing the diagonal elements, else return ‘NO’ with an empty array.

Constraints :
1  <= T <= 10
1  <= N,M <= 50
1 <= A[i] <= 1000

Time Limit: 1 sec

Sample Input 1:
2
3 3
1 2 3
4 5 6
7 8 9
2 3
1 3 2 
4 5 5

Sample Output 1:
YES
1 5 9
NO

Explanation Of Sample Input 1 :
Test 1:
The number of rows and columns is equal, so the given array forms a square matrix.

Test 2:
The number of rows and columns is not equal, so the given array doesn’t form a square matrix.

Sample Input 2 :
2
2 2
1 2
2 1
1 1
3

Sample Output 2 :
YES
1 1
YES
3
*/

#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int n, m;
        cin >> n >> m;

        int input_array[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> input_array[i][j];
            }
        }

        // SquareMatrix(input_array, n, m);

        if(n == m) {
            cout << "YES" << endl;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(i == j) {
                        cout << input_array[i][j] << " ";
                    }
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}