/*
this problem is solved by using segment tree with lazy prop.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxx=300005;
ll arr[maxx];
ll segT[maxx];
ll lazyseg[maxx];
void update(ll ul,ll ur,ll nodel,ll noder,ll pos,ll val){
    if(nodel>noder) return;
    if(lazyseg[pos]!=0){
        segT[pos]+=((noder-nodel+1)*lazyseg[pos]);
        if(nodel!=noder){
            lazyseg[2*pos+1]+=lazyseg[pos];
            lazyseg[2*pos+2]+=lazyseg[pos];
        }
        lazyseg[pos]=0;
    }
    if(ul>noder || ur<nodel) return ; //no overlap
    if(ul<=nodel && ur>=noder){    // total overlap
        segT[pos]+=((noder-nodel+1)*val);
        if(nodel!=noder){
            lazyseg[2*pos+1]+=val;
            lazyseg[2*pos+2]+=val;
        }
        return ;
    }
    // partial overlap
    ll mid=(nodel+noder)/2;
    update(ul,ur,nodel,mid,2*pos+1,val);
    update(ul,ur,mid+1,noder,2*pos+2,val);
    segT[pos]=segT[2*pos+1]+segT[2*pos+2];
}
ll sumQ(ll ql,ll qr,ll nodel,ll noder,ll pos){
    if(lazyseg[pos]!=0){
        segT[pos]+=((noder-nodel+1)*lazyseg[pos]);
        if(nodel!=noder){
            lazyseg[2*pos+1]+=lazyseg[pos];
            lazyseg[2*pos+2]+=lazyseg[pos];
        }
        lazyseg[pos]=0;
    }
    if(ql>noder || qr<nodel) return 0; //no overlap
    if(ql<=nodel && qr>=noder) {
            return segT[pos];
    }// total overlap
    //partial overlap
    ll mid=(nodel+noder)/2;
    ll a=sumQ(ql,qr,nodel,mid,2*pos+1);
    ll b=sumQ(ql,qr,mid+1,noder,2*pos+2);
    return a+b;
}
void printleaf(int nodel,int noder,int pos){
    if(nodel==noder) printf("%d ",segT[pos]);
    else{int mid=(nodel+noder)/2;
    printleaf(nodel,mid,2*pos+1);
    printleaf(mid+1,noder,2*pos+2);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(arr,0,sizeof(arr));
        memset(segT,0,sizeof(segT));
        memset(lazyseg,0,sizeof(lazyseg));
        ll n,c;
        cin>>n>>c;
        while(c--)
        {
            ll op;
            cin>>op;
            if(op==0){
                ll x,y;
                ll val;
                cin>>x>>y>>val;
                x--,y--;
                update(x,y,0,n-1,0,val);
            }
            if(op==1){
                ll x,y;
                cin>>x>>y;
                x--,y--;
                cout<<sumQ(x,y,0,n-1,0)<<endl;
            }
        }
       // printleaf(0,7,0);


    }
    return 0;
}
