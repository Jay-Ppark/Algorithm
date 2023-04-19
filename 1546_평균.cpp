#include<iostream>
using namespace std;
double score[1000];
int main(void){
    int N;
    cin>>N;
    int tmpmax=0;
    for(int i=0;i<N;i++){
        cin>>score[i];
        if(score[i]>tmpmax){
            tmpmax=score[i];
        }
    }
    double sum=0;
    for(int i=0;i<N;i++){
        sum+=(score[i]/tmpmax)*100;
    }
    cout<<sum/N;
    return 0;
}