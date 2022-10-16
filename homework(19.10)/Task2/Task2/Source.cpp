/* There a numbers from a1 to an. We know that a1 > 0 and there is at least 1 negative numbers. We do nit know n . Find a number of even numbers*/
#include<iostream>
using namespace std;

int main()
{
	cout << " Enter n" << endl;
	int n;
	cin >> n;
	cout << "enter a1, a1 > 0" << endl;
	int a1;
	cin >> a1;
	int total = 0;
	int negative = 0;
	if (a1 > 0) {
		a1 = a1;
		if (a1 % 2 == 0) {
			total = total + 1;
		}
	}
	else {
		cout << " You enter a wrong number , so a1 = 1" << endl;
		a1 = 1;
	}
	int i = 0;
	while (i != n - 1) {
		cout << "enter a number" << endl;
		int a;
		cin >> a;
		if (negative == 0 and n - i == 2 ) {
			cout << "You must enter negative number" << endl;
			cin >> a;
			if (a >= 0) {
				cout << " You enter a wrong number so a = -1" << endl;
				a = -1;
			}
			if (a < 0 and a % 2 == 0) {
				total = total + 1 ;
			}
		}
		else
		{
			if (a % 2 == 0) {
				total = total + 1;
			}
			if (a < 0) {
				++negative;
			}
		}
		i = i + 1;
	

			
		
			
	}
	cout << "The amount of even number =" << total << endl;
	return 0;
}