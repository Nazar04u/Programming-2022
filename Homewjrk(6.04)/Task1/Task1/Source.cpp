#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<fstream>



using namespace std;



string Tab(double(*f)(double), double* arr, int size) {
	ostringstream os;
	os << "|" << setw(5) << "i" << setw(5) << "|" << setw(5) << "a[i]" << setw(5) << "|" << setw(5) << "modified a[i]" << endl;
	for (int a = 0; a < size; a += 1) {
		os << "|" << setw(5) << a << setw(5) << "|" << setw(5) << arr[a] << setw(5) << "|" << setw(5) << round(f(arr[a])*100)/100 <<endl;
	}
	return os.str();
}
int main() {
	const size_t size = 8;
	double arr[size] = { 1.23, 2.34, 3.45, 4.56, 5.67 ,7.89, 34.6, 21.11 };
	string st, st2, st3;
	st = Tab([](double x) { return x * x; }, arr, size);
	ofstream file1("result.txt");
	file1 << "Square:" << endl << st;
	st2 = Tab([](double x) { return sin(x) + cos(x) - tan(x); }, arr, size);
	file1 << "Sin + Cos - Tg:" << endl << st2;
	st3 = Tab([](double x) { return round(x); }, arr, size);
	file1 << "RoundtoInt:" << endl << st3;
	file1.close();
}