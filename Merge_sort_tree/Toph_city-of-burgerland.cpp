/*
this problem is solved by using merge sort tree..it is similar type of algorithm to segment tree with every node representing a vector.
*/


#include<bits/stdc++.h>
using namespace std;
const int maxx=100005;
typedef long long ll;
int n,m;
ll arr[maxx];
//ll pre[maxx];
vector<ll>segT[4*maxx];
vector<ll>presum[4*maxx];
void init(){
    for(int i=0;i<4*maxx;i++) segT[i].clear();
    for(int i=0;i<4*maxx;i++) presum[i].clear();
}
void mergee(vector<ll>lf,vector<ll>rt,int pos){
    int sizel=lf.size(),sizer=rt.size();
    segT[pos].assign(sizel+sizer,0);
    presum[pos].assign(sizel+sizer,0);
    //cout<<sizel<<" "<<sizer<<endl;
    int lindex=0,rindex=0,mainindex=0;
    while(lindex<sizel && rindex<sizer){
        if(lf[lindex]<=rt[rindex]){
            segT[pos][mainindex]=lf[lindex];
            if(mainindex==0){
                presum[pos][mainindex]=lf[lindex];
            }
            else{
                presum[pos][mainindex]=presum[pos][mainindex-1]+lf[lindex];
            }
            mainindex++;
            lindex++;
        }
        else{
            segT[pos][mainindex]=rt[rindex];
            if(mainindex==0){
                presum[pos][mainindex]=rt[rindex];
            }
            else{
                presum[pos][mainindex]=presum[pos][mainindex-1]+rt[rindex];
            }
            mainindex++;
            rindex++;
        }
    }
    while(lindex<sizel){
        segT[pos][mainindex]=lf[lindex];
            if(mainindex==0){
                presum[pos][mainindex]=lf[lindex];
            }
            else{
                presum[pos][mainindex]=presum[pos][mainindex-1]+lf[lindex];
            }
            mainindex++;
            lindex++;
    }
    while(rindex<sizer){
        segT[pos][mainindex]=rt[rindex];
            if(mainindex==0){
                presum[pos][mainindex]=rt[rindex];
            }
            else{
                presum[pos][mainindex]=presum[pos][mainindex-1]+rt[rindex];
            }
            mainindex++;
            rindex++;
    }
}
void build(int nodel,int noder,int pos){
    if(nodel==noder){
        segT[pos].push_back(arr[nodel]);
        presum[pos].push_back(arr[nodel]);
        //cout<<segT[pos][0]<<endl;
        return;
    }
    if(nodel<noder){
        int mid=nodel+(noder-nodel)/2;
        build(nodel,mid,2*pos+1);
        build(mid+1,noder,2*pos+2);
        //vector<ll>lf(arr+nodel,arr+mid+1);
       // vector<ll>rf(arr+mid+1,arr+(noder-mid));
        //cout<<"nodel: "<<nodel<<" "<<"noder: "<<noder<<endl;
       // cout<<"left: "<<endl;
       // for(int i=0;i<lf.size();i++) cout<<lf[i]<<" ";
       // cout<<endl;
       // cout<<"right: "<<endl;
       // for(int i=0;i<rf.size();i++) cout<<rf[i]<<" ";
       // cout<<endl;

        //merge(segT[2*pos+1].begin(),segT[2*pos+1].end(),segT[2*pos+2].begin(),segT[2*pos+2].end(),back_inserter(segT[pos]));
        //cout<<"heda"<<endl;
        mergee(segT[2*pos+1],segT[2*pos+2],pos);
       // cout<<"pos"<<pos<<endl;
       // for(int i=0;i<segT[pos].size();i++) cout<<segT[pos][i]<<" ";
       // cout<<endl;
    }
}
ll query(int nodel,int noder,int ql,int qr,ll val,int pos){
    if(nodel>noder or (nodel>qr or noder<ql)){
        return 0ll;
    }
    if(ql<=nodel && qr>=noder){
        int index=lower_bound(segT[pos].begin(),segT[pos].end(),val)-segT[pos].begin();
        //cout<<presum[pos][index-1]<<endl;
        ll rangeval=index-1>=0?presum[pos][index-1]:0;
        return (val*(ll)index)-rangeval;

    }
    int mid=nodel+(noder-nodel)/2;
    ll a=query(nodel,mid,ql,qr,val,2*pos+1);
    ll b=query(mid+1,noder,ql,qr,val,2*pos+2);
    return a+b;
}
int main(){
    while(cin>>n>>m){
    init();
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //pre[i]=arr[i];
    }
    //sort(pre,pre+n);
    //for(int i=1;i<n;i++){
       // pre[i]+=pre[i-1];
   // }
   // for(int i=0;i<n;i++) cout<<pre[i]<<" ";
    //cout<<endl;
    build(0,n-1,0);
    for(int i=0;i<m;i++){
        int l,r;
        ll cap;
        cin>>l>>r>>cap;
        l--,r--;
        cout<<query(0,n-1,l,r,cap,0)<<endl;
    }
    }

    return 0;
}
