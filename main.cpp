#include <bits/stdc++.h>

using namespace std;

void NextArr(int nextarr[],int n){
  for(int i=1;i<=n;i++){
    int y=i&-i;
    int z=i+y;
    nextarr[i]=z;
  }
}

void create(int ftree[],int arr[],int nextarr[],int n){
   int y;
   for(int i=1;i<=n;i++){
    ftree[i]+=arr[i-1];
    y=nextarr[i];
   while(y<=n){
    ftree[y]+=arr[i-1];
    y=nextarr[y];
   }
  }
}

void update(int ftree[],int arr[],int nextarr[],int value,int index,int n){
  int y=index+1;
  while(y<=n){
    ftree[y]+=(value-arr[y-1]);
    y=nextarr[y];
  }
}

int sum(int endindex,int ftree[],int n){
  int z=endindex+1;
  int sum1=0;
  while(z>0){
   sum1+=ftree[z];
    z=z&z-1;
  }
  return sum1;
}
int main()
{    int n,endingindex,ind,val;
    cout<<"Enter number of elements:->";
    cin>>n;
    int arr[n],ftree[n+1],nextarr[n+1];
    cout<<"Enter elements in the array:->";
    for(int i=0;i<n;i++){
        cin>>arr[i];ftree[i]=0;
    }
    ftree[n]=0;
    cout<<"Enter ending Index";
    cin>>endingindex;
    NextArr(nextarr,n);
    create(ftree,arr,nextarr,n);
    int sum1=sum(endingindex,ftree,n);
    cout<<"Required prefix sum is:->"<<sum1<<endl;
    cout<<"Enter index and value to be updated:->";
    cin>>ind>>val;
    update(ftree,arr,nextarr,val,ind,n);
    arr[ind]=val;
    sum1=sum(endingindex,ftree,n);
    cout<<"Required prefix sum is:->"<<sum1<<endl;
    return 0;
}
