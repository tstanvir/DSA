/*merge_sort algorithm sorts an array in O(nlogn) time complexity and uses Divide & conquer paradigm*/

#include<bits/stdc++.h>
using namespace std;
const int maxx=100005;
int arr[maxx];
int  merging(int l,int mid,int r){
    int lefttrace=0,righttrace=0,maintrace=l;
    //cout<<"L: "<<l<<" R: "<<r<<endl;
    int n1=mid-l+1;
    int pairs1=0;
    int n2=r-mid;
    int leftarr[n1],rightarr[n2];
    for(int i=0;i<n1;i++) leftarr[i]=arr[i+l];
    for(int i=0;i<n2;i++) rightarr[i]=arr[i+mid+1];
    /*cout<<endl;
    cout<<endl;
    for(int i=0;i<n1;i++) cout<<leftarr[i]<<" ";
    cout<<endl;
    for(int i=0;i<n2;i++) cout<<rightarr[i]<<" ";
    cout<<endl;
    cout<<endl;
    */
    while(lefttrace<n1 && righttrace<n2){
        if(leftarr[lefttrace]<=rightarr[righttrace]){
            arr[maintrace++]=leftarr[lefttrace++];
        }
        else{
            pairs1+=(n1-lefttrace);
            arr[maintrace++]=rightarr[righttrace++];
        }
    }
    while(lefttrace<n1){
        arr[maintrace++]=leftarr[lefttrace++];
    }
    while(righttrace<n2){
        arr[maintrace++]=rightarr[righttrace++];
    }
    return pairs1;
}
int  merge_sort(int l,int r){
    int pairs=0;
    if(l<r){
        int mid=l+(r-l)/2;
        pairs+=merge_sort(l,mid);
        pairs+=merge_sort(mid+1,r);
        pairs+=merging(l,mid,r);
        //cout<<pairs<<endl;
    }
    return pairs;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<merge_sort(0,n-1)<<endl;
    //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    //cout<<endl;

    return 0;
}
