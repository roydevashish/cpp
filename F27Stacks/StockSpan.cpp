/*
Title: Stock Span

Problem statement
Amit has been working with an organization called 'Money Traders' for the past few years. The organization 
is into the money trading business. His manager assigned him a task. For a given array/list of stock's 
prices for N days, find the stock's span for each day.

The span of the stock's price today is defined as the maximum number of consecutive days(starting from 
today and going backwards) for which the price of the stock was less than today's price.

Explanation:
For the stock prices [100, 80, 60, 70, 60, 75, 85], the span of each day is calculated by counting 
consecutive previous days with a price less than or equal to today's price:

Day 1 (100): No previous days, span = 1.
Day 2 (80): Less than 100, span = 1.
Day 3 (60): Less than 80, span = 1.
Day 4 (70): Greater than 60, span = 2.
Day 5 (60): Less than 70, span = 1.
Day 6 (75): Greater than 60, 70, and 60, span = 4.
Day 7 (85): Greater than all previous days, span = 6.
Final spans: [1, 1, 1, 2, 1, 4, 6].

Amit has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve 
the task.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer N, denoting the total number of days.
The second line of input contains the stock prices of each day. A single space will separate them.

Output Format:
The only line of output will print the span for each day's stock price. A single space will separate them.

Note:
You are not required to print the expected output explicitly. It has already been taken care of. Just 
store the values of output in the spans array.

Constraints:
0 <= N <= 10^7
1 <= X <= 10^9
Where X denotes the stock's price for a day.

Time Limit: 1 second

Sample Input 1:
4
10 10 10 10

Sample Output 1:
1 1 1 1 

Sample Input 2:
8
60 70 80 100 90 75 80 120

Sample Output 2:
1 2 3 4 1 1 2 8
*/

#include<iostream>
#include<stack>
using namespace std;

void calculateSpan(int prices[], int n, int spans[]) {
    // Also need to solve it using stack.
    for(int i = 0; i < n; i++) {
        int j = i - 1;
        int count = 1;
        while(j >= 0 && prices[j] < prices[i]) {    
            count++;
            j--;
        }

        spans[i] = count;
    }
}

int main() {
    int n;
    cin >> n;

    int * prices = new int[n];
    for(int i = 0; i < n; i++)
        cin >> prices[i];

    int * spans = new int[n];
    calculateSpan(prices, n, spans);

    for(int i = 0; i < n; i++)
        cout << spans[i] << " ";

    delete[] prices;
    delete[] spans;

    return 0;
}