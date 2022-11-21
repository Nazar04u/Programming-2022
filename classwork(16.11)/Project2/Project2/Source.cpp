#include<iostream>
#include<string>
using namespace std;
void F(int& x, int& y) {
	cout << x++ << --y;
}
void main() {
	int a = 5;
	int b = 6;
	F(a, b);
	

}