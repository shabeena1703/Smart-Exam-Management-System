#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
using namespace std;
 class student
 {
    private:
        int id;
        string name;
        string password;
        int marks;
        int ques_no;
    public:
    void studentreg();
    void studentlogin();
    void studentmenu();
    void takeexam();
    void calculateResult();
    void viewresult();
 };
 #endif