#include<iostream>
#include<string>
using namespace std;

void main() {
	string text = "abcdef";

	for (int i = 0; i < 5; i++) {
		text[i] = text[i + 1];
	}
	cout << text;
}