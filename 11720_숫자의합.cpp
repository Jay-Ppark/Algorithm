#include<iostream>
using namespace std;
int main(void){
    int tmp;
    cin>>tmp;
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<tmp;i++){
        sum+=(s[i]-'0');
    }
    cout<<sum;
    return 0;
}