/*
Title: Multiplication(Recursive)

Problem statement
Given two integers M & N, calculate and return their multiplication using recursion. You can only
use subtraction and addition for your calculation. No other operators are allowed.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Integer M
Line 2 : Integer N

Output format :
M x N

Constraints :
0 <= M <= 1000
0 <= N <= 1000

Sample Input 1 :
3
5

Sample Output 1 :
15

Sample Input 2 :
4
0

Sample Output 2 :
0
*/

#include<iostream>
using namespace std;

int MultiplyNumbers(int m, int n) {
    if(n == 0) {
        return 0;
    }

    return MultiplyNumbers(m, n-1) + m;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << MultiplyNumbers(m, n) << endl;
}