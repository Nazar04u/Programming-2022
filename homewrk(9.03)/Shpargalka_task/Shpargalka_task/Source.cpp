#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SparNote {
public:
    string subject;
    int number;

    virtual void printInfo() = 0;
};

class PaperNote : public SparNote {
public:
    string size;
    string storagePlace;

    void printInfo() {
        cout << "Paper Note: " << subject << ", " << number << ", " << size << ", " << storagePlace << endl;
    }
};

class ElectronicNote : public SparNote {
public:
    string mediaName;

    void printInfo() {
        cout << "Electronic Note: " << subject << ", " << number << ", " << mediaName << endl;
    }
};

class Student {
public:
    string fullName;
    string group;
    vector<SparNote*> notes;

    void printNotes() {
        sort(notes.begin(), notes.end(), [](SparNote* a, SparNote* b) {
            if (a->subject == b->subject) {
                return a->number < b->number;
            }
        return a->subject < b->subject;
            });

        ofstream fout("all_notes.txt");
        for (auto note : notes) {
            note->printInfo();
            fout << note->subject << " " << note->number << endl;
        }
        fout.close();
    }

    void printElectronicNotes() {
        int count = 0;
        ofstream fout("electronic_notes.txt");
        for (auto note : notes) {
            ElectronicNote* enote = dynamic_cast<ElectronicNote*>(note);
            if (enote && enote->mediaName == "комп") {
                enote->printInfo();
                count++;
            }
        }
        fout << "Count of electronic notes on 'комп': " << count << endl;
        fout.close();
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter data for student " << i + 1 << ":" << endl;
        cout << "Full Name: ";
        getline(cin >> ws, students[i].fullName);
        cout << "Group: ";
        getline(cin >> ws, students[i].group);

        int m;
        cout << "Enter number of notes: ";
        cin >> m;

        for (int j = 0; j < m; j++) {
            cout << "Enter data for note " << j + 1 << ":" << endl;
            cout << "Subject: ";
            string subject;
            getline(cin >> ws, subject);
            cout << "Number: ";
            int number;
            cin >> number;
            cout << "Type of note (paper or electronic): ";
            string noteType;
            getline(cin >> ws, noteType);

            if (noteType == "paper") {
                cout << "Size: ";
                string size;
                getline(cin >> ws, size);
                cout << "Storage place: ";
                string storagePlace;
                getline(cin >> ws, storagePlace);

                PaperNote* pnote = new PaperNote();
                pnote->subject = subject;
                pnote->number = number;
                pnote->size = size;
                pnote->storagePlace = storagePlace;

                students[i].notes.push_back(pnote);
            }
        }
    }
}