#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    string name;
    int id;
    string profession;
public:
    Student() : name("Jonh"), id(1), profession("Computer Science") {};

    Student(string n, int i, string p) : name(n), id(i), profession(p) {};

    friend istream& operator>>(istream& is, Student& data) {
        is >> data.name >> data.id >> data.profession;
        return is;
    }
    friend ostream& operator<<(ostream& os, Student& data1) {
        os << data1.name << "  " << data1.id << "  " << data1.profession;
        return os;
    }
    bool operator!=(Student& object) {
        return id != object.id;
    }
    string GetProfession() {
        return profession;
    }
    int GetID() {
        return id;
    }
};

class Course {
private:
    string name;
    int number;
    string profession;
public:
    Course() : name("programming"), number(1), profession("Computer Science") {};

    Course(string n, int num, string p) : name(n), number(num), profession(p) {};

    friend istream& operator>>(istream& is, Course& data) {
        is >> data.name >> data.number >> data.profession;
        return is;
    }
    friend ostream& operator<<(ostream& os, Course& data1) {
        os << data1.name << "  " << data1.number << "  " << data1.profession;
        return os;
    }

    bool operator !=(Course& object) {
        return number != object.number;
    }
    string GetProfession() {
        return profession;
    }
    int GetNumber() {
        return number;
    }

};

class University {
private:
    string name;
    string location;
    Student* students = new Student;
    int current_student = 0;
    Course* courses = new Course[100];
    int current_course = 0;
public:
    University() : name("Franko University"), location("Lviv") { students = new Student[150]; courses = new Course[100]; }

    void addStudent(Student student) {
        students[current_student] = student;
        current_student++;
    }
    void addCourse(Course course) {
        courses[current_course] = course;
        current_course++;
    }
    void delStudent(int id) {
        int i = 0;
        for (i; students[i].GetID() != id; i++) {
            if (i > current_student) {
                cout << "There is no such student." << endl;
                break;
            }
        }
        for (i; i != current_student; i++) {
            students[i] = students[i + 1];
        }
        current_student--;
    }
    void delCourse(int num) {
        int i = 0;
        for (i; courses[i].GetNumber() != num; i++) {
            if (i > current_course) {
                cout << "There is no such course." << endl;
                break;
            }
        }
        for (i; i != current_course; i++) {
            courses[i] = courses[i + 1];
        }
        current_course--;
    }
    void students_of_course(Course course) {
        for (int j = 0; j != current_student; j++) {
            if (students[j].GetProfession() == course.GetProfession()) {
                cout << students[j] << endl;
            }
        }
    }
    void students_courses(Student student) {
        for (int j = 0; j != current_course; j++) {
            if (courses[j].GetProfession() == student.GetProfession()) {
                cout << courses[j] << endl;
            }
        }
    }
};

int main() {
    University univer;
    while (true) {
        cout << "Choose action:" << endl;
        cout << "addStudent   " << "addCourse   " << "deleteStudent   " << "deleteCourse   " << "StudentsOfCourse   " << "Student'sCourses   " << "finish" << endl;
        string command;
        cin >> command;
        if (command == "addStudent") {
            cout << "Enter student name:" << endl;
            string name, prof;
            cin >> name;
            cout << "Enter student id:" << endl;
            int id;
            cin >> id;
            cout << "Enter student's profession:" << endl;
            cin >> prof;
            Student temp(name, id, prof);
            univer.addStudent(temp);
            continue;
        };
        if (command == "addCourse") {
            cout << "Enter coure's name:" << endl;
            string name;
            cin >> name;
            cout << "Enter course's number:" << endl;
            int number;
            cin >> number;
            cout << "Enter course's profession:" << endl;
            string profession;
            cin >> profession;
            Course temp(name, number, profession);
            univer.addCourse(temp);
            continue;
        }
        if (command == "deleteStudent") {
            cout << "Enter id of student you want to delete:" << endl;
            int n;
            cin >> n;
            univer.delStudent(n);
            continue;
        };
        if (command == "deleteCourse") {
            cout << "Enter number of course you want to delete:" << endl;
            int n;
            cin >> n;
            univer.delCourse(n);
            continue;
        };
        if (command == "StudentsOfCourse") {
            cout << "Enter coure's name:" << endl;
            string name;
            cin >> name;
            cout << "Enter course's number:" << endl;
            int number;
            cin >> number;
            cout << "Enter course's profession:" << endl;
            string profession;
            cin >> profession;
            Course temp(name, number, profession);
            univer.students_of_course(temp);
            continue;
        }
        if (command == "Student'sCourses") {
            cout << "Enter student name:" << endl;
            string name, prof;
            cin >> name;
            cout << "Enter student id:" << endl;
            int id;
            cin >> id;
            cout << "Enter student's profession:" << endl;
            cin >> prof;
            Student temp(name, id, prof);
            univer.students_courses(temp);
            continue;
        }
        if (command == "finish") {
            break;
        };
        cout << "There is no such command" << endl;

    }

    return 0;
}