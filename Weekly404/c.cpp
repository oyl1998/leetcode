#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {

        int ret = 0;

        int sums[1005] = {0};
        set<int> se;
        int Max_sum = 0;

        nums[0] %= k;
        for (int i = 1; i < nums.size(); i++) {
            nums[i] %= k;

            int tmp = (nums[i] + nums[i-1]) % k;
            // Max_sum = max(Max_sum, tmp);
            se.insert(tmp);
        }

        for (auto x:se) {
            int i = x;
            for (int j = 0;j < nums.size(); j++) {
                
                int len = 1;
                int l = j-1;
                int ld = j;

                int rd = j;
                int r = j+1;

                while (l >= 0) {
                    if ((nums[l] + nums[ld])%k == i) {
                        len++;
                        ld = l;
                    }
                    l--;
                }
                while (r < nums.size()) {
                    if ((nums[rd] + nums[r])%k == i) {
                        len++;
                        rd = r;
                    }
                    r++;
                }
                ret = max(ret, len);
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums();
    Solution A;

    return 0;
}