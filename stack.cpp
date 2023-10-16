#include <iostream>
using namespace std;

template <typename T>

class Stack
{

public:

    Stack() {
        m_size = 0;
        m_capacity = 1;
        m_stack = new T[m_capacity];
    }

    Stack(const Stack& other) {

        m_size = other.size();

        m_capacity = other.m_capacity;

        m_stack = new T[m_capacity];
        

        for(int i = 0; i < m_size; i++) {
            m_stack[i] = other.m_stack[i];
        }

    }

    ~Stack() {
        delete[] m_stack;
    }


public:

    void push(T element) {
        
        if(m_size == m_capacity) {
            resize();
        }

        m_stack[m_size] = element;
        m_size++;
    }

    T top() const {
        return *(m_stack + m_size - 1);
    }

    void pop() {
        m_stack[m_size - 1] = 0;
        m_size--;
    }

    bool empty() const {
        return (m_size == 0);
    }

    const int size() const {
        return (m_size);
    }

private:

    int m_size;
    int m_capacity;
    T* m_stack;

    void resize() {
        
        m_capacity *= 2;
        
        T* tmp = new T[m_capacity];

        for(int i = 0; i < m_size; i++) {
            tmp[i] = m_stack[i];
        }

        delete[] m_stack;
        m_stack = tmp;
    }


};






int main() {

    Stack<int> test;


    test.push(7);
    test.push(33);
    test.push(1);

    Stack<int> second(test);


    cout << second.size() << endl;

    return 0;
}