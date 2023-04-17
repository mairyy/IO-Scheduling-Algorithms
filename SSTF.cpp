#include <iostream>
#include <vector>
using namespace std;
bool check[1000] = {0};
int find_nearest(int size, int requestLocation[], int head)
{
    int min = 9999;
    int index;
    for (int i = 1; i <= size; i++)
    {
        if (!check[requestLocation[i]] && abs(requestLocation[i] - head) < min)
        {
            min = abs(requestLocation[i] - head);
            index = i;
        }
    }
    return index;
}
void SSTF(int size, int requestLocation[], int head)
{
    int seekCount = 0;
    vector<int> seekSequence;
    int i = 0;
    while (i < size)
    {
        int j = find_nearest(size, requestLocation, head);
        seekCount += abs(requestLocation[j] - head);
        head = requestLocation[j];
        check[requestLocation[j]] = 1;
        seekSequence.push_back(requestLocation[j]);
        i++;
    }
    cout << "Total seek distance: " << seekCount << endl;
    cout << "Seek sequence is: ";
    for (int i = 0; i < seekSequence.size(); i++)
    {
        cout << seekSequence[i] << " ";
    }
}
int main()
{
    int size, head, requestLocation[1000];
    cout << "Enter size of request array: ";
    cin >> size;
    cout << "Enter the request locations: ";
    for (int i = 1; i <= size; i++)
    {
        cin >> requestLocation[i];
    }
    cout << "Enter current track position ";
    cin >> head;
    SSTF(size, requestLocation, head);
    return 0;
}