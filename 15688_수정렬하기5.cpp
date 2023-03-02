#include<iostream>
using namespace std;
int N;
int arr[2000002];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        arr[tmp+1000001]++;
    }
    for(int i=0;i<=2000001;i++){
        if(arr[i]>0){
            for(int j=0;j<arr[i];j++){
                cout<<i-1000001<<'\n';
            }
        }
    }
    return 0;
}