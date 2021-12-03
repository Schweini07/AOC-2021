#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

std::vector<std::pair<std::string, int> > getPuzzleInput();

int main()
{
    int pos_x = 0;
    int depth = 0;
    int aim = 0;
    std::vector<std::pair<std::string, int> > puzzle_input = getPuzzleInput();

    for (auto cmd : puzzle_input)
    {
        if (cmd.first == "forward")
        {
            pos_x += cmd.second;
            depth += cmd.second*aim;
        }
        else
            cmd.first == "up" ? aim -= cmd.second : aim += cmd.second;
    }

    std::cout << "Pos X is: " << pos_x << " Depth is: " << depth << std::endl;

    return 0;
}

std::vector<std::pair<std::string, int> > getPuzzleInput()
{
    std::vector<std::pair<std::string, int> > puzzle_input;
    std::string line;
    std::ifstream f("puzzle_input.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            std::size_t sep_pos = line.find(" ");
            puzzle_input.push_back(std::make_pair(line.substr(0, sep_pos), std::stoi(line.substr(sep_pos))));
        }
        
    }

    return puzzle_input;
}