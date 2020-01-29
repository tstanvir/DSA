#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx=6;
int sparse[maxx][(int)log2(maxx)+1];
int arr[maxx];

int logg(long long val){
    int cnt=0;
    while(val!=1 && val!=0) {cnt++;val/=2; }
    return cnt;
}

int  po(int  base , int power){
    int ret=1;
    while(power){
        ret*=base;
        power--;
    }
    return ret;
}
void prepo(){
    int col=logg(maxx)+1;
   // cout<<logg(maxx)<<endl;
    for(int i=0;i<maxx;i++) sparse[i][0]=i; /*the first column of sparse table is equal to the row number because
    the index of the minimum element in range start from ith index to the next 2^j element is the i itself*/
    //for(int i=0;i<maxx;i++) cout<<sparse[i][0]<<" ";
  //  cout<<endl;
    for(int j=1;j<=col;j++){
        for(int i=0;i+po(2,j)-1<maxx;i++){ // this condition is for not going out of bound. else range may go out of bound.
            if(arr[sparse[i][j-1]]<arr[sparse[i+po(2,j-1)][j-1]]){ /*this conditions use the previous range's result. Basically,breaks the
                    present range into two halves that represents the previously calculated halves and compare between them. Seems like used
                    DP here*/
                sparse[i][j]=sparse[i][j-1];
            }
            else {
                sparse[i][j]=sparse[i+po(2,j-1)][j-1];
            }
        }
    }
}
int minQ(int l,int r){
    int tot=r-l+1;
    int k=log2(tot);
    int slide=l+(tot-pow(2,k));
    return min(arr[sparse[l][k]],arr[sparse[slide][k]]);
    /*
    dividing the range into to halves: 1st--> starting from l to next 2^k elements
                                       2nd--> starting from l+(number of the rest of the elements that was outside the 1st range) to l
    */
}
int main()
{
   // cout<<logg(6)<<endl;
    //cout<<po(2,3)<<endl;


    arr[0]=4,arr[1]=6,arr[2]=1,arr[3]=5,arr[4]=7,arr[5]=3;
    for(int i=0;i<6;i++) cout<<arr[i]<<" ";
    cout<<endl;
    prepo();
    /*for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++) cout<<sparse[i][j]<<" ";
        cout<<endl;
    }
    */


    cout<<minQ(2,3)<<endl;
    cout<<minQ(0,5)<<endl;
    cout<<minQ(3,3)<<endl;
    cout<<minQ(0,1)<<endl;

    return 0;
}
