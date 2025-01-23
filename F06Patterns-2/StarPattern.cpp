/*
Title: Star Pattern

Problem statement
Print the following pattern

Pattern for N = 4
   *
  ***
 *****
*******

Hint
As taught in the video, you just have to modify the code so that instead of printing numbers, it should output stars ('*').
The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
N (Total no. of rows)

Output Format :
Pattern in N lines

Constraints :
0 <= N <= 50

Sample Input 1 :
3

Sample Output 1 :
   *
  *** 
 *****

Sample Input 2 :
4

Sample Output 2 :
   *
  *** 
 *****
*******
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n-1-row; col++) {
            cout << " ";
        }

        for(int col = 0; col < row*2+1; col++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}