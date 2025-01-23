/*
Title: Array Rotation

Problem statement
You are given an array A of size N.

You are also given an integer X and a direction DIR. You need to rotate the array A by X positions 
in the direction specified by DIR.
DIR can be:
    'LEFT': Rotate the array to the left by X positions.
    'RIGHT': Rotate the array to the right by X positions.
Return the resulting rotated array.

For example:
Input :
A = [6, 2, 6, 1], X = 1, DIR = ‘LEFT’

Output :
2 6 1 6

Explanation: Rotate array ‘A’ to the left one time.
[6, 2, 6, 1] => [2, 6, 1, 6]

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
First-line contains 'T,' denoting the number of Test cases.
For each Test case:
The first line contains two integers, ‘N', ‘X’, and the string ‘DIR’.
The second line has ‘N’ integers denoting the array ‘A’.

Output Format:-
You must return the rotated array.
Note:-
You don’t need to print anything. Just implement the given function.

Constraints :
1 <= T <= 10
1 <= N <= 10^5 
1 <= X <= 10^9
‘DIR’ is an element of {‘LEFT’, ‘RIGHT’}

Time Limit: 1 sec

Sample Input 1 :
2
4 1 LEFT
1 2 3 4
6 2 RIGHT
1 2 4 3 5 6 

Sample Output 1 :
2 3 4 1
5 6 1 2 4 3

Explanation Of Sample Input 1 :
For test case one:
Input :
A = [1, 2, 3, 4], X = 1, DIR = ‘LEFT’

Output :
2 3 4 1

Explanation: Rotate array ‘A’ to the left one time.
[1, 2, 3, 4] => [2, 3, 4, 1]

For test case two:
Input :
A = [1, 2, 4, 3, 5, 6], X = 2, DIR = ‘RIGHT’

Output :
5 6 1 2 4 3

Explanation: Rotate array ‘A’ to the right one time.
[1, 2, 4, 3, 5, 6] => [6, 1, 2, 4, 3, 5]

Sample Input 2 :
2
6 3 LEFT
22 8 4 7 5 10
6 2 RIGHT
9 3 1 6 3 9

Sample Output 2 :
7 5 10 22 8 4 
3 9 9 3 1 6
*/

#include<iostream>
#include<string>
using namespace std;

void RotateArray(int array[], int size, int x, string dir) {
    if(dir.compare("LEFT") == 0) {
        // Left Rotate
        while(x--) {
            int temp_0 = array[0];
            for(int i = 1; i < size; i++) {
                array[i-1] = array[i];
            }
            array[size-1] = temp_0;
        }
    } else if(dir.compare("RIGHT") == 0){
        // right Rotate
        while(x--) {
            int temp_last = array[size-1];
            for(int i = size - 2; i >= 0; i--) {
                array[i+1] = array[i];
            }
            array[0] = temp_last;
        }
    } else {
        return;
    }
    
    return;
}

int main() {
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int n, x;
        string dir = "";

        cin >> n >> x >> dir;

        int array[n];
        for(int i = 0; i < n; i++) {
            cin >> array[i];
        }

        RotateArray(array, n, x, dir);

        for(int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    return 0;
}