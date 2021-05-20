#ifndef _department_h_
#define _department_h_

class Course;
class Department;
typedef map<string, Course*> COURSES;

class Course {
public:
    Course(const string& _course_name, const string& _course_code) :
      course_name(_course_name), 
      course_code(_course_code) 
    {}
    void print() const {
        cout << course_name << "-" << course_code << endl;
    }
private:
    string course_name;
    string course_code;
    friend class Department;
};

class Department {
public:
    Department(const string& _department_name,const string& _department_code) : 
      department_name(_department_name), 
      department_code(_department_code) 
    {}
    void add_course(const string& _course_name){
        string course_code = to_string(1000 + department_courses.size() * 10);
        Course* new_course = new Course(_course_name, course_code);
        department_courses.insert(make_pair(course_code, new_course));
    }
    void print() const {
        cout << department_code << ":" << department_name << endl;
        COURSES::const_iterator course_itr;
        for(course_itr = department_courses.begin(); course_itr != department_courses.end(); course_itr++){
            cout << "    " << department_code << '-' <<  course_itr->second->course_code << ':' << course_itr->second->course_name << endl;
        }
    }
private:
    COURSES department_courses;
    string department_name;
    string department_code;
};

#endif