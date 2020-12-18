#include<bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;
#define SET(x) memset(x, 0, sizeof(x))
#define SET2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
#define SETBOOL(x) memset(x,false,sizeof(x))
#define CLR(x) memset(x, -1, sizeof(x))
#define mp make_pair
#define PII pair<int, int>
#define pf printf

#define sf scanf

#define ALL(x) x.begin(),x.end()
#define pb push_back

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define np std::string::npos
#define for0(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=n-1;i>=0;i--)
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
typedef long long ll;
#define max_id 1000000

//this fuction sorts vector pair according to first element in descending order.
bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}

template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}
int root,nnode;
int tree[max_id][4];
//string whole="ACGT";
unordered_map<string,ll>mm2;
ll ans;

//int len[55];
void init()
{
    root=0;
    ans=-1;
    nnode=0;
    //SET(endoflet);
    SET2d(tree,max_id,4);
    map<char,int>mm;
    mm['A']=0;
    mm['C']=1;
    mm['G']=2;
    mm['T']=3;
    //mm.clear();
    mm2.clear();
    for(int i=0;i<4;i++) tree[root][i]=-1;

}
void prematch(char s[]){
    int now=root;
    int l=strlen(s);
    //cout<<"main_strings: "<<s<<endl;
    map<char,int>mm;
    mm['A']=0;
    mm['C']=1;
    mm['G']=2;
    mm['T']=3;

    string tmp="";
    for(int i=0;i<l;i++){
        //cout<<"          " <<tree[now][s[i]-'A']<<endl;
        if(tree[now][mm[s[i]]]==-1){

            tree[now][mm[s[i]]]=++nnode;
        }
        else {
            tmp.pb(s[i]);
            if(tmp.size()>0) {
                    //cout<<tmp<<endl;
                    if(mm2[tmp]==0) mm2[tmp]=tmp.size();
                    mm2[tmp]+=tmp.size();
                    ans=max(ans,mm2[tmp]);

            }

        }
       // cout<<"i: "<<i<<" "<<tmp<<endl;
        for(int j=0;j<4;j++) tree[nnode][j]=-1;
        now=tree[now][mm[s[i]]];
    }
    //cout<<tmp<<endl;

}

int main()

{
    //IOS;
    int t;
    sf("%d",&t);
    for(int o=1;o<=t;o++){
        int n;
        sf("%d",&n);
        init();
        int maxi=-1;
        //vector<pair<int,string>>vec;
        while(n--){
            char a[55];
            sf("%s",a);
            prematch(a);
           // vec.pb({a.size(),a});
           if((int)strlen(a)>maxi) maxi=strlen(a);
           //maxi=max(maxi,(int)strlen(a));
        }
        //sort(ALL(vec));

        //for(int i=0;i<vec.size();i++) {

       // }
      // cout<<maxi<<endl;
       ll x;
        pf("Case %d: %lld\n",o,x=(((ll)maxi>ans)?(ll)maxi:ans));


    }


     return 0;

}
