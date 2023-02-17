#include<iostream>
using namespace std;
long long int POW(long long int a,long long int b,long long int c){
    if(b==1){
        return a%c;
    }
    long long int v=POW(a,b/2,c);
    v=v*v%c;
    if(b%2==0){
        return v;
    }
    else{
        return v*a%c;
    }
}
int main(void){
    long long int a,b,c;
    cin>>a>>b>>c;
    cout<<POW(a,b,c);
    
    return 0;
}