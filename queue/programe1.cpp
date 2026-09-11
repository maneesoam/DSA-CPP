#include <iostream>
using namespace std;
 class student{
        private:
            int rollno;
            string name;
            float marks;
    
        public:
        void setdata (int r, string n, float m) {
            rollno = r;
            name = n;
            marks = m;
        }
        void displaydata () {
            cout << "Roll No: " << rollno << endl;
            cout << "Name: " << name << endl;
            cout << "Marks: " << marks << endl;
        }
    };
         int main () {
            
        
            student s1;
            s1.setdata(1, "siya", 95.5);
            s1.displaydata();

            student s2;            
            s2.setdata(2, "sneha", 90.5);
            s2.displaydata();
            return 0;
        } 
        