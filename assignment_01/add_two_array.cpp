#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int nums1[n];
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    cin >> m;
    int nums2[m];
    for (int i = 0; i < m; i++)
        cin >> nums2[i];

    int left_size = n;
    int L[left_size + 1];

    int right_size = m;
    int R[right_size + 1];

    nums1[left_size] = INT_MIN;
    nums2[right_size] = INT_MIN;
    int nums[n + m];
    int lp = 0, rp = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (nums1[lp] >= nums2[rp])
            nums[i] = nums1[lp++];
        else
            nums[i] = nums2[rp++];
    }

    for (int i = 0; i < n + m; i++)
        cout << nums[i] << " ";
    return 0;
}