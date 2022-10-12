#include<iostream>
using namespace std;

#include<iostream>
#include<numeric>
using namespace std;

int main()
{
    cout << "enter a and b" << endl;
    long long a, b;
    cin >> a >> b;
    while (a != 0 and b != 0)
    {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    cout << a + b << endl;
    return 0;

}
	
