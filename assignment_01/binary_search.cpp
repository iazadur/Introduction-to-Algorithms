#include <bits/stdc++.h>
using namespace std;
int binary_search(vector<int> &nums, int x, int l, int r)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (nums[mid] == x)
        return mid;
    else if (nums[mid] > x)
        return binary_search(nums, x, l, mid - 1);
    else
        return binary_search(nums, x, mid + 1, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

  
        int x;
        cin >> x;
        int index = binary_search(nums, x, 0, n - 1);
        if (index != -1)
            cout << index << endl;
        else
            cout << "Not Found" << endl;
    
    return 0;
}