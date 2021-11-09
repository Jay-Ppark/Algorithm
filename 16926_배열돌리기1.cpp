#include<iostream>
using namespace std;
int arr[301][301];
int main(void){
    int height, width, rotate;
    cin>>height>>width>>rotate;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>arr[i][j];
        }
    }

    while(rotate>0){
        rotate--;
        int lux=0;
        int luy=0;
        int rux=width-1;
        int ruy=0;
        int rdx=width-1;
        int rdy=height-1;
        int ldx=0;
        int ldy=height-1;

        while(lux<rux && luy<ldy){

            int tmp=arr[luy][lux];
            for(int i=lux;i<rux;i++){
                arr[luy][i] = arr[luy][i+1];
            }
            for(int i=ruy;i<rdy;i++){
                arr[i][rux]=arr[i+1][rux];
            }
            for(int i=rdx;i>ldx;i--){
                arr[rdy][i] = arr[rdy][i-1];
            }
            for(int i=ldy;i>ruy;i--){
                arr[i][ldx] = arr[i-1][ldx];
            }
            arr[luy+1][ldx]=tmp;
            
            lux++;
            luy++;
            rux--;
            ruy++;
            rdx--;
            rdy--;
            ldx++;
            ldy--;
        }
    }
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}