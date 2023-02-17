#include <iostream>
#include<string>
using namespace std;

class Worker {
private:
    int age;
    string surname;
    string attitude;
public:
    Worker() : age(0), surname(""), attitude("") {}
    Worker(int A, string B, string C) : age(A), surname(B), attitude(C) {}
    Worker(const Worker& p) : age(p.age), surname(p.surname), attitude(p.attitude) {}
    friend istream& operator>>(istream& is, Worker& data) {
        is >> data.age >> data.surname >> data.attitude;
        return is;
    }
    friend ostream& operator<<(ostream& os, Worker& data1) {
        os << data1.age << "years " << data1.surname<<"\t" << data1.attitude;
        return os;
    }
    int Getage() {
        return age;
    }
    string Getsurname() {
        return surname;
    }
    string Getattitude() {
        return attitude;
    }
};
int main() {
    cout << "Enter amount of man" << endl;
    int n;
    cin >> n;
    Worker arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter age, surname and attitude" << endl;
        cin >> arr[i];
    }
    cout << "" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].Getsurname()<<endl;
    }
    int k = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].Getage() > k) {
            k = arr[i].Getage();
            count = i;
        }
    }
    cout << "____________" << endl;
    cout << "The oldest man called " << arr[count].Getsurname() << endl;
    
}