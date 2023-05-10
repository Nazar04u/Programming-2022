#include <iostream>
using namespace std;

template <typename T>
void double_odd_positions(T arr[], int size) {
    for (int i = 1; i < size; i += 2) {
        arr[i] *= 2;
    }
}

int main() {
    // Приклад для масиву цілих чисел
    int int_arr[] = { 2, 6, 3, 2, 6, 4 };
    int int_size = sizeof(int_arr) / sizeof(int_arr[0]);

    cout << "Original int array: ";
    for (int i = 0; i < int_size; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;

    double_odd_positions(int_arr, int_size);

    cout << "Modified int array: ";
    for (int i = 0; i < int_size; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;

    // Приклад для масиву рядків
    std::string str_arr[] = { "foo", "bar", "baz", "qux" };
    int str_size = sizeof(str_arr) / sizeof(str_arr[0]);

    cout << "Original string array: ";
    for (int i = 0; i < str_size; i++) {
        cout << str_arr[i] << " ";
    }
    cout << endl;

    double_odd_positions(str_arr, str_size);

    cout << "Modified string array: ";
    for (int i = 0; i < str_size; i++) {
        cout << str_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
