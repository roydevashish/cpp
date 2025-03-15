/*
Title: Minimum Bracket Reversal

Problem statement
For a given expression in the form of a string, find the minimum number of brackets that can be reversed 
in order to make the expression balanced. The expression will only contain curly brackets.
If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. 
Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening 
bracket and hence will not be able to make the expression balanced and the output will be -1.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.

Output Format :
The only line of output will print the number of reversals required to balance the whole expression. 
Prints -1, otherwise.

Note:
You don't have to print anything. It has already been taken care of.

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec

Sample Input 1:
{{{

Sample Output 1:
-1

Sample Input 2:
{{{{}}

Sample Output 2:
1
*/

#include<iostream>
#include<string>
using namespace std;

int countBracketReversals(string input) {
    if(input.length() % 2 != 0) {
        return -1;
    }

    stack<char> x;

    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '}' && !x.empty()) {
            if(x.top() == '{') {
                x.pop();
            } else {
                x.push(input[i]);
            }
        } else {
            x.push(input[i]);
        }
    }

    int red_len = x.size();

    int n = 0;
    while(!x.empty() && x.top() == '{') {
        x.pop();
        n++;
    }

    return red_len / 2 + n % 2;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input) << endl;;
}