/*
Title: Find Pair with Smallest Difference

Problem statement
Given two unsorted arrays of non-negative integers, 'arr1' and 'arr2' of size 'N' and 'M', respectively. 
Your task is to find the pair of elements (one from each array), such that their absolute (non-negative) 
difference is the smallest, and return the min difference.

Example :
N = 3, arr1 = [10, 20, 30]
M = 2, arr2 = [17, 15]
The smallest difference pair is (20, 17) with an absolute difference of 3. So, the answer is 3.

Note :
Both the arrays are unsorted, and all array elements are non-negative integers.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line of input contains an integer ‘T’ denoting the number of test cases.
The first line of each test case contains two space-separated integers, 'N' and 'M', where 'N' and 
'm' are the sizes of array 'arr1' and 'arr2', respectively.
The second line of each test case contains 'N' space-separated integers denoting the elements of 
array 'arr1'.
The third line of each test case contains 'M' space-separated integers denoting the elements of array 
'arr2'.

Output format :
For each test case, return the smallest absolute difference.

Note:
You do not need to print anything; it has already been taken care of. Just implement the function.

Constraints :
1 <= T <= 10
1 <= N, M <= 1000
0 <= arr1[i], arr2[i] <=10^6

Time Limit: 1 second

Sample input 1 :
2
3 3
12 7 5
4 4 6
3 2
10 20 30 
17 15

Sample output 1 :
1
3

Explanation For Sample Input 1 :
Test Case 1 :
The smallest difference pairs are (7, 6) and (5, 6) with an absolute difference of 1, so the answer is 1.

Test Case 2 :
The smallest difference pair is (20, 17) with an absolute difference of 3, so the answer is 3.

Sample input 2 :
2
4 4
1 5 12 3
16 9 10 20
2 4
20 10
10 13 19 16

Sample output 2 :
2
0
*/

#include<iostream>
using namespace std;

int FindPairWithSmallestDifference(int array_1[], int size_1, int array_2[], int size_2) {
    int min = INT_MAX;
    for(int i = 0; i < size_1; i++) {
        for(int j = 0; j < size_2; j++) {
            if(array_1[i] - array_2[j] < min) {
                min = array_1[i] - array_2[j];
                if(min < 0) {
                    min *= -1;
                }
            }
        }
    }

    return min;
}

int main() {
    int t;
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++) {
        int size_1, size_2;
        cin >> size_1 >> size_2;

        int array_1[size_1];
        int array_2[size_2];
        for(int i = 0; i < size_1; i++) {
            cin >> array_1[i];
        }

        for(int i = 0; i < size_2; i++) {
            cin >> array_2[i];
        }

        cout << FindPairWithSmallestDifference(array_1, size_1, array_2, size_2) << endl; 
    }
    return 0;
}