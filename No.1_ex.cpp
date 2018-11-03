#include<iostream>
#include<string.h>
using namespace std; 

class Student  
{  
	public:  
	
	    enum Gender { Male,  Female }; //枚举类型，性别
	
	    //声明友元函数，用于将枚举类型输出文本形式  
	
	    friend std::ostream& operator<<(std::ostream& os, Gender gender);  
	
	    Student(); //无参数构造函数  
	
	    Student(const char* name, Gender gender); //带参数构造函数  
	
	    Student(const Student& student); //拷贝构造函数  
	
	    Student& operator= (const Student& student); //赋值运算符  
	
	    ~Student(); //析构函数  
	
	    void Show() const; //常成员函数  
	
	private:  
	
	    char* name_;    //名字  
	
	    Gender gender_; //性别  
	    
};
std::ostream& operator<<(std::ostream& os, Student::Gender gender)
{
//	cout<<"运算符重载"<<endl;                //出错 
	if(gender == Student::Male)
	  os<<"Male";
	else
	  os<<"Female";
	
	return os;
}
Student::Student()
{
	cout<<"调用默认构造函数"<<endl;
	gender_ = Male;
	name_ = new char[20];
	name_ = "Tomy";
}
Student::Student(const char* name, Gender gender) 
{
	cout<<"调用带参数构造函数"<<endl;
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);
	gender_ = gender;
}
Student::Student(const Student& student)
{
	cout<<"调用拷贝构造函数"<<endl;
	name_ = new char[strlen(student.name_) + 1];
	strcpy(name_, student.name_);
	gender_ = student.gender_;
}
Student& Student::operator=(const Student& student)
{
	cout<<"调用赋值运算符函数"<<endl;
	name_ = new char[strlen(student.name_) + 1];
	strcpy(name_, student.name_);
	gender_ = student.gender_;
	return *this;
}
Student::~Student()
{
    cout<<"调用析构函数"<<endl; 
	delete[] name_;
	cout<<"Delete successful"<<endl;
}
void Student::Show() const
{
//	name_ = "Tomy";     //不能在常成员函数里修改成员数据的值 
	cout<<"name："<<name_<<endl;
	cout<<"gender："<<gender_<<endl;
}

int main()
{
//	Student* student1 = new Student("Rory", Student::Male);                 //指针存储 
//	student1->Show();                                                      //指针间接调用 
//	cout<<"student1---------------------------------end"<<endl<<endl;;
//	
//	Student student2(*student1);
//	student2.Show();

    Student student1("Rory", Student::Male);                              //直接复制整块空间的首地址给student1 
	student1.Show();                                                     //间接调用 
	cout<<"student1---------------------------------end"<<endl<<endl;;
	
	Student student2(student1);
	student2.Show();
	cout<<"student2---------------------------------end"<<endl<<endl;
	
	Student student3 = student1;
	student3.Show();
	cout<<"student3---------------------------------end"<<endl<<endl;
	

	
	return 0;
}

 
