#include <iostream>
using namespace std;

template <typename T>

class Vector
{

public:

    Vector() {
        m_capacity = 4;
        m_size = 0;
        m_arr = new T[m_capacity];
    }

    Vector(const Vector& other) {

        m_capacity = other.capacity();
        m_size = other.size();
        m_arr = new T[m_capacity];
        
        for(int i = 0; i < m_size; i++) {
            m_arr[i] = other.at(i);
        }

    }

    ~Vector() {
        delete[] m_arr;
    }

public:

    T& operator[] (int index) {
        return *(m_arr + index);
    }

    void operator= (const Vector& other) {
        
        delete[] m_arr;
        m_capacity = other.capacity();
        m_size = other.size();
        m_arr = new int[m_capacity];
        
        for(int i = 0; i < m_size; i++) {
            m_arr[i] = other.at(i);
        }

        return;
    }

    void push_back(const T element) {
        if(m_size == m_capacity) {
            resize_vector();
        }
        m_arr[m_size] = element;
        ++m_size;
        return;
    }

    void push_front(const T element) {

        while(m_size + 1 >= m_capacity) {
            resize_vector();
        }

        for(int i = m_size - 1; i >= 0; --i) {
            m_arr[i + 1] = m_arr[i];    
        }

        m_arr[0] = element;
        m_size++;
        return;

    }

    int size() const {
        return m_size;
    }

    int capacity() const {
        return m_capacity;
    }

    T& at(const int index) const {
        if(index < 0 || index >= m_size) {
            cout << "Index out of range" << endl;
            abort();
        }
        return *(m_arr + index);
    }

    int binary_search (T target)  const {
        int start = 0;
        int end = m_size - 1;

        while(start <= end){

            int middle = (end + start) / 2;

            if(m_arr[middle] == target){
                return middle;
            }
            else if(m_arr[middle] > target){
                end = middle - 1;
            }
            else if(m_arr[middle] < target){
                start = middle + 1;
            }
        }
        return -1;   
    }


private:

    int m_capacity;
    int m_size;
    T* m_arr;

    void resize_vector() {
        m_capacity *= 2;
        T* tmp = new T[m_capacity];
        for(int i = 0; i < m_size; i++) {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }

};


int main() {

    Vector<int> juju;
    juju.push_back(123);
    juju.push_back(9);
    juju.push_back(5);
    juju.push_back(2);
    juju.push_back(7);
    juju.push_back(8);

    Vector<int> copy = juju;
    

    Vector<string> strs;

    string first = "aie";

    strs.push_back(first);

    cout << strs.at(-9) << endl;

    return 0;
}
