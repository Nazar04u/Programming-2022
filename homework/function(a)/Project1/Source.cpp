#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "Enter x" << endl;
	int x;
	cin >> x;
	if (x < 0) {
		cout << abs(x) << endl;
     }
	else if (x > 0) {
		cout << x * x << endl;
	}
}