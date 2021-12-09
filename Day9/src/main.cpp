#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::vector<int> > getPuzzleInput();
bool isSmaller(std::vector<std::vector<int> > input, int row, int n, int level);

// This solution is hard on performance, there was a faster one before, but for readability's sake it changed
int main()
{
    std::vector<std::vector<int> > input = getPuzzleInput();

    int risk_level = 0;
    for (int row = 0; row < input.size(); row++)
    {
        for (int n = 0; n < input[row].size(); n++)
        {
            int level = input[row][n];
            if (isSmaller(input, row+1, n, level) && isSmaller(input, row-1, n, level)
            && isSmaller(input, row, n+1, level) && isSmaller(input, row, n-1, level))                
                risk_level += level+1;
        }
        std::cout << std::endl;
    }

    std::cout << "Risk level is: " << risk_level << std::endl;

    return 0;
}

bool isSmaller(std::vector<std::vector<int> > input, int row, int n, int level)
{
    try
    {
        if (level < input.at(row).at(n))
            return true;
    }
    catch (...)
    {
        return true;
    }
    
    return false;
}

std::vector<std::vector<int> > getPuzzleInput()
{
    std::vector<std::vector<int> > puzzle_input;
    std::string line;
    std::ifstream f("puzzle_input.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            std::vector<int> row;
            for (auto c : line)
            {
                row.push_back(c - '0');
            }
            puzzle_input.push_back(row);
        }
        
    }

    return puzzle_input;
}