#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

std::stack<char> getPuzzleInput();

int main()
{
    std::stack<char> input = getPuzzleInput();

    std::stack<int> stack;

    return 0;
}

std::stack<char> getPuzzleInput()
{
    std::stack<char> puzzle_input;
    std::string line;
    std::ifstream f("test.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            for (auto c : line)
                puzzle_input.push(c);
        }
        
    }

    return puzzle_input;
}