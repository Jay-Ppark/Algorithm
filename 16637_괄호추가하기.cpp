#include<iostream>
#include<string>
using namespace std;
int N;
string s;
int num[10];
char oper[9];
int main(void){
    cin>>N;
    cin>>s;
    int numindex=0;
    int operindex=0;
    for(int i=0;i<s.length();i++){
        if(i%2==0){
            oper[operindex]=s[i];
            operindex++;
        }
        else{
            num[numindex]=atoi(s[i]);
        }
    }
    return 0;
}