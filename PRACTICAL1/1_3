#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int n;
    cout<<"Number of strings : ";
    cin>>n;
    vector<string>arr(n);
    cout<<"Enter "<<n<<" strings :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    string longest=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i].length()>longest.length())
        {
            longest = arr[i];
        }
    }
    cout<<"Longest One is : "<<longest<<endl<<"Length of Longest : "<<longest.length()<<endl;
    return 0;
}
