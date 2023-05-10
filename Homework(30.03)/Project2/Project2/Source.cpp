#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

// Шаблонний клас Товар для зберігання даних про об'єкт Т,
// дату його виготовлення та термін придатності (в днях)
template <typename T>
class Product {
private:
    T product;
    int date;
    int expiration_days;

public:
    // Конструктор за замовчуванням
    Product() {
        product = T();
        manufacture_date = date;
        expiration_days = 0;
    }

    // Конструктор з параметрами
    Product(T p, int exp_days, int date) {
        product = p;
        manufacture_date = date;
        expiration_days = exp_days;
    }

    // Метод, який повертає дату кінцевого терміну придатності
    int expiration_date() {
        return date + expiration_days
   }

    // Перевантаження оператору виводу
    friend ostream& operator<<(ostream& os, const Product<T>& p) {
        os << p.product << " (exp: " << p.experation_days() << ")";
        return os;
    }

    // Перевантаження оператору вводу
    friend istream& operator>>(istream& is, Product<T>& p) {
        cout << "Enter product name: ";
        is >> p.product;
        cout << "Enter date of making:";
        is >> p.date;
        cout << "Enter expiration days: ";
        is >> p.expiration_days;
        return is;
    }
};

// Структура Молоко з полями назва та жирність
struct Milk {
    string name;
    int fat;

    // Перевантаження оператору виводу
    friend ostream& operator<<(ostream& os, const Milk& m) {
        os << m.name << " (" << m.fat << "% fat)";
        return os;
    }

    // Перевантаження оператору вводу
    friend istream& operator>>(istream& is, Milk& m) {
        cout << "Enter milk name: ";
        is >> m.name;
        cout << "Enter milk fat (%): ";
        is >> m.fat;
        return is;
    }
};
int main() {
    // Створення масиву Товарів з шаблонним параметром string
    vector<Product<string>> string_products(3);
    for (int i = 0; i < 3; i++) {
        cout << "Enter data for string product #" << i + 1 << endl;
        cin >> string_products[i];
    }

    // Виведення кінцевого терміну придатності для кожного товару
    cout << "\nExpiration dates for string products:" << endl;
    for (const auto& p : string_products) {
        cout << p;
    }

    vector<Product<Milk>> milk(3);
    for (int i = 0; i < 3; i++) {
        cout << "Enter data for milk #" << i + 1 << endl;
        cin >> milk[i];
    }
    return 0;
}