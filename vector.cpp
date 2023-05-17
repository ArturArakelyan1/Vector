#include<iostream>

template<typename T >
class Vector{
private:
    T* m_data{};
    int m_topindex {0};
    int m_capacity {0};

public:
    Vector<T>(int number)
    {
        m_capacity = number * 2;
        m_data = new T [m_capacity];
        m_topindex = -1;
    };
    ~Vector<T>()
    {
        delete[] m_data;
        m_data = nullptr;
    }
    void PushBack(int value)
    {
        if(m_topindex == m_capacity - 1)
        {
            m_capacity *= 2;
            T* tmp = new T [m_capacity];
            for (size_t i = 0; i <= m_topindex; i++)
            {
                tmp[i] = m_data[i];
            }
            delete[] m_data;
            m_data = tmp;
        }
        m_topindex++;
        m_data[m_topindex] = value;
    }

    void Erase(int index)
    {
        if (index == m_topindex)
        {
            m_topindex--;
        }
        else
        {
            for (size_t i = index; i < m_topindex; i++)
            {
                m_data[i] = m_data[i+1];
            }
            this -> PopBack();
        }
        
    }

     int Find( int vlaue)
    {
        for (size_t first = 0; first != m_topindex; first++)
        {
            if (m_data[first] == vlaue)
            {
                return first;
            }
            
        }
        return m_topindex;
    }
    void PopBack()
    {
        T* tmp = new T [m_topindex  - 1];
        for (size_t i = 0; i < m_topindex; i++)
        {
            tmp[i] = m_data[i];
        }
        m_topindex--;
        delete[] m_data;
        m_data = tmp;

    }

T& operator[](int index)
{
    return m_data[index];
}
};
