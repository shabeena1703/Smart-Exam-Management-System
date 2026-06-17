#include<iostream>
#include "student.h"
#include "admin.h"


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
using namespace std;
int main()
{
    int choice;
    student studentobj;
    admin adminobj;
    do
    {
        cout<<BLUE;
        cout<<"------------------------------------------------"<<endl;
        cout<<"                ONLINE EXAMINATION             "<<endl;  
        cout<<"------------------------------------------------"<<endl;
        cout<<RESET;

        cout<<YELLOW <<"1.Admin registration"<< RESET <<endl;  
        cout<<YELLOW <<"2.Admin login"<< RESET << endl; 
        cout<<YELLOW <<"3.student registration"<< RESET <<endl;
        cout<<YELLOW <<"4.student login"<< RESET <<endl;
        cout<<YELLOW <<"5.Exit"<< RESET <<endl; 
        
        cout<<"Enter the choice"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            adminobj.adminreg();
            break;

            case 2:
            adminobj.adminlogin();
            break;

            case 3:
            studentobj.studentreg();
            break;

            case 4:
            studentobj.studentlogin();
            break;

            case 5:
            cout<<GREEN <<"Successfully Exited from the site"<<RESET <<endl;
            break;
            default:
            cout<<RED <<"Invalid choice"<<endl;
        }

    }while(choice!=5);
    return 0;
}