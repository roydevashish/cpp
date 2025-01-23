/*
Title: Largest Row or Column

Problem statement
You are given a 2D list (array) with dimensions N rows and M columns, filled with integers. Your 
task is to find the row or column that has the largest sum of its elements.

Important Rules:
- If two or more rows/columns have the same sum, choose the one that comes first.
- If a row and a column have the same largest sum, choose the row.
Goal: Return which row or column has the largest sum.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains two integer values, 'N' and 'M', separated by a single 
space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.
Second line onwards, the next 'N' lines or rows represent the ith row values.
Each of the ith row constitutes 'M' column values separated by a single space.

Output Format :
For each test case, If row sum is maximum, then print: "row" <row_index> <row_sum>
OR
If column sum is maximum, then print: "column" <col_index> <col_sum>
It will be printed in a single line separated by a single space between each piece of information.
Output for every test case will be printed in a seperate line.

Consider :
If there doesn't exist a sum at all then print "row 0 -2147483648", where -2147483648 or -2^31 is the 
smallest value for the range of Integer.

Constraints:
1 <= t <= 10^2
1 <= N <= 10^3
1 <= M <= 10^3

Time Limit: 1sec

Sample Input 1:
1
3 2
6 9 
8 5 
9 2 

Sample Output 1:
column 0 23

Sample Input 2:
1
4 4
6 9 8 5 
9 2 4 1 
8 3 9 3 
8 7 8 6 

Sample Output 2:
column 0 31
*/

#include<iostream>
using namespace std;

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

        // FindLargest(input_array, n, m);

        int sum_row_max = INT_MIN;
        int sum_row_max_idx = 0;
        for(int i = 0; i < n; i++) {
            int sum_row = 0;
            for(int j = 0; j < m; j++) {
                sum_row += input_array[i][j];
            }

            if(sum_row > sum_row_max) {
                sum_row_max = sum_row;
                sum_row_max_idx = i;
            }
        }

        int sum_col_max = INT_MIN;
        int sum_col_max_idx = 0;
        for(int i = 0; i < m; i++) {
            int sum_col = 0;
            for(int j = 0; j < n; j++) {
                sum_col += input_array[j][i];
            }

            if(sum_col > sum_col_max) {
                sum_col_max = sum_col;
                sum_col_max_idx = i;
            }
        }

        if(sum_row_max >= sum_col_max) {
            cout << "row " << sum_row_max_idx << " " << sum_row_max << endl;
        } else {
            cout << "column " << sum_col_max_idx << " " << sum_col_max << endl;
        }
    }

    return 0;
}