#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 0) return -1;

        vector<pair<int, int>> shift = {{0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> distance(n, vector<int>(n, -1));

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        distance[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n-1 && y == n-1) return distance[x][y];

            for (auto [dx, dy] : shift) {
                int newX = x + dx;
                int newY = y + dy;
                if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                    if (!visited[newX][newY] && grid[newX][newY] == 0) {
                        visited[newX][newY] = true;
                        distance[newX][newY] = distance[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return -1; 
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {1, 1, 1},
        {1, 1, 0}
    };
    Solution sol;
    cout << sol.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}