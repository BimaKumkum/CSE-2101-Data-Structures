#include<bits/stdc++.h>
using namespace std;


class CourseInfo{

    private:
         double CourseCredit;
         double CourseGPA;

    public:
        double setCredit(){
        cout<<"\tEnter Course Credit: ";
        cin>>CourseCredit;
        return CourseCredit;
        }

        double setGPA(){
        cout<<"\tEnter Course GPA: ";
        cin>>CourseGPA;
        return CourseGPA;
        }
};



class Student{

private:
    int StudentID;
    double cgpa;
    double Merit;

public:

    void setStudentID(int n){

        StudentID=n;
    }

    void setStudentcgpa(double cg)
    {
        cgpa = cg;
    }

    double ShowStudentID(){

       return StudentID;
    }

   double ShowStudentcgpa()
    {
        return cgpa;
    }

};



class StudentResult{

private:

    int StudentNum;
    int CourseNumber;
    int ID;
    double TotalCredit;
    double TotalGPA;
    double Cgpa;

public:

    StudentResult(){
    TotalCredit=0.0;
    TotalGPA=0.0;
    }

    Student s[100];
    CourseInfo c;

   void Result() {

       cout<<"Enter the number of student : ";
       cin>>StudentNum;

   for(int i=1;i<StudentNum+1;i++){

        TotalCredit=0.0;
        TotalGPA=0.0;
   ///Input Student ID
   cout<<endl<<"Enter Student ID: ";
   cin>>ID;
   s[i].setStudentID(ID);

   ///Input Course Details
   cout<<"Enter Student Course Number: ";
   cin>>CourseNumber;

   cout<<endl<<"Enter Course Information of Student ID "<<ID<<endl<<endl;
   for(int j=1;j<CourseNumber+1;j++)
   {
       cout<<"Course "<<j<<" Information:"<<endl;

       double crd = c.setCredit();
       TotalGPA = TotalGPA +(crd*c.setGPA());
       TotalCredit = TotalCredit+crd;
   }

   Cgpa = (double)(TotalGPA/TotalCredit);

   s[i].setStudentcgpa(Cgpa);

 }

}
   double findresult(int no){
       int merit=0;
   for(int i=1;i<StudentNum+1;i++)
   {
       if(s[i].ShowStudentID()==no){
            cout<<endl<<"Student ID :"<<s[i].ShowStudentID();
        cout<<endl<<"CGPA : "<<fixed<<setprecision(2)<<s[i].ShowStudentcgpa()<<endl;

       for(int j=1;j<=StudentNum;j++){
       if(s[i].ShowStudentcgpa()<s[j].ShowStudentcgpa())
       {
            merit++;
       }
       }
       cout<<"Merit :"<<merit+1<<endl;
       }
   }
   }

};

int main()
{
int id;
StudentResult obj;
obj.Result();
cout<<"------------------------------------------------------------------"<<endl;
cout<<endl<<"Enter Student ID to find CGPA and Merit : ";
cin>>id;
obj.findresult(id);

}

