#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void C_LOOK(int n, int requestLocation[], int head, int pre)
{
    vector<int> right;
    vector<int> left;
    vector<int> res;
    for (int i = 1; i <= n; i++)
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
        head = left[0];
        for (int i = 0; i < left.size(); i++)
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
        head = right[right.size() - 1];
        for (int i = right.size() - 1; i >= 0; i--)
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
    int n, head, pre, requestLocation[1000];
    cout << "Enter size of request array: ";
    cin >> n;
    cout << "Enter the request locations: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> requestLocation[i];
    }
    cout << "Enter current track position ";
    cin >> head;
    cout << "Enter the previous track position: ";
    cin >> pre;
    C_LOOK(n, requestLocation, head, pre);
}