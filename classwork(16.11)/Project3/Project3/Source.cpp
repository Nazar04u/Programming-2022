#include<iostream>
#include<string>
using namespace std;
int *F(int *x) {
	for (int i = 0; i < 3; i++)
		x[i] += 2;
	return x;

void main() 
{
	int mas[] = { 1,2,3 };
	int *p;
	p = F(mas);
	cout << *p + *mas;


}