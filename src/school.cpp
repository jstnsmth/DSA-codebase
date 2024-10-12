#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct Student {
    string name;
    int studentID;
    double gpa;
};

struct Node {
    Student student;
    Node* next;
};

class Course {
protected:
    int courseID;
    string courseName;
    Node* students;

public:
    Course() {
        courseID = 0;
        courseName = "";
        students = nullptr;
    }

    Course(int courseID, string courseName) {
        this->courseID = courseID;
        this->courseName = courseName;
        students = nullptr;
    }

    ~Course() {

    }

    void enrollStudent(string name, int studentID, double gpa) {
        if (students == nullptr) {
            students = new Node({{name, studentID, gpa}, nullptr});
        }
        else {
            Node* temp = students;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new Node({{name, studentID, gpa}, nullptr});
        }
    }

    void dropStudent(int studentID) {
        if (students == nullptr) {
            cout << "Student does not exist.\n";
            return;
        }
        else {
            Node* temp = students;
            Node* prev = nullptr;
            while (temp != nullptr && temp->student.studentID != studentID) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "Student was not found\n";
                return;
            }
            
            if (prev == nullptr) {
                students = students->next;
            }
            else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Student with ID " << studentID << " has been dropped.\n";
        }
    }

    void displayStudents() {
        Node* temp = students;
        if (temp == nullptr) {
            cout << "No students.\n";
        }
        else {
            while (temp != nullptr) {
                cout << "Name: " << temp->student.name << " | Student ID: " << temp->student.studentID << " | GPA: " << temp->student.gpa << endl;
                temp = temp->next;
            }
        }
    }

    int getCourseID() {
        return courseID;
    }

    string getCourseName() {
        return courseName;
    }
};

class CourseList{
private:
    Course* courses;
    int size;
    int capacity;

    void resizeCourseList() {
        capacity *= 2;
        Course* newCourses = new Course[capacity];
        for (int i = 0; i < size; i++) {
            newCourses[i] = courses[i];
        }
        delete[] courses;
        courses = newCourses;
    }

public:
    CourseList(int capacity = 2) {
        this->capacity = capacity;
        size = 0;
        courses = new Course[capacity];
    }

    ~CourseList() {
        delete[] courses;
    }

    void addCourse(string courseName, int courseID) {
        if (size == capacity) {
            resizeCourseList();
        }
        courses[size] = Course(courseID, courseName);
        size++;
    }

    void removeCourse(int courseID) {
        for (int i = 0; i < size; i++) {
            if (courses[i].getCourseID() == courseID) {
                for (int j = i; j < size-1; j++) {
                    courses[j] = courses[j+1];
                }
                size--;
                cout << "Course with ID " << courseID << " has been removed.\n";
                return;
            }
        }
        cout << "Course not found.\n";
    }

    void displayCourses() {
        for (int i = 0; i < size; i++) {
            cout << "Course ID: " << courses[i].getCourseID() << " | Course Name: " << courses[i].getCourseName() << endl;
            cout << "Students: \n";
            courses[i].displayStudents();
            cout << endl;
        }
    }

    Course* getCourse(int courseID) {
        for (int i = 0; i < size; i++) {
            if (courses[i].getCourseID() == courseID) {
                return &courses[i];
            }
        }
        return nullptr;
    }
};

int main() {
    CourseList courselist;
    courselist.addCourse("Math", 123);
    courselist.getCourse(123)->enrollStudent("Justin Smith", 103, 4.0);
    courselist.getCourse(123)->enrollStudent("Bob Jone", 432, 3.9);
   // courselist.displayCourses();
    courselist.addCourse("English", 321);
   // courselist.displayCourses();
    courselist.getCourse(123)->dropStudent(432);
    courselist.displayCourses();
    return 0;
}
