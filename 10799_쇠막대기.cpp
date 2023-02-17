#include<iostream>
#include<stack>
using namespace std;
int main(void){
    string sen;
    cin>>sen;
    stack<int> s;
    int result=0;
    int lcnt=0;
    for(int i=0;i<sen.size();i++){
        if(sen[i]=='('){
            lcnt++;
        }
        else{
            if(sen[i-1]=='('){
                lcnt--;
                if(lcnt!=0){
                    result=result+lcnt;
                }
            }
            else{
                result++;
                lcnt--;
            }
        }
    }
    cout<<result;
    return 0;
}