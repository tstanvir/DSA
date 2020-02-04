#include<bits/stdc++.h>
using namespace std;
const int maxx = 300005;
typedef long long ll;
int k;
int arr[maxx];
int ans[maxx];
int freq[maxx],cnt[maxx],maxi;
struct query{
    int index,l,r;
    bool operator < (const query &other) const{
        int block_own=l/k;
        int block_other=other.l/k;
        if(block_own==block_other){
            return r<other.r;
        }
        return block_own<block_other;
    }
}Query[maxx];
void add(int x){
    cnt[freq[x]]--;
    freq[x]++;
    cnt[freq[x]]++;
    if(cnt[maxi+1]>0) maxi++;
   // cout<<"add"<<endl;
    //cout<<x<<" "<<mm[x]<<endl;
}
void rmove(int x){
    cnt[freq[x]]--;
    freq[x]--;
    cnt[freq[x]]++;
    if(cnt[maxi]==0) maxi--;
    //cout<<"h"<<endl;
    //cout<<(*it).second<<endl;
    //cout<<"rmove"<<endl;
    //cout<<x<<" "<<mm[x]<<endl;
}
int main()
{
    int n,q;
        //st.clear();

        //mm.clear();
        while(scanf("%d",&n)!=EOF){
        	  maxi=0;
        memset(arr,0,sizeof(arr));
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(ans));
        memset(freq,0,sizeof(freq));
        k=sqrt(n);
        scanf("%d",&q);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        for(int i=0;i< q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r--;
            Query[i].l=l;
            Query[i].r=r;
            Query[i].index=i;
        }
        sort(Query,Query+q);
        //for(int i=0;i<q;i++) cout<<Query[i].l << " "<<Query[i].r<<endl;
        int L=0,R=-1;
        for(int i=0;i<q;i++){
            //ll maxi=numeric_limits<int>::min();

            while(L<Query[i].l) {int ind=L++;rmove(arr[ind]);}
            while(L>Query[i].l) {int ind=--L;add(arr[ind]);}
            while(R<Query[i].r) {int ind=++R;add(arr[ind ]);}
            while(R>Query[i].r) {int ind=R--;rmove(arr[ind]);}
            //cout<<a.first<<endl;
            ans[Query[i].index]=maxi;
        }
        for(int i=0;i<q;i++){
            printf("%d\n",ans[i]);
        }
        }
    return 0;
}

