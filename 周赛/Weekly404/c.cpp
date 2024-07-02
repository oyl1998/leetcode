#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int res = 0;

        int n = nums.size();
        vector<vector<int>> cnt(k, vector<int>(k));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                int x = nums[i] % k;
                int y = (j - nums[i] % k + k) % k;

                cnt[y][x] = cnt[x][y] + 1;
                res = max(res, cnt[y][x]);
            }
        }

        // for (int i = 0;i < nums.size(); i++) {
        //     for (int j = 0;j < k; j++) {
        //         printf("%d ", f[i][j]);
        //     }
        //     printf("\n");
        // }
        return res;
    }
};

int main()
{
    int k = 3;
    vector<int> nums{1,4,2,3,1,4};

    // for (int i = 0;i < nums.size(); i++) printf("%d ", nums[i]);
    Solution A;
    int res = A.maximumLength(nums, k);
    cout << res << endl;
    return 0;
}