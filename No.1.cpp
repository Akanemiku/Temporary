#include <iostream>

using namespace std;
class Student
{
public:
    enum Gender { Male,  Female }; //枚举类型，性别
    //声明友元函数，用于将枚举类型输出文本形式
    friend std::ostream& operator<<(std::ostream& os, Gender gender)
	{
		if(gender==Female)
			os<<"Female";
		else
			os<<"Male";
		return os;
	}
    Student(); //无参数构造函数
    Student(const char* name, Gender gender) //带参数构造函数
    {
        
    }
    Student(const Student& student) //拷贝构造函数
	{
		name_ = new char[strlen(Student.name_)+1];
		strcpy(name_,Student.name_);
		gender = Student.gender;
	}
    Student& operator= (const Student& student) //赋值运算符
	{
		if(this==student) reuturn *this;
		delete[] name_;
		name_ = new char[strlen(Student.name_)+1];
		strcpy(name_,Student.name_);
	}
    ~Student() //析构函数
    {

    }
    void Show() const; //常成员函数
private:
    char* name_;    //名字
    Gender gender_; //性别
};
int main()
{
    return 0;
}
