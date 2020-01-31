#include<bits/stdc++.h>
using namespace std;
const int maxx=100005;
int arr[maxx];
int BIT[maxx];
void update(int pos,int val,int maxi){
    while(pos<=maxi){
        BIT[pos]+=val;
        pos+=(pos&-pos);
    }
}
int getSum(int pos){
    int sum=0;
    while(pos>0){
        sum+=BIT[pos];
        pos-=(pos&-pos);
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int maxval=numeric_limits<int>::min();
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxval=max(maxval,arr[i]);
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=getSum(arr[i]-1);
        update(arr[i],1,maxval);
    }
    cout<<ans<<endl;
    return 0;
}
