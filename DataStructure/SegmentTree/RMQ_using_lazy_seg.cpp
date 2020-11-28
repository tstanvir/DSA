/*lazy segment tree is used if there is a lots of update happens*/
#include<bits/stdc++.h>
using namespace std;
const int maxx = 100;
int arr[maxx];
int segT[maxx];
int lazySegT[maxx];
void build(int nodel,int noder,int pos){
    if(nodel==noder){
        segT[pos]=arr[nodel];
    }
    else{
        int mid=(nodel+noder)/2;
        build(nodel,mid,2*pos+1);
        build(mid+1,noder,2*pos+2);
        segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);
    }
}
void update(int ul,int ur,int nodel,int noder,int pos,int val){
    if(noder<nodel) return;
    if(lazySegT[pos]!=0){
        segT[pos]+=lazySegT[pos];
        if(nodel!=noder)
        {
            lazySegT[2*pos+1]+=lazySegT[pos];
            lazySegT[2*pos+2]+=lazySegT[pos];
        }
        lazySegT[pos]=0;
    }
    if(ul<=nodel && ur>=noder){
        segT[pos]+=val;
        if(nodel!=noder){
            lazySegT[2*pos+1]+=val;
            lazySegT[2*pos+2]+=val;
        }
        return;
    }
    else if(ul>noder || ur<nodel) return;
    else{
        int mid=(nodel+noder)/2;
        update(ul,ur,nodel,mid,2*pos+1,val);
        update(ul,ur,mid+1,noder,2*pos+2,val);
        segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);
    }
}
int MinQ(int ql,int qr,int nodel,int noder,int pos){
    if(nodel>noder) return numeric_limits<int>::max();
    if(lazySegT[pos]!=0){
        segT[pos]+=lazySegT[pos];
        if(nodel!=noder)
        {
            lazySegT[2*pos+1]+=lazySegT[pos];
            lazySegT[2*pos+2]+=lazySegT[pos];
        }
        lazySegT[pos]=0;
    }
    if(ql<=nodel && qr>=noder){
        return segT[pos];
    }
    else if(ql>noder || qr<nodel) return numeric_limits<int>::max();
    else{
        int mid=(nodel+noder)/2;
        return min(MinQ(ql,qr,nodel,mid,2*pos+1),MinQ(ql,qr,mid+1,noder,2*pos+2));
    }
}
void printleaf(int nodel,int noder,int pos){
    if(nodel==noder) printf("%d ",segT[pos]);
    else{int mid=(nodel+noder)/2;
    printleaf(nodel,mid,2*pos+1);
    printleaf(mid+1,noder,2*pos+2);
    }
}
int main(){
    arr[0]=-1,arr[1]=2,arr[2]=4,arr[3]=1,arr[4]=7,arr[5]=1,arr[6]=3,arr[7]=2;
    build(0,7,0);
    update(0,3,0,7,0,3);
    update(0,3,0,7,0,1);
    update(0,0,0,7,0,2);
    printf("%d\n",MinQ(3,5,0,7,0));
    printleaf(0,7,0);
    printf("\n");
    return 0;
}
