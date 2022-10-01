#include <iostream>
#include <map>
#include<string>
using namespace std;

int main() 
{
	map < int, string> s;
	s[1] = "January";
	s[2] = "February";
	s[3] = "March";
	s[4] = "April";
	s[5] = "May";
	s[6] = "June";
	s[7] = "July";
	s[8] = "August";
	s[9] = "September";
	s[10] = "October";
	s[11] = "November";
	s[12] = "December";
	cout << "Enter number of year " << endl;
	int a;
	cin >> a;
	while (a > 12) {
		a -= 12;
	}
	cout << s[a] << endl;
	return 0;
}





