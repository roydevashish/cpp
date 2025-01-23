/*
Title: Binary to Decimal

Problem statement
Given a binary number as an integer N, convert it into decimal and print.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
An integer N in the Binary Format

Output format :
Corresponding Decimal number (as integer)

Constraints :
0 <= N <= 10^9

Sample Input 1 :
1100

Sample Output 1 :
12

Sample Input 2 :
111

Sample Output 2 :
7
*/

#include<iostream>
using namespace std;

int main() {
    int binary;
    cin >> binary;

    int power = 0;
    int decimal = 0;
    while(binary > 0) {
        int bit = binary % 10;
        if(bit != 0) {
            int power_of_2 = 1;
            for(int i = 0; i < power; i++) {
                power_of_2 *= 2;
            }
            decimal += power_of_2;
        }

        power++;
        binary = binary / 10;
    }

    cout << decimal << endl;
    return 0;
}