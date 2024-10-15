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
	void print_Details(){
		cout << "Name of course: "<< course_Name <<"\n";
		cout << "Code of the course is: "<< course_Code << "\n";

	}
};
int main() {
	offline_Course course1("c++", "23bcs103");
	course1.print_Details();

	return 0;
}