#include<iostream>
using namespace std;

int main()
{
	cout << "Enter m > 1 " << endl;
	int m;
	cin >> m ;
	int k = 0;
	while (pow(4, k) <= m) {
		k = k + 1;
    }
	cout << "4^k < m, when k is equal " << k << endl;
	return 0;


}