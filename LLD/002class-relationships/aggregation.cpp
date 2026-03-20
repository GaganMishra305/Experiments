// "has-a" relationship
// whole is destroyed then the parts ARE NOT destroyed (playlist and songs)

#include <bits/stdc++.h>
using namespace std;

class Professor {
private:
    string name;
public:
    Professor(const string& name) : name(name) {}

    string getName() const {
        return name;
    }
};

class Department {
private:
    string name;
    vector<Professor*> professors;
public:
    Department(const string& name, const vector<Professor*>& professors)
        : name(name), professors(professors) {}

    void printProfessors() const {
        cout << "Professors in " << name << " Department:" << endl;
        for (const auto& professor : professors) {
            cout << "- " << professor->getName() << endl;
        }
    }
};

int main() {
    Professor* p1 = new Professor("Dr. Smith");
    Professor* p2 = new Professor("Dr. Johnson");

    vector<Professor*> profs = {p1, p2};

    Department csDept("Computer Science", profs);
    csDept.printProfessors();

    // csDept can go out of scope or be deleted...
    // but p1 and p2 still exist and can be used elsewhere.

    delete p1;
    delete p2;

    return 0;
}
