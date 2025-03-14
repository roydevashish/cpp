/*
Title: x to the power n

Problem statement
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Two integers x and n (separated by space)

Output Format :
x^n (i.e. x raise to the power n)

Constraints :
0 <= x <= 30
0 <= n <= 30

Sample Input 1 :
3 4

Sample Output 1 :
81

Sample Input 2 :
2 5

Sample Output 2 :
32
*/

#include<iostream>
using namespace std;

int Power(int x, int n) {
    if(n == 0) {
        return 1;
    }

    return x * Power(x, n-1);
}

int main() {
    int x, n;
    cin >> x >> n;
    cout << Power(x, n) << endl;
}