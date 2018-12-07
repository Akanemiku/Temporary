//https://blog.csdn.net/niu2212035673/article/details/72805098
#include<iostream>

using namespace std;

template<class T>
class DynamicArray
{
public:
    //默认构造函数
    DynamicArray()
    {
        this->capacity_ = 100;
        this->size_ = 0;
        this->data_ = new T[this->capacity_];
    }
    //给定数组长度构造动态数组
    DynamicArray(size_t size)
    {
        this->capacity_ = 100;
        this->size_ = size;
        this->data_ = new T[this->capacity_];

    }
    //从数组中构造动态数组
    DynamicArray(T arr[], size_t size)
    {
        this->capacity_ = 100;
        this->size_ = size;
        this->data_ = new T[this->capacity_];
        for(int i=0;i<size;i++)
        {
            this->data_[i] = arr[i];
        }
    }
    //拷贝构造函数
    DynamicArray(const DynamicArray& rhs)
    {
        this->capacity_ = rhs.capacity_;
        this->size_ = rhs.size_;
        this->data_ = new T[this->capacity_];
        //拷贝数据
        for(int i=0;i<this->size_;i++)
        {
            this->data_[i] = rhs.data_[i];
        }
    }
    //复制运算符
    DynamicArray& operator=(const DynamicArray& arr)
    {
        if(this->data_!=NULL)
        {
            delete[] this->data_;
            this->data_ = NULL;
        }

        //分配内存
        this->size_ = arr.size_;
        this->capacity_ = arr.capacity_;
        this->data_ = new T[arr.capacity_];

        //拷贝数据
        for(int i=0;i<this->size_;i++)
        {
            this->data_[i] = arr.data_[i];
        }
        return *this;
    }
    //析构函数，释放内存
    ~DynamicArray()
    {
        cout << "调用析构函数" << endl;
        if (this->data_ != NULL)
        {
            delete[] this->data_;
            this->data_ = NULL;
        }
        this->capacity_ = 0;
        this->size_ = 0;
    }
    //检查动态数组容量，如果数组长度>=数组容量，重新分配内存空间，并将原始数据复制到新空间
    void check_capacity()
    {
        if(this->size_>=this->capacity_)
        {
            capacity_+=10;
            this->data_ = new T[this->capacity_];
            /*
            for(int i=0;i<this->size_;i++)
            {
                this->data_[i] = arr.data_[i];
            }*/
        }
    }
    //数组末尾添加一个元素
    void push_back(const T& item)
    {
        this->data_[this->size_] = item;
        this->size_++;
    }
        //删除最后一个元素
    void pop_back()
    {
        if(this->size_==0){return;}
        this->size_--;
    }
         //在pos位置插入元素
    void insert(size_t pos, const T& item)
    {
        if(pos<0 || pos>this->size_)
        {
            pos = this->size_;
        }
        for(int i=this->size_;i>=pos; i--)
        {
            this->data_[i+1]=this->data_[i];
        }
        this->data_[pos] = item;
        this->size_++;
    }
    size_t size() const
    {
        return size_;
    }
    size_t capacity() const
    {
        return capacity_;
    }
    //下标运算符重载[],返回pos位置的元素
    T& operator[](size_t pos)
    {
        if(pos<0 || pos>this->size_-1)
        {
            throw 0;
        }
        return this->data_[pos];
    }
private:
    T* data_; //数据指针
    size_t capacity_; //动态数组容量
    size_t size_; //动态数组长度
};
int main()
{
    return 0;
}





#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
    enum SortType { byname, byscore };
    static SortType sort_type;
    Student(string name, int score) :name_(name), score_(score) {}
    bool operator > (const Student& rhs)
    {
        if(sort_type==byname) {return name_ > rhs.name_;}
        else {return score_ > rhs.score_;}
    }
    bool operator < (const Student& rhs)
    {
       return !(*this > rhs);
    }
    friend ostream& operator<<(ostream& os, Student& student)
    {
        os<<"姓名："<<name_<<" "<<"学号："<<score_<<endl;
        return os;
    }
private:
    string name_;
    int score_;
};

template <class T>
bool greater_than(T x,T y)
{
    if(x>y){return true;}
    else return false;
}
template <class T>
bool less_than(T x,T y)
{
    if(x>=y){return false;}
    else return true;
}

void Print(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template <class T>
void bubble_sort(T arr[], int len, bool(*compare)(T&, T&));

Student::SortType Student::sort_type = Student::byscore;
int main() {
    int int_array[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(int_array) / sizeof(*int_array);
    cout << "origin int array:" << endl;
    Print(int_array, len);
    bubble_sort(int_array, len, greater_than);
    cout << "sort: ascending order:" << endl;
    Print(int_array, len);
    bubble_sort(int_array, len, less_than);
	cout << "sort: descending order:" << endl;
    Print(int_array, len);

    cout << "\n----------华丽的分割线 666-----------------\n" << endl;

    float float_array[] = { 17.5f, 19.1f, 0.6f, 1.9f, 10.5f, 12.4f, 3.8f, 19.7f, 1.5f, 25.4f, 28.6f, 4.4f, 23.8f, 5.4f };
    len = (int) sizeof(float_array) / sizeof(*float_array);
    cout << "origin float array:" << endl;
    Print(float_array, len);
    bubble_sort(float_array, len, greater_than);
    cout << "sort: ascending order:" << endl;
    Print(float_array, len);
    bubble_sort(float_array, len, less_than);
    cout << "sort: descending order:" << endl;
    Print(float_array, len);

    //cout << "\n----------华丽的分割线 666-----------------\n" << endl;

    //注释部分是关于C语言的字符串比较，需要重载模板函数，有兴趣可以做，没兴趣就当注释。
    /*const char* const_char_array[] = { "ye", "meng", "jie" };
    len = (int) sizeof(const_char_array) / sizeof(*const_char_array);
    cout << "origin float array:" << endl;
    Print(const_char_array, len);
    bubble_sort(const_char_array, len, greater_than);
    cout << "sort: ascending order:" << endl;
    Print(const_char_array, len);
    bubble_sort(const_char_array, len, less_than);
    cout << "sort: descending order:" << endl;
    Print(const_char_array, len);*/

    cout << "\n----------华丽的分割线 666-----------------\n" << endl;

    Student student_array[] = { Student("ye",100), Student("meng",60), Student("jie",70) };
    len = (int) sizeof(student_array) / sizeof(*student_array);
    //sort by name
    cout << "sort student object by name------" << endl;
    Student::sort_type = Student::byname;
    cout << "origin student array:" << endl;
    Print(student_array, len);
    bubble_sort(student_array, len, greater_than);
    cout << "sort by name: ascending order:" << endl;
    Print(student_array, len);
    bubble_sort(student_array, len, less_than);
    cout << "sort by name: descending order:" << endl;
    Print(student_array, len);

    cout << "\n----------华丽的分割线 666-----------------\n" << endl;

    //sort by score
    cout << "sort student object by score------" << endl;
    Student::sort_type = Student::byscore;
    cout << "origin student array:" << endl;
    Print(student_array, len);
    bubble_sort(student_array, len, greater_than);
    cout << "sort by score: ascending order:" << endl;
    Print(student_array, len);
    bubble_sort(student_array, len, less_than);
    cout << "sort by score: descending order:" << endl;
    Print(student_array, len);
    return 0;
}
