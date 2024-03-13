#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void Login_Menu_display();

class Username_Password{
        string Username;
        string Password;
        string E_mail;
        string First_Name;
        string Last_Name;
        string Full_Name;
        static int raw;
    public:
        Username_Password(){
            string UserName,PassWord,Email,FName,Lname;
            cout<<"Input your First Name\n";
            cin>>FName;
            First_Name = FName;
            cout<<"Input yout Last Name\n";
            cin>>Lname;
            Last_Name = Lname;
            cout<<"Input New Username\n";
            cin>>UserName;
            Username = UserName;
            cout<<"Input New Password\n";
            cin>>PassWord;
            Password = PassWord;
            cout<<"Input Your E-Mail\n";
            cin>>PassWord;
            E_mail = Email;

        }
    void Display_Account_Info(){
        cout<<"Username is : "<<Username<<endl;
        cout<<"Password is : "<<Password<<endl;
    }
    void Save_New_username_Password_To_File(){
        ofstream DB("UsernameDB.txt",ios::app);
        if (DB.is_open()){
            if (Chack_Existing_Username(Username)!= 0){
                Full_Name = First_Name +" "+Last_Name;
                DB << "First Name : "<<First_Name<<endl;
                DB << "Last Name  : "<<Last_Name<<endl;
                DB << "Username   : "<<Username<<endl;
                DB << "Password   : "<<Password<<endl;
                DB << "E-Mail     : "<<E_mail<<endl<<endl;
            
            cout<<"Wellcome To my App : "<<Full_Name<<endl;
            }
        }
    }
    int Chack_Existing_Username(string Username){
         int valid = 1;
        ifstream DB("UsernameDB.txt");
        if(DB.is_open()){
           string line;
           while(getline(DB,line)){
                stringstream ss(line);
                string word;
                while(ss>>word){
                    if(Username == word){
                        cout<<"Username has been taken!\n\n\n\n";
                        valid = 0;
                        break;
                    }
                }
           }
        };
        return valid;
    }
    
};



int main(){
    char C; 
    do{ 
          
        int Option_select;
        Login_Menu_display();
        cin>>Option_select;

        switch (Option_select){
            case 1:{
                cout<<"** Sign Up menu **\n\n";
                Username_Password User1;
                User1.Display_Account_Info();
                User1.Save_New_username_Password_To_File();
                break;
            }
            case 2:{
                cout<<"** log in Menu **\n\n";
            }
            default:{
                cout<<"Invalid Choice !";
                return 0;
                break;
            }
        }
        cout<<"wanna countinue? : (Y/N)\n";
        cin>>C;
        system("CLS");
    }while (C == 'Y'||'y');
    return 0;
}

void Login_Menu_display(){
    cout<<"Welcome To The APP\n"
        <<"To access The Programm,\t"
        <<"Select Option :\n"
        <<"1- Sign up.\n"
        <<"2- Log in.\n"
        <<"Choice : ";
}

