#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector <string> username;
vector<string> passwords;


void SignIn(string uname, string pass){
    cout<<"Enter your username: ";
    cin>>uname;
    cout<<endl<<"Enter your password: ";
    cin>>pass;
    int a = 0;
    for(int i=0; i<username.size(); i++){
        if(username[i]==uname) a = 1;
    }
    int b = 0;
    for(int i=0; i<passwords.size(); i++){
        if(passwords[i]==pass) b = 1;
    }
    if(a==1 && b==1){
        cout<<endl<<"Login successful";
    }
    else{
        cout<<endl<<"Incorrect username or password, please try again";
    }
}
int main(){
    string name, uname, pass, re_pass;
    SignIn(uname,pass);
}