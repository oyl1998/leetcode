#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int Max = max(red, blue);
        int Min = min(red, blue);

        int Max1 = Max;
        int Min1 = Min;

        int ret = 0;
        int num = 1;
        while (Max >= 0 && Min >= 0) {
            if (num%2 == 1) {
                if (Max >= num) {
                    ret++;
                    Max -= num;
                }
                else break;
            }
            else {
                if (Min >= num) {
                    ret++;
                    Min -= num;
                }
                else break;
            }
            num++;
        }
        int ret1 = ret;
        ret = 0;
        num = 1;
        Max = Max1;
        Min = Min1;
        while (Max >= 0 && Min >= 0) {
            if (num%2 == 0) {
                if (Max >= num) {
                    ret++;
                    Max -= num;
                }
                else break;
            }
            else {
                if (Min >= num) {
                    ret++;
                    Min -= num;
                }
                else break;
            }
            num++;
        }
        int ret2 = ret;
        cout << ret1 << " " << ret2 << endl;
        return max(ret1, ret2);
    }
};

int main()
{
    Solution A;
    cout << A.maxHeightOfTriangle(1, 2) << endl;
    getchar();
    return 0;
}