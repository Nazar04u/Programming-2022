#include <iostream>
#include <string>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>



using namespace std;

struct Point {
	double x;
	double y;

	friend ostream& operator<<(ostream& os, Point& point) {
		os << '(' << point.x << ", " << point.y << ')';
		return os;
	}
};

class Line {
private:
	double a;
	double b;
	double c;

public:
	Line() :a(0), b(0), c(0) {}
	Line(double _a, double _b, double _c) :a(_a), b(_b), c(_c) {}
	Line(const Line& line) :a(line.a), b(line.b), c(line.c) {}
	//gets
	double getA() {
		return a;
	}
	double getB() {
		return b;

	}
	double getC() {
		return c;
	}
	//sets

	void setA(double _a) {
		a = _a;
	}
	void setB(double _b) {
		b = _b;
	}
	void setC(double _c) {
		c = _c;
	}

	friend istream& operator>>(istream& is, Line& line) {
		cout << "Enter a, b, c" << endl;
		is >> line.a >> line.b >> line.c;

		return is;
	}

	friend ostream& operator<<(ostream& os, Line& line) {
		os << "Line with parameters - " << line.a << ' ' << line.b << ' ' << line.c;
		return os;
	}

	double delta(Line other) {
		return a * other.b - other.a * b;
	}

	double deltaX(Line other) {
		return c * other.b - other.c * b;
	}
	double deltaY(Line other) {
		return a * other.c - other.a * c;
	}

	Point getIntersectionPoint(Line other) {

		double x;
		double y;

		x = deltaX(other) / delta(other);
		y = deltaY(other) / delta(other);

		Point p = { x, y };

		return p;

	}

	double getAngle(Line other) {

		double tg = (other.a * b - a * other.b) / (a * other.a + b * other.b);

		return atan(tg);

	}

	bool isInLine(Point point) {
		//x = (c - b*y)/a

		if (point.x == (c - b * point.y) / a) {
			return true;
		}
		return false;
	}

	bool isParalel(Line other) {
		if (delta(other) == 0) {
			return true;
		}
		return false;
	}

};
int isParalel(Line line1, Line line2) {
	if (line1.delta(line2) == 0) {
		return 1;
	}
	return 0;
}

int main() {

	//init
	Line ox(0, 1, 0);
	int n = 10;
	Line* lines = new Line[n];

	int c1 = 0;
	int c2 = 0;
	int k = 1;

	for (int i = 0; i < n; i++) {
		cin >> lines[i];
	}

	for (int i = 0; i < n; i++) {
		cout << lines[i] << " has intersection with:" << endl;
		for (int j = 0; j < n; j++) {
			if (j != i) {
				if (!lines[i].isParalel(lines[j])) {
					Point p = lines[i].getIntersectionPoint(lines[j]);
					cout << k << " - " << lines[j] << " in point " << p << " Angle=" << lines[i].getAngle(lines[j]) << endl;
					k++;

				}
				double angle = lines[j].getAngle(ox);
				if (angle == 0 || lines[j].isParalel(ox) == 1) {
					c1++;
				}
				else if (tan(angle) == 0) {
					c2++;
				}
			}
		}
		cout << "There are " << c1 << " paralel and " << c2 << " perpendicular lines to OX" << endl;
		c1 = 0;
		c2 = 0;
		k = 1;
	}


	return 0;
}