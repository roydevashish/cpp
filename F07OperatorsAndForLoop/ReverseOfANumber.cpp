/*
Title: Reverse of a Number

Problem statement
Write a program to generate the reverse of a given number N. Print the corresponding reverse number.

Note : If a number has trailing zeros, then its reverse will not include them. For e.g., reverse of 
10400 will be 401 instead of 00401.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N

Output format :
Corresponding reverse number

Constraints:
0 <= N < 10^8

Sample Input 1 :
1234

Sample Output 1 :
4321

Sample Input 2 :
1980

Sample Output 2 :
891
*/

#include<iostream>
using namespace std;

int main() {
    int num;
    cin >> num;


    int reverse_num = 0;
    while(num > 0) {
        int remainder = num % 10;
        reverse_num = reverse_num * 10 + remainder;

        num = num / 10;


    }
    cout << reverse_num << endl;
    return 0;
}