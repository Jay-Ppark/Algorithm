#include<iostream>
using namespace std;
int N;
int arr[1000000];
int tmp[1000000];
void merge(int st,int en){
    int mid=(st+en)/2;
    int lindex=st;
    int rindex=mid;
    for(int i=st;i<en;i++){
        if(rindex==en){
            tmp[i]=arr[lindex];
            lindex++;
        }
        else if(lindex==mid){
            tmp[i]=arr[rindex];
            rindex++;
        }
        else if(arr[lindex]<=arr[rindex]){
            tmp[i]=arr[lindex];
            lindex++;
        }
        else{
            tmp[i]=arr[rindex];
            rindex++;
        }
    }
    for(int i=st;i<en;i++){
        arr[i]=tmp[i];
    }
}
void mergesort(int st,int en){
    if(st+1==en){
        return;
    }
    int mid=(st+en)/2;
    mergesort(st,mid);
    mergesort(mid,en);
    merge(st,en);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    mergesort(0,N);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}