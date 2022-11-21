#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	enum Color {
		blue,
		yellow,
		green,
		red,
		purple,
		brown,
		pink,
		black,
		white
	};
	srand(time(NULL));
	cout << "Enter n" << endl;
	int n; 
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10;
		
	}
	cout << "Enter m" << endl;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cout << "enter color number from 0 to 9" << endl;
		int a;
		cin >> a;
		switch (a) {
		case blue:
			 cout<<"blue"<<endl;
			 break;
		case yellow:
			cout<< "yellow";
			break;
		case green:
            cout<< "green";
			break;
		case red:
			cout << "red";
			break;
		case purple:
			cout<<"purple";
			break;
		case brown:
			cout<< "brown";
			break;
		case pink:
			cout<< "pink";
			break;
		case black:
			cout<< "black";
			break;
		case white:
			cout<<"white";
			break;
		}
	}
	

	
}