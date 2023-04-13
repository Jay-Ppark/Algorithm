#include<iostream>
#include<stack>
using namespace std;
double arr[26];
int main(void){
    int N;
    cin>>N;
    string problem;
    cin>>problem;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    stack<double> s;
    for(int i=0;i<(int)problem.size();i++){
        if(problem[i]=='*'||problem[i]=='/'||problem[i]=='+'||problem[i]=='-'){
            double cur=s.top();
            s.pop();
            double prev=s.top();
            s.pop();
            if(problem[i]=='*'){
                s.push(prev*cur);
            }
            else if(problem[i]=='/'){
                s.push(prev/cur);
            }
            else if(problem[i]=='+'){
                s.push(prev+cur);
            }
            else{
                s.push(prev-cur);
            }
        }
        else{
            s.push(arr[problem[i]-'A']);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<s.top();
    return 0;
}