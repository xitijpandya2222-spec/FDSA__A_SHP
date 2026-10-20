
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> shelf[10];
    int n, book;

    cout << "Enter number of books: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid number of books!";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter book code: ";
        cin >> book;

        int index = book % 10;
        if (index < 0) index += 10;

        shelf[index].push_back(book);

        cout << "Book " << book
             << " placed on shelf " << index << "\n";
    }

    cout << "\nFinal Library Hash Table:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Shelf " << i << ": ";

        if (shelf[i].empty())
        {
            cout << "Empty";
        }
        else
        {
            for (int b : shelf[i])
            {
                cout << b << " -> ";
            }
            cout << "NULL";
        }

        cout << endl;
    }

    int searchBook;
    cout << "\nEnter book code to search: ";
    cin >> searchBook;

    int index = searchBook % 10;
    if (index < 0) index += 10;

    bool found = false;

    for (int b : shelf[index])
    {
        if (b == searchBook)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Book found on shelf " << index;
    else
        cout << "Book not found!";

    cout << endl;
    return 0;
}
