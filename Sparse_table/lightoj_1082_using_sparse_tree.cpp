//this problem is solved by using sparse tree
#include<bits/stdc++.h>
using namespace std;
const int maxx=100001;
int sparse[maxx][(int)log2(maxx)+1];
int arr[maxx];
void prepo(){
    for(int i=0;i<maxx;i++) sparse[i][0]=i;
    for(int j=1;(int)pow(2,j)<=maxx;j++){
        for(int i=0;i+pow(2,j)-1<maxx;i++){
            if(arr[sparse[i][j-1]]<arr[sparse[i+(int)pow(2,j-1)][j-1]])
            {
                sparse[i][j]=sparse[i][j-1];
            }
            else{
                sparse[i][j]=sparse[i+(int)pow(2,j-1)][j-1];
            }
        }
    }
}
int minQ(int l,int r){
    int tot=r-l+1;
    int k=log2(tot);
    int slide=l+(tot-pow(2,k));
    return min(arr[sparse[l][k]],arr[sparse[slide][k]]);
}

int main()
{
    int t;
    scanf("%d",&t);
    int cs=0;
    while(t--){
        memset(sparse,0,sizeof(sparse[0][0])*maxx*((int)log2(maxx)+1));
        memset(arr,0,sizeof(arr));
        printf("Case %d:\n",++cs);
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        prepo();
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r--;
            printf("%d\n",minQ(l,r));

        }
    }
    return 0;
}
