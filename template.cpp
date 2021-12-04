#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> getPuzzleInput();

int main()
{


    return 0;
}

std::vector<int> getPuzzleInput()
{
    std::vector<int> puzzle_input;
    std::string line;
    std::ifstream f("puzzle_input.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            
        }
        
    }

    return puzzle_input;
}