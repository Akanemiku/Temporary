#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Student
{
public:
    void Account(double score) //设置成绩
    {
        score_ = score;
        total_score_ += score;
        count++;
    }
    static double Sum()        //返回成绩总和
    {
        return total_score_;
    }
    static double Average()    //求平均成绩
    {
        return total_score_/count;
    }
private:
    double score_;              //成绩
    static double total_score_;  //总成绩
    static double count;         //学生人数
};

double Student::total_score_ = 0;
double Student::count = 0;

int main()
{
  int n; //学生总数
  cin >> n; //键盘输入学生总数
  //创建学生动态数组
  Student *student = new Student[n];
  //可以从键盘输入学生成绩，也可以随机生成。
  for(int i=0;i<n;i++)
  {
     srand((int)time(NULL));
     student[i].Account(rand()%101);
  }
    cout<<"学生成绩之和："<<Student::Sum()<<endl;
    cout<<"学生平均分："<<Student::Average()<<endl;
  return 0;
}
