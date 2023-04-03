#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int solve(int M,int N,int x,int y){
    if(x==M){
        x=0;
    }
    if(y==N){
        y=0;
    }
    int l=lcm(M,N);
    for(int i=x;i<=l;i=i+M){
        if(i==0){
            continue;
        }
        if(i%N==y){
            return i;
        }
    }
    return -1;
}
int main(void){
    int testcase;
    cin>>testcase;
    for(int t=0;t<testcase;t++){
        int M,N,x,y;
        cin>>M>>N>>x>>y;
        cout<<solve(M,N,x,y)<<'\n';
    }
    return 0;
}