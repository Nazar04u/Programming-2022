#include <iostream>
#define _USE_MATH_DEFINES
#define M_PI_2
#include <cmath>
using namespace std;

struct Point {
	double x, y;
};

class Line {
private:
	double a, b, c;
public:
	Line() : a(0), b(0), c(0) {}
	Line(double A, double B, double C) : a(A), b(B), c(C) {}
	Line(const Line& p) : a(p.a), b(p.b), c(p.c) {}				//copy
	friend istream& operator>>(istream& is, Line& line) {
		is >> line.a >> line.b >> line.c;
		return is;												//input			
	}
	friend ostream& operator<<(ostream& os, Line& line) {
		os << line.a << "x + " << line.b << "y + " << line.c << "c = 0";
		return os;												//output
	}
	bool isInter(Line& line2) {
		double bottom = a * line2.b - line2.a * b;
		if (bottom == 0) return false;
		else return true;
	}
	Point GetInterseption(Line& line2) {
		double bottom = a * line2.b - line2.a * b;
		Point point;
		point.x = (b * line2.c - line2.b * c) / bottom;
		point.y = (c * line2.a - line2.c * a) / bottom;
		return point;
		//interseption
	}
	bool GetParallel(Line& line2) {
		cout << "are lines parallel? - ";
		if (line2.b == b) return true;
		else return false;
	}															//is parallel
	double GetAngle(Line& line2) {
		double angle;
		angle = (a * line2.a + b * line2.b) / (sqrt(a * a + b * b) * sqrt(line2.a * line2.a + line2.b * line2.b));
		return angle;
	}															//angle between
	bool Isonaline(Point& p) {
		if (a * p.x + b * p.y + c == 0) return true;
		else return false;
	}
};




int main() {
	const int n = 3;
	Line line;
	Line* array = new Line[10];
	cout << "enter an array" << endl;
	for (int i = 0; i < n; i++)
		cin >> array[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n - 1; j++) {
			if (array[i].isInter(array[j])) {
				cout << "line " << array[i] << " intersepts " << array[j] << endl;
				cout << "point of interseption is (" << array[i].GetInterseption(array[j]).x << ',' << array[i].GetInterseption(array[j]).y << ")" << endl;
			}
		}
	int c1 = 0, c2 = 0;
	Line OX(0, 1, 0);
	for (int i = 0; i < n; i++) {
		if (array[i].isInter(OX)) c1++;
		else if (array[i].GetAngle(OX) == M_PI_2(90)) c2++;

	}
	cout << "lines parallel to OX = " << c1 << endl;
	cout << "lines that intersept with 90 degree angle = " << c2 << endl;
	return 0;
}