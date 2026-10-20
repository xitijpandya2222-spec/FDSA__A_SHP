

#include <iostream>
using namespace std;

int main()
{
    int table[10] = {0};
    bool occupied[10] = {false};
    int n, vehicle;

    cout << "Enter number of vehicles: ";
    cin >> n;

    if (n < 0 || n > 10)
    {
        cout << "Invalid number of vehicles!";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter vehicle number: ";
        cin >> vehicle;

        int index = vehicle % 10;
        if (index < 0) index += 10;

        int start = index;

        while (occupied[index])
        {
            cout << "Slot " << index
                 << " is occupied. Checking next slot.\n";

            index = (index + 1) % 10;

            if (index == start)
            {
                cout << "Parking lot is full!\n";
                break;
            }
        }

        if (!occupied[index])
        {
            table[index] = vehicle;
            occupied[index] = true;
            cout << "Vehicle parked at slot "
                 << index << "\n";
        }
    }

    cout << "\nFinal Parking Table:\n";
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
