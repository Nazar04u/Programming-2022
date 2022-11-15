#include<iostream>
using namespace std;

int main()
{
	cout << "Enter number n" << endl;
	int n;
	cin >> n;
	bool flag = true;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			cout << "enter number" << endl;
			int a;
			cin >> a;
			arr[i][j] = a;			
		}
	}
	int total = 0;
	int count = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			total = total + arr[i][j];
		}
		if (j == 0){
			count = total;
		}
		if (j != 0) {
			if (total != count) {
				flag = false;
			}
		}
		total = 0;
	}
	if (flag == true) {
		cout << "The sum is equal in each columns" << endl;
    }
	if (flag == false)  {
		cout << "The sum is not equal in each columns" << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}