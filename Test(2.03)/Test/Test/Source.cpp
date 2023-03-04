#include<iostream>
#include<string>
#include <algorithm>
#include <istream>
using namespace std;

class Goods {
private:
	string name;
public:
	Goods() : name("") {}
	friend istream& operator>>(istream& is, Goods& data) {
		is >> data.name;
		return is;
	}
	friend ostream& operator<<(ostream& os,Goods& data1) {
		os << data1.name;
		return os;
	};
	string get_name() {
		return name;
	}
	void set_name(string value) {
		name = value;
	}
};
class Storage {
private:
	int amount;
	Goods* arr = new Goods[amount];
	int number;
	string address;
public:
	Storage() : amount(0), number(0), address("") { arr[amount]; }
	Storage(int A, int B, string C) : amount(A), number(B), address(C) { 
		for (int i = 0; i < amount; i++) {
			cout << "Enter Goods" << endl;
			cin >> arr[i];
		};
	}
	Storage(const Storage& p) : amount(p.amount), number(p.number), address(p.address), arr(p.arr) {}
	friend istream& operator>>(istream& is, Storage& data) {
		is >> data.amount >> data.number >> data.address ;
		return is;
	}
	friend ostream& operator<<(ostream& os, Storage& data) {
		os << data.amount << data.number << data.address;
		return os;
	}
	Storage& operator= (const Storage& data)
	{
		amount = data.amount;
		arr[amount] = data.arr[amount];
		number = data.number;
		address = data.address;

		return *this;
	}
	Goods& operator[](int index) {
		return arr[index];
	}
	int get_amount() {
		return amount;
	}
	void set_amount(int value) {
		amount = value;
	}
	int get_number() {
		return number;
	};
	void set_number(int value) {
		number = value;
	}
	string get_address() {
		return address;
	}
	void set_address(string value) {
		address = value;
	}
	void get_arr() {
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
			cout << arr[i] << " ";
		}
	}
	void setarr(int value) {
		for (int i = 0; i < value; i++) {
			cout << "Enter goods" << endl;
			string value;
			cin >> value;
			arr[i].set_name(value);
		}
	}
	~Storage() {};
};

int main() {
	Storage list_of_goods[2];
	for (int i = 0; i < 2; i++) {
		cout << "Enter data about storage: amount of goods, numbers of storage, address of storage." << endl;
		cin >> list_of_goods[i];
		}
	}
	cout << "List sorted by addresses" << endl;
	if (list_of_goods[0].get_address() > list_of_goods[1].get_address()) {
		cout << list_of_goods[0] ;
	};
	
	return 0;
}