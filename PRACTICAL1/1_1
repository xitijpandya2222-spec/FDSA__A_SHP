#include<iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items : ";
    cin >> n;

    int a[n];

    cout << "Enter the items : ";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter number of hours : ";
    cin >> h;

    h = h % n;

    for(int i = 0; i < h; i++)
    {
        int temp = a[0];

        for(int j = 0; j < n - 1; j++)
        {
            a[j] = a[j + 1];
        }

        a[n - 1] = temp;
    }

    cout << "Final display order : ";
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
