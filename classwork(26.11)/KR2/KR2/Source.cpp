#include <iostream>
using namespace std;
struct Point {
	double x, y;
};
double dist(Point& a, Point& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
class Rectangle {
private: Point l, t, r, b;
public:
	Rectangle() : l{ 0, 0 }, t{ 0,0 }, r{ 0,0 }, b{ 0,0 } {}
	Rectangle(Point left, Point top, Point right, Point bottom) : l(left), t(top), r(right), b(bottom) {}

	friend istream& operator>>(istream& is, Rectangle& rec) {
		is >> rec.l.x >> rec.l.y >> rec.t.x >> rec.t.y >> rec.r.x >> rec.r.y >> rec.b.x >> rec.b.y;
		return is;
	}
	friend ostream& operator<<(ostream& os, Rectangle& rec) {
		os << "left: (" << rec.l.x << ',' << rec.l.y << ") top: (" << rec.t.x << ',' << rec.t.y << ") right: (" << rec.r.x << ',' << rec.r.y << ") bottom: (" << rec.b.x << ',' << rec.b.y << ')' << endl;
		return os;
	}
	bool IsSquare() {
		double leftside, topside, rightside, bottomside;
		leftside = dist(l, t);
		topside = dist(t, r);
		rightside = dist(r, b);
		bottomside = dist(b, l);
		return (leftside == topside && leftside == rightside && leftside == bottomside);
	}
	bool IsRectangle() {
		double leftside, topside, rightside, bottomside;
		leftside = dist(l, t);
		topside = dist(t, r);
		rightside = dist(r, b);
		bottomside = dist(b, l);
		return (leftside == rightside && topside == bottomside);
	}
	double Perimetr() {
		double leftside, topside, rightside, bottomside;
		leftside = dist(l, t);
		topside = dist(t, r);
		rightside = dist(r, b);
		bottomside = dist(b, l);
		return leftside + topside + rightside + bottomside;
	}

};
bool operator<(Rectangle& rec1, Rectangle& rec2) {
	return (rec1.Perimetr() < rec2.Perimetr());
}
void sort(Rectangle* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);
}

int main() {
	const int n = 10;
	Rectangle arr[n];
	cout << "enter x and y for every point of a rectangle" << endl << "start with bottom left one and go by the clock" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, n);
	cout << "sorted by perimetr: " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " perimetr = " << arr[i].Perimetr() << endl;
	cout << endl << "rectangles: " << endl;
	for (int i = 0; i < n; i++)
		if (arr[i].IsRectangle())
			cout << i + 1 << " = is rectangle " << endl;
	cout << endl << "squares: " << endl;
	for (int i = 0; i < n; i++)
		if (arr[i].IsSquare())
			cout << i + 1 << " = is square " << endl;

	return 0;
}