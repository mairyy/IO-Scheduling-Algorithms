#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void LOOK(int size, int requestLocation[], int head, int pre)
{
    vector<int> right;
    vector<int> left;
    vector<int> res;
    for (int i = 1; i <= size; i++)
    {
        if (requestLocation[i] > head)
        {
            right.push_back(requestLocation[i]);
        }
        else
        {
            left.push_back(requestLocation[i]);
        }
    }
    sort(right.begin(), right.end());
    sort(left.begin(), left.end());
    int total = 0;
    if (pre < head)
    {
        for (int i = 0; i < right.size(); i++)
        {
            res.push_back(right[i]);
            total += abs(right[i] - head);
            head = right[i];
        }
        total += abs(left[left.size() - 1] - head);
        head = left[left.size() - 1];
        for (int i = left.size() - 1; i >= 0; i--)
        {
            res.push_back(left[i]);
            total += abs(left[i] - head);
            head = left[i];
        }
    }
    else if (pre > head)
    {
        for (int i = left.size() - 1; i >= 0; i--)
        {
            res.push_back(left[i]);
            total += abs(left[i] - head);
            head = left[i];
        }
        total += abs(right[0] - head);
        head = right[0];
        for (int i = 0; i < right.size(); i++)
        {
            res.push_back(right[i]);
            total += abs(right[i] - head);
            head = right[i];
        }
    }
    cout << "Total seek distance: " << total << endl;
    cout << "Seek sequence is: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
int main()
{
    int size, head, pre, requestLocation[1000];
    cout << "Enter size of request array: ";
    cin >> size;
    cout << "Enter the request locations: ";
    for (int i = 1; i <= size; i++)
    {
        cin >> requestLocation[i];
    }
    cout << "Enter current track position ";
    cin >> head;
    cout << "Enter the previous track position: ";
    cin >> pre;
    LOOK(size, requestLocation, head, pre);
}