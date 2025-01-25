/*
Title: String to Integer

Problem statement
Write a recursive function to convert a given string into the number it represents. That is input
will be a numeric string that contains only numbers, you need to convert the string into
corresponding integer and return the answer.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 < |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
00001231

Sample Output 1 :
1231

Sample Input 2 :
12567

Sample Output 2 :
12567
*/

#include<iostream>
#include<math.h>
using namespace std;

int StringToNumber(char input[]) {
    if(input[0] == '\0') {
        return 0;
    }

    int smallOutput = StringToNumber(&input[1]);

    int length = 0;
    while(input[length] != '\0') {
        length++;
    }

    return ((int)input[0]-48) *  pow(10, length-1) + smallOutput;
}

int main() {
    char input[50];
    cin >> input;
    cout << StringToNumber(input) << endl;
}