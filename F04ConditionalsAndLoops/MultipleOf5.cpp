/*
Title: Multiple of 5

Problem statement
Given a number, print " Multiple of 5" if the number is a multiple of 5, otherwise print "Not a Multiple of 5"

for N = 5
"Multiple of 5" 

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N (Total no. of rows)

Output format :
"Multiple of 5 " or " Not a Multiple of 5" 

Constraints:
0 <= N <= 50

Sample Input 1:
7

Sample Output 1:
Not a Multiple of 5

Sample Input 2:
10

Sample Output 2:
Multiple of 5
*/

#include<iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    if(num % 5 == 0) {
        cout << "Multiple of 5" << endl;
    } else {
        cout << "Not a multiple of 5" << endl;
    }

    return 0;
}