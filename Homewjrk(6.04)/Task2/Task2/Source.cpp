#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef string(*Translator)(string);

string translateToEnglish(string text) {
    return "Happy Birthday, " + text + "!";
}

string translateToSpanish(string text) {
    return "¡Feliz cumpleaños, " + text + "!";
}

string translateToUkrainian(string text) {
    return "З днем народження, " + text + "!";
}


string sayHappyBirthday(string name, Translator translator) {
    return translator(name);
}

int main() {
    string name;
    int language;
    cout << "Enter the name of the birthday person: ";
    getline(cin, name);
    cout << "Choose a language: " << endl;
    cout << "1 - English" << endl;
    cout << "2 - Spanish" << endl;
    cout << "3 - Ukrainian" << endl;
    cin >> language;
    string greeting;
    switch (language) {
    case 1:
        greeting = sayHappyBirthday(name, translateToEnglish);
        break;
    case 2:
        greeting = sayHappyBirthday(name, translateToSpanish);
        break;
    case 3:
        greeting = sayHappyBirthday(name, translateToUkrainian);
        break;
    default:
        cout << "Invalid choice. Defaulting to English." << endl;
        greeting = sayHappyBirthday(name, translateToEnglish);
        break;
    }
    ofstream file("birthday_greeting.txt");
    file << greeting << endl;
    file.close();
    cout << "Birthday greeting saved to file." << endl;
    return 0;
}