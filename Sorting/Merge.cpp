
#include<iostream>

using namespace std;

void merge(int left[],int nleft,int right[],int nright,int arr[]){
    int i=0,j=0,k=0;
    while(i<nleft && j<nright){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<nleft){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<nright){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int n){
    if(n>1){
        int mid=n/2;
        int left[mid];
        int right[n-mid];
        for(int i=0;i<mid;i++){
            left[i]=arr[i];
        }
        for(int i=mid;i<n;i++){
            right[i-mid]=arr[i];
        }
        mergesort(left,mid);
        mergesort(right,n-mid);
        merge(left,mid,right,n-mid,arr);
    }
}

int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    mergesort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}