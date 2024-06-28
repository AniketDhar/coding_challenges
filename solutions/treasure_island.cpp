#include <iostream>
#include <string>
#include <vector>
#include <queue>

int shortestPathToTreasure(std::vector<std::vector<char>>& grid)
{
    int rowSize = grid.size();
    if (rowSize == 0)
        return -1;
    int colSize = grid[0].size();
    if (colSize == 0)
        return -1;

    // todo
    std::vector<std::vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::queue<std::pair<int, int>> q;
    q.push({0, 0}); //initialize at top left

    int stepCount = 0;

    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; ++i)
        {
            auto current = q.front();
            q.pop();
            int x = current.first;
            int y = current.second;

            if(grid[x][y] == 'X')   // found treasure
                return stepCount;

            for(const auto& dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if(newX >= 0 && newY >= 0 && newX < rowSize && newY < colSize)
                {
                    q.push({newX, newY});
                }
            }

        }
        stepCount++;
    }

    return -1;
}

int main()
{

    std::vector<std::vector<char>> grid1 = {
        {'O', 'O', 'O', 'O'},
        {'L', 'L', 'L', 'O'},
        {'O', 'L', 'O', 'X'},
        {'O', 'O', 'O', 'O'}
    };

    std::vector<std::vector<char>> grid2 = {
        {'O', 'L', 'O'},
        {'O', 'L', 'X'},
        {'O', 'O', 'O'}
    };

    std::vector<std::vector<char>> grid3 = {
        {'O', 'L', 'O'},
        {'O', 'L', 'L'},
        {'O', 'X', 'O'}
    };

    std::vector<std::vector<std::vector<char>>> collection = {grid1, grid2, grid3};

    for(auto& grid : collection)
    {
        int shortestPath = shortestPathToTreasure(grid);
        std::cout << "Shortest path to treasure " << shortestPath << std::endl;
    }

}