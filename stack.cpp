#include <iostream>
using namespace std;

template <typename T>

class Stack
{

public:

    Stack() {

        m_name = "Mukuch";
        m_size = 0;
        m_capacity = 1;
        m_stack = new T[m_capacity];

    }

    Stack(string name) {

        m_name = name;
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
        cout << m_name << " deleted" << endl;
    }


public:

    Stack operator+ (const Stack& other) {

        Stack tmp("gag");        

        const int length = (m_size <= other.m_size) ? m_size : other.m_size;
        

        for(int i = 0; i < length; i++) {
            tmp.push(m_stack[i] + other.m_stack[i]);
        }
        
        return tmp;
    }

    Stack operator- (const Stack& other) {

        Stack tmp;        

        const int length = (m_size <= other.m_size) ? m_size : other.m_size;
        
        for(int i = 0; i < length; i++) {
            tmp.push(m_stack[i] - other.m_stack[i]);
        }
        
        return tmp;
    }


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
    string m_name;


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

    string teststr = "test";
    string secondstr = "second";
    string plustr = "plu";

    Stack<int> test(teststr);


    test.push(7);
    test.push(33);
    test.push(21);

    Stack<int> second(secondstr);

    second.push(7);
    second.push(14);
    second.push(6);


    Stack<int> plu = test + second;

    Stack<int> vzg("vzg");

    cout << plu.top() << endl;

    cout << test.top() << endl;

    return 0;
}