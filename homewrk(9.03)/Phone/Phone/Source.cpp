#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Phone {
private:
    string name;
    string company;
    float price;
public:

    virtual void input(istream& is) {
        is >> name >> company >> price;
    }
    friend istream& operator>>(istream& is, Phone& data) {
        data.input(is);
        return is;
    }
    virtual void output(ostream& os) {
        os << name << " " << company << " " << price << " ";
    }
    friend ostream& operator<<(ostream& os, Phone& data1) {
        data1.output(os);
        return os;
    }
    virtual float Get_price() {
        return price;
    }
    bool operator<(Phone& p) {
        return price < p.price;
    }

};

class MobilePhone : public Phone {
private:
    string color;
    int memory;

public:
    void input(istream& is) {
        Phone::input(is);
        is >> color >> memory;
    }
    void output(ostream& os) {
        Phone::output(os);
        os << color << " " << memory;
    }


};

class RadioPhone : public Phone {
private:
    float radius;
    bool answeringMachine;

public:

    void input(istream& is) {
        Phone::input(is);
        is >> radius >> answeringMachine;
    }
    void output(ostream& os) {
        Phone::output(os);
        os << radius << " " << answeringMachine;
    }


};

int main() {

    ofstream outfile("phones1.txt");

    outfile << "Mobile iPhone7 Apple 300 red 32" << endl;
    outfile << "Mobile iPhone12 Apple 1000 blue 64" << endl;
    outfile << "Radio iPhone10 Apple 700 30 true" << endl;

    outfile.close();


    ofstream outfile2("phones2.txt");

    outfile2 << "Mobile Samsung1 Samsung 500 black 32" << endl;
    outfile2 << "Radio Samsung2 Samsung 800 25 false" << endl;
    outfile2 << "Radio Samsung_Galaxy Samsung 900 20 true" << endl;

    outfile2.close();

    vector <Phone*> list;
    ifstream file("phones1.txt");
    while (!file.eof()) {
        string type;
        Phone* temp;
        file >> type;

        if (type == "Mobile") {
            temp = new MobilePhone();
        }
        if (type == "Radio") {
            temp = new RadioPhone();
        }
        temp->input(file);
        list.push_back(temp);
    }
    file.close();
    ifstream file2("phones2.txt");
    while (!file2.eof()) {
        string type;
        Phone* temp;
        file2 >> type;
        if (type == "Mobile") {
            temp = new MobilePhone();
        }
        if (type == "Radio") {
            temp = new RadioPhone();
        }
        temp->input(file2);
        list.push_back(temp);
    }
    file2.close();

    float total = 0;
    for (int i = 0; i < list.size(); i++) {
        total += list[i]->Get_price();
    }
    cout << "Total price: " << total << endl;
    sort(list.begin(), list.end());


    std::ofstream result("results.txt");
    for (int i = 0; i != list.size(); i++) {
        for (int j = 0; j != 5; j++) {
            result << list[i][j];
        }
        result << endl;
    }

    result.close();
    return 0;
}