#include<bits/stdc++.h>
using namespace std;
#define SET2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
string s="";
const int maxx=1024005;
int segT[4*maxx][2];
int lazy[4*maxx][2];
void build(int nodel,int noder,int pos){
    if(nodel==noder ){
        segT[pos][s[nodel]-'0']++;
        return;
    }
    int mid=nodel+(noder-nodel)/2;
    build(nodel,mid,2*pos+1);
    build(mid+1,noder,2*pos+2);
    segT[pos][1]=segT[2*pos+1][1]+segT[2*pos+2][1];
    segT[pos][0]=segT[2*pos+1][0]+segT[2*pos+2][0];

}
void update(int ul,int ur,int nodel,int noder ,int pos,char op){
    if(noder<nodel) return;
    if(lazy[pos][0]!=0){
        segT[pos][0]+=lazy[pos][0];
        if(nodel!=noder)
        {
            lazy[2*pos+1][0]+=lazy[pos][0];
            lazy[2*pos+2][0]+=lazy[pos][0];
        }
        lazy[pos][0]=0;
    }
    if(lazy[pos][1]!=0){
        segT[pos][1]+=lazy[pos][1];
        if(nodel!=noder)
        {
            lazy[2*pos+1][1]+=lazy[pos][1];
            lazy[2*pos+2][1]+=lazy[pos][1];
        }
        lazy[pos][1]=0;
    }
    if(op=='F'){
        if(ul<=nodel && ur>=noder){
        segT[pos][1]+=segT[pos][0];
        segT[pos][0]=0;
        if(nodel!=noder){
            lazy[2*pos+1][1]+=segT[2*pos+1][0];
            lazy[2*pos+2][1]+=segT[2*pos+1][0];
            lazy[2*pos+1][0]+=(-1*segT[2*pos+1][0]);
            lazy[2*pos+2][0]+=(-1*segT[2*pos+1][0]);
        }
        return;
    }
    else if(ul>noder || ur<nodel) return;
    else{
        int mid=(nodel+noder)/2;
        update(ul,ur,nodel,mid,2*pos+1,op);
        update(ul,ur,mid+1,noder,2*pos+2,op);
        segT[pos][1]=segT[2*pos+1][1]+segT[2*pos+2][1];
        segT[pos][0]=segT[2*pos+1][0]+segT[2*pos+2][0];

    }
    }
    if(op=='E'){
        if(ul<=nodel && ur>=noder){
        segT[pos][0]+=segT[pos][1];
        segT[pos][1]=0;
        if(nodel!=noder){
            lazy[2*pos+1][0]+=segT[2*pos+1][1];
            lazy[2*pos+2][0]+=segT[2*pos+1][1];
            lazy[2*pos+1][1]+=(-1*segT[2*pos+1][1]);
            lazy[2*pos+2][1]+=(-1*segT[2*pos+1][1]);
        }
        return;
    }
    else if(ul>noder || ur<nodel) return;
    else{
        int mid=(nodel+noder)/2;
        update(ul,ur,nodel,mid,2*pos+1,op);
        update(ul,ur,mid+1,noder,2*pos+2,op);
        segT[pos][1]=segT[2*pos+1][1]+segT[2*pos+2][1];
        segT[pos][0]=segT[2*pos+1][0]+segT[2*pos+2][0];

    }
    }
    if(op=='I'){
        if(ul<=nodel && ur>=noder){
        int tmp=segT[pos][0];
        segT[pos][0]=segT[pos][1];
        segT[pos][1]=tmp;
        if(nodel!=noder){
            lazy[2*pos+1][0]+=segT[2*pos+1][1];
            lazy[2*pos+2][0]+=segT[2*pos+1][1];
            lazy[2*pos+1][1]+=segT[2*pos+1][0];
            lazy[2*pos+2][1]+=segT[2*pos+1][0];
        }
        return;
    }
    else if(ul>noder || ur<nodel) return;
    else{
        int mid=(nodel+noder)/2;
        update(ul,ur,nodel,mid,2*pos+1,op);
        update(ul,ur,mid+1,noder,2*pos+2,op);
        segT[pos][1]=segT[2*pos+1][1]+segT[2*pos+2][1];
        segT[pos][0]=segT[2*pos+1][0]+segT[2*pos+2][0];

    }
    }

}
int query(int ql,int qr,int nodel,int noder,int pos){
    if(nodel>noder) return 0;
    if(lazy[pos][0]!=0){
        segT[pos][0]+=lazy[pos][0];
        if(nodel!=noder)
        {
            lazy[2*pos+1][0]+=lazy[pos][0];
            lazy[2*pos+2][0]+=lazy[pos][0];
        }
        lazy[pos][0]=0;
    }
    if(lazy[pos][1]!=0){
        segT[pos][1]+=lazy[pos][1];
        if(nodel!=noder)
        {
            lazy[2*pos+1][1]+=lazy[pos][1];
            lazy[2*pos+2][1]+=lazy[pos][1];
        }
        lazy[pos][1]=0;
    }
    if(ql<=nodel && qr>=noder){
        return segT[pos][1];
    }
    else if(ql>noder || qr<nodel) return 0;
    else{
        int mid=(nodel+noder)/2;
        return query(ql,qr,nodel,mid,2*pos+1)+query(ql,qr,mid+1,noder,2*pos+2);
    }
}
int main(){
    int t;
    cin>>t;
    int cs=0;
    while(t--){
        SET2d(segT,4*maxx,2);
        SET2d(lazy,4*maxx,2);
        cout<<"Case "<<++cs<<":"<<endl;

        s.clear();
        int m;
        cin>>m;
        while(m--){
            int n;
            cin>>n;
            string t;
            cin>>t;
            while(n--){
                s+=t;
            }
        }
        int sz=s.size();
        build(0,sz-1,0);
        int q;
        cin>>q;
        int qs=0;
        while(q--){
            char op;
            cin>>op;
            if(op=='F'){
                int l,r;
                cin>>l>>r;
                update(l,r,0,sz-1,0,op);
            }
            else if(op=='E'){
                    int l,r;
                cin>>l>>r;
                update(l,r,0,sz-1,0,op);
            }
            else if(op=='I'){
                int l,r;
                cin>>l>>r;
                update(l,r,0,sz-1,0,op);
            }
            else{
                int l,r;
                cin>>l>>r;
                cout<<"Q"<<++qs<<": "<<query(l,r,0,sz-1,0)<<endl;

            }
        }

    }

    return 0;
}

