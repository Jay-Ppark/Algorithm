// Quick Sort
#include<iostream>
using namespace std;
int n=10;
int arr[1001]={6,-8,1,12,8,3,7,-7,5,2};
void quicksort(int st,int en){
    if(en<=st+1){
        return;
    }
    int pivot=arr[st];
    int l=st+1;
    int r=en-1;
    while(1){
        while(l<=r && arr[l]<=pivot){
            l++;
        }
        while(l<=r && arr[r]>=pivot){
            r--;
        }
        if(l>r){
            break;
        }
        int tmp=arr[l];
        arr[l]=arr[r];
        arr[r]=tmp;
    }
    int tmp=arr[st];
    arr[st]=arr[r];
    arr[r]=tmp;
    quicksort(st,r);
    quicksort(r+1,en);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    quicksort(0,10);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}