#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include<string>
using namespace std;

class admin
{
    private:
    string username;
    string password;
    public:
    void adminreg();
    void adminlogin();
    void adminmenu();
    void addques();
    void modifyques();
    void viewallresults();

};

#endif