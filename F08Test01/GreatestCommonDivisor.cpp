/*
Title: Greatest Common Divisor

Problem statement
You are given two numbers, ‘X’ and ‘Y’. Your task is to find the greatest common divisor of the 
given two numbers.
The Greatest Common Divisor of any two integers is the largest number that divides both integers.

For Example:
You are given ‘X’ as 20 and ‘Y’ as 15. The greatest common divisor, which divides both 15 and 20, 
is 5. Hence the answer is 5.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains ‘T’, representing the number of test cases. 
The first line of each test case contains two space-separated integers, ‘X’ and ‘Y’, representing the given numbers.

Output Format:
For each test case, print a single integer representing the Greatest Common Divisor of ‘X’ and ‘Y’.
Print a separate line for each test case.

Note (c++, python):
You do not need to print anything, it has already been taken care of. Just implement the given function.

Constraints:
1 <= T <= 10
1 <= X, Y <= 10^9

Sample Input 1:
2
20 15
8 32

Sample Output 1:
5
8

Explanation:
For the first test case, the greatest common divisor which divides both 15 and 20 is 5. Hence the answer is 5.
For the second test case, the greatest common divisor which divides both 8 and 32 is 8. Hence the answer is 8.

Sample Input 2:
2
98 56
36 60

Sample Output 2:
14
12
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int X[n];
    int Y[n];

    for(int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }

    for(int i = 0; i < n; i++) {
        int x = X[i], y = Y[i];

        while(y != 0 || y > 0) {
            int rem = x % y;
            x = y;
            y = rem;
        }

        cout << x << endl;
    }
    return 0;
}