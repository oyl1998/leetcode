#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int res_all;

    int dfs(vector<vector<int>>& g, int x, int fa) {
        int max_len = 0;
        for(auto &y : g[x]) {
            if (y != fa) {
                int sub_len = dfs(g, y, x) + 1;
                res_all = max(res_all, max_len + sub_len);
                max_len = max(max_len, sub_len);
            }
        }
        return max_len;
    }

    int diameter(vector<vector<int>>& edges) {
        vector<vector<int>> g(edges.size() + 1); // n+1个点
        for (auto &e : edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        int res = 0;

        // auto dfs = [&](auto &&dfs, int x, int fa) -> int {
        //     int max_len = 0;
        //     for(auto y : g[x]) {
        //         int sub_len = dfs(dfs, y, x) + 1;
        //         res = max(res, max_len + sub_len);
        //         max_len = max(max_len, sub_len);
        //     }
        // }
        res = dfs(g, 0, -1);
        res = res_all;
        return res;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        res_all = 0;
        int d1 = diameter(edges1);
        res_all = 0;
        int d2 = diameter(edges2);
        int d3 = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
        int res = max(d1, d2);
        res = max(res, d3);
        return res;
    }
};

int main()
{
    return 0;
}