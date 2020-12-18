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
typedef long long ll;


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
#define max_len 1000000
vector<int> auxi_arr(string pat,int m){
    vector<int>lps(m);
    lps[0]=0;
    int j=0,i=1;
    while(i<m){
        if(pat[j]==pat[i]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else {
                lps[i]=0;
                i++;
            }
        }
        //cout<<lps[i]<<endl;
    }
    return lps;
}
int kmp(string  text,string pat ){
    int n=text.size(),m=pat.size();
    vector<int>vec;
    vec=auxi_arr(pat,m);
    int i=0,j=0;
    int cnt=0;
    while(i<n){
        if(text[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            cnt++;
            j=vec[j-1];
        }
        else if(i<n&&text[i]!=pat[j]){
            if(j!=0){
                j=vec[j-1];
            }
            else i++;
        }
    }
    return cnt;
}
int main()

{
	IOS;
	int t;
	cin>>t;
	for0(i,t){
	    string text,pat;
	    cin>>text>>pat;
	    int ans=kmp(text,pat);
	    pf("Case %d: %d\n",i+1,ans);
	}

	 return 0;

}

