/*
Title: Sum Pattern

Problem statement
Write a program to print triangle of user defined integers sum.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
A single integer, N

Output Format :
Required Pattern

Constraints :
0 <= N <= 50

Sample Input 1 :
3

Sample Output 1 :
1=1
1+2=3
1+2+3=6

Sample Input 2 :
5

Sample Output 2 :
1=1
1+2=3
1+2+3=6
1+2+3+4=10
1+2+3+4+5=15
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int sum = 0;

        for(int j = 1; j <= i; j++) {
            cout << j;
            sum += j;

            if(i == j) {
                cout << "=" << sum;
            } else {
                cout << "+";
            }
        }

        cout << endl;
    }

    return 0;
}