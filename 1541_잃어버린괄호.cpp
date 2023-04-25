#include<iostream>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int result=0;
    string tmp;
    bool isminus=false;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='+'){
            if(isminus){
                result-=stoi(tmp);
                tmp="";
            }
            else{
                result+=stoi(tmp);
                tmp="";
            }
        }
        else if(s[i]=='-'){
            if(isminus){
                result-=stoi(tmp);
                tmp="";
            }
            else{
                isminus=true;
                result+=stoi(tmp);
                tmp="";
            }
        }
        else{
            tmp+=s[i];
        }
    }
    if(isminus){
        result-=stoi(tmp);
    }
    else{
        result+=stoi(tmp);
    }
    cout<<result;
    return 0;
}