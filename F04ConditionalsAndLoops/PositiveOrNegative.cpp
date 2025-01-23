/*
Title: Positive or Negative

Problem statement
You are given an integer n. If the number is less than zero then the print ‘Negative’ otherwise the print ‘Positive’.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
First line contains an integer n

Output Format:
Print "Negative" if n is less than zero otherwise print "Positive".

Constraints:
-10^9<=n<=10^9

Sample Input1:
3

Sample Output 1:
Positive

Sample Input2:
-100

Sample Output 2:
Negative
*/

#include<iostream>
using namespace std;

int main() {
    long num;
    cin >> num;

    if(num < 0) {
        cout << "Negative" << endl;
    } else {
        cout << "Positive" << endl;
    }

    return 0;
}