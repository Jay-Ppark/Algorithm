#include<iostream>
#include<stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<char> s;
    string problem;
    cin>>problem;
    for(int i=0;i<problem.size();i++){
        if(problem[i]=='('){
            s.push('(');
        }
        else if(problem[i]==')'){
            while(!s.empty()){
                char tmp=s.top();
                s.pop();
                if(tmp==')'){
                    break;
                }
                if(tmp=='('){
                    break;
                }
                cout<<tmp;
            }
        }
        else if(problem[i]=='+'||problem[i]=='-'){
            if(s.empty()){
                s.push(problem[i]);
            }
            else{
                while(!s.empty()){
                    char tmp=s.top();
                    if(tmp=='('){
                        break;
                    }
                    cout<<s.top();
                    s.pop();
                }
                s.push(problem[i]);
            }
        }
        else if(problem[i]=='*'||problem[i]=='/'){
            if(s.empty()){
                s.push(problem[i]);
            }
            else{
                while(!s.empty()&&(s.top()=='*'||s.top()=='/')){
                    char tmp=s.top();
                    if(tmp=='('){
                        break;
                    }
                    cout<<s.top();
                    s.pop();
                }
                s.push(problem[i]);
            }
        }
        else{
            cout<<problem[i];
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}