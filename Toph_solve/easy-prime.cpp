/*this is a point update range query problem. can be solved with BIT,segment tree*/

#include<bits/stdc++.h>
using namespace std;
int prime[10000007];
void primegen(){
    prime[0]=1;
    prime[1]=1;
    int lim=sqrt(10000007)+2;
    for(int i=4;i<=10000007;i+=2) prime[i]=1;
    for(int i=3;i<=lim;i++){
        if(prime[i]==0){
            for(int j=i*i;j<=10000007;j+=(2*i)){
                prime[j]=1;
            }
        }
    }
}
const int maxx=100005;
int n,q;
int arr[maxx];
int BIT[maxx];
void update(int pos,int val){
    while(pos<=n){
        BIT[pos]+=val;
        pos+=(pos&-pos);
    }
}
int query(int pos){
    int sum=0;
    while(pos>0){
        sum+=BIT[pos];
        pos-=(pos&-pos);
    }
    return sum;
}

int main()
{
    primegen();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(prime[arr[i]]==0){
                update(i+1,1);
        }
    }
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            cout<<query(r)-query(l-1)<<endl;
        }
        else{
            int pos,val;
            cin>>pos>>val;
            if(prime[arr[pos-1]]==0) update(pos,-1);
            arr[pos-1]=val;
            if(prime[arr[pos-1]]==0) update(pos,+1);
        }
    }

    return 0;
}
