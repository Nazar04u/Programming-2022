/*there is a number n and numbers forom a1 to a39. In sequance from a to a39 change numbers on remainder from a**2%n */
#include<iostream>
using namespace std;

int main() {
	cout << "Enter n" << endl;
	int n;
	cin >> n;
	int list1[40];
	for (int i = 0; i < 40; i++) 
	{
		cout << i * i % n << endl;
	}
	return 0;
}