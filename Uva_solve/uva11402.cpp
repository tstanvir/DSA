#include<bits/stdc++.h>
using namespace std;
#define SET2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
string s="";
const int maxx=1024005+7;
int segT[4*maxx];
int lazy[4*maxx];
void build(int nodel,int noder,int pos){
    if(nodel==noder  ){
        if(s[nodel]=='1') segT[pos]=1;
        return;
    }
    int mid=nodel+(noder-nodel)/2;
    build(nodel,mid,2*pos+1);
    build(mid+1,noder,2*pos+2);
    segT[pos]=segT[2*pos+1]+segT[2*pos+2];

}
int doFlip(int x) {
    if( x == 2 ) return 1 ;
    if( x == 1 ) return 2 ;
    if( x == 3 ) return 0 ;
    return 3 ;
}
void update1(int ul,int ur,int nodel,int noder,int pos){
    if(lazy[pos]!=0){
        if(lazy[pos]==1){
            segT[pos]=(noder-nodel+1);
        }
        if(lazy[pos]==2){
            segT[pos]=0;
        }
        if(lazy[pos]==3){
            segT[pos]=(noder-nodel+1)-segT[pos];
        }
        if(nodel!=noder){
            if(lazy[pos]==1 || lazy[pos]==2 ) lazy[2*pos+1]=lazy[2*pos+2]=lazy[pos];
            else if(lazy[pos]==3){
                lazy[2*pos+1]=doFlip(lazy[2*pos+1]);
                lazy[2*pos+2]=doFlip(lazy[2*pos+2]);
            }
        }
        lazy[pos]=0;
    }
    if(ul>noder || ur<nodel || nodel>noder){
        return ;
    }
    if(ul<=nodel && ur>=noder){
        segT[pos]=(noder-nodel+1);
        if(nodel!=noder){
                lazy[2*pos+1]=1;
                lazy[2*pos+2]=1;
        }
        return;
    }
    int mid=(nodel+noder)/2;
    update1(ul,ur,nodel,mid,2*pos+1);
    update1(ul,ur,mid+1,noder,2*pos+2);
    segT[pos]=segT[2*pos+1]+segT[2*pos+2];
}
void update2(int ul,int ur,int nodel,int noder,int pos){
    if(lazy[pos]!=0){
        if(lazy[pos]==1){
            segT[pos]=(noder-nodel+1);
        }
        if(lazy[pos]==2){
            segT[pos]=0;
        }
        if(lazy[pos]==3){
            segT[pos]=(noder-nodel+1)-segT[pos];
        }
        if(nodel!=noder){
            if(lazy[pos]==1 || lazy[pos]==2 ) lazy[2*pos+1]=lazy[2*pos+2]=lazy[pos];
            else if(lazy[pos]==3){
                lazy[2*pos+1]=doFlip(lazy[2*pos+1]);
                lazy[2*pos+2]=doFlip(lazy[2*pos+2]);
            }
        }
        lazy[pos]=0;
    }
    if(ul>noder || ur<nodel || nodel>noder){
        return ;
    }
    if(ul<=nodel && ur>=noder){
        segT[pos]=0;
        if(nodel!=noder){
                lazy[2*pos+1]=2;
                lazy[2*pos+2]=2;
        }
        return;
    }
    int mid=(nodel+noder)/2;
    update2(ul,ur,nodel,mid,2*pos+1);
    update2(ul,ur,mid+1,noder,2*pos+2);
    segT[pos]=segT[2*pos+1]+segT[2*pos+2];
}
void update3(int ul,int ur,int nodel,int noder,int pos){
    if(lazy[pos]!=0){
        if(lazy[pos]==1){
            segT[pos]=(noder-nodel+1);
        }
        if(lazy[pos]==2){
            segT[pos]=0;
        }
        if(lazy[pos]==3){
            segT[pos]=(noder-nodel+1)-segT[pos];
        }
        if(nodel!=noder){
            if(lazy[pos]==1 || lazy[pos]==2 ) lazy[2*pos+1]=lazy[2*pos+2]=lazy[pos];
            else if(lazy[pos]==3){
                lazy[2*pos+1]=doFlip(lazy[2*pos+1]);
                lazy[2*pos+2]=doFlip(lazy[2*pos+2]);
            }
        }
        lazy[pos]=0;
    }
    if(ul>noder || ur<nodel || nodel>noder){
        return ;
    }
    if(ul<=nodel && ur>=noder){
        segT[pos]=(noder-nodel+1)-segT[pos];
        if(nodel!=noder){
                lazy[2*pos+1]=doFlip(lazy[2*pos+1]);
                lazy[2*pos+2]=doFlip(lazy[2*pos+2]);
        }
        return;
    }
    int mid=(nodel+noder)/2;
    update3(ul,ur,nodel,mid,2*pos+1);
    update3(ul,ur,mid+1,noder,2*pos+2);
    segT[pos]=segT[2*pos+1]+segT[2*pos+2];
}
int query(int ql,int qr,int nodel,int noder,int pos){
    if(lazy[pos]!=0){
        if(lazy[pos]==1){
            segT[pos]=(noder-nodel+1);
            if(nodel!=noder){
                lazy[2*pos+1]=lazy[pos];
                lazy[2*pos+2]=lazy[pos];
            }
        }
        if(lazy[pos]==2){
            segT[pos]=0;
            if(nodel!=noder){
                lazy[2*pos+1]=lazy[pos];
                lazy[2*pos+2]=lazy[pos];
            }
        }
        lazy[pos]=0;
    }
    if(ql>noder || qr<nodel || nodel>noder){
        return 0;
    }
    if(ql<=nodel && qr>=noder){
        return segT[pos];
    }
    int mid=(nodel+noder)/2;
    return query(ql,qr,nodel,mid,2*pos+1)+query(ql,qr,mid+1,noder,2*pos+2);
}
int main(){
    int t;
    cin>>t;
    int cs=0;
    while(t--){
        memset(segT,0,sizeof(segT));
        memset(lazy,0,sizeof(lazy));
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
        /*for(int i=0;i<20;i++){
            cout<<segT[i][0]<<" "<<segT[i][1]<<endl;
        }*/
        int q;
        cin>>q;
        int qs=0;
        while(q--){
            char op;
            cin>>op;
            if(op=='F'){
                int l,r;
                cin>>l>>r;
                update1(l,r,0,sz-1,0);
            }
            else if(op=='E'){
                    int l,r;
                cin>>l>>r;
                update2(l,r,0,sz-1,0);
            }
            else if(op=='I'){
                int l,r;
                cin>>l>>r;
                update3(l,r,0,sz-1,0);
            }
            else{
                int l,r;
                cin>>l>>r;
                cout<<"Q"<<++qs<<": "<<query(l,r,0,sz-1,0)<<endl;

            }
           /* for(int i=0;i<64;i++){
            cout<<segT[i][0]<<" "<<segT[i][1]<<endl;*/
        }
        }
        /*cout<<endl<<endl;
        cout<<"segT: "<<endl;
        for(int i=0;i<2*(pow(2,log2(sz))+1)-1;i++) cout<<segT[i][0]<<" "<<segT[i][1]<<endl;
        cout<<endl<<"Lazy: "<<endl;
        for(int i=0;i<2*(pow(2,log2(sz))+1)-1;i++) cout<<lazy[i][0]<<" "<<lazy[i][1]<<endl;
        cout<<endl<<endl;
        */



    return 0;
}

