#include<iostream>
using namespace std;

int main()
{
	struct ColorBalls {
		double radius;
		char color;
	};
	const int size = 5;
	double arr[size];
	char name_of_balls[size];
	char color_of_balls[size];
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter name of ball" << endl;
		char a;
		cin >> a;
		name_of_balls[i] = a;
		cout << "Enter radius of ball" << endl;
		double actual_radius;
		cin >> actual_radius;
		cout << "Enter color of ball" << endl;
		char actual_color;
		cin >> actual_color;
		color_of_balls[i] = actual_color;
		arr[i] = actual_radius;
	}
	double maximum = 0;
	int pointer = 0;
	for (int i = 0; i < 5; i++) {
		if (arr[i] > maximum) {
			pointer = i;
			maximum = arr[i];
		}
		cout << name_of_balls[pointer] << " { radius = " << arr[pointer] << ", color is " << color_of_balls[pointer] << endl;
	}
	return 0;
}