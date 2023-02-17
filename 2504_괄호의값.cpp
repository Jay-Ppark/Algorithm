#include<iostream>
#include<stack>
using namespace std;
int main(void){
    string sentence;
    cin>>sentence;
    stack<char> s;
    int result=0;
    int tmp=1;
    bool isok=true;
    for(int i=0;i<sentence.size();i++){
        if(sentence[i]=='('){
            s.push('(');
            tmp=tmp*2;
        }
        else if(sentence[i]=='['){
            s.push('[');
            tmp=tmp*3;
        }
        else if(sentence[i]==')'){
            if(s.empty()||s.top()!='('){
                isok=false;
                break;
            }
            else{
                if(s.top()=='('){
                    s.pop();
                    if(sentence[i-1]=='('){
                        result=result+tmp;
                        tmp=tmp/2;
                    }
                    else{
                        tmp=tmp/2;
                    }
                }
            }
        }
        else if(sentence[i]==']'){
            if(s.empty()||s.top()!='['){
                isok=false;
                break;
            }
            else{
                s.pop();
                if(sentence[i-1]=='['){
                    result=result+tmp;
                    tmp=tmp/3;
                }
                else{
                    tmp=tmp/3;
                }
            }
        }
    }
    if(isok&&s.empty()){
        cout<<result;
    }
    else{
        cout<<0;
    }
}