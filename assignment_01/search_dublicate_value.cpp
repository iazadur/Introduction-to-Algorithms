#include <bits/stdc++.h>
using namespace std;
int flag = 0;
int first_search(int nums[], int x, int l, int r)
{

    if (l > r)
        return 0;
    int mid = (l + r) / 2;
    if (nums[mid] == x)
    {
        if (flag == 0)
        {
            flag = 1;
            return first_search(nums, x, l, mid - 1);
        }
        else
        {
            flag = 2;
            return flag;
        }

        flag = 1;
        return mid;
    }
    else if (nums[mid] > x)
        return first_search(nums, x, l, mid - 1);
    else
        return first_search(nums, x, mid + 1, r);
}
int last_search(int nums[], int x, int l, int r)
{
 
    if (l > r)
        return 0;
    int mid = (l + r) / 2;
    if (nums[mid] == x)
    {
        if (flag == 0)
        {
            flag = 1;
            return last_search(nums, x, mid + 1, r);
        }
        else
        {
            flag = 2;
            return flag;
        }

        flag = 1;
        return mid;
    }
    else if (nums[mid] > x)
        return last_search(nums, x, l, mid - 1);
    else
        return last_search(nums, x, mid + 1, r);
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int x;
    cin >> x;
    flag = 0;
    int first = first_search(nums, x, 0, n - 1);
    flag = 0;
    int last = last_search(nums, x, 0, n - 1);

    if (last - first > 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}