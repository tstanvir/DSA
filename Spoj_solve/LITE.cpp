#include<bits/stdc++.h>
using namespace std;
const int maxx=100005;
int segt[4*maxx];
int lazy[4*maxx];
int n,m;
void update(int ul,int ur,int nodel,int noder,int pos){
    if(lazy[pos]){
        segt[pos]=(noder-nodel+1)-segt[pos];
        if(nodel!=noder){
            lazy[2*pos+1]=!lazy[2*pos+1];
            lazy[2*pos+2]=!lazy[2*pos+2];
        }
        lazy[pos]=0;
    }
    if(nodel>ur || noder<ul || nodel>noder) return;
    if(ul<=nodel && ur>=noder){
        segt[pos]=(noder-nodel+1)-segt[pos];
        if(nodel!=noder){
            lazy[2*pos+1]=!lazy[2*pos+1];
            lazy[2*pos+2]=!lazy[2*pos+2];
        }
        return ;
    }
    int mid=nodel+(noder-nodel)/2;
    update(ul,ur,nodel,mid,2*pos+1);
    update(ul,ur,mid+1,noder,2*pos+2);
    segt[pos]=segt[2*pos+1]+segt[2*pos+2];
}
int query(int ql,int qr,int nodel,int noder,int pos){
    /*if(lazy[pos]%2==1){
        segt[pos]=(noder-nodel+1);
        if(nodel!=noder){
            lazy[2*pos+1]++;
            lazy[2*pos+2]++;
        }
        lazy[pos]=0;
    }
    else if(lazy[pos]!=0 && lazy[pos]%2==0){
        segt[pos]=0;
        if(nodel!=noder){
            lazy[2*pos+1]++;
            lazy[2*pos+2]++;
        }
        lazy[pos]=0;
    }*/
    if(lazy[pos]){
        segt[pos]=(noder-nodel+1)-segt[pos];
        if(nodel!=noder){
            lazy[2*pos+1]=!lazy[2*pos+1];
            lazy[2*pos+2]=!lazy[2*pos+2];
        }
        lazy[pos]=0;
    }
    if(nodel>qr || noder<ql || nodel>noder) return 0;
    if(ql<=nodel && qr>=noder){
        return segt[pos];
    }
    int mid=(nodel+(noder-nodel)/2);
    int a=query(ql,qr,nodel,mid,2*pos+1);
    int b=query(ql,qr,mid+1,noder,2*pos+2);
    return a+b;
}

int main()
{
    cin>>n>>m;
    while(m--){
        int op;
        cin>>op;
        if(op==0){
            int l,r;
            cin>>l>>r;
            l--,r--;
            update(l,r,0,n-1,0);

        }
        else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<query(l,r,0,n-1,0)<<endl;
        }
    }
    return 0;
}
