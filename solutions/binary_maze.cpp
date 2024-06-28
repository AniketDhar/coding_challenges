#include <iostream>
#include <vector>
#include <queue>

int shortestPathBinaryMaze(std::vector<std::vector<int>>& grid)
{
    int pathLength = 1;
    
    // If grid is empty or first row is empty, return -1
    int rowSize = grid.size();
    if (rowSize == 0)
        return -1;

    int colSize = grid[0].size();
    if (colSize == 0)
        return -1;

    // If top-left or botton-right cell is blocked, return -1
    if ((grid[0][0] == 0) || (grid[rowSize-1][colSize-1] == 0))
        return -1;

    // define the possible movement directions
    std::vector<std::vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::queue<std::pair<int, int>> q; // define Q for BFS
    q.push({0, 0}); // initialize first element

    grid[0][0] = 0; // mark as visited

    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i < size; ++i)
        {
            auto current = q.front();
            q.pop();

            int x = current.first;
            int y = current.second;

            if(x == rowSize-1 && y == colSize-1)    // reached bottom right
                return pathLength;

            for(const auto& dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if( newX >= 0 && newY >= 0 && newX < rowSize && newY < colSize 
                    && grid[newX][newY] ==1 )
                {
                    q.push({newX, newY});
                    grid[newX][newY] = 0; // mark as visited
                }
            }
        }
        pathLength++;
    }

    return -1;
}

int main()
{
    std::vector<std::vector<int>> grid1 = 
    {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1}
    };

    std::vector<std::vector<int>> grid2 = 
    {
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
    };

    std::vector<std::vector<int>> grid3 = 
    {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    std::vector<std::vector<int>> grid4 = 
    {
        {1, 0, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    std::vector<std::vector<std::vector<int>>> grids = {grid1, grid2, grid3, grid4};

    for (auto& grid : grids)
    {
        int lengthPath = shortestPathBinaryMaze(grid);
        std::cout << "Shortest path for grid1 " << lengthPath << std::endl;
    }

}