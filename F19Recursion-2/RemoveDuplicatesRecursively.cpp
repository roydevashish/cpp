/*
Title: Remove duplicates

Problem statement
Given a string S, remove consecutive duplicates from it recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba

Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz

Sample Output 2 :
xyzwz
*/

#include<iostream>
using namespace std;

void RemoveConsecutiveDuplicates(char s[]) {
    if(s[0] == '\0') {
        return;
    }

    RemoveConsecutiveDuplicates(&s[1]);

    if(s[0] == s[1]) {
        int idx = 0;
        while(s[idx] != '\0') {
            s[idx] = s[idx+1];
            idx++;
        }
    }

    return;
}

int main() {
    char s[100000];
    cin >> s;
    RemoveConsecutiveDuplicates(s);
    cout << s << endl;
}