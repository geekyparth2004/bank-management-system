#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector <string> username;
vector<string> passwords;

void SignUp(string name, string uname, string p1, string p2){
    cout<<"Enter Your Name: ";
    getline(cin,name);
    cout<<endl<<"Create a user name: ";
    getline(cin,uname);
    username.push_back(uname);
    int n = username.size();
    for(int i=0; i<=n-2; i++){
        if(username[i] == username[n-1]) cout<<"Please enter another username"<<endl;
    }
    cout<<endl<<"Enter password: ";
    getline(cin,p1);
    cout<<endl<<"Re-enter the password: ";
    getline(cin,p2);
    if(p1 != p2) cout<<"Please recheck the password: ";
    else passwords.push_back(p1);
    cout<<endl<<"Submit";   
}

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
    int n; 
    cout<<"What you want to do ?"; 
    cout<<"Press 1 for SignUp and Press 2 for Login; 
    cin>>n; 

    if(n==1)
    {
        
    }
        
    
    string name, uname, pass, re_pass;
    SignIn(uname,pass)
    
}
