#include<iostream>
using namespace std;

void main()
{
    int i1, j1;
    int n;
    cout << "enter the matrix size:";
    cin >> n;
    int rows, cols, max, minriad;
    rows = n;
    cols = n;
    int** arr = new int* [rows];
    for (int i = 0; i < cols; i++)
    {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "===";
    }cout << endl;
    int k = -32000;
    minriad = arr[0][0];
    for (int i = 0; i < rows; i++)
    {

        if (arr[i][i] < 0)
        {
            minriad = arr[i][0];
            for (int j = 0; j < rows; j++)
            {
                if (arr[i][j] < minriad)
                {
                    minriad = arr[i][j];
                }
            }
            if (minriad > k) {
                k = minriad;
            }
        }
        
    }
    cout << k << endl;
}