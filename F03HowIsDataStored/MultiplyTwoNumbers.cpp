/*
Title: Multiply Two Numbers

Problem statement
Write a code which takes two integers "F1" and "F2" as inputs and print their product .

Detailed explanation ( Input/output format, Notes, Images )
Input Format
The first and only line contains two two integers, ‘F1’, and 'F2',

Output format:
Print the product of these numbers.

Constraints:
1<= F1, F2 <= 100000

Time Limit: 1-sec

Sample Input 1:
6789  6789

Sample Output 1:
46090521

Sample Input 2:
123456 123456

Sample Output 2:
15241383936
*/

#include<iostream>
using namespace std;

int main() {
    int f1, f2;

    cin >> f1 >> f2;

    long product = (long) f1 * f2;

    cout << product << endl;

    return 0;
}