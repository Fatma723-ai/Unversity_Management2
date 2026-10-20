#include<bits/stdc++.h>
using namespace std;
class person
{
protected:
    int id;
    string name;
    public:
    person (int Id, string n)
    {
        id= Id;
        name= n;
    }
    virtual void display () =0;

};
class student :virtual public person
{
protected:
    string major;
    public:
    student (int Id, string n,string m):person (Id,n)
    {
       major =m;
    }
     void display ()
    {
           cout <<"ID= "<<id<< endl;
            cout <<"Name= "<<name<< endl;
            cout <<"Major= "<<major<< endl;
    }
    friend class UnversityAdmin;
};
class employee :virtual public person
{
   protected:
    double salary;
    public:
employee (int Id, string n,double s):person (Id,n)
    {
       salary = s;
    }
        void display ()
    {
          cout <<"ID= "<<id<< endl;
            cout <<"Name= "<<name<< endl;
            cout <<"Salary= "<<salary<< endl;
    }
    friend void compareslary(employee e1, employee e2);
};
class TeachingAssistant : public student, public employee
{
    public:
TeachingAssistant(int Id, string n,string m,double s):person (Id,n), student(Id,n,m), employee(Id,n,s)
    {

    }
        void display ()
    {
      cout <<"ID= "<<id<< endl;
            cout <<"Name= "<<name<< endl;
        cout <<"Major= "<<major<< endl;
            cout <<"Salary= "<<salary<< endl;
    }

};
    class  UnversityAdmin
    {
    public:
        void show_Information_Student( student s)
        {
                 cout <<"ID= "<<s.id<< endl;
            cout <<"Name= "<<s.name<< endl;
            cout <<"Major= "<<s.major<< endl;
        }
    };
   void compareslary(employee e1, employee e2)
   {
       if (e1.salary > e2.salary)
        cout<<e1.name <<  " earn more From " << e2.name<<endl;
         else if (e2.salary > e1.salary)
        cout<<e2.name <<  " earn more From " << e1.name<<endl;
        else
            cout<<e1.name <<" and "<<e2.name<<" Equal Salary "<<endl;
   }

int main()
{
student s1(101, "fatma","cs");

employee e1(102, "Ali",9000);

TeachingAssistant ta1(201, "Abdo","it",8000);


person *p;
p = &s1;
p->display();
cout<<"----------------------------"<<endl;

p = &e1;
p->display();
cout<<"----------------------------"<<endl;

p = &ta1;
p->display();
cout<<"----------------------------"<<endl;
employee e2(105, "Ahmed",20000);
compareslary(e1, e2);
cout<<"----------------------------"<<endl;
UnversityAdmin un;
un.show_Information_Student(s1);
    return 0;
}
