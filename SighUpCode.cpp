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
int main()
{
    string name, uname, p1, p2;
    SignUp(name,uname,p1,p2);
}
