#ifndef __REGISTRATIONSYSTEM_H
#define __REGISTRATIONSYSTEM_H
#include <string>
using namespace std;

class Course
{
	public:
	Course(int courseid = 0, string course = "null");
	int getId();
	string getCourse();
	private:
	int courseid;
	string course;
};

class Student
{
	public:
	Student(const int id = 0, const string firstName = "null", const string lastName = "null");
	void DeleteStudent();
	int getId();
	string getName();
	string getLastName();
	void deleteCourse();
	Course* cources;
	int count = 0;
	private:
	string name;
	string lastName;
	int id;
};

class RegistrationSystem
{
	public:
	RegistrationSystem();
	~RegistrationSystem();
	void addStudent(const int studentId, const string firstName, const string lastName);
	void deleteStudent(const int studentId);
	void addCourse(const int studentId, const int courseId, const string courseName);
	void withdrawCourse(const int studentId, const int courseId);
	void cancelCourse(const int courseId);
	void showStudent(const int studentId);
	void showCourse(const int courseId);
	int findStudentlocation(const int studentId);
	void showAllStudents();
	private:
	Student* findStudentpointer(const int studentId);
	int count = 0;
	int crsCount = 0;
	int findEnrolledCourse(const int studentId, const int courseId);
	int findCourse(const int courseId);
	Student* arrStu;
	Course* arrCrs;
};
#endif
