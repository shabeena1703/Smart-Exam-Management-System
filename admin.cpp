#include "admin.h"
#include <fstream>
#include<iomanip>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void admin::adminreg()
{
    ofstream file("admin.txt",ios::app);
    cout<<"Enter Admin username: ";
    cin>>username;

    cout<<"Enter Admin password: ";
    cin>>password;
    file << username <<" "<<password << endl;
    file.close();
    cout<<GREEN<<"Admin Registration Successful!" <<RESET<<endl;
}


void admin::adminlogin()
{
    string inputuser,inputpass;
    //cout<<"\n------------------------------------------------"<<endl;
    cout<<CYAN<<"---------------------ADMIN LOGIN----------------------"<<RESET<<endl;
    //cout<<"------------------------------------------------"<<endl;
    cout<<"Enter Username: ";
    cin>>inputuser;

    cout<<"Enter Password: ";
    cin>>inputpass;

    ifstream file("admin.txt");
    string fileuser,filepass;
    while(file>>fileuser>>filepass)
    {
        if(fileuser==inputuser && filepass==inputpass)
        {
            username=fileuser;
            password=filepass;

            cout<<GREEN<<"Login Successful!"<<RESET<<endl;
            file.close();
            adminmenu();
            return;
        }
    }
    file.close();
    cout<<RED<<"Invalid Login!"<<RESET<<endl;
}



void admin::adminmenu()

{
    int choice;
    do
    {
        cout<<CYAN;
        cout<<"\n------------------------------------------------"<<endl;
        cout<<"                       ADMIN MENU                 "<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<RESET;
        cout<<YELLOW<<"1. Add Question"<<RESET<<endl;
        cout<<YELLOW<<"2. Modify Question"<<RESET<<endl;
        cout<<YELLOW<<"3.View All Results"<<RESET<<endl;
        cout<<YELLOW<<"4.Logout"<<RESET<<endl;
        cout<<YELLOW<<"5.Exit"<<RESET<<endl;

        cout<<"Enter the choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            addques();
            break;

            case 2:
            modifyques();
            break;

            case 3:
            viewallresults();
            break;

            case 4:
            cout<<GREEN<<"Logged out Successfully"<<RESET<<endl;
            break;

            case 5:
            cout<<GREEN<<"Exited Successfully from the site"<<RESET<<endl;
            break;

            default:
            cout<<RED<<"Invalid Choice"<<RESET<<endl;

        }
    }while(choice!=5);
}



void admin::addques()
{
    ofstream file("questions.txt",ios::app);
    string question,A,B,C,D;
    char correct;
    cin.ignore(1000,'\n');

    cout<<"Enter Question: ";
    getline(cin,question);

    cout<<"Enter option A:";
    getline(cin,A);

    cout<<"Enter option B: ";
    getline(cin,B);

    cout<<"Enter option C: ";
    getline(cin,C);

    cout<<"Enter option D; ";
    getline(cin,D);

    cout<<"Enter correct answer(A/B/C/D): ";
    cin>>correct;

    file<<question<<endl;
    file<<A<<endl;
    file<<B<<endl;
    file<<C<<endl;
    file<<D<<endl;
    file<<correct<<endl;

    file.close();
    cout<<GREEN<<"Question Added Successfully"<<RESET<<endl;
}



void admin::modifyques()
{

}



void admin::viewallresults()
{
    ifstream file("results.txt");
    int id;
    string name;
    string marks;
    string percentage;
    string status;
    cout<<MAGENTA;
    cout<<"\n-------------------------------------------------"<<endl;
    cout<<"              ALL STUDENTS RESULTS                "<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<RESET;

    cout<<CYAN;
    cout<<left
    <<setw(10)<<"ID"
    <<setw(20)<<"Name"
    <<setw(12)<<"Percentage"
    <<setw(10)<<"Status"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<RESET;
    while(file>>id>>name>>marks>>percentage>>status)
    {
        cout<<left
        <<setw(10)<<id
        <<setw(20)<<name
        <<setw(12)<<percentage
        <<setw(10)<<status<<endl;
    }
    file.close();
}