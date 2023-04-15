#include <iostream>
#include <vector>
using namespace std;
bool check[1000] = {0};
//tim vi tri gan head nhat
int findMin(int n, int a[], int s)
{
    int min = 9999;
    int index;
    for (int i = 1; i <= n; i++)
    {
        if (!check[a[i]] && abs(a[i] - s) < min)
        {
            min = abs(a[i] - s);
            index = i;
        }
    }
    return index;
}
int main()
{
    int n, s, a[1000];
    cout << "Number of request: ";
    cin >> n;
    cout << "List of request: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << "Initial head position: ";
    cin >> s;
    int sum = 0;
    int i = 0;
    vector<int> res;
    //lap cho toi khi thuc hien du n yeu cau
    while (i <= n)
    {
        int j = findMin(n, a, s);
        sum += abs(a[j] - s);
        s = a[j];
        check[a[j]] = 1;
        res.push_back(a[j]);
        i++;
    }
    cout << "Total number of seek operations = ";
    cout << sum << endl;
    cout << "Seek sequence is: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}