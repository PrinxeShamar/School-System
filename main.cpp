#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

#include "department.h"
#include "student.h"

typedef map<string, Department*> DEPARTMENTS;
typedef map<string, Student*> STUDENTS;

void create_depts(DEPARTMENTS& depts, istream& depts_data){
    string line;
    while(getline(depts_data, line)){
        stringstream ss(line);
        string dept_code, dept_name;
        getline(ss, dept_code, ',');
        getline(ss, dept_name, ',');

        Department* new_department = new Department(dept_name, dept_code);
        depts.insert(make_pair(dept_code, new_department));
    }
}

void create_courses(DEPARTMENTS& depts, istream& courses_data){
    string line;
    while(getline(courses_data, line)){
        stringstream ss(line);
        string dept_code, course_name;
        getline(ss, dept_code, ',');
        getline(ss, course_name, ',');
        
        DEPARTMENTS::iterator dept_itr = depts.find(dept_code);
        
        if(dept_itr == depts.end()){
            cerr << "Department " << dept_code << " not found." << endl;
            exit(1);
        }
        dept_itr->second->add_course(course_name);
    }
}

void create_students(STUDENTS& students, istream& students_data){
    string line;
    while(getline(students_data, line)){
        stringstream ss(line);
        string student_first_name, student_last_name;
        getline(ss, student_first_name, ',');
        getline(ss, student_last_name, ',');
        
        string student_id = to_string(1000 + students.size());
        Student* new_student = new Student(student_id, student_first_name, student_last_name);
        students.insert(make_pair(student_id, new_student));
    }
}

int main(){

    DEPARTMENTS depts;
    STUDENTS students;

    string command;
    while(cin >> command){
        if(command == "create"){
            string data_type, data_file_name;
            cin >> data_type >> data_file_name;
            ifstream data_file(data_file_name);
            if(!data_file.good()){
                cerr << "Error Opening " << data_file_name << "." << endl;
                exit(1);
            }
            if(data_type == "depts"){
                create_depts(depts, data_file);
            }else if(data_type == "courses"){
                create_courses(depts, data_file);
            }else if(data_type == "students"){
                create_students(students, data_file);
            }
        }else if(command == "print"){
            string data_type;
            cin >> data_type;
            if(data_type == "depts"){
                cout << "Departments:" << endl;
                DEPARTMENTS::iterator dept_itr;
                for(dept_itr = depts.begin(); dept_itr != depts.end(); dept_itr++){
                    cout << "  ";
                    dept_itr->second->print();
                }
            }else if(data_type == "students"){
                cout << "Students:" << endl;
                STUDENTS::iterator student_itr;
                for(student_itr = students.begin(); student_itr != students.end(); student_itr++){
                    cout << "  ";
                    student_itr->second->print();
                }
            }
        }
    }
}