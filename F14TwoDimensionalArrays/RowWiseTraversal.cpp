/*
Title: Row Wise Traversal

Problem statement
Given a matrix, ‘A’ of size ‘N’ * ‘M’, you must traverse the matrix row-wise.

You must return an integer array of size ‘N’ * ‘M’ denoting the row-wise traversal of the matrix.

Constraints :
1 <= T <= 10
1 <= N * M <= 10^5
1 <= A[ i ][ j ] <= 10^9
Time Limit: 1 sec


For example:

Input :
A = [ [1, 2, 3], [4, 5, 6] ]

Output :
1 2 3 4 5 6

Explanation: 

For the given matrix, the first row is [1, 2, 3], and the second is [4, 5, 6].
For row-wise traversal, you must traverse the first row and then the second.
Constraints :
1 <= T <= 10
1 <= N * M <= 10^5
1 <= A[ i ][ j ] <= 10^9
Time Limit: 1 sec


For example:

Input :
A = [ [1, 2, 3], [4, 5, 6] ]

Output :
1 2 3 4 5 6

Explanation: 

For the given matrix, the first row is [1, 2, 3], and the second is [4, 5, 6].
For row-wise traversal, you must traverse the first row and then the second.
Input Format:
First-line contains 'T,' denoting the number of Test cases.
For each Test case:
The first line contains two integers, ‘N' and ‘M’.
The following ‘N’ lines have ‘M’ integers each, denoting the matrix ‘A’.
Output Format:-
You must return the array with elements in order of row-wise traversal.
Note:-
You don’t need to print anything. Just implement the given function.
Sample Input 1 :
2
2 2 
4 3
2 1
1 5
1 2 3 4 5
Sample Output 1 :
4 3 2 1
1 2 3 4 5 
Explanation Of Sample Input 1 :
For test case one:
Input :
A = [ [4, 3], [2, 1] ]
Output :
4 3 2 1
Explanation: For the given matrix, the first row is [4, 3], and the second is [2, 1].
For row-wise traversal, you must traverse the first row and then the second.

For test case two:
Input :
A = [ [1, 2, 3, 4, 5] ]
Output :
1 2 3 4 5
Explanation: For the given matrix, the first row is [1, 2, 3, 4, 5].
For row-wise traversal, you need to traverse the first row.
Sample Input 2 :
2
1 1 
4
5 1
1 
2 
3 
4 
5
Sample Output 2 :
4
1 2 3 4 5
*/

#include<iostream>
using namespace std;

// void PrintRowWise(int input_array[], int row, int col) {
    
// }

int main() {
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

        // PrintRowWise(input_array, n, m);

        int k = 0;
        int output_array[n * m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                output_array[k++] = input_array[i][j];
            }
        }

        for(int i = 0; i < n * m; i++) {
            cout << output_array[i] << " ";
        }
        cout << endl;
    }
    return 0;
}