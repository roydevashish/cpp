/*
Title: Query and Matrix

Problem statement
You are given a binary matrix with ‘M’ rows and ‘N’ columns initially consisting of all 0s. 'Q' 
queries follow. The queries can be of 4 types:

Query 1: 1 R index
Query 2: 1 C index 
Query 3: 2 R index
Query 4: 2 C index

In each query, the first input is the type of the query, the second input is whether we have to 
consider the row ('R') or the column ('C') and the third input is the index of the row/column. 

For each type 1 query, we need to flip the elements of the row/column having the given index. 
For each type 2 query, we have to output the number of zeros present in the row/column having the given index. 

Note:
Note that the matrix is a binary matrix, meaning that it only contains either 0 or 1.

Example :
Given M = 3, N = 3, 
Queries : 1R1, 1R2, 2C1

So, in the above example the change in the matrix would look like this:
0 0 0       0 0 0       0 0 0
0 0 0       1 1 1       1 1 1
0 0 0       0 0 0       1 1 1
Next query 2C1 will return the count of the number of zeroes in the 1st column: 1

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line contains an integer ‘T’ which denotes the number of test cases.
The first line of each test case contains two space-separated integers ‘M’ and ‘N’, denoting the 
dimensions of the matrix.
The next line contains a single integer ‘Q’ denoting the number of queries.
The next ‘Q’ lines of each test contain the queries.

Output Format:
For each test case, return a single integer denoting the number of zeroes according to the given query of type 2.
Print the output of each test case in a separate line.

Note:
You don’t need to print anything; It has already been taken care of. Juts implement the given function.

Constraints:
1 <= T <= 10
1 <= M, N  <= 100
1 <= Q <= 1000
1 <= R <= M
1 <= C <= N
type = 1, 2

Time limit: 1 sec

Sample Input 1:
2
3 3
3
1R1
1R2
2C1
2 2
1
2R1

Sample Output 1:
1
2

Explanation of Sample Output 1:
In test case 1, Next query 2C1 will return the count of the number of zeroes in the 1st column: 1

The change in the matrix after the first and second queries would look like this:
0 0 0       0 0 0       0 0 0
0 0 0       1 1 1       1 1 1
0 0 0       0 0 0       1 1 1

In test case 2, all the matrix elements are zero and hence the count of zeroes will be 2 for the first row.

Sample Input 2:
2
3 3
4
2C1
1R1
1R1
2R1
2 2
5
2C1
1R1
1R1
1R1
2R1

Sample Output 2:
3 3
2 0

Explanation of Sample Output 2:
In test case 1, 
First query 2C1 will return the count of the number of zeroes in the 1st column: 3
Next query 2R1 will return the count of the number of zeroes in the 1st column: 3
The change in the matrix after the second and third queries would look like this:
0 0 0       0 0 0       0 0 0
0 0 0       1 1 1       0 0 0
0 0 0       0 0 0       0 0 0

In test case 2,
First query 2C1 will return the count of the number of zeroes in the 1st column: 2
Next query 2R1 will return the count of the number of zeroes in the 1st column: 0
The change in the matrix after the second and third queries would look like this:
0 0       0 0       0 0       0 0
0 0       1 1       0 0       1 1
*/

#include<iostream>
#include<string.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int m, n, q;
        cin >> m >> n;

        int matrix[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
            cout << endl;
        }

        cin >> q;
        for(int query = 0; query < q; query++) {
            string input_query;
            cin >> input_query;

            int query_type = input_query[0] - 48;
            char query_x = input_query[1];
            int query_index = input_query[2] - 48;


            if(query_type == 1) {
                if(query_x == 'R') {
                    for(int col = 0; col < n; col++) {
                        if(matrix[query_index][col] == 0) {
                            matrix[query_index][col] = 1;
                        } else {
                            matrix[query_index][col] = 0;
                        }
                    }
                } else if(query_x == 'C') {
                    for(int row = 0; row < m; row++) {
                        if(matrix[row][query_index] == 0) {
                            matrix[row][query_index] = 1;
                        } else {
                            matrix[row][query_index] = 0;
                        }
                    }
                }
            } else if(query_type == 2) {
                if(query_x == 'R') {
                    int count = 0;
                    for(int col = 0; col < n; col++) {
                        if(matrix[query_index][col] == 0) {
                            count++;
                        }
                    }
                    cout << count << " ";
                } else if(query_x == 'C') {
                    int count = 0;
                    for(int row = 0; row < m; row++) {
                        if(matrix[row][query_index] == 0) {
                            count++;
                        }
                    }
                    cout << count << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}