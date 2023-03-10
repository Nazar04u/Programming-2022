#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
class ElectricTools {
private:
	string name;
	string company;
	float price;
public:
	virtual void input(istream& is) {
	is >> name >> company >> price;
}
	  friend istream& operator>>(istream& is, ElectricTools& data) {
		  data.input(is);
		  return is;
	  }
	  virtual void output(ostream& os) {
		  os << name << " " << company << " " << price << " ";
	  }
	  friend ostream& operator<<(ostream& os, ElectricTools& data1) {
		  data1.output(os);
		  return os;
	  }
	  virtual float Get_price() {
		  return price;
	  }
	  virtual string Get_company() {
		  return company;
	  }
	  virtual string Get_name() {
		  return name;
	  }
	  bool operator<(ElectricTools& p) {
		  return price < p.price;
	  }
};
class Porohotiag : public ElectricTools {
private:
	int power;
	string color;
public:
	void input(istream& is) {
		ElectricTools::input(is);
		is >> power >> color;
	}
	void output(ostream& os) {
		ElectricTools::output(os);
		os << power << " " << color;
	}
};
class Washer : public ElectricTools {
private:
	int amount_of_programs;
	float volume;
public:
	void input(istream& is) {
	ElectricTools::input(is);
	is >> amount_of_programs >> volume;
}
					void output(ostream& os) {
						ElectricTools::output(os);
						os << amount_of_programs << " " << volume;
					}
};
int main() {
	ofstream outfile("data.txt");
	if (!outfile) {
		cerr << "Uh oh, SomeText.txt could not be opened for writing!" << endl;
		exit(1);
	}
	outfile << "1" << endl;
	outfile << "A A1 2000 5000 red" << endl;
	outfile << "1" << endl;
	outfile << "B A1 2030 5200 blue" << endl;
	outfile << "1" << endl;
	outfile << "C A1 2300 5700 yellow" << endl;
	outfile << "1" << endl;
	outfile << "D B1 24000 15000 red" << endl;
	outfile << "2" << endl;
	outfile << "E C1 2300 12 345" << endl;
	outfile << "2" << endl;
	outfile << "F C1 2400 13 1234" << endl;
	outfile << "2" << endl;
	outfile << "G C1 2800 34 23" << endl;
	vector<ElectricTools*> tools;
	ifstream inf("data.txt");
	if (!inf)
	{
		cerr << "Uh oh, SomeText.txt could not be opened for reading!" << endl;
		exit(1);
	}
	while (!inf.eof())
	{
		string strInput;
		getline(inf, strInput);
		ElectricTools* temp;
		if (strInput == "1") {
			Porohotiag* temp = new Porohotiag();
			temp->input(inf);
			tools.push_back(temp);
		}
		else if (strInput == "2") {
			Washer* temp = new Washer();
			temp->input(inf);
			tools.push_back(temp);
		}
	}

	vector<string> names;
	vector<ElectricTools*> tools_sorted_by_name;
	for (int i = 0; i < tools.size(); i++) {
		names[i] = tools[i]->Get_name();
	}
	ofstream name("File1.txt");
	sort(names.begin(), names.end());
	for (int i = 0; i < tools.size(); i++) {
		for (int j = 0; j < tools.size(); j++) {
			if (names[i] == tools[j]->Get_name()) {
				name << tools[j] << endl;
			}
		}
	}
	ofstream company_file("File2.txt");
	if (!company_file) {
		cerr << "Uh oh, SomeText.txt could not be opened for writing!" << endl;
		exit(1);
	}
	float total = 0;
	for (int i = 0; i < tools.size(); i++) {
		if (tools[i]->Get_company() == "A1") {
			total = total + tools[i]->Get_price();
		}
	}
	company_file << "Total price for A1 tools is "<<total<< endl;
	return 0;
}