/*
Title: Check Palindrome (Recursive)

Problem statement
Determine if a given string ‘S’ is a palindrome using recursion. Return a Boolean value of true if
it is a palindrome and false if it is not.
Note: You are not required to print anything, just implement the function.
Example:
Input: s = "racecar"
Output: true
Explanation: "racecar" is a palindrome.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of the input contains string S.

Output format:
Return a boolean value True or False.

Sample Input 1:
abbba

Sample Output 1:
true

Explanation Of Sample Input 1 :
“abbba” is a palindrome

Sample Input 2:
abcd

Sample Output 2:
false

Explanation Of Sample Input 2 :
“abcd” is not a palindrome.

Constraints:
0 <= |S| <= 10^6
where |S| represents the length of string S.
*/

#include<iostream>
#include<string>
using namespace std;

bool IsPalindrome(string t) {
    if(t.length() == 0) {
        return true;
    }

    if(t.at(0) != t.at(t.length() - 1)) {
        return false;
    }

    return IsPalindrome(t.substr(1, t.length() - 2));
}

class Runner {
    string t;

    public:
        void takeInput() {
            cin >> t;
        }

        void execute() {
            auto ans = IsPalindrome(t);
        }

        void executeAndPrintOutput() {
            auto ans = IsPalindrome(t);
            ans ? cout << "true" : cout << "false";
            cout << endl;
        }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}