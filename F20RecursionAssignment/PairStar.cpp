/*
Title: Pair Star

Problem statement
Given a string S, compute recursively a new string where identical chars that are adjacent in the
original string are separated from each other by a "*".

Detailed explanation ( Input/output format, Notes, Images )
Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
aaaa

Sample Output 2 :
a*a*a*a
*/

#include<iostream>
using namespace std;

void PairStar(char input[]) {
    if(input[0] == '\0') {
        return;
    }

    PairStar(&input[1]);

    if(input[0] == input[1]) {
        int count = 0;
        while(input[count] != '\0') {
            count++;
        }

        while(count > 0) {
            input[count+1] = input[count];
            count--;
        }

        input[1] = '*';
    }

    return;
}

int main() {
   char input[100];
   cin.getline(input, 100);
   PairStar(input);
   cout << input << endl;
}