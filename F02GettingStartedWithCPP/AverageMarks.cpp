/*
Title: Average Marks

Problem statement
Write a program to input a name(as a single character) and marks of three tests as m1, m2, and m3 
of a student considering all the three marks have been given in integer format.

Now, you need to calculate the average of the given marks and print it along with the name as 
mentioned in the output format section.

All the test marks are in integers and hence calculate the average in integer as well. That is, 
you need to print the integer part of the average only and neglect the decimal part.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Name(Single character)
Line 2 : Marks scored in the 3 tests separated by single space. 

Output format :
First line of output prints the name of the student.
Second line of the output prints the average mark.

Constraints
Marks for each student lie in the range 0 to 100 (both inclusive)

Sample Test 1
Input:
R
0 100 99 

Output:
R 
66
*/

#include<iostream>
using namespace std;

int main() {
    char name;
    int m1, m2, m3;

    cin >> name >> m1 >> m2 >> m3;

    int average_marks = (m1 + m2 + m3) / 3;

    cout << name << endl;
    cout << average_marks << endl;
    return 0;
}