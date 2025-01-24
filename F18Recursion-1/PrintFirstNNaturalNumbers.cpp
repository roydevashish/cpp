/*
Title: Print Numbers

Problem statement
Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Integer n

Output Format :
Numbers from 1 to n (separated by space)

Constraints :
1 <= n <= 10000

Sample Input 1 :
6

Sample Output 1 :
1 2 3 4 5 6

Sample Input 2 :
4

Sample Output 2 :
1 2 3 4
*/

#include<iostream>
using namespace std;

void PrintFirstNNaturalNumbers(int n) {
    if(n <= 0) {
        return;
    }
    PrintFirstNNaturalNumbers(n-1);
    cout << n << " ";
    return;
}

int main(){
    int n;
    cin >> n;

    PrintFirstNNaturalNumbers(n);
}