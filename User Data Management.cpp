#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int crd;

void Login_Menu_display();
void SignUp_menu();
void Signin_Menu();

class Username_Password{
        string Username;
        string Password;
        string E_mail;
        string First_Name;
        string Last_Name;
        string Full_Name;
        static int raw;
    public:
    void Creat_Username_Password(){
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
            cin>>Email;
            E_mail = Email;

        }
    int Login_Username_Password(){
        int Credential=0;
            string InputUsername,InutPassword;
            cout<<"Input Username :\n";
            cin>>InputUsername;
            cout<<"Input Password :\n";
            cin>>InutPassword;
            Username = InputUsername;
            Password = InutPassword;
            if(Check_Correct_Username(InputUsername)==0 && Check_Correct_Password(InutPassword)==0){
                    cout<<"Username And Password Correct!\n";
                    Credential=1;
            }
            else {cout<<"Username or Password is not correct\n";}
            return Credential;
        }
    void Display_Account_Info(){
        cout<<"Username is : "<<Username<<endl;
        cout<<"Password is : "<<Password<<endl<<endl;
    }
    int Save_New_username_Password_To_File(){
        int Credential =0;
        ofstream DB("UsernameDB.txt",ios::app);
        if (DB.is_open()){
            if (Check_Existing_Username(Username)!= 0){
                Full_Name = First_Name +" "+Last_Name;
                DB << "First Name : "<<First_Name<<endl;
                DB << "Last Name  : "<<Last_Name<<endl;
                DB << "Username   : "<<Username<<endl;
                DB << "Password   : "<<Password<<endl;
                DB << "E-Mail     : "<<E_mail<<endl<<endl;
            cout<<"Wellcome To my App : "<<Full_Name<<endl;
            Credential =1;
            }
            else { 
                Signin_Menu();
                }
        }
        DB.close();
        return Credential;
    }
    int Check_Existing_Username(string Username){
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
        DB.close();
        return valid;
    }
    int Check_Correct_Username(string Username){
         int valid = 1;
        ifstream DB("UsernameDB.txt");
        if(DB.is_open()){
           string line;
           while(getline(DB,line)){
                stringstream ss(line);
                string word;
                while(ss>>word){
                    if(Username == word){
                        valid = 0;
                        break;
                    }
                }
           }
        }
        DB.close();
        return valid;
    }
    int Check_Correct_Password(string Password){
         int valid = 1;
        ifstream DB("UsernameDB.txt");
        if(DB.is_open()){
           string line;
           while(getline(DB,line)){
                stringstream ss(line);
                string word;
                while(ss>>word){
                    if(Password == word){
                        valid = 0;
                        break;
                    }
                }
           }
        };
        DB.close();
        return valid;
    }

    
};


int main(){
    char countinue='y'; 
    while(countinue == 'Y' || countinue == 'y'){ 
          
        int Option_select;
        Login_Menu_display();
        cin>>Option_select;

        switch (Option_select){
            case 1:{
                SignUp_menu();
                break;
            }
            case 2:{
                Signin_Menu();
                break;
            }
            default:{
                cout<<"Invalid Choice!\n\n";
                break;
            }
        }
        cout<<"wanna countinue? : (Y/N)\n";
        cin>>countinue;
    }
    
    return crd;
}

void Login_Menu_display(){
    cout<<"**** Welcome To The APP ****\n\n"
        <<" To access The Programm,\n"
        <<"Select Option :\n"
        <<"-> 1- Sign up.\n"
        <<"-> 2- Log in.\n"
        <<"Choice : ";
}

void SignUp_menu(){
    cout<<"** Sign Up menu **\n\n";
                Username_Password User1;
                User1.Creat_Username_Password();
                User1.Display_Account_Info();
                crd = User1.Save_New_username_Password_To_File();
}
void Signin_Menu(){
                cout<<"** log in Menu **\n\n";
                Username_Password User2;
                
                crd = User2.Login_Username_Password();
}
