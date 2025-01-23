/*
Title: Reverse Each Word

Problem statement
Aadil has been provided with a sentence in the form of a string as a function parameter. The task is 
to implement a function so as to change the sentence such that each word in the sentence is reversed. 
A word is a combination of characters without any spaces.

Example:
Input Sentence: "Hello I am Aadil"
The expected output will look, "olleH I ma lidaA".

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. The input 
string represents the sentence given to Aadil.

Output Format:
You don't need to print anything just change the sentence(string) such that each word in the sentence 
is reversed. 

Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

All the words in string are separated by a single space.

String does not contain any leading or trailing spaces.

Time Limit: 1 second

Sample Input 1:
Welcome to Coding Ninjas

Sample Output 1:
emocleW ot gnidoC sajniN

Sample Input 2:
Always indent your code

Sample Output 2:
syawlA tnedni ruoy edoc
*/

#include<iostream>
#include<string.h>
using namespace std;

string ReverseWord(string word) {
    int l = 0, h = word.length() - 1;
    while(l < h) {
        char temp = word[l];
        word[l] = word[h];
        word[h] = temp;
        
        l++;
        h--;
    }

    return word;
}

string ReverseEachWord(string input_string) {
    string output_string;
    int idx_start = 0;
    for(int i = 0; i < input_string.length(); i++) {
        if(input_string[i] == ' ') {
            output_string += ReverseWord(input_string.substr(idx_start, i - idx_start)) + " ";
            idx_start = i + 1;
        }
    }
    output_string += ReverseWord(input_string.substr(idx_start, input_string.length() - idx_start)) + " "; 
    return output_string;
}

int main() {
    string input_string;
    getline(cin, input_string);
    string output_string = ReverseEachWord(input_string);
    cout << output_string << endl;
    return 0;
}