#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int nums[N];
void merge(int l, int mid, int r)
{
    int left_size = mid - l + 1;
    int L[left_size+1];

    int right_size = r - mid;
    int R[right_size+1];

    for (int i = 0; i < left_size; i++)
        L[i] = nums[l + i];

    for (int i = 0; i < right_size; i++)
        R[i] = nums[mid + 1 + i];

    L[left_size] = INT_MIN;
    R[right_size] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] >= R[rp])
            nums[i] = L[lp++];
        else
            nums[i] = R[rp++];
    }

}

void merge_sort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, r);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;
    
    return 0;
}