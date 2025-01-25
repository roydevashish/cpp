/*
Title: Remove X

Problem statement
Given a string, compute recursively a new string where all 'x' chars have been removed.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.

Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc

Sample Input 3 :
xx

Sample Output 3:
*/

#include<iostream>
#include<typeinfo>
using namespace std;

void RemoveX(char * input) {
    if(input[0] == '\0') {
        return;
    }

    RemoveX(&input[1]);

    if(input[0] == 'x') {
        int i = 0;
        while(input[i] != '\0') {
            input[i] = input[i+1];
            i++;
        }
    }

    return;
}

int main() {
    char input[100];
    cin.getline(input, 100);
    RemoveX(input);
    cout << input << endl;
}