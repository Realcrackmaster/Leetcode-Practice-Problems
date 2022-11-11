#include <bits/stdc++.h>

#define pb             push_back
#define endl "\n" 
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define IO	       { ios_base::sync_with_stdio(false); cin.tie(0); }
#define read(x)	       freopen(x, "r", stdin)
#define write(x)       freopen(x, "w", stdout)

using namespace std;

typedef long long      ll;
typedef pair<int, int> ii;
typedef vector<int>    vi;


int main() {
    int size{0}; cin >> size;
    vector <int> nums(size);
    for (int i{0}; i < size; i++)
        cin >> nums[i];
    if (size == 1) return 0;

    int right_most_peak_index{-1};
    for (int i{1}; i < size; i++) // Finding right most peak. Caution: i = 1 theke start korte hobe neile er age garbage value provide korbe
    {
        if (nums[i] > nums[i-1]) 
        {
            right_most_peak_index = i;
        }
    }

    if (right_most_peak_index == -1) 
    {
        for (int i{0}; i < size/2; i++)
        {
            swap (nums[i], nums[size - i - 1]);
        }
    }

    // Handling the special case
    int peak_ind = right_most_peak_index;
    for (int i{right_most_peak_index}; i < size; i++)
    {
        if (nums[i] > nums[right_most_peak_index-1] and nums[i] < nums[peak_ind])
        {
            peak_ind = i;
        }
    }
    
    swap(nums[right_most_peak_index-1], nums[peak_ind]);
    sort(nums.begin() + right_most_peak_index, nums.end());
    for (int i{0}; i < size; i++)
        cout << nums[i] << " ";
}