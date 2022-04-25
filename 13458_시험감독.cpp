#include<iostream>
using namespace std;
int classes[1000000];
int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>classes[i];
    }
    int mainP, subP;
    cin>>mainP>>subP;
    long long int answer=0;
    for(int i=0;i<N;i++){
        if(classes[i]<=mainP){
            answer++;
        }
        else{
            if((classes[i]-mainP)%subP==0){
                answer=answer+(classes[i]-mainP)/subP;
            }
            else{
                answer=answer+(classes[i]-mainP)/subP;
                answer++;
            }
            answer++;
        }
    }
    cout<<answer;
    return 0;
}