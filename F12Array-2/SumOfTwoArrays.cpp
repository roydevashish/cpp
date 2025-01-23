/*
Title: Sum of Two Arrays

Problem statement
Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. 
Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every 
index). The idea here is to represent each array/list as an integer in itself of digits N and M.

You need to find the sum of both the input arrays/list treating them as two integers and put the 
result in another array/list i.e. output array/list will also contain only single digit at every 
index.

Note:
The sizes N and M can be different. 

Output array/list(of all 0s) has been provided as a function argument. Its size will always be 
one more than the size of the bigger array/list. Place 0 at the 0th index if there is no carry. 

No need to print the elements of the output array/list.

Using the function "sumOfTwoArrays", write the solution to the problem and store the answer inside 
this output array/list. The main code will handle the printing of the output on its own.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.
Second line contains 'N' single space separated integers representing the elements of the first array/list.
Third line contains an integer 'M' representing the size of the second array/list.
Fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Output Format :
For each test case, print the required sum of the arrays/list in a row, separated by a single space.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5

Time Limit: 1 sec 

Sample Input 1:
1
3
6 2 4
3
7 5 6

Sample Output 1:
1 3 8 0

Sample Input 2:
2
3
8 5 2
2
1 3
4
9 7 6 1
3
4 5 9

Sample Output 2:
0 8 6 5
1 0 2 2 0
*/

#include<iostream>
using namespace std;

void SumOfTwoArray(int array_1[], int size_1, int array_2[], int size_2, int array_output[], int size_output) {
    int x = size_1 - 1, y = size_2 - 1, z = size_output - 1;
    
    int carry = 0;
    while(x >= 0 && y >= 0) {
        int sum = array_1[x] + array_2[y] + carry;
        array_output[z] = sum % 10;
        carry = sum / 10;

        x--, y--, z--;
    }

    while(x >= 0) {
        int sum = array_1[x] + carry;
        array_output[z] = sum % 10;
        carry = sum / 10;
        x--, z--;
    }

    while(y >= 0) {
        int sum = array_2[y] + carry;
        array_output[z] = sum % 10;
        carry = sum / 10;

        y--, z--;
    }

    array_output[0] = carry;
}

int main() {
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int size_1, size_2;
        cin >> size_1;

        int array_1[size_1];
        for(int i = 0; i < size_1; i++) {
            cin >> array_1[i];
        }

        cin >> size_2;
        
        int array_2[size_2];
        for(int i = 0; i < size_2; i++) {
            cin >> array_2[i];
        }

        int size_output;
        if(size_1 >= size_2) {
            size_output = size_1 + 1;
        } else {
            size_output = size_2 + 1;
        }
        int array_output[size_output]; 

        SumOfTwoArray(array_1, size_1, array_2, size_2, array_output, size_output);

        cout << endl << "Sum: " << endl;
        for(int i = 0; i < size_output; i++) {
            cout << array_output[i] << " ";
        }
        cout << endl;
    }
    return 0;
}