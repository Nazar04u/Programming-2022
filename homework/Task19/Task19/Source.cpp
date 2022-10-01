#include<iostream>
using namespace std;

int main() {
	cout << "Enter hour minute and second"<<endl;
	int a;
	int b;
	int c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a > 0 and a < 24 and b > 0 and b < 60 and c > 0 and c < 60) {
		cout << "YES" << endl;
		cout << a << ":" << b << ':' << c << endl;
	}
	else {
		cout << "NO" << endl;
	}
}