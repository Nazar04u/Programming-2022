#include <iostream>
#include<string>
using namespace std;

int main()
{
	cout << "Enter amount of seconds, no more than 86400" << endl;
	float b;
	int g;
	int h;
	int s;
	cin >> b;
    g = b / 3600;
	h = b / 3600 / 60;
	s = b / 3600 / 60 / 60;

	cout << g << ":" << h << ":" << s << endl;
	return 0;
}