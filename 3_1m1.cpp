#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number of students : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter Marks : "<<endl;
    for(int i=0 ; i<n;i++)
    {
        cin>>arr[i];
    }
     for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout<<"Sorted Marks : ";
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}