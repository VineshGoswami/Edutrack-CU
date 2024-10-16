#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<unordered_map>
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
    string getcoursecode() override {
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

    string getcoursecode() override {
        return course_Code;
    }
};

class unicore_Course : public Course {
private:
    string course_Name;
    string course_Code;
public:
    unicore_Course(string name, string code) {
        course_Name = name;
        course_Code = code;
    }
    void print_Details() override {
        cout << "Name of the course is:" << course_Name << "\n";
        cout << "Code of the course is:" << course_Code << "\n";
    }
    string getcoursecode() override {
        return course_Code;
    }
};

class authenticator {
private:
    unordered_map<string, string> user_Credentials;
public:
    void insert(const string& username, const string& password) {
        if (user_Credentials.find(username) == user_Credentials.end()) {
            user_Credentials[username] = password;
            cout << "User " << username << " registered successfully.\n";
        }
        else {
            cout << "Username " << username << " already exists. Try a different one.\n";
        }
    }

    bool authenticate(const string& username, const string& password) {
        if (user_Credentials.count(username) && user_Credentials[username] == password) {
            cout << "Authentication successful for user " << username << "!\n";
            return true;
        }
        else {
            cout << "Authentication failed. Invalid username or password.\n";
            return false;
        }
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
    authenticator auth;
    string Name, UID, Section, Password;

    // User registration
    cout << "---- User Registration ----\n";
    cout << "Enter the user credentials to register:\n";
    cout << "Name: ";
    getline(cin, Name);
    cout << "UID: ";
    getline(cin, UID);
    cout << "Section: ";
    getline(cin, Section);
    cout << "Password: ";
    getline(cin, Password);
    auth.insert(Name, Password);

    // User login for course registration
    cout << "\n---- Sign in ----";
    string login_name, login_password;
    cout << "Enter your name: ";
    getline(cin, login_name);
    cout << "Enter your password: ";
    getline(cin, login_password);

    if (!auth.authenticate(login_name, login_password)) {
        cout << "Login failed. Exiting.\n";
        return 1;
    }

    // Student object created after successful login.
    student s1(Name, UID, Section, Password);

    // Course enrollmentregistration logic.
    string courseName, courseCode;
    int numcourses;

    cout << "Enter the number of courses in the university portal for offline pursuing:\n";
    cin >> numcourses;
    cin.ignore();

    vector<offline_Course*> offline_Courses;
    for (int i = 1; i <= numcourses; ++i) {
        cout << "Enter the course details " << i << ":\n";
        cout << "Course name: ";
        getline(cin, courseName);
        cout << "Course code: ";
        getline(cin, courseCode);
        offline_Course* course = new offline_Course(courseName, courseCode);
        course->print_Details();
        offline_Courses.push_back(course);
    }

    cout << "Enter the number of courses in the university portal for online section:\n";
    cin >> numcourses;
    cin.ignore();

    vector<online_Course*> online_Courses;
    for (int i = 1; i <= numcourses; ++i) {
        cout << "Enter the course details " << i << ":\n";
        cout << "Course name: ";
        getline(cin, courseName);
        cout << "Course code: ";
        getline(cin, courseCode);
        online_Course* course = new online_Course(courseName, courseCode);
        course->print_Details();
        online_Courses.push_back(course);
    }

    cout << "Enter the number of courses in the university portal for university core section:\n";
    cin >> numcourses;
    cin.ignore();

    vector<unicore_Course*> unicore_Courses;
    for (int i = 1; i <= numcourses; ++i) {
        cout << "Enter the course details " << i << ":\n";
        cout << "Course name: ";
        getline(cin, courseName);
        cout << "Course code: ";
        getline(cin, courseCode);
        unicore_Course* course = new unicore_Course(courseName, courseCode);
        course->print_Details();
        unicore_Courses.push_back(course);
    }

    string regcourse_code;
    cout << "Enter the course code for which you want to register:\n";
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
    for (auto& course : unicore_Courses) {
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
    for (auto course : unicore_Courses) {
        delete course;
    }

    return 0;
}
