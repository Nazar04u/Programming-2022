#include<iostream>
using namespace std;

int main()
{
	int count = 0;
	int i = 1;
	float total = 0.0;
	while (total < 1000)
	{
		total = total + 1.0 / i;
		i = i + 1;
		count = count + 1;
	}
	cout << count << endl;
	return 0;
}