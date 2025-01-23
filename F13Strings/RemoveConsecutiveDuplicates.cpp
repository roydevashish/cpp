/*
Title: Remove Consecutive Duplicates

Problem statement
For a given string(str), remove all the consecutive duplicate characters.

Example:
Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbcc"
Expected Output: "abc"

Input Format:
The first and only line of input contains a string without any leading and trailing spaces. 
All the characters in the string would be in lower case.

Output Format:
The only line of output prints the updated string.

Note:
You are not required to print anything. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1:
aabccbaa

Sample Output 1:
abcba

Sample Input 2:
xxyyzxx

Sample Output 2:
xyzx
*/

#include<iostream>
#include<string.h>
using namespace std;

string RemoveConsecutiveDuplicates(string input_string) {
    string output_string;

    int i = 0, j = 0;
    while(j < input_string.length()) {
        if(input_string[j] == input_string[i]) {
            if(j == input_string.length() - 1 && input_string[j] == input_string[i]) {
                output_string += input_string[i];  
            }
            j++;
        } else {
            output_string += input_string[i];
            i = j;
        }
    }

    return output_string;
}

int main() {
    string input_string;
    getline(cin, input_string);
    string output_string = RemoveConsecutiveDuplicates(input_string);
    cout << output_string << endl;
    return 0;
}