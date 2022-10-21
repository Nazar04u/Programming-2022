#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	float S = 0;
	for (int i = 1; i <= 10; i++)
	{
		cout << "Enter x" << endl;
		int x;
		cin >> x;
		int factorial = 1;
		for (int j = 1; j <= i; j++)
		{
			factorial = factorial * j;
		}
		S = S + (pow(log(x), i) * 3 * x) / factorial;
        float y = pow(3, x);
		int pohubka = abs((S - y) / y) * 100;
		cout << "X = " << x << " S = " << S << " y = " << y << " pohubka = " << pohubka << endl;
	}
	return 0;
}