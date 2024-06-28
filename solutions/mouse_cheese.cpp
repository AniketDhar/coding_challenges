#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int shortestPathToCheese(std::vector<std::vector<char>>& grid)
{
    int rowSize = grid.size();
    if (rowSize == 0)
        return -1;
    int colSize= grid[0].size();
    if (colSize == 0)
        return -1;

    std::queue<std::tuple<int, int, int>> q; // x, y, length
    std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    std::vector<std::vector<bool>> visited(rowSize, std::vector<bool>(colSize, false)); // to mark visited cells

    // find all the starting mouse positions and push them in the Q
    for(int i = 0; i < rowSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            if(grid[i][j] == 'M')
            {
                q.push({i, j, 0});
                visited[i][j] = true;
            }                
        }
    }

    while(!q.empty())
    {
        auto [x, y, length] = q.front();
        q.pop();

        // if cheese found, return length
        if(grid[x][y]=='C')
            return length;

        for(const auto& dir : directions)
        {
            int xx = x + dir[0];
            int yy = y + dir[1];

            if(xx >= 0 && xx < rowSize && yy >= 0 && y < colSize && !visited[xx][yy] && grid[xx][yy]!='1')
            {
                q.push({xx, yy, length+1}); // push the new cell
                visited[xx][yy] = true;  // mark as visited
            }
        }
    }

    return -1;
}

int main()
{
    std::vector<std::vector<char>> grid1 = {
        {'M', '0', '1', '0', 'C'},
        {'1', '0', '1', '0', '1'},
        {'0', '0', '0', '0', '0'},
        {'1', '1', '1', '1', '0'},
        {'M', '0', '0', '0', '0'}
    };

    std::vector<std::vector<char>> grid2 = {
        {'M', '1', '1', '1', 'C'},
        {'1', '1', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'M', '1', '1', '1', '1'},
        {'0', '0', '0', '0', '0'}
    };

    std::vector<std::vector<char>> grid3 = {
        {'M', '1', '1', '1', 'C'},
        {'0', '0', '0', '0', '0'},
        {'M', '1', '1', '1', '1'}
    };

    std::vector<std::vector<std::vector<char>>> collection = {grid1, grid2, grid3};

    for (auto& grid : collection)
    {
        int shortestPathLength = shortestPathToCheese(grid);
        std::cout << shortestPathLength << std::endl;
    }

}