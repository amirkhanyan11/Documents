#include <iostream>

class String
{

public:

    String() {

        m_capacity = 10;
        m_size = 0;
        m_string = new char[m_capacity];

    }

    String (const char* str) {

        const char* t_str = str;

        while(*t_str) {
            m_size++, t_str++;
        }

        m_capacity = m_size * 2;

        m_string = new char[m_capacity];

        for(int i = 0; i < m_size; i++) {
            m_string[i] = str[i];
            
        }

    }
    
    ~String() {

        delete[] m_string;
        m_string = nullptr;

    }


public:

    void print() const {
        
        for(int i = 0; i < m_size; i++) {
            std::cout << m_string[i];
        }
        std::cout << '\n';

    }

    const char at(const int index) const {

        if(index < 0 || index >= m_size) {
            
            std::cout << "Index out of range" << std::endl;
            std::abort();

        }

        return m_string[index];
    }    

    const char* front() const {
        return m_string;
    }

    const char* back() const {
        return (m_string + m_size - 1);
    }

    const char* c_str() const {

        char* c_string = new char[m_size];

        int index = 0;

        while(m_string[index] != '\0') {

            c_string[index++] = m_string[index];

        }

        c_string[m_size] = '\0';

        return c_string;
    }

    bool empty() const {
        return (m_size == 0);
    }

    const int length() const {
        return (m_size);
    }

    const int size() const {
        return (m_size);
    }

    const int capacity() const {
        return m_capacity;
    }

    void reserve(const int len) {

        m_capacity += len;

        char* temp = new char[m_capacity];

        for(int i = 0; i < m_size; ++i) {

            temp[i] = m_string[i];

        }

        delete[] m_string;

        m_string = temp;
    }

    void shrink_to_fit() {
        
        m_capacity = m_size;

        char* temp = new char[m_capacity];

        for(int i = 0; i < m_size; ++i) {

            temp[i] = m_string[i];

        }

        delete[] m_string;

        m_string = temp;

    }

    void clear() {

        for(int i = 0; i < m_capacity; ++i) {

            m_string[i] = '\0';

        }
    }

    void insert(const int index, const char* target) {

        if(index < 0 || index > m_size) {
            
            std::cout << "Index out of range" << std::endl;
            std::abort();

        }

        const char* t_target = target;

        int target_length = 0;

        while(*t_target) {
            target_length++, t_target++;
        }
        
        if(m_size + target_length >= m_capacity) {
            resize();
        }

        m_size += target_length;
        
        char* temp = new char[m_capacity];


        for(int i = 0, j = 0, k = 0; i < m_size; i++) {

            if((i >= index) && (k + index <= target_length)) {
                temp[i] = target[k++];            
            }

            else {
                temp[i] = m_string[j++];
            }
        }

        delete[] m_string;

        m_string = temp;        

    }

    void insert(int index, const char element) {

        if(index < 0 || index >= m_size) {
            
            std::cout << "Index out of range" << std::endl;
            std::abort();

        }

        ++m_size;

        char* temp = new char[m_capacity];

        for(int i = 0, j = 0; i < m_size; i++) {

            if(i == index) {
                temp[index] = element;
            }

            else {
                temp[i] = m_string[j++];
            }

        }

        delete[] m_string;

        m_string = temp;
   
    }

    void erase(const int index, const int quantity) {

        if(index < 0 || index >= m_size || quantity == 0) {
            return;
        }

        char* temp = new char[m_capacity];

        for(int i = 0, j = 0; i < m_size; i++) {

            if(i >= index && i - index < quantity) {
                continue;
            }


            else {
                temp[j] = m_string[i];
                j++;
            }
        }

        m_size -= quantity;

        delete[] m_string;
        m_string = temp;
    }

    void erase(const int index) {

        bool flag = false;

        for(int i = 0 ; i < m_size - 1; i++) {

            if(i == index) {flag = true;}

            if(flag) {
                m_string[i] = m_string[i + 1];
            }
        }

        m_size--;
    }

    void push_back(const char element) {
        if(m_size == m_capacity) {
            resize();
        }
        m_string[m_size] = element;
        ++m_size;
        return;
    }

    void pop_back() {
        m_string[--m_size] = '\0';
    }

    void append(const char* str) {

        const char* t_str = str;
        int str_length = 0;

        while(*t_str) {
            str_length++, t_str++;
        }

        while(m_size + str_length >= m_capacity) {
            resize();
        }

        for(int i = m_size; i < m_size + str_length; i++) {

            m_string[i] = str[i - m_size];

        }

        m_size += str_length;

    }

    const char* substr(const char* target) const {
        
        for(int i = 0; i < m_size; ) {

            int j = 0;

            int i_backup = i;

            while(i < m_size && m_string[i] == target[j]) {
                j++, i++;

                if(target[j] == '\0') {
                    return (m_string + i - j);
                }
            }

            i = ++i_backup;
        }

        return nullptr;
    }


private:

    int m_capacity;
    int m_size;
    char* m_string;

    void resize() {

        m_capacity *= 2;
        
        char* temp = new char[m_capacity];

        for(int i = 0; i < m_size; ++i) {
            temp[i] = m_string[i];
        }

        delete[] m_string;
        m_string = temp;

    }


};


int main() {

    String test = "hello";

    test.print();

    std::cout << *test.front() << std::endl;

    return 0;
}
