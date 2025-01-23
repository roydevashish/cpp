/*
Title: String Palindrome

Problem statement
Given a string, determine if it is a palindrome, considering only alphanumeric characters.

Palindrome:
A palindrome is a word, number, phrase, or other sequences of characters which read the same 
backwards and forwards.

Example:
If the input string happens to be, "malayalam" then as we see that this word can be read the same 
as forward and backwards, it is said to be a valid palindrome.
The expected output for this example will print, 'true'.
From that being said, you are required to return a boolean value from the function that has been 
asked to implement.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. All 
the characters in the string would be in lower case.

Output Format:
The only line of output prints either 'true' or 'false'.

Note:
You are not required to print anything. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1 :
abcdcba

Sample Output 1 :
true 

Sample Input 2:
coding

Sample Output 2:
false
*/

#include<iostream>
#include<string.h>
using namespace std;

bool CheckPalindrome(string input_string) {
    int l = 0, h = input_string.length() - 1;

    while(l < h) {
        if(input_string[l] != input_string[h]) {
            return false;
        }

        l++;
        h--; 
    }

    return true;
}

int main() {
    string input_string;
    getline(cin, input_string);
    CheckPalindrome(input_string) ? cout << "true" << endl : cout << "false" << endl;
    return 0;
}