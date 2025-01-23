/*
Title: Count Words

Problem statement
For a given input string(str), find and return the total number of words present in it.

It is assumed that two words will have only a single space in between. Also, there wouldn't be any 
leading and trailing spaces in the given input string.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.

Output Format:
The only line of output prints an integer value denoting the tool number of words present in the string.
Note:
You are not required to print anything. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 sec

Sample Input 1:
Coding Ninjas!

Sample Output 1:
2

Sample Input 2:
this is a sample string

Sample Output 2:
5
*/

#include<iostream>
#include<string.h>
using namespace std;

int CountWords(string input_string) {
    if(input_string.length() == 0) {
        return 0;
    }
    
    string x = " ";
    int count = 0;
    for(int i = 0; i < input_string.length(); i++) {
        if(input_string[i] == ' ') {
            count++;
        }
    }

    return count+1;
    
}

int main() {
    string input_string;
    getline(cin, input_string);
    int count = CountWords(input_string);
    cout << count << endl;
}