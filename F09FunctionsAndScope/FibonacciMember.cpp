/*
Title: Fibonacci Member

Problem statement
Create a function that determines whether a given number N belongs to the Fibonacci sequence. 
If N is found in the Fibonacci sequence, the function should return true; otherwise, it should 
return false.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Integer N

Output Format :
true or false

Constraints :
0 <= n <= 10^4

Sample Input 1 :
5

Sample Output 1 :
true

Explanation :
Fibonacci sequence begins 0, 1, 1, 2, 3, 5, ... and so on. Since 5 appears in the sequence.

Sample Input 2 :
14

Sample Output 2 :
false
*/

#include<iostream>
using namespace std;

bool CheckFibonacciMember(int n) {
    int n1 = 1;
    int n2 = 1;

    while(n >= n2) {
        if(n2 == n) {
            return true;
        }
        
        int sum = n1 + n2;
        n1 = n2;
        n2 = sum;

    }

    return false;

}

int main() {
    int n;
    cin >> n;

    if(CheckFibonacciMember(n)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}