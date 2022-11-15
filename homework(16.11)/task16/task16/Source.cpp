#include<iostream>
using namespace std;

int main()
{
	cout << "enter amount of numbers" << endl;
	int n;
	cin >> n;
	int counting = 0;
	int *arr = new int [n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter any number" << endl;
		int a;
		cin >> a;
		int total = 0;
		for (int b = 0; b < i; b++)
		{
			if (arr[b] != a) {
				total++;
			}
			
		}
		if (total == i ) {
			 arr[i-counting] = a;
		}
		else {
			counting++;
		}
		
	}
	cout<<"Your sequence look like:"<<endl;
	for (int c = 0; c < n-counting; c++)
	{
		cout << arr[c];
	}
	delete[] arr;
	return 0;
}
