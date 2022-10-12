#include<iostream>
using namespace std;

int main()
{
	cout << "enter a ";
	int a;
	cin >> a;
	
	while (a != 0) 
	{
		if (a > 0) {
			cout << a % 10;
			a = a / 10;
		}
		else {
			a = abs(a);
			cout << "-" << a % 10;
			a = a / 10;

		}
	}
	return 0;
}