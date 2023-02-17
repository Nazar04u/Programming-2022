
#include<iostream>
#include<string>
using namespace std;

class Product {
private:
	string name;
	int price;
	int code;
public:
	Product() : name(""), price(0), code(1) {}
	Product(string A, int B, int C) : name(A), price(B), code(C) {}
	friend istream& operator>>(istream& is, Product& data) {
		is >> data.name >> data.price >> data.code;
		return is;
	}
	friend ostream& operator<<(ostream& os, Product& data1) {
		os << data1.name << " \t" << data1.price << " \t" << data1.code;
		return os;
	};
	int get_price() {
		return price;
	}
	string get_name() {
		return name;
	}
	int get_code() {
		return code;
	}
	bool operator !=(const Product & other) {
		return !(this->code == other.code);
	}
	bool operator ==(const Product& other) {
		return (this->code == other.code);
	}
};
class Cart {
private:
	Product *products = new Product [100];
	int total_price;
	int* counts;
	int current;
public:
	Cart() : current(0), total_price(0) { products = new Product[100]; counts = new int[100];}
	void addProduct(Product item, int count) {
		bool check = true;
		if (current > 100) {
			cout << "Too many products" << endl;
			bool check = false;
		}
		if (check) {
			products[current] = item;
			counts[current] = count;
			current++;
		}
	}
	void delProduct(int codes) {
		int i = 0;
		bool flag = true;
		while (products[i].get_code() != codes) {
			if (i == 100) {
				bool flag = false;
				cout << "There is no such product" << endl;
				break;
			}
			i++;
		}
		if (flag) {
			for (i, i <= current; i++;) {
				products[i] = products[i + 1];			
			};
			current = current - 1;
		}
		
	};
	void seeProducts() {
		cout << "Products:" << endl;
		for (int j = 0; j < current; j++) {
			cout << products[j] << endl;
		};
	}
	void TotalPrice() {
		for (int j = 0; j < current; j++) {
			total_price = total_price + products[j].get_price()*counts[j];
		};
		cout << total_price << endl;
		total_price = 0;
	}
};
int main() {
	Cart a;
	cout << "To start enter start , to end enter end" << endl;
	string start = "start";
	string end = "end";
	cin >> start;
	while (start != end) {
		cout << "You can add_products or delete products from tour cart(enter add or del)." << endl;
		cout << "Also you can seeproducts(enter see) or see total price(enter total)" << endl;
		cout << "What do you want to do" << endl;
		string command;
		cin >> command;
		if (command == "add") {
			cout << "Enter Product and amount" << endl;
			Product product;
			cin >> product;
			int amount;
			cin >> amount;
			a.addProduct(product, amount);
		}
		if (command == "del") {
			cout << "Enter Code of product you want to delete" << endl;
			int codes;
			cin >> codes;
			a.delProduct(codes);
		}
		if (command == "see") {
			a.seeProducts();
		}
		if (command == "total") {
			a.TotalPrice();
		}
		cout << "If you want to end (enter end)" << endl;
		cin >> start;
	};
	return 0;
}