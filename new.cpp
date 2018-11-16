#include <iostream>
#include <string>
using namespace std;
class Birthday
{
    private:
        int day_;
        int month_;
        int year_;
    public:
        Birthday(){}
        Birthday(int day,int month,int year)
        {
            day_ = day;
            month_ = month;
            year_ = year;
        }
        void Print()
        {
            cout<<"Birthday:"<<year_<<" "<<month_<<" "<<day_<<endl;
        }
};
class Person
{
public:
    enum Gender { Male,  Female };
    Person(){}
    Person(Birthday birth,Gender gender,string name)
    {
        birth_ = birth;
        gender_ = gender;
        name_ = name;
    }
    void Print()
    {
        cout<<"Name:"<<name_<<
        " Gender:"<<gender_<<endl;
        birth_.Print();

    }
private:
    Birthday birth_;
    Gender gender_;
    string name_;
};
class Teacher:virtual public Person
{
public:
    Teacher(){}
    Teacher(Birthday birth,Gender gender,string name,string title)
    :Person(birth,gender,name)
    {

    }
    void Print()
    {

    }
private:
    string title_;
};
class Student:virtual public Person
{
public:
    Student(){}
    Student(Birthday birth,Gender gender,string name,int score)
    :Person(birth,gender,name)
    {

    }
    void Print()
    {

    }
private:
    int score_;
};
class Graduate:public Student
{
public:
    Graduate(){}
    Graduate(Birthday birth,Gender gender,string name,int score,string advisor):Student(birth,gender,name,score)
    {

    }
    void Print()
    {

    }
private:
    string advisor_;
};

class Assistant:public Graduate,public Teacher
{
public:
    Assistant(){}
    Assistant(Birthday birth,Gender gender,string name,int score,string advisor,string title)
    :Graduate(birth,gender,name,score,advisor)
    ,Teacher(birth,gender,name,title)
    {
        
    }
private:
    string subject_;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
