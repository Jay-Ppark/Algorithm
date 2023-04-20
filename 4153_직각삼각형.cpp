#include<iostream>
using namespace std;
int main(void){
    while(true){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0){
            break;
        }
        int aa=a*a;
        int bb=b*b;
        int cc=c*c;
        if(abs(cc-bb)==aa){
            cout<<"right\n";
        }
        else if(abs(aa-cc)==bb){
            cout<<"right\n";
        }
        else{
            cout<<"wrong\n";
        }
    }
    return 0;
}