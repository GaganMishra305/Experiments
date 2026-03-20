// "uses-a" relationship

/*
TYPE of association depends on:
    - direction (bi-directional, uni-directional)
    - multiplicity (1-to-1, 1-to-many, many-to-many)
*/

#include <bits/stdc++.h>
using namespace std;

class Course;
class Student;

class Instructor {
private:
    string name;
    vector<Course*> courses;
public:
    Instructor(const string& name) : name(name) {}

    void addCourse(Course* course);

    string getName() const { return name; }
    vector<Course*> getCourses() const { return courses; }
};

class Course {
private:
    string title;
    Instructor* instructor = nullptr;
    vector<Student*> students;
public:
    Course(const string& title) : title(title) {}

    void setInstructor(Instructor* instr) {
        instructor = instr;
    }

    void enrollStudent(Student* student);

    string getTitle() const { return title; }
    Instructor* getInstructor() const { return instructor; }
    vector<Student*> getStudents() const { return students; }
};

class Student {
private:
    string name;
    Course* enrolledCourse = nullptr;
public:
    Student(const string& name) : name(name) {}

    void setEnrolledCourse(Course* course) {
        enrolledCourse = course;
    }

    string getInstructorName() const {
        if (enrolledCourse != nullptr && enrolledCourse->getInstructor() != nullptr) {
            return enrolledCourse->getInstructor()->getName();
        }
        return "No instructor";
    }

    string getName() const { return name; }
};

void Instructor::addCourse(Course* course) {
    courses.push_back(course);
    course->setInstructor(this);
}

void Course::enrollStudent(Student* student) {
    students.push_back(student);
    student->setEnrolledCourse(this);
}

int main() {
    Instructor alice("Alice");
    Course dsa("Data Structures");
    Course sysDesign("System Design");

    alice.addCourse(&dsa);
    alice.addCourse(&sysDesign);

    Student bob("Bob");
    Student charlie("Charlie");

    dsa.enrollStudent(&bob);
    dsa.enrollStudent(&charlie);
    sysDesign.enrollStudent(&charlie);

    cout << alice.getName() << "'s courses:" << endl;
    for (auto* c : alice.getCourses())
        cout << "  - " << c->getTitle() << endl;

    cout << "Students in " << dsa.getTitle() << ":" << endl;
    for (auto* s : dsa.getStudents())
        cout << "  - " << s->getName() << endl;

    cout << bob.getName() << "'s instructor: " << bob.getInstructorName() << endl;

    return 0;
}

