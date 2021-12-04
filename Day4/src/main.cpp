#include "bingo.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

std::pair<std::vector<int>, std::vector<std::vector<std::vector<std::pair<int, int> > > > > getPuzzleInput();

int main()
{
    std::pair<std::vector<int>, std::vector<std::vector<std::vector<std::pair<int, int> > > > > input = getPuzzleInput();
    Bingo bingo (input.first, input.second);

    return 0;
}

std::pair<std::vector<int>, std::vector<std::vector<std::vector<std::pair<int, int> > > > > getPuzzleInput()
{
    std::vector<int> draw_nums;
    std::vector<std::vector<std::vector<std::pair<int, int> > > > boards;
    std::vector<std::vector<std::pair<int, int> > > board_vec;
    boards.push_back(board_vec);

    std::string line;
    std::ifstream f("puzzle_input.txt");

    if (f.is_open())
    {
        int board = 0;
        int board_row_count = 0;

        while (getline(f, line))
        {
            if (line.size() > 14)
            {
                int last_found_pos = 0;
                std::string::size_type n = 0;
                while (n != std::string::npos)
                {
                    n = line.find(",", n+1);
                    draw_nums.push_back(std::stoi(line.substr(last_found_pos, n-last_found_pos)));
                    last_found_pos = n+1;
                }
            }
            else if (line.size() > 0)
            {
                std::vector<std::pair<int, int> > new_row;
                boards[board].push_back(new_row);

                for (int i = 0; i < 15; i+=3)
                    boards[board][board_row_count].push_back(std::make_pair(std::stoi(line.substr(i, 2)), 0));
                
                board_row_count++;
                if (board_row_count > 4)
                {
                    boards.push_back(board_vec);
                    board++;
                    board_row_count = 0;
                }
            }
        }
        
    }

    return std::make_pair(draw_nums, boards);
}