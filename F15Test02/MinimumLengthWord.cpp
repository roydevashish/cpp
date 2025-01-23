/*
Title: Minimum Length Word

Problem statement
Given a string S (that can contain multiple words), you need to find the word which has minimum length.

Note : If multiple words are of same length, then answer will be first minimum length word in the string. 
Words are seperated by single space only.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
String S

Output Format :
Minimum length word

Constraints :
1 <= Length of String S <= 10^5

Sample Input 1 :
this is test string

Sample Output 1 :
is

Sample Input 2 :
abc de ghihjk a uvw h j

Sample Output 2 :
a
*/

#include<iostream>
#include<string.h>
using namespace std;

string MinimumLengthWord(string input_string) {
    int min_count = INT_MAX;
    int count = 0;
    int idx_start = 0;
    int min_idx = 0;
    for(int i = 0; i < input_string.length(); i++) {
        if(input_string[i] == ' ') {
            if(count < min_count) {
                min_count = count;
                min_idx = idx_start;
            }
            idx_start = i+1;
            count = 0;
        } else {
            count++;
        }
    }

    if(count < min_count) {
        min_count = count;
        min_idx = idx_start;
    }

    return input_string.substr(min_idx, min_count);
}

int main() {
    string input_string;
    getline(cin, input_string);
    string output_string = MinimumLengthWord(input_string);
    cout << output_string << endl;
    return 0;
}