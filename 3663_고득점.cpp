#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;
deque<int> dql;
deque<int> dqr;
string name;
vector<int> answer;
int tmpanswer=0;
int tmpleft=0;
int tmpright=0;
void checkalpha(){
    for(int i=0;i<name.size();i++){
        if(name[i]=='A'){
            continue;
        }
        else{
            if(name[i]-'A'<=13){
                tmpanswer=tmpanswer+name[i]-'A';
            }
            else{
                tmpanswer=tmpanswer+26-(name[i]-'A');
            }
            if(i!=0){
                dql.push_back(i);
                dqr.push_back(i);
            }
        }
    }
}
void checkleft(){
    int currentindex=dql.back();
    dql.pop_back();
    tmpleft=name.length()-currentindex;
    while(!dql.empty()){
        int right=dql.front()-currentindex;
        if(right<0){
            right=right+name.length();
        }
        int left=currentindex-dql.back();
        if(left<0){
            left=left+name.length();
        }
        if(left>right){
            currentindex=dql.front();
            dql.pop_front();
            tmpleft=tmpleft+right;
        }
        else{
            currentindex=dql.back();
            dql.pop_back();
            tmpleft=tmpleft+left;
        }
    }
}
void checkright(){
    int currentindex=dqr.front();
    dqr.pop_front();
    tmpright=currentindex;
    while(!dqr.empty()){
        int right=dqr.front()-currentindex;
        if(right<0){
            right=right+name.length();
        }
        int left=currentindex-dqr.back();
        if(left<0){
            left=left+name.length();
        }
        if(left>right){
            currentindex=dqr.front();
            dqr.pop_front();
            tmpright=tmpright+right;
        }
        else{
            currentindex=dqr.back();
            dqr.pop_back();
            tmpright=tmpright+left;
        }
    }
}
int main(void){
    int testcase;
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        cin>>name;
        checkalpha();
        if(!dql.empty()){
            checkleft();
            checkright();
        }
        if(tmpleft<tmpright){
            answer.push_back(tmpleft+tmpanswer);
        }
        else{
            answer.push_back(tmpright+tmpanswer);
        }
        tmpanswer=0;
        tmpleft=0;
        tmpright=0;
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<'\n';
    }
    return 0;
}