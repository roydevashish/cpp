/*
Title: Number Star Pattern - 1

Problem statement
Print the following pattern for given number of rows.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Integer N (Total number of rows)

Output Format :
Pattern in N lines

Sample Input :
5

Sample Output :
5432*
543*1
54*21
5*321
*4321
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row = 0; row < n; row++) {
        for(int col = n; col > 0; col--) {
            if(col == row + 1) {
                cout << "* "; 
            } else {
                cout << col << " ";
            }
        }
        cout << endl;
    }
    return 0;
}