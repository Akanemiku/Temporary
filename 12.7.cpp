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
        this->capacity_ = 10;
        this->size_ = 0;
        this->data_ = new T[this->capacity_];
    }
    //给定数组长度构造动态数组
    DynamicArray(size_t size)
    {
        this->capacity_ = 100;
        this->size_ = size_;
        this->data_ = new T[this->capacity_];

    }
    //从数组中构造动态数组
    DynamicArray(T arr[], size_t size)
    {
        
    }
    //拷贝构造函数
    DynamicArray(const DynamicArray& rhs)
    {
        this->capacity_ =  rhs.capacity_;
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
        this->capacity_ =  arr.capacity_;
        this->data_ = new T[arr.data_];

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
