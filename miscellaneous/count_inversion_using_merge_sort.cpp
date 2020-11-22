/*merge_sort algorithm sorts an array in O(nlogn) time complexity and uses Divide & conquer paradigm*/
/*
    Inversion Count for an array indicates – how far (or close) the array is from being sorted.
    If array is already sorted then inversion count is 0. If array is sorted in reverse order that
    inversion count is the maximum.
    Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
*/

#include<bits/stdc++.h>
using namespace std;
const int maxx=100005;
int arr[maxx];
int  merging(int l,int mid,int r){
    int lefttrace=0,righttrace=0,maintrace=l;
    //cout<<"L: "<<l<<" R: "<<r<<endl;
    int n1=mid-l+1;//size of left sub-array
    int pairs1=0;
    int n2=r-mid;//size of right sub-array
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
            pairs1+=(n1-lefttrace);//here,as the two sub array is sorted,if an element of left sub array is greater than an element
            //of right sub array then the next all element of left sub array satisfy the condition of inversion for i<j and arr[i]>arr[j].
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

