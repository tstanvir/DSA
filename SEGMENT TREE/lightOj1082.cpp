/*
this is simple range minimum query problem. here,solved by using segment tree
*/
#include<bits/stdc++.h>
using namespace std;
const int maxx=300005;
int segT[maxx];
void build(int arr[],int low,int high,int pos){
    if(low==high){
        segT[pos]=arr[low];
    }
    else{
        int mid=(low+high)/2;
        build(arr,low,mid,2*pos+1);
        build(arr,mid+1,high,2*pos+2);
        segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);
    }
}
int MinQ(int ql,int qr,int nodel,int noder,int pos){
    if(qr<nodel || ql>noder) return numeric_limits<int>::max(); //no overlap
    if(ql<=nodel && qr>=noder){
        return segT[pos];
        //total overlap
    }
    //partial overlap
    int mid=(nodel+noder)/2;
    return min(MinQ(ql,qr,nodel,mid,2*pos+1),MinQ(ql,qr,mid+1,noder,2*pos+2));
}
int main(){
    int t;
    scanf("%d",&t);
    int cs=0;
    while(t--){
        memset(segT,0,sizeof(segT[0]));
        printf("Case %d:\n",++cs);
        int n,q;
        scanf("%d%d",&n,&q);
        int arr[n];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        build(arr,0,n-1,0);
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r--;
            printf("%d\n",MinQ(l,r,0,n-1,0));
        }



    }
    return 0;
}
