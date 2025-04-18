/*
Title: Decimal to Binary

Problem statement
Given a decimal number (integer N), convert it into binary and print.

Note for C++ coders:
Do not use the inbuilt implementation of "pow" function. The implementation of that function is done 
for 'double's and it may fail when used for 'int's, 'long's, or 'long long's. Implement your own "pow" 
function to work for non-float data types. 
The given input number could be large, so the corresponding binary number can exceed the integer range. 
So you may want to take the answer as long for CPP and Java. 

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N

Output format :
Corresponding Binary number (long)

Constraints :
0 <= N <= 10^5

Sample Input 1 :
12

Sample Output 1 :
1100

Sample Input 2 :
7

Sample Output 2 :
111

Sample Input 2 :
0

Sample Output 2 :
0
*/

#include<iostream>
using namespace std;

int main() {
    int decimal;
    cin >> decimal;

    long binary = 0;
    int index = 0;
    while(decimal > 0) {
        int bit = decimal % 2;
        if(bit != 0) {
            int power_of_10 = 1;
            for(int i = 0; i < index; i++) {
                power_of_10 *= 10;
            }

            binary += power_of_10;
        }


        index++;
        decimal /= 2;
    }
    cout << binary << endl;
    return 0;
}