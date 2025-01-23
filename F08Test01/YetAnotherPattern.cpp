/*
Title: Yet Another Pattern

Problem statement
Ninja was playing with her sister to solve a puzzle pattern. However, even after taking several 
hours, they could not solve the problem.

A value of N is given to them, and they are asked to solve the problem. Since they are stuck for 
a while, they ask you to solve the problem. Can you help solve this problem?

Example : Pattern for N = 4
****
 ***     
  **
   *

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer ‘T,’ denoting the number of test cases. The test cases 
follow.
The first line of each test case contains a single integer ‘N’.

Output Format:
For each test case, print 'N' strings corresponding to every row in a new line (row elements not 
separated by space)
Print the output of each test case in a separate line.

Note (C++ ,Python):
You are not required to print the expected output; it has already been taken care of. Just implement 
the function.

Constraints:
1 <= T <= 50
1 <= N <= 300

Time Limit: 1 sec

Sample Input 1:
2
3
2

Sample Output 1:
***
 **     
  *

**
 *     

Explanation for Sample Input 1:
In the first test case, the value of ‘N’ is 3, so three rows are to be printed from 1 to 3 where each 
row starts from 3, which goes on till 1. Hence the answer is [“***”,”**”,”*”].

In the second test case, the value of ‘N’ is 2, so the two rows are to be printed from 1 to 3 where 
each row starts from 3, which goes on till 1. Hence the answer is [“**”,”*”].

Sample Input 2:
2
4
5

Sample Output 2:
****
 ***     
  **
   *

*****
 ****     
  ***
   **
    *
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int input[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for(int i = 0; i < n; i++) {
        
        for(int row = 0; row < input[i]; row++) {
            for(int col = 0; col < row; col++) {
                cout << " ";
            }

            for(int col = row; col < input[i]; col++) {
                cout << "*";
            }

            cout << endl;
        }
        cout << endl;
    }

    return 0;
}