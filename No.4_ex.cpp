/*
定义一个平面点的类Point，x，y坐标设为私有成员变量；定义线段类Line，成员变量包括线段的两个端点、线段的长度，定义线段类Line的常成员函数
用于显示线段端点坐标和线段长度。完成两个类的构造函数和一些必要的成员函数，并在main函数中构建一个线段，调用常成员函数显示结果。
*/
#include<iostream>
#include<math.h>
using namespace std;

class Point
{
	public:
		Point(double x, double y);
		double getx() const {return x;};
		double gety() const {return y;};
		void display() const;
		
	private:
		double x, y;
};
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::display() const
{
	cout << "(" << getx() << "," << gety() << ")" << endl;
} 

class Line
{
	public:
		Line(double x1, double y1, double x2, double y2);
		void display() const;
		double getlength() const;
		
	private:
		Point point1_, point2_;
		double length_;
};
Line::Line(double x1, double y1, double x2, double y2):point1_(0, 0), point2_(0, 0)
{
	this->point1_ = *(new Point(x1, y1));
	this->point2_ = *(new Point(x2, y2));
	length_ = sqrt(pow(point1_.getx() - point2_.getx(), 2) + pow(point1_.gety() - point2_.gety() , 2));
}
void Line::display() const
{		
	cout<<"point1:";
	point1_.display();
	cout<<"point2:";
	point2_.display();
	cout<<"length = "<<getlength()<<endl;
}
double Line::getlength() const
{
	return sqrt(pow(point1_.getx() - point2_.getx(), 2) + pow(point1_.gety() - point2_.gety() , 2));
}

int main()
{
	cout<<"请输入两个坐标点:";
	double x1, x2, y1, y2;
	cin>>x1>>y1>>x2>>y2;
	
	Line line(x1, y1, x2, y2);
	line.display();
	
	return 0;
}
