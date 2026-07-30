//design a programme to convert a prosseger implimantation of student record system into object oriented approach using class and object
#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
    string name;
    int rollno;
    float marks;

public:
void input(){
    cout<<"Enter the Roll no.";
    cin>>rollno;
    cin.ignore();
    getline(cin,name);
    cout<<"Enter marks";
    cin>>marks;

}
void display(){
    cout<<"Student Record"<<endl;
    cout<<"roll no : "<<rollno<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Marks : "<<marks<<endl;
    
}
};
int main(){
    Student s;   // Object of Student class

    s.input();   // Calling member function
    s.display(); // Calling member function

    
    return 0;
}