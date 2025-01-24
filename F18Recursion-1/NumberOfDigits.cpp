/*
Title: Number of Digits

Problem statement
You are given a number 'n'.
Return number of digits in ‘n’.

Example:
Input: 'n' = 123
Output: 3

Explanation:
The 3 digits in ‘123’ are 1, 2 and 3.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains an integer ‘n’.

Output Format:
Return an integer as described in the problem statement.

Note
You don’t need to print anything, it has already been taken care of, just complete the given function.
Sample Input 1:
121

Sample Output 1:
3

Explanation of sample output 1:
There are 3 digits in 121 are 1,2 and 1.

Sample Input 2:
38

Sample Output 2:
2

Expected time complexity :
The expected time complexity is O(log n).

Constraints:
1 <= ‘n’ <= 10^9
*/

#include <iostream>
using namespace std;

int countDigits(int n) {
    if(n == 0) {
        return 0;
    }

    return countDigits(n/10) + 1;
}

class Runner {
    int N;

    public:
        void takeInput()
        {
            cin >> N;
        }

        void execute()
        {
            int ans = countDigits(N);
        }

        void executeAndPrintOutput()
        {

            int ans = countDigits(N);
            cout << ans << endl;
        }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}