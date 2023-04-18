#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void LOOK(int n, int a[], int s, int pre)
{
    vector<int> right;
    vector<int> left;
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > s)
        {
            right.push_back(a[i]);
        }
        else
        {
            left.push_back(a[i]);
        }
    }
    sort(right.begin(), right.end());
    sort(left.begin(), left.end());
    int total = 0;
    if (pre < s)
    {
        for (int i = 0; i < right.size(); i++)
        {
            res.push_back(right[i]);
            total += abs(right[i] - s);
            s = right[i];
        }
        total += abs(left[left.size() - 1] - s);
        s = left[left.size() - 1];
        for (int i = left.size() - 1; i >= 0; i--)
        {
            res.push_back(left[i]);
            total += abs(left[i] - s);
            s = left[i];
        }
    }
    else if (pre > s)
    {
        for (int i = left.size() - 1; i >= 0; i--)
        {
            res.push_back(left[i]);
            total += abs(left[i] - s);
            s = left[i];
        }
        total += abs(right[0] - s);
        s = right[0];
        for (int i = 0; i < right.size(); i++)
        {
            res.push_back(right[i]);
            total += abs(right[i] - s);
            s = right[i];
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
    int n, s, pre, a[1000];
    cout << "Enter size of request array: ";
    cin >> n;
    cout << "Enter the request locations: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter current track position ";
    cin >> s;
    cout << "Enter the previous track position: ";
    cin >> pre;
    LOOK(n, a, s, pre);
}