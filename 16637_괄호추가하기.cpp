#include<iostream>
#include<string>
using namespace std;
int num[10];
char op[9];
int main(void){
    int N;
    cin>>N;
    string form;
    cin>>form;
    for(int i=0;i<N;i++){
        if(i%2==0){
            num[i]=form[i]-48;
        }
        else{
            op[i]=form[i];
        }
    }
    
    return 0;
}
//최대 괄호 개수 : 숫자 / 2