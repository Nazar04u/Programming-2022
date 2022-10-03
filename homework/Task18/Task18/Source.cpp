#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "Enter three numbers from 100 to 999" << endl;
	string a;
	cin >>  a;
    cout << "Summary=" << (int)a[0] + (int)a[1]+ (int)a[2] - 48*3 << endl;
	return 0;
}