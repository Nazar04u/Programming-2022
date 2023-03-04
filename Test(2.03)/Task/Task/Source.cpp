#include<iostream>
#include<string>
#include <algorithm>
#include <istream>
using namespace std;

class Goods {
private:
	string name;
public:
	Goods() : name("something") {}
	friend istream& operator>>(istream& is, Goods& data) {
		is >> data.name;
		return is;
	}
	friend ostream& operator<<(ostream& os, Goods& data1) {
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
	Goods* arr;
	int number;
	string address;
public:
	Storage() : amount(0), number(0), address("") {}
	Storage(int A, int B, string C) : amount(A), number(B), address(C) {
		this->arr = new Goods[amount];
		for (int i = 0; i != amount; i++) {
			this->arr[i] = arr[i];
		};
	}
	Storage(const Storage& p) : amount(p.amount), number(p.number), address(p.address), arr(p.arr) {}
	friend istream& operator>>(istream& is, Storage& data) {
		is >> data.amount >> data.number >> data.address;
		data.arr = new Goods[data.amount];
		for (int i = 0; i != data.amount; i++) {
			cout << "Enter product:  ";
			Goods temp;
			cin >> temp;
			data.arr[i] = temp;
		}
		cout << endl;
		return is;
		return is;
	}
	friend ostream& operator<<(ostream& os, Storage& data) {
		os << data.amount << " " << data.number << " " << data.address << endl;
		cout << "List of products:" << endl;
		for (int i = 0; i != data.amount; i++) {
			cout << data.arr[i] << endl;
		}
		cout << endl;
		return os;
	}
	Storage& operator= (const Storage& data)
	{
		amount = data.amount;
		arr[amount] = data.arr[amount];
		number = data.number;
		address = data.address;
		delete[] this->arr;
		this->arr = new Goods[data.amount];
		for (int i = 0; i != data.amount; i++) {
			this->arr[i] = data.arr[i];
		}

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
		for (int i = 0; i < amount; i++) {
			cout << arr[i] << endl;
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
	cout << "List sorted by addresses" << endl;
	if (list_of_goods[0].get_address() > list_of_goods[1].get_address()) {
		cout << list_of_goods[1] << endl;
		cout << list_of_goods[0] << endl;
	}
	else {
		cout << list_of_goods[0] << endl;
		cout << list_of_goods[1] << endl;
	}
	cout << "####################################" << endl;
	cout << "List sorted by number" << endl;
	if (list_of_goods[0].get_number() > list_of_goods[1].get_number()) {
		list_of_goods[1].get_arr();
		cout << endl;
	}
	else {
		list_of_goods[0].get_arr();
		cout << endl;
	}
	if (list_of_goods[0].get_amount() > list_of_goods[1].get_amount()) {
		Storage newStorage = list_of_goods[1];
	}
	else {
		Storage newStorage = list_of_goods[0];
	}
	return 0;
}