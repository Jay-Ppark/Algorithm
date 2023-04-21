#include<iostream>
using namespace std;
int arr[15][15];
int main(void){
    int testcase;
    cin>>testcase;
    for(int i=0;i<=14;i++){
        int sum=0;
        for(int j=1;j<=14;j++){
            if(i==0){
                arr[i][j]=j;
            }
            else{
                sum+=arr[i-1][j];
                arr[i][j]=sum;
            }
        }
    }
    for(int i=0;i<testcase;i++){
        int k,n;
        cin>>k>>n;
        cout<<arr[k][n]<<'\n';
    }
    return 0;
}