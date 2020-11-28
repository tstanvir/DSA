/*
2*n+1==left child of n
2*n+2==right child or subtree of n
*/


#include<bits/stdc++.h>
using namespace std;
const int maxx=10;
int segT[maxx];
void build(int arr[],int low,int high,int pos){
    if(low==high) segT[pos]=arr[low];
    else{
        int mid=(low+high)/2;
        build(arr,low,mid,2*pos+1);
        build(arr,mid+1,high,2*pos+2);
        segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);

    }
}
int MinQ(int qlow,int qhigh,int nodelow,int nodehigh,int pos){
    if(nodehigh<nodelow) return numeric_limits<int>::max();
    if(qlow<=nodelow && qhigh>=nodehigh){
        return segT[pos];                   //Total overlap
    }
    if(qhigh<nodelow || qlow>nodehigh) return numeric_limits<int>::max(); //No overlap
    //partial overlap
    int mid=(nodelow+nodehigh)/2;
    return min(MinQ(qlow,qhigh,nodelow,mid,2*pos+1),MinQ(qlow,qhigh,mid+1,nodehigh,2*pos+2));


}
void update(int *arr,int nodel,int noder,int pos,int x,int val){
    if(nodel==noder and x==nodel){
            arr[x]=val;
            segT[pos]=val;
    }
    //printf("1\n");
    else{
    int mid=(nodel+noder)/2;
    if(nodel<=x && x<=mid) update(arr,nodel,mid,2*pos+1,x,val);
    else update(arr,mid+1,noder,2*pos+2,x,val);
    segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);
    }
}
int main()
{
    int arr[4]={4,-1,8,0};//for size n,the number of node needed for segment tree is (2*n)-1 if n is a power of 2.else 2*(next power of two)-1
     build(arr,0,3,0);
     cout<<MinQ(0,3,0,3,0)<<endl;
                            //for 4 the number of nodes needed=2*4 - 1=7
                            // for 5 the number of nodes needed=2*8 - 1=15

    return 0;
}
