#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
using namespace std;

class Course {
public:
    virtual void print_Details() = 0;
    virtual string getcoursecode() = 0;
};

class offline_Course : public Course {
private:
    string course_Name;
    string course_Code;
public:
    offline_Course(string name, string code) {
        course_Name = name;
        course_Code = code;
    }

    void print_Details() override {
        cout << "Name of course is: " << course_Name << "\n";
        cout << "Code of the course is: " << course_Code << "\n";
    }
    string getcoursecode() override{
        return course_Code;
    }
};

class online_Course : public Course {
private:
    string course_Name;
    string course_Code;
public:
    online_Course(string name, string code) {
        course_Name = name;
        course_Code = code;
    }

    void print_Details() override {
        cout << "Name of the course is: " << course_Name << "\n";
        cout << "Code of the course is: " << course_Code << "\n";
    }

    string getcoursecode() override{
        return course_Code;
    }
};

class student {
private:
    string Name;
    string UID;
    string Section;
    string Password;
    list<Course*> registered_course;
public:
    student(string name, string uid, string section, string password) {
        Name = name;
        UID = uid;
        Section = section;
        Password = password;
    }

    void register_course(Course* course) {
        registered_course.push_back(course);
    }

    void print_reg_course() {
        cout << "Registered courses for: " << Name << "\n";
        for (Course* course : registered_course) {
            course->print_Details();
        }
    }
   
};

int main() {
    string courseName, courseCode;
    int numcourses;

    cout << "Enter the number of courses in the university portal for offline pursuing:" << "\n";
    cin >> numcourses;
    cin.ignore();

    vector<offline_Course*> offline_Courses;

    for (int i = 1; i <= numcourses; ++i) {
        cout << "Enter the course details " << i << ": " << "\n";
        cout << "Course name: ";
        getline(cin, courseName);
        cout << "Course code: ";
        getline(cin, courseCode);

        offline_Course* course = new offline_Course(courseName, courseCode);
        course->print_Details();
        offline_Courses.push_back(course);
    }
    cout << "Enter the number of course in the univerity portal for online section:" << "\n";
    cin >> numcourses;
    cin.ignore();
    vector<online_Course* >online_Courses;
    for (int i = 1; i <= numcourses; ++i) {
        cout << "Enter the courses details:" << "\n";
        cout << "course Name: ";
        getline(cin, courseName);
        cout << "Course code: ";
        getline(cin, courseCode);
        online_Course* course = new online_Course(courseName, courseCode);
        course->print_Details();
        online_Courses.push_back(course);
    }
 

    string Name, UID, Section, Password;
    cout << "Enter the user credential:" << "\n";
    cout<<"Name: ";
    getline(cin, Name);
    cout << "UID: ";
    getline(cin, UID);
    cout << "Section: ";
    getline(cin, Section);
    cout << "Password: ";
    getline(cin, Password);
    student s1(Name, UID, Section, Password);

    string regcourse_code;
    cout << "Enter the course code for which you want to register:" << "\n"; 
    cout << "Regcourse_code: ";
    getline(cin, regcourse_code);

    bool found = false;
    for (auto& course : offline_Courses) {
        if (course->getcoursecode() == regcourse_code) {
            s1.register_course(course);
            found = true;
            break;
        }
      }
    for (auto& course : online_Courses) {
        if (course->getcoursecode() == regcourse_code) {
            s1.register_course(course);
            found = true;
            break;
        }
    }
    if (found) {
        cout << "Course registered successfully!\n";
    }
    else {
        cout << "Course code not found. Registration failed.\n";
    }

    s1.print_reg_course();

    for (auto course : offline_Courses) {
        delete course;
    }
    for (auto course : online_Courses) {
        delete course;
    }

    return 0;
}
