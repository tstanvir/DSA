#include<bits/stdc++.h>
using namespace std;
const int maxx = 300005;
typedef long long ll;
int k;
ll sum=0;
ll arr[maxx];
ll ans[maxx];
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
    sum+=arr[x];
}
void rmove(int x){
    sum-=arr[x];
}
int main()
{
    int n;
    cin>>n;
    k=sqrt(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    for(int i=0;i< q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        Query[i].l=l;
        Query[i].r=r;
        Query[i].index=i;
    }
    sort(Query,Query+q);
    int L=0,R=-1;
    for(int i=0;i<q;i++){
        while(R<Query[i].r) add(++R);
        while(R>Query[i].r) rmove(R--);
        while(L<Query[i].l) rmove(L++);
        while(L>Query[i].l) add(--L);
        ans[Query[i].index]=sum;
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
