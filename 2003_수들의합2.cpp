#include<iostream>
using namespace std;
int arr[10000];
int main(void){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int low = 0;
    int high = 0;
    int sum = arr[0];
    int answer=0;
    while(low<=high && high < N){
        if(sum<M){
            high++;
            sum = sum + arr[high];
        }
        else if(sum==M){
            answer++;
            high++;
            sum = sum+arr[high];
        }
        else{
            sum=sum-arr[low];
            low++;
            if(low>high && low < N){
                high = low;
                sum = arr[low];
            }
        }
    }
    cout<<answer<<'\n';
    return 0;
}