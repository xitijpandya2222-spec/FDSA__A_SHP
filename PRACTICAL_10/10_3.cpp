
#include <iostream>
using namespace std;

int main()
{
    int table[10];
    bool occupied[10] = {false};
    int n, id;

    cout << "Enter number of students (max 10): ";
    cin >> n;

    if (n < 0 || n > 10)
    {
        cout << "Invalid number of students!";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;
        if (h1 < 0) h1 += 10;

        int h2 = 2 * (id % 5) + 1;
        if (h2 < 0) h2 += 10;

        bool inserted = false;

        for (int j = 0; j < 10; j++)
        {
            int index = (h1 + j * h2) % 10;

            if (!occupied[index])
            {
                table[index] = id;
                occupied[index] = true;

                cout << "Student ID " << id
                     << " stored at slot " << index << "\n";

                inserted = true;
                break;
            }
            else
            {
                cout << "Collision at slot "
                     << index << ". Trying next position.\n";
            }
        }

        if (!inserted)
        {
            cout << "Hash table is full!\n";
            break;
        }
    }

    cout << "\nFinal Student Hash Table:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "Slot " << i << ": ";

        if (occupied[i])
            cout << table[i];
        else
            cout << "Empty";

        cout << endl;
    }

    return 0;
}
