/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
template <typename T>
class DynamicArray
{
public:
    explicit DynamicArray(int size) :
        m_size{ size }, m_array{ new T[size] }
    {
        cout << "Constructor: dynamic array is created!\n";
    }

    virtual ~DynamicArray()
    {
        delete[] m_array;
        cout << "Destructor: dynamic array is destroyed!\n";
    }

    // 复制构造函数
    DynamicArray(const DynamicArray& rhs);
    DynamicArray(DynamicArray&& rhs);
    /*
    DynamicArray(const DynamicArray& rhs) :
        m_size{ rhs.m_size }
    {

        m_array = new T[m_size];
        for (int i = 0; i < m_size; ++i)
            m_array[i] = rhs.m_array[i];
        cout << "Copy constructor: dynamic array is created!\n";
    }
    */

    // 复制赋值操作符
    
    DynamicArray& operator=(const DynamicArray& rhs)
    {
        cout << "Copy assignment operator is called\n";
        if (this == &rhs)
            return *this;

        delete[] m_array;

        m_size = rhs.m_size;
        m_array = new T[m_size];
        for (int i = 0; i < m_size; ++i)
            m_array[i] = rhs.m_array[i];

        return *this;
    }
    


    // 索引运算符
    T& operator[](int index)
    {
        // 不进行边界检查
        return m_array[index];
    }

    const T& operator[](int index) const
    {
        return m_array[index];
    }

    int size() const { return m_size; }
private:
    T* m_array;
    int m_size;
};
template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& rhs) :
        m_size{ rhs.m_size }
    {

        m_array = new T[m_size];
        for (int i = 0; i < m_size; ++i)
            m_array[i] = rhs.m_array[i];
        cout << "Copy constructor: dynamic array is created!\n";
    }
template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& rhs) :
        m_size{ rhs.m_size }, m_array{rhs.m_array}
    {
        rhs.m_size = 0;
        rhs.m_array = nullptr;
        cout << "Move constructor: dynamic array is moved!\n";
    }
DynamicArray<int> arrayFactor(int size)
{
    DynamicArray<int> arr{ size };
    return arr;
}
int main()
{
    {
        DynamicArray<int> arr(10);
        arr = arrayFactor(10);
        //arr = arr1;
        //arr = arr1;
    }
    return 0;
}
