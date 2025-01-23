/*
Title: Game of Pattern

Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 3
###
###
###

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
Integer N (Total no. of rows)

Output Format:
Pattern in N lines

Constraints:
0 <= N <= 50

Sample Input1:
5

Sample Output 1:
#####
#####
#####
#####
#####

Sample Input 2:
4

Sample Output 2:
####
####
####
####
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            cout << "#";
        }
        cout << endl;
    }
    return 0;
}