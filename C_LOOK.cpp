#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, s, pre, a[1000];
    int total = 0;
    cout << "Number of request: ";
    cin >> n;
    cout << "List of request: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << "Initial head position: ";
    cin >> s;
    cout << "The previous position: ";
    cin >> pre;
    vector<int> right;
    vector<int> left;
    vector<int> res;
    //chia yeu cau thanh hai phia
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
    //sap xep hai phia yeu cau tang dan
    sort(right.begin(), right.end());
    sort(left.begin(), left.end());
    //truong hop huong di la phai
    if (pre < s)
    {
        for (int i = 0; i < right.size(); i++)
        {
            res.push_back(right[i]);
            total += abs(right[i] - s);
            s = right[i];
        }
        s = left[0];
        for (int i = 0; i < left.size(); i++)
        {
            res.push_back(left[i]);
            total += abs(left[i] - s);
            s = left[i];
        }
    }
    //truong hop huong di la trai
    else if (pre > s)
    {
        for (int i = left.size() - 1; i >= 0; i--)
        {
            res.push_back(left[i]);
            total += abs(left[i] - s);
            s = left[i];
        }
        s = right[right.size() - 1];
        for (int i = right.size() - 1; i >= 0; i--)
        {
            res.push_back(right[i]);
            total += abs(right[i] - s);
            s = right[i];
        }
    }
    cout << "Total number of seek operations = ";
    cout << total << endl;
    cout << "Seek sequence is: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}