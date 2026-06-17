#include "student.h"
#include<iostream>
#include<cstring>
#include<fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
using namespace std;

    void student::studentreg()
    {
        ofstream file("student.txt",ios::app);

        cout<<"Enter student ID: "<<endl;
        cin >> id;

        cout <<"Enter student name: "<<endl;
        cin >> name;

        cout<<"Enter password: "<<endl;
        cin >>password;

        file << id << " " << name << " " << password <<endl;
        file.close();
        cout<<GREEN <<"Registration Successful"<<RESET <<endl;
    }


    void student::studentlogin()
    {
        int inputid;
        string inputpass;

        cout<<CYAN <<"\n--------------STUDENT LOGIN-------------------"<<RESET <<endl;
        cout<<"Enter id: "<<endl;
        if(!(cin>>inputid))
        {
            cout<<RED <<"Invalid ID! ID should only contain numbers."<<RESET <<endl;
            cin.clear();     //ignore our wrong id
            cin.ignore(1000,'\n');
            return;
        }
        cout<<"Enter the password:"<<endl;
        cin>>inputpass;
        

        ifstream file("student.txt");

        int fileid;
        string filename;
        string filepass;
        while(file >> fileid>>filename>>filepass)
        {
            if(fileid==inputid && filepass==inputpass)
            {
                id=fileid;
                name=filename;
                password=filepass;
                cout<<GREEN <<"Login Successful!"<<RESET <<endl;
                file.close();
                studentmenu();
                return;
            }
        }
        file.close();
        cout<<"Invalid login!"<<endl;
    }



    void student ::studentmenu()
    {
        int choice;
        do
        {
            cout<<CYAN;
            cout<<"------------------------------------------------"<<endl;
            cout<<"                 Student Menu                   "<<endl;
            cout<<"------------------------------------------------"<<endl;
            cout<<RESET;

            cout<<YELLOW<<"1.Take Exam"<<RESET<<endl;
            cout<<YELLOW<<"2.View Result"<<RESET <<endl;
            cout<<YELLOW <<"3.Logout"<<RESET <<endl;
            cout<<YELLOW <<"4.Exit"<<RESET <<endl;
            cout<<"Enter choice:";
            cin>>choice;
            switch(choice)
            {
                case 1:
                takeexam();
                break;

                case 2:
                viewresult();
                break;

                case 3:
                cout<<GREEN<<"Logged out successfully!"<<RESET <<endl;
                break;

                case 4:
                cout<<GREEN <<"Exited successfully"<<RESET <<endl;
                break;

                default:
                cout<<RED <<"Invalid choice!"<<RESET<<endl;
            }
        }while(choice!=4);
    }



    void student::takeexam()
    {

        //check whether the student has already taken the exam or not
        ifstream checkfile("results.txt");

        int fileid;
        string filename;
        string filemarks;
        string filepercentage;
        string filestatus;
         while(checkfile >> fileid >> filename >> filemarks >> filepercentage >> filestatus)
        {
            if(fileid == id)
            {
                cout <<CYAN<<"You have already taken the exam." <<RESET << endl;
                cout << CYAN <<"Please contact the admin if you want to retake the exam." <<RESET<< endl;

                checkfile.close();
                return;
            }
        }
        checkfile.close();

        //if student has not taken the exam,then start the exam
        ifstream file("questions.txt");
        if(!file)
        {
            cout<<RED"Question file is not found!"<<RESET<<endl;
            return;
        }
        string question,A,B,C,D;
        char correct,answer;
         marks=0;
         ques_no=0;
        
         cout<<MAGENTA;
        cout<<"------------------------------------------------"<<endl;
        cout<<"                   START EXAM                   \n";
        cout<<"------------------------------------------------"<<endl;
        cout<<RESET;

        while(getline(file,question))
        {
            getline(file,A);
            getline(file,B);
            getline(file,C);
            getline(file,D);

            file>>correct;
            file.ignore(1000,'\n');

            ques_no++;

            cout<<"\nQuestion " << ques_no <<endl;
            cout<<question<<endl;
            cout<< "A. "<< A << endl;
            cout<< "B. "<< B << endl;
            cout<< "C. "<< C << endl;
            cout<< "D. "<< D << endl;

            cout<<"Enter your answer: ";
            cin>>answer;
            if(answer==correct)
            {
                marks++;
            }
        }
        file.close();
        calculateResult();
    }



    void student::calculateResult()
    {
        cout<<BLUE<<"\n-----------RESULT----------\n"<<RESET;
        float percentage=(float(marks *100)) / ques_no;

        cout<<YELLOW<<"marks obtained : "<<marks<<"/"<<ques_no<<RESET<<endl;
        cout<<YELLOW<<"percentage is : "<<percentage<<"%"<<RESET<<endl;

        if(percentage>=40)
        {
            cout<<YELLOW"Status : PASS" <<RESET<<endl;
            
        }
        else
        {
            cout<<YELLOW<<"Status : FAIL" <<RESET<<endl;
        }

        ofstream file("results.txt", ios::app);

        file << id << " "<< name << " "<< marks << "/"<< ques_no << " "<< percentage << "% ";

        if(percentage >= 40)
        {
            file << "PASS";
        }
        else
        {
            file << "FAIL";
        }
        file<<endl;
        file.close();

    }




    void student::viewresult()
    {
        ifstream file("results.txt");
        int fileid;
        string filename;
        string marks;
        string status;
        string percentage;
        while(file >> fileid >> filename >> marks >> percentage >> status)
        {
            if(fileid==id)
            {
                cout<<MAGENTA;
                cout<<"------------------------------------------------"<<endl;
                cout <<"                YOUR RESULT                    "<<endl;
                cout<<"------------------------------------------------"<<endl;
                cout<<RESET;
                cout<<CYAN<< "ID          : " <<fileid <<RESET<<endl;
                cout<<CYAN<< "Name        : "<<filename <<RESET<<endl;
                cout<<CYAN<< "Marks       : "<<marks <<RESET<<endl;
                cout<<CYAN<< "percentage  : "<<percentage <<RESET<<endl;
                cout<< CYAN<<"Status      : "<<status<<RESET<<endl;
                file.close();
                return;
            }
        }
        cout<<RESET<<"No result found!" <<RESET<<endl;
        file.close();
    }



