/*
Title: Quick Sort

Problem statement
Given the 'start' and the 'end'' positions of the array 'input'. Your task is to sort the elements
between 'start' and 'end' using quick sort.

Note : Make changes in the input array itself.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Integer N i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Sample Input 1 :
6
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 2 3 5 7

Sample Output 2 :
1 2 3 5 7

Constraints :
1 <= N <= 10^3
0 <= input[i] <= 10^9
*/

#include<iostream>
#include<vector>
using namespace std;

int Partition(int arr[], int low, int high) {
    int idxPivot = high;
    int idxSmallerElement = low-1;

    for(int i = low; i <= high; i++) {
        if(arr[i] < arr[idxPivot]) {
            idxSmallerElement++;

            int temp = arr[i];
            arr[i] = arr[idxSmallerElement];
            arr[idxSmallerElement] = temp;
        }
    }

    idxSmallerElement++;
    int temp = arr[idxSmallerElement];
    arr[idxSmallerElement] = arr[idxPivot];
    arr[idxPivot] = temp;

    return idxSmallerElement;
}

void QuickSort(int arr[], int low, int high) {
    if(low <= high) {
        int idxPartition = Partition(arr, low, high);
        QuickSort(arr, low, idxPartition-1);
        QuickSort(arr, idxPartition+1, high);
    }
}

class Runner {
    vector<int> v;

    public:
        void takeInput() {
            int n;
            cin >> n;
            v.resize(n);
            for (int i = 0; i < n; i++)
                cin >> v[i];
        }

        void execute() {
            int n = (int)v.size();

            int* input = new int[n];
            for (int i = 0; i < n; i++)
                input[i] = v[i];

            QuickSort(input, 0, n - 1);

            free(input);
        }

        void executeAndPrintOutput() {
            int n = (int)v.size();

            int* input = new int[n];
            for (int i = 0; i < n; i++)
                input[i] = v[i];

            QuickSort(input, 0, n - 1);

            for (int i = 0; i < n; i++)
                cout << input[i] << ' ';
            cout << '\n';

            free(input);
        }
};

int main() {
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}