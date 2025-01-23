/*
Title: Reverse String Word Wise

Problem statement
Reverse the given string word wise. That is, the last word in given string should come at 1st place, 
last second word at 2nd place and so on. Individual words should remain as it is.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
String in a single line

Output format :
Word wise reversed string in a single line

Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.

Sample Input 1:
Welcome to Coding Ninjas

Sample Output 1:
Ninjas Coding to Welcome

Sample Input 2:
Always indent your code

Sample Output 2:
code your indent Always
*/

#include<iostream>
#include<string.h>
using namespace std;

string ReverseString(string input_string) {
    string output_string = "";
    if(input_string.length() == 0) {
        return output_string;
    }

    int idx_start = 0;
    for(int i = 0; i < input_string.length(); i++) {
        if(input_string[i] == ' ') {
            output_string = input_string.substr(idx_start, i-idx_start) + " " + output_string;
            idx_start = i+1;
        }
    }
    output_string = input_string.substr(idx_start, input_string.length() - idx_start) + " " + output_string;

    return output_string;
}

int main() {
    string input_string;
    getline(cin, input_string);
    string output_string = ReverseString(input_string);
    cout << output_string << endl;
    return 0;
}