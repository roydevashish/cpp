/*
Title: Sum of Digits(Recursive)

Problem statement
Write a recursive function that returns the sum of the digits of a given integer.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N

Output format :
Sum of digits of N

Constraints :
0 <= N <= 10^9

Sample Input 1 :
12345

Sample Output 1 :
15

Sample Input 2 :
9

Sample Output 2 :
9
*/

#include<iostream>
using namespace std;

int SumOfDigits(int n) {
    if(n == 0) {
        return 0;
    }

    return n % 10 + SumOfDigits(n / 10);
}

int main() {
   int n;
   cin >> n;
   cout << SumOfDigits(n) << endl;
}