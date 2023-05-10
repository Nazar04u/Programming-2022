#include <iostream>
#include <string>
using namespace std;

template <typename T>
void double_odd_positions(T arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (i % 2 == 0) { 
            arr[i] += arr[i];
        }
    }
}

int main() {

    size_t int_size;
    cout << "Enter size of integer array: ";
    cin >> int_size;

    string * int_arr = new string[int_size];

    cout << "Enter " << int_size << " integer values: ";
    for (size_t i = 0; i < int_size; i++) {
        cin >> int_arr[i];
    }

    cout << "Original int array: ";
    for (size_t i = 0; i < int_size; i++) {
        cout << int_arr[i];
    }
    cout << endl;

    double_odd_positions(int_arr, int_size);

    cout << "Modified int array: ";
    for (size_t i = 0; i < int_size; i++) {
        cout << int_arr[i];
    }
    cout << endl;

    delete[] int_arr;

    size_t str_size;
    cout << "Enter size of string array: ";
    cin >> str_size;

    string* str_arr = new string[str_size];

    cout << "Enter " << str_size << " string values: ";
    for (size_t i = 0; i < str_size; i++) {
        std::cin >> str_arr[i];
    }

    cout << "Original string array: ";
    for (size_t i = 0; i < str_size; i++) {
        cout << str_arr[i];
    }
    cout << endl;

    double_odd_positions(str_arr, str_size);

    cout << "Modified string array: ";
    for (size_t i = 0; i < str_size; i++) {
        cout << str_arr[i];
    }
    cout << endl;

    delete[] str_arr;

    return 0;
}
