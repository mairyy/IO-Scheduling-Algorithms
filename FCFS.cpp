#include <iostream>

using namespace std;

void FCFS(int requestLocation[], int head, int size) {
    int seekCount = 0, distance = 0, j = 0;
    int seekSequence[size];

    for(int i = 0; i < size; i++) {
        distance = abs(head - requestLocation[i]);
        seekCount += distance;
        seekSequence[j] = requestLocation[i];
        head = requestLocation[i];
        j++;
    }

    cout << "Total seek movements: " << seekCount << endl
        << "Seek sequence: ";
    for (int i = 0; i < size; i++) {
        cout << seekSequence[i];
        if (i != size-1) {
            cout << " -> ";
        }
    }
}

int main() {
    int size, head;
    cout << "Enter size of request array: ";
    cin >> size;
    int requestLocation[size];
    cout << "Enter request locations: ";
    for (int i = 0; i < size; i++) {
        cin >> requestLocation[i];
    }
    cout << "Enter current track postion: ";
    cin >> head;
    FCFS(requestLocation, head, size);
    return 0;
}

/// size = 8 
/// 89 183 37 122 14 124 65 67
/// head = 53