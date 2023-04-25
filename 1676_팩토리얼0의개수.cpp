#include<iostream>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int rest2=0;
    int rest5=0;
    for(int i=1;i<=N;i++){
        int x=i;
        while(x%2==0){
            rest2++;
            x=x/2;
        }
        x=i;
        while(x%5==0){
            rest5++;
            x=x/5;
        }
    }
    cout<<min(rest2,rest5);
    return 0;
}