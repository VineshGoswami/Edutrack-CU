#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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


};
int main() {
	{
		offline_Course course1("c++", "23bcs103");
		course1.print_Details();
	}
	{
		online_Course course1("evs", "23bcs1998");
		course1.print_Details();
	}

	return 0;
}