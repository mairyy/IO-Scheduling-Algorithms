#include <iostream>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

void SCAN(int requestLocation[], int head, int pre, int size, int tracks) {
    int k = -1, distance = 0, seekCount = 0, j = 0;
    int seekSequence[size];
    sort(requestLocation, requestLocation + size);
    if (pre < head) {
        for (int i = 0; i < size; i++) {
            if (requestLocation[i] < head) {
                continue;
            } else {
                if (k == -1) {
                    k = i;
                }
                distance = abs(head - requestLocation[i]);
                seekCount += distance;
                head = requestLocation[i];
                seekSequence[j] = requestLocation[i];
                j++;
            }
        }
        seekCount += abs(head - tracks + 1);
        head = tracks - 1;
        for (int z = k - 1; z >= 0; z--) {
            distance = abs(head - requestLocation[z]);
            seekCount += distance;
            head = requestLocation[z];
            seekSequence[j] = requestLocation[z];
            j++;
        }
    } else {
        for (int i = size-1; i >= 0; i--) {
            if (requestLocation[i] > head) {
                continue;
            } else {
                if (k == -1) {
                    k = i;
                }
                distance = abs(head - requestLocation[i]);
                seekCount += distance;
                head = requestLocation[i];
                seekSequence[j] = requestLocation[i];
                j++;
            }
        }
        seekCount += head;
        head = 0;
        for (int z = k + 1; z < size; z++) {
            distance = abs(head - requestLocation[z]);
            seekCount += distance;
            head = requestLocation[z];
            seekSequence[j] = requestLocation[z];
            j++;
        }
    }

    cout << "Total seek distance: " << seekCount << endl
        << "Seek sequence: ";
    for (int i = 0; i < size; i++) {
        cout << seekSequence[i];
        if (i != size-1) {
            cout << " -> ";
        }
    }
}

int main() {
    int tracks, size, head, pre;
    cout << "Enter total number of tracks in disk: ";
    cin >> tracks;
    cout << "Enter size of request array: ";
    cin >> size;
    int requestLocation[size];
    cout << "Enter request locations: ";
    for (int i = 0; i < size; i++) {
        cin >> requestLocation[i];
    }
    cout << "Enter current and previous track postion: ";
    cin >> head >> pre;
    SCAN(requestLocation, head, pre, size, tracks);
    return 0;
}

/// tracks = 5000 size = 10
/// 2069 1212 2296 2800 544 1618 356 1523 4965 3681
/// head = 2150 pre 1085