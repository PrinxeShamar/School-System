#ifndef _student_h_
#define _student_h_

class Student {
public:
    Student(const string& _student_id, const string& _student_first_name,const string& _student_last_name) : 
      student_id(_student_id), 
      student_first_name(_student_first_name),
      student_last_name(_student_last_name)
    {}
    void print() const {
        cout << student_id << ":" << student_first_name << ":" << student_last_name << endl;
    }
private:
    string student_first_name;
    string student_last_name;
    string student_id;
};

#endif