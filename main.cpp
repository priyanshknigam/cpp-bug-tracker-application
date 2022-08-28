//Created By: Priyansh Kumar Nigam
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <ctime>
#include <fstream>

using namespace std;

void createbug (int id)
{
    cout<<"******************\nCreate Bug Option selected\n******************"<<endl;
    time_t curr_time;
    curr_time = time(NULL);
    
    char*tm = ctime(&curr_time);
    
    char t[20] {}, typepfbug[50] {}, description[1000] {}, priority[25] {};
    string title;
    int stat {};
    cout<<"Enter Name: "<<endl;
    cin.ignore();
    cin.getline(t, 20);
    title = t;
    string ids= to_string(id);
    title = title + ids;
    string ext = ".txt";
    title = title + ext;
    cout<<"File Title: "<<title<<endl;
    ofstream
    file_one(title);
    file_one<<"Date and Time: "<<tm<<endl;
    file_one<<"Bug ID: "<<id<<endl;
    cout<<"Bug ID: "<<id<<endl;
    file_one<<"Reported By: "<<title<<endl;
    cout<<"Enter Bug Type: "<<endl;
//    cin.ignore();
    cin.getline(typepfbug, 50);
    cout<<"Enter Bug Priority: "<<endl;
//    cin.ignore();
    cin.getline(priority, 25);
    cout<<"Enter Bug Description (in 1000 words): "<<endl;
//    cin.ignore();
    cin.getline(description, 1000);
    file_one<<"Bug Type: "<<typepfbug<<endl;
    file_one<<"Bug Priority: "<<priority<<endl;
    file_one<<"Bug Description: "<<description<<endl;
    file_one<<"\n\nBug Entry Date and Time: "<<tm;
    while (stat <=0 || stat >4)
    {
        cout<<"Select current status of the bug: "<<endl;
        cout<<"1. Not Yet Assigned\n2. In Progress\n3. Fixed"<<endl;
        cout<<"4. Delivered"<<endl;
        cout<<"Enter status number: "<<endl;
        cin>>stat;
        file_one<<"Bug Status: ";
        switch (stat) 
        {
            case 1:
                file_one<<"Not Yet Assigned"<<endl;
                break;
            case 2:
                file_one<<"In Progress"<<endl;
                break;
            case 3:
                file_one<<"Fixed"<<endl;
                break;
            case 4:
                file_one<<"Delivered"<<endl;
                break;
            default:
                cout<<"Invalid Selection"<<endl;
                break;
        }
         file_one.close();
    }
}

void changebugstat() 
{
    cout<<"******************\nChange Bug Status selected\n******************"<<endl;
    time_t curr_time;
    curr_time = time(NULL);
    
    char*tm = ctime(&curr_time);
    char filet[20] {};
    string filetitle;
    int stat {};
    cout<<"Enter File Name: "<<endl;
    cin.ignore();
    cin.getline(filet, 20);
    filetitle = filet;
    string ext = ".txt";
    filetitle += ext;
    fstream opfile;
    opfile.open(filetitle, ios::app);
    string line{}, filecontent {};
    if (opfile.is_open())
    {
//        cin.ignore()
//        while (getline(opfile, line))
//        {
//            filecontent = filecontent + line + "\n"
//        }
        
        opfile<<"\nBug Entry Date and Time: "<<tm;
        while (stat <=0 || stat >4)
        {
            cout<<"Select current status of the bug: "<<endl;
            cout<<"1. Not Yet Assigned\n2. In Progress\n3. Fixed"<<endl;
            cout<<"4. Delivered"<<endl;
            cout<<"Enter status number: "<<endl;
            cin>>stat;
            opfile<<"Bug Status: ";
            
            switch (stat) 
            {
                case 1:
                    opfile<<"Not Yet Assigned"<<endl;
                    break;
                case 2:
                    opfile<<"In Progress"<<endl;
                    break;
                case 3:
                    opfile<<"Fixed"<<endl;
                    break;
                case 4:
                    opfile<<"Delivered"<<endl;
                    break;
                default:
                    cout<<"Invalid Selection"<<endl;
                    break;
            }
            opfile.close();
        }
    }
    else
    {
        cout<<"Invalid file name"<<endl;
    }
}

void bugreport ()
{
    cout<<"******************\nGenerating Bug Report\n******************"<<endl;
    char filename[20];
    string fileline;
    cout<<"Enter file name: "<<endl;
    cin.ignore();
    cin.getline(filename, 20);
    strcat(filename, ".txt");
    fstream refile;
    refile.open(filename, ios::in);
    string line{}, filecontent {};
    if (refile.is_open())
    {
        while (getline(refile, fileline))
        {
            cout<<fileline<<endl;
        }   
    }
    else
    {
        cout<<"Invalid Filename"<<endl;
    }
}

int main() {
    int i {}, ch {}, id {};
    cout<<"***********************\nWelcome to Bug Traking System\n**************************"<<endl;
    
    while (i == 0)
    {
        cout<<"Press 1: To add a new bug"<<endl;
        cout<<"Press 2: To change the status of a bug"<<endl;
        cout<<"Press 3: To get bug report\nPress 4: To Exit\n"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                id++;
                createbug(id);
                break;
            case 2:
                changebugstat();
                break;
            case 3:
                bugreport();
                break;
            case 4:
                i=1;
                break;
        }
    }
    return 0;
}