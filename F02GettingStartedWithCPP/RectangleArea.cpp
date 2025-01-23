/*
Title: Rectancle Area

Problem statement
You are given a rectangle in a plane whose sides are parallel to the axes. The coordinates of one 
of its diagonals are provided to you. You have to print the total area of the rectangle.

The coordinates of the rectangle are provided as four integral values: x1, y1, x2, y2. It is given 
that x1 < x2 and y1 < y2.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains an integer x1 
The second line of input contains an integer y1  
The third line of input contains an integer x2 
The fourth line of input contains an integer y2 

Constraints:
1 <= x1 <= 10
1 <= y1 <= 10
1 <= x2 <= 10
1 <= y2 <= 10 

Time Limit: 1 second

Output format:
The first and only line of output contains the result.  

Sample Input:
1
1
3
3

Sample Output:
4

Explanation:
The given coordinates of the diagonal are (x1,y1) = (1,1) and (x2,y2) = (3, 3). 
The area of the rectangle can then easily be calculated as: 
area of rectangle = (x2-x1)*(y2-y1)
(3 – 1) * ( 3 – 1) = 2 * 2 = 4
*/

#include<iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int rectangle_area = (x2 - x1) * (y2 - y1);

    cout << rectangle_area << endl;

    return 0;
}