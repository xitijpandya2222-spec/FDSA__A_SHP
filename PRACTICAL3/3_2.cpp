#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n ;
    cout<<"Enter number of buckets : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter all buckts colour codes : ";
    for(int i = 0 ;i<n;i++)
    {
        cin>>arr[i];
    }
    int zero = 0 ;
    int one = 0 ;
    int two = 0 ;
    for(int i = 0 ;i<n;i++)
    {
        if(arr[i]==0)
        {
            zero++;
        }
        else if(arr[i]==1)
        {
            one++;
        }
        else 
        {
            two++;
        }
    }
    int index = 0 ;
    while(zero>0)
    {
        arr[index]=0;
        index++;
        zero--;        
    }
    while(one>0)
    {
        arr[index]=1;
        index++;
        one--;        
    }
    while(two>0)
    {
        arr[index]=2;
        index++;
        two--;        
    }
    cout<<"Sorted Bucket : ";
    for(int i = 0 ;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0 ;
}