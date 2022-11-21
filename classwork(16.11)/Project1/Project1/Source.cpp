#include<iostream>
#include<string>
using namespace std;
void F(int& x, int& y) {
	cout << x++ << --y;
}
void main() {
	int a = 5;
	F(a, 6);
	cout << a;

}