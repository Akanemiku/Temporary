#include<iostream>
#include<string.h>
using namespace std;

class Birthday
{
	public:
		Birthday(){}
		Birthday(int year, int month, int day)
		{
			cout<<"Birthday has been build."<<endl;
			year_ = year;
			month_ = month;
			day_ = day;
		}
		void Print()
		{
			cout<<year_<<"/"<<month_<<"/"<<day_<<endl;
		}
		
	private:
		int year_;
		int month_;
		int day_;
};

enum Gender
{
	Male,
	Female
};
std::ostream& operator<<(std::ostream& os, Gender gender)
{
	switch (gender)  
    {  
    case Male:  
        os << "Male";  
        break;  
    case Female:  
        os << "Female";  
        break; 
	}
	return os;	
} 
class Person
{
	public:
		Person(){}
		Person(char* name, Gender gender, Birthday birth)
		{
			cout<<"Person has been build."<<endl;
			name_ = new char[strlen(name) + 1];
			strcpy(name_, name);
			gender_ = gender;
			birth_ = birth;
			
		}
		void Print()
		{
			cout<<"Name:"<<name_<<endl;
			cout<<"Gender:"<<gender_<<endl;
			cout<<"Birthday:";
			birth_.Print();
		}
		
	private:
		char* name_;
		Gender gender_;
		Birthday birth_;
};

class Teacher:virtual public Person
{
	public:
		Teacher(){}
		Teacher(char* name, Gender gender, Birthday birth, string title)
		{
			Person(name, gender, birth);
			cout<<"Teacher has been build."<<endl;
			title_ = title;
		}
		void Print()
		{
			Print();
			cout<<"Title:"<<title_<<endl;
		}
		void setTitle(string title)
		{
			title_ = title;
		}
		string getTitle()
		{
			return title_;
		}

	private:
		string title_;
};

class Student:virtual public Person
{
	public:
		Student(){}
		Student(char* name, Gender gender, Birthday birth, int score):Person(name, gender, birth)
		{
			cout<<"Student has been build."<<endl;
			score_ = score;
		}
		void Print()
		{
			Person::Print();
			cout<<"Score:"<<score_<<endl;
		}
	private:
		int score_;
};

class Graduate:public Student
{
	public:
		Graduate()
		{
		}
		Graduate(char* name, Gender gender, Birthday birth, int score, string advisor):Student(name, gender, birth, score),Person(name, gender, birth)
		{
			cout<<"Graduate has been build."<<endl;
			advisor_ = advisor;
		}
		void Print()
		{
			Student::Print();
			cout<<"Advisor:"<<advisor_<<endl;
		}
	private:
		string advisor_;
};

class Assistant:public Graduate, public Teacher
{
	public:
		Assistant()
		{
		}
		Assistant(char* name, Gender gender, Birthday birth, int score, string advisor, string title, string subject):Graduate(name, gender, birth, score, advisor),Teacher(name, gender, birth, title),Person(name, gender, birth) 
		{
			cout<<"Assistant has been build."<<endl;
			Teacher::setTitle(title);
			subject_ = subject;
		}
		void Print()
		{
			Graduate::Print();	
			cout<<"Title:"<<Teacher::getTitle()<<endl;
			cout<<"Subject:"<<subject_;
		}
	private:
		string subject_;
};

int main()
{ 	
	Birthday birth(1997, 9, 15);
	Assistant assistant("Rory", Male, birth, 100, "mengjie Ye", "Senior engineer", "Computer science");
	assistant.Print();
	
	
	return 0;
}
