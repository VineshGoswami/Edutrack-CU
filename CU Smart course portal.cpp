#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
using namespace std;
class Course {
public:
	virtual void print_Details() = 0;
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
	void print_Details() override{
		cout << "Name of course is: "<< course_Name <<"\n";
		cout << "Code of the course is: "<< course_Code << "\n";

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
	void print_Details() override{
		cout << "Name of te course is:" << course_Name << "\n";
		cout << "Code of te course is:" << course_Code << "\n";
	}

	class student {
	private:
		string Name;
		string UID;
		string Section;
		string Password;
		list< Course* > registered_course;
	public:
		student(string name, string uid, string section, string password) {
			Name = name;
			UID = uid;
			Section = section;
			Password = password;
		}
		void registered_course( Course* course) {
			registered_course.push_back(course);
		}
		void print_reg_course() {
			cout << "Registered course for :" << Name << "\n";
			for (Course* course : registered_course) {
				course->print_Details();
			}
		}

	};

};
int main() {



	return 0;
}