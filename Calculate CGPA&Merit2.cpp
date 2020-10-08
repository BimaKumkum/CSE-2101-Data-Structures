#include<bits/stdc++.h>
#define course_number 3
using namespace std;

class CourseInfo{

  private:
    float course_gpa;
    float course_credit;

    void set_course_gpa(float GPA){
        course_gpa = GPA;
    }
    void set_course_credit(float Course_credit){
        course_credit = Course_credit;
    }

public:

    float get_course_gpa(){
        return course_gpa;
    }
    float get_course_credit(){
        return course_credit;
    }
    void set_course_information(float Course_gpa,float Course_credit){

        set_course_gpa(Course_gpa);
        set_course_credit(Course_credit);

    }
};

class Student{
private:
    CourseInfo course[course_number];
    int student_id;
    void set_student_id(int Student_id){
        student_id = Student_id;
    }

public:

    void get_student_information();

    int get_student_id(){
        return student_id;
       }
    float get_cgpa();
};

void Student::get_student_information(){
    int student_id;
    float course_gpa,course_credit;
    cout<<endl<<"Enter Student ID: ";
    cin>>student_id;
    set_student_id(student_id);
    for(int i=0;i<course_number;i++){
        cout<<endl<<"Enter course "<<i+1<<" Information : "<<endl;
       cout<<"\tCourse Credit: ";
        cin>>course_credit;
        cout<<"\tCourse GPA: ";
        cin>>course_gpa;
        course[i].set_course_information(course_gpa,course_credit);
    }
    cout<<endl;
}
float Student::get_cgpa(){
        float Total_GPA = 0.0,Total_Credit = 0.0;
        for(int i=0;i<course_number;i++){
            Total_GPA += course[i].get_course_gpa()*course[i].get_course_credit();
           Total_Credit += course[i].get_course_credit();
        }
        return (float)Total_GPA/Total_Credit;
    }


int main(){

    cout<<"Enter the number of Student: ";
    int number_of_student;
    cin>>number_of_student;
    Student student[number_of_student];

    for(int i=0;i<number_of_student;i++){
        student[i].get_student_information();
    }
    system("cls");
    int id;
    float temp;
    cout<<"Enter Student ID to find CGPA and Merit : "<<endl;
    cin>>id;
    for(int i=0;i<number_of_student;i++){
       if(id==student[i].get_student_id()){
            cout<<"\tStudent ID : "<<student[i].get_student_id()<<endl;
        cout<<"\tCGPA : "<<fixed<<setprecision(2)<<student[i].get_cgpa()<<endl;
        temp=student[i].get_cgpa();
       }
    }
    int merit =0;
    for(int i=0;i<number_of_student;i++){
       if(temp<student[i].get_cgpa()){
        merit++;
       }
    }
    cout<<"\tMerit : "<<merit+1<<endl;
    return 0;
}
