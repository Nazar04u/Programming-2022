#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    string address;
};

template<typename T>
void sort_by_name(vector<T>& v) {
    sort(v.begin(), v.end(), [](const T& a, const T& b) {
        return a.name < b.name;
        });
}

int main() {
    vector<Person> people{
        {"John", "123 Main St."},
        {"Alice", "456 Elm St."},
        {"Bob", "789 Oak St."},
        {"Jane", "456 Elm St."},
    };
    sort_by_name(people);
    for (const Person& person : people) {
        cout << person.name << " (" << person.address << ")" << endl;
    }

    return 0;
}
