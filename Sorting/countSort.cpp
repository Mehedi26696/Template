
#include<iostream>

using namespace std;


void countSort(int a[],int n)
{
    int b[100000] = {0};
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int k=0;
    for (int i = 0; i < 100000; i++)
    {
        if (b[i] != 0)
        {
            for (int j = 0; j < b[i]; j++)
            {
                a[k]=i;
                k++;
            }
        }
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

    countSort(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}

