#include<iostream>
using namespace std;

int main()
{
	cout << "Enter 3 numbers" << endl;
	int a;
	cin >> a;
	int b;
	cin >> b;
	int c;
	cin >> c;
	if (a + b == 2 * c or a + c == 2 * b or b + c == 2 * a) {
		cout << "YES" << endl;
     }
	else {
		cout << "NO" << endl;
	}
}