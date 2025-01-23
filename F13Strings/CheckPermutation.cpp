/*
Title: Check Permutation

Problem statement
For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.

Permutations of each other
Two strings are said to be a permutation of each other when either of the string's characters can be 
rearranged so that it becomes identical to the other one.

Example: 
str1= "sinrtg" 
str2 = "string"

The character of the first string(str1) can be rearranged to form str2 and hence we can say that the 
given strings are a permutation of each other.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains a string without any leading and trailing spaces, representing the 
first string 'str1'.

The second line of input contains a string without any leading and trailing spaces, representing the 
second string 'str2'.

Note:
All the characters in the input strings would be in lower case.

Output Format:
The only line of output prints either 'true' or 'false', denoting whether the two strings are a permutation 
of each other or not.

You are not required to print anything. It has already been taken care of. Just implement the function. 

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second

Sample Input 1:
abcde
baedc

Sample Output 1:
true

Sample Input 2:
abc
cbd

Sample Output 2:
false
*/

#include<iostream>
#include<string.h>
using namespace std;

bool IsPermutation(string input_string_1, string input_string_2) {
    if(input_string_1.length() != input_string_2.length()) {
        return false;
    }

    int array_char[26] = {0};

    for(int i = 0; i < input_string_1.length(); i++) {
        array_char[(int)input_string_1[i] - (int) 'a'] += 1;
    }

    for(int i = 0; i < input_string_2.length(); i++) {
        array_char[(int)input_string_2[i] - (int) 'a'] -= 1;
    }

    for(int i = 0; i < 26; i++) {
        if(array_char[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string input_string_1, input_string_2;
    getline(cin, input_string_1);
    getline(cin, input_string_2);

    if(IsPermutation(input_string_1, input_string_2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}