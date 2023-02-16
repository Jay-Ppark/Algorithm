#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        string s;
        getline(cin,s);
        if(s=="."){
            break;
        }
        stack<char> sc;
        bool isValid=true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                sc.push('(');
            }
            else if(s[i]=='['){
                sc.push('[');
            }
            else if(s[i]==')'){
                if(sc.empty()){
                    isValid=false;
                    break;
                }
                else if(sc.top()=='('){
                    sc.pop();
                }
                else{
                    isValid=false;
                    break;
                }
            }
            else if(s[i]==']'){
                if(sc.empty()){
                    isValid=false;
                    break;
                }
                else if(sc.top()=='['){
                    sc.pop();
                }
                else{
                    isValid=false;
                    break;
                }
            }
        }
        if(sc.empty()&&isValid){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}