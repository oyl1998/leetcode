#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int vvlen = grid.size();
        int vlen = grid[0].size();
        vector<int> res = {0, 0};
        int flag[50*50+2] = {0};
        for (int i = 0;i < vvlen; i++) {
            for (int j = 0;j < vlen; j++) {
                flag[grid[i][j]]++;
            }   
        }
        for (int i = 1; i <= vvlen*vlen; i++) {
            if (flag[i] == 2)
                res[0] = i;
            if (flag[i] == 0)
                res[1] = i;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};

    Solution A;
    vector<int> res = A.findMissingAndRepeatedValues(grid);
    printf("%d %d\n", res[0], res[1]);
    return 0;
}