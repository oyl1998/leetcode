#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ret = 0;
        int ret0 = 0;
        int ret1 = 0;
        int ret3 = 0;

        for (int i = 0;i < nums.size(); i++) {
            if (nums[i]%2 == 0)
                ret0++;
            else
                ret1++;
        }
        ret = max(ret0, ret1);
        for (int i = 1; i < nums.size(); i++) {
            int tmp = (nums[i] + nums[i-1]) % 2;

            // tmp == 1
            if (tmp == 1)
                ret3++;
        }

        ret = max(ret, ret3+1);
        return ret;
    }
};

int main()
{

    return 0;
}