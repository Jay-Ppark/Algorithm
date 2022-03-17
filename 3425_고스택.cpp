#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
vector<string> cmd;
vector<int> num;
int mnum = 1000000000;
void init(){
    cmd.clear();
    num.clear();
}
int main(void){
    while(true){
        init();
        string str;
        while(true){
            cin>>str;
            if(str=="QUIT"){
                return 0;
            }
            else if(str=="END"){
                break;
            }
            else if(str=="NUM"){
                int n;
                cin>>n;
                num.push_back(n);
            }
            cmd.push_back(str);
        }
        int testcase;
        cin>>testcase;
        for(int i=0;i<testcase;i++){
            int tmp;
            cin>>tmp;
            stack<int> s;
            s.push(tmp);
            bool isError = false;
            int index=0;
            for(int j=0;j<cmd.size();j++){
                if(cmd=="NUM"){
                    s.push(q[index]);
                    index++;
                }
                else if(cmd=="POP"){
                    if(s.empty()){
                        isError=true;
                    }
                    else{
                        s.pop();
                    }
                }
                else if(cmd=="INV"){
                    if(s.empty()){
                        isError=true;
                    }
                    else{
                        s.push(s.pop()*-1);
                    }
                }
                else if(cmd=="DUP"){
                    if(s.empty()){
                        isError=true;
                    }
                    else{
                        s.push(s.top());
                    }
                }
                else if(cmd=="SWP"){
                    if(s.size()<2){
                        isError=true;
                    }
                    else{
                        int first = s.pop();
                        int second = s.pop();
                        s.push(first);
                        s.push(second);
                    }
                }
                else if(cmd=="ADD"){
                    if(s.size()<2){
                        isError=true;
                    }
                    else{
                        int first = s.pop();
                        int second = s.pop();
                        if(abs(first+second)>mnum){
                            isError=true;
                        }
                        else{
                            s.push(first+second);
                        }
                    }
                }
                else if(cmd=="SUB"){
                    if(s.size()<2){
                        isError=true;
                    }
                    else{
                        int first = s.pop();
                        int second = s.pop();
                        else{
                            s.push(second-first);
                        }
                    }
                }
                else if(cmd=="MUL"){
                    if(s.size()<2){
                        isError=true;
                    }
                    else{
                        int first = s.pop();
                        int second = s.pop();
                        if(abs(first*second)>mnum){
                            isError=true;
                        }
                        else{
                            s.push(first*second);
                        }
                    }
                }
                else if(cmd=="DIV"){
                    if(s.size()<2){
                        isError=true;
                    }
                    else{
                        int first = s.pop();
                        int second = s.pop();
                        if(first==0){
                            isError=true;
                        }
                        else{
                            if(first>)
                        }
                    }
                }
                else if(cmd=="MOD"){
                    if(s.size()<2){
                        isError=true;
                    }
                    else{
                        int first = s.pop();
                        int second = s.pop();
                        if(abs(first*second)>mnum){
                            isError=true;
                        }
                        else{
                            s.push(first*second);
                        }
                    }
                }
            }
        }
    }
    return 0;
}