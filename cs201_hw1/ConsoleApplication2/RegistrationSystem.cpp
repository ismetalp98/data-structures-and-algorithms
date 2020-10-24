#include <iostream>
using namespace std;
#include "RegistrationSystem.h"

Course::Course(int courseid, string course)
{
	Course::courseid = courseid;
	Course::course = course;
}


int Course::getId()
{
	return courseid;
}

string Course::getCourse()
{
	return course;
}

Student::Student(const int id, const string firstName, const string lastName)
{
	cources = new Course[10];
	Student::name = firstName;
	Student::lastName = lastName;
	Student::id = id;
}

void Student::DeleteStudent()
{
	cout << "deleted";
	delete[] cources;
}

void Student::deleteCourse()
{
	delete[] cources;
}

int Student::getId()
{
	return id;
}

string Student::getName()
{
	return name;
}

string Student::getLastName()
{
	return lastName;
}

RegistrationSystem::RegistrationSystem()
{
}

RegistrationSystem::~RegistrationSystem()
{
	for(int i = 0; i < count;i++)
	{
		arrStu[i].deleteCourse();
	}
	delete[] arrCrs;
	delete[] arrStu;
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName)
{
	bool have = false;
	if(firstName._Equal("") || lastName == "")
	{
		cout << "fill the gaps" << endl;
	}
	else
	{
		for(int i = 0; i < count; i++)
		{
			if(studentId == arrStu[i].getId())
			{
				cout << "Student " << studentId << " already exists" << endl;
				have = true;
				break;
			}
		}
	}
	if(!have)
	{
		if(count == 0)
		{
			Student stu(studentId, firstName, lastName);
			arrStu = new Student[1];
			arrStu[0].deleteCourse();
			arrStu[0] = stu;
			count++;
			cout << "Student " << studentId << " has been added " << endl;
		}
		else
		{	
			Student* tempt = arrStu;
			arrStu = new Student[count + 1];
			for(int i = 0; i < count; i++)
			{
				arrStu[i].deleteCourse();
				arrStu[i] = tempt[i];
			}
			delete[] tempt;
			if(studentId < arrStu[0].getId())
			{
				Student stu(studentId, firstName, lastName);
				arrStu[count].deleteCourse();
				for(int i = count; i > 0; i--)
				{
					arrStu[i] = arrStu[i - 1];
				}
				arrStu[0] = stu;
				count++;
				cout << "Student " << studentId << " has been added " << endl;
			}
			else if(studentId > arrStu[count-1].getId())
			{
				
				Student stu(studentId, firstName, lastName);
				arrStu[count].deleteCourse();
				arrStu[count] = stu;
				count++;
				cout << "Student " << studentId << " has been added " << endl;
			}
			else
			{
				for(int i = 0; i < count-1; i++)
				{
					if(studentId > arrStu[i].getId() && studentId < arrStu[i + 1].getId())
					{
						Student stu(studentId, firstName, lastName);
						arrStu[count].deleteCourse();
						for(int j = count; j > i+1; j--)
						{
							arrStu[j] = arrStu[j - 1];
						}
						arrStu[i+1] = stu;
						count++;
						cout << "Studen " << studentId << " has been added " << endl;
					}
				}
			}
		}	
	}
}

void RegistrationSystem::deleteStudent(const int studentId)
{
	Student* tempt = findStudentpointer(studentId);
	int location = findStudentlocation(studentId);
	if(tempt == NULL)
	{
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else
	{
		tempt->deleteCourse();
		for(int i = location; i < count-1;i++)
		{
			arrStu[i] = arrStu[i + 1];
		}
		cout << "Student " << studentId << " deleted" << endl;
		count--;
	}
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName)
{
	bool have = false;
	Student* tempt = findStudentpointer(studentId);
	if(tempt == NULL)
	{
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else
	{
		for(int i = 0; i < tempt->count; i++)
		{
			if(tempt->cources[i].getId() == courseId)
			{
				cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
				have = true;
			}
		}
		if(!have)
		{
			Course* temptCourse = arrCrs;
			arrCrs = new Course[crsCount + 1];
			for(int i = 0; i < crsCount; i++)
			{
				arrCrs[i] = temptCourse[i];
			}
			delete[] temptCourse;

			Course ctempt(courseId, courseName);
			tempt->cources[tempt->count] = ctempt;
			if(findCourse(courseId) == 0)
			{
				arrCrs[crsCount] = ctempt;
				crsCount++;
			}
			cout << "Course " << courseId << " has been added to student " << studentId << endl;
			tempt->count++;
		}
	}
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId)
{
	Student* tempt = findStudentpointer(studentId);
	if(tempt == NULL)
	{
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else if(findEnrolledCourse(studentId, courseId) == 0)
	{
		cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
	}
	else
	{
		int size = tempt->count;
		for(int i = 0; i < size; i++)
		{
			if(tempt->cources[i].getId() == courseId)
			{
				for(int j = i; j < size - 1; j++)
				{
					tempt->cources[j] = tempt->cources[j + 1];
					cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
					tempt->count = tempt->count - 1;
					break;
				}
			}
		}
	}
}

void RegistrationSystem::showAllStudents()
{
	cout << "Student id" << "   " << "Name  " << "   " << "Last Name" << endl;
	for(int i = 0; i < count; i++)
	{
		showStudent(arrStu[i].getId());
	}
}

void RegistrationSystem::cancelCourse(const int courseId)
{
	if(findCourse(courseId) != 0)
	{
		cout << "Course " << courseId << " has been cancelled" << endl;
		for(int i = 0; i < count; i++)
		{
			Student& tempt = arrStu[i];
			int size = tempt.count;
			for(int j = 0; j < size; j++)
			{
				if(tempt.cources[j].getId() == courseId)
				{
					for(int k = j; k < size - 1; k++)
					{
						tempt.cources[k] = tempt.cources[k + 1];
					}
					tempt.count = tempt.count - 1;
				}
			}
		}
	}
	else
		cout << "Course " << courseId << " does not exist" << endl;
}

void RegistrationSystem::showStudent(const int studentId)
{

	Student* tempt = findStudentpointer(studentId);
	if(tempt == NULL)
	{
		cout << "Student " << studentId << " does not exist" << endl;
	}
	else
	{
		int size = tempt->count;
		cout << tempt->getId() << "        " << tempt->getName() << "       " << tempt->getLastName() << endl;
		cout << "          " << "Course id" << "   Course Name" << endl;
		for(int i = 0; i < size; i++)
		{
			int courseid = tempt->cources[i].getId();
			string couse = tempt->cources[i].getCourse();
			cout << "            " << courseid << "         " << couse << endl;
			cout << endl;
		}
	}
}

void RegistrationSystem::showCourse(const int courseId)
{
	int control = findCourse(courseId);
	if(control != 0)
	{
		cout << "Course id" << "   Course Name" << endl;
		cout << arrCrs[control].getCourse() << "          " << arrCrs[control].getId()<<endl;
		for(int i = 0; i < count; i++)
		{
			for(int j = 0; j < arrStu[i].count; j++)
			{
				if(arrStu[i].cources[j].getId() == courseId)
				{
					cout<<arrStu[i].getId()<<"          "<<arrStu[i].getName()<<" "<< arrStu[i].getLastName()<<endl;
				}
			}
		}
	}
	else
		cout << "Course can not found" << endl;
}

Student* RegistrationSystem::findStudentpointer(const int studentId)
{
	for(int i = 0; i < count; i++)
	{
		if(arrStu[i].getId() == studentId)
		{
			return &arrStu[i];
		}
	}
	return NULL;
}

int RegistrationSystem::findStudentlocation(const int studentId)
{
	for(int i = 0; i < count; i++)
	{
		if(arrStu[i].getId() == studentId)
		{
			return i;
		}
	}
	return -1;
}



int RegistrationSystem::findEnrolledCourse(const int studentId, const int courseId)
{
	Student* tempt = findStudentpointer(studentId);
	int size = tempt->count;
	for(int i = 0; i < size; i++)
	{
		if(tempt->cources[i].getId() == courseId)
		{
			return 1;
		}
	}
	return 0;
}

int RegistrationSystem::findCourse(const int courseId)
{
	for(int i = 0; i < crsCount;i++)
	{
		if(arrCrs[i].getId() == courseId)
		{
			return i;
		}
	}
	return 0;
}