/*
Title: Replace character recursively

Problem statement
Given an input string S and two characters c1 and c2, you need to replace every occurrence of
character c1 with character c2 in the given string.
Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)

Output Format :
Updated string

Constraints :
1 <= Length of String S <= 10^6

Sample Input :
abacd
a x

Sample Output :
xbxcd
*/

#include<iostream>
using namespace std;

void ReplaceCharacter(char input[], char x, char y) {
    if(input[0] == '\0') {
        return;
    }

    ReplaceCharacter(&input[1], x, y);

    if(input[0] == x) {
        input[0] = y;
    }

    return;
}

int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    ReplaceCharacter(input, c1, c2);
    cout << input << endl;
}