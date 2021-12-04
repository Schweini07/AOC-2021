#include "bingo.h"

#include <iostream>
#include <algorithm>

Bingo::Bingo(std::vector<int> nums_to_draw, std::vector<std::vector<std::vector<std::pair<int, int> > > > boards_vec)
{
    draw_nums = nums_to_draw;
    boards = boards_vec;

    start();
}

void Bingo::start()
{
    for (int num = 0; num < draw_nums.size(); num++)
    {
        for (int board = 0; board < boards.size();)
        {
            checkNumbersOnBoard(draw_nums[num], board);
            bool won = checkForWin(boards[board]);
            if (won)
            {
                std::cout << "Size: " << boards.size() << " ";
                if (boards.size() > 1)
                    boards.erase(std::remove(boards.begin(), boards.end(), boards[board]), boards.end());
                std::cout << boards.size() << std::endl;
                
                if (boards.size() == 1)
                {
                    std::cout << "Board: " << boards.size() << std::endl;
                    std::cout << "WON! Final drawn Number was: " << draw_nums[num] << std::endl
                    << "Sum of all unchecked numbers are: " << sumOfAllUncheckedNums(boards[board]) << std::endl;

                    return;
                }
            }
            if (!won) board++;
        }
    }
}

void Bingo::checkNumbersOnBoard(int drawn_num, int board)
{
    for (int i = 0; i < boards[board].size(); i++)
    {
        for (int j = 0; j < boards[board][i].size(); j++)
        {
            if (boards[board][i][j].first == drawn_num)
                boards[board][i][j].second = 1;
        }
    }

/*
    for (int i = 0; i < boards.size(); i++)
    {
        for (int j = 0; j < boards[i].size(); j++)
        {
            for (int k = 0; k < boards[i][j].size(); k++)
            {
                std::cout << boards[i][j][k].first << ", " << boards[i][j][k].second << " | ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
*/
}

bool Bingo::checkForWin(std::vector<std::vector<std::pair<int, int> > > board)
{
    // Check Rows for Bingo
    for (int i = 0; i < board.size(); i++)
    {
        bool won = true;
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j].second == 0) won = false;
        }
        if (won)
        {
            for (int k = 0; k < board.size(); k++)
            {
                for (int l = 0; l < board[k].size(); l++)
                {
                    std::cout << board[k][l].first << " " << board[k][l].second << " | ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;

            return true;
        }
    }

    // Check Columns for Bingo
    for (int i = 0; i < board.size(); i++)
    {
        bool won = true;
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[j][i].second == 0) won = false;
        }
        if (won)
        {
            for (int k = 0; k < board.size(); k++)
            {
                for (int l = 0; l < board[k].size(); l++)
                {
                    std::cout << board[k][l].first << " " << board[k][l].second << " | ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;

            return true;
        }
    }

    return false;
}

int Bingo::sumOfAllUncheckedNums(std::vector<std::vector<std::pair<int, int> > > board)
{
    std::vector<int> unchecked_nums;

    std::cout << board.size() << std::endl;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            std::cout << board[i][j].first << " " << board[i][j].second << std::endl;
            if (board[i][j].second == 0)
                unchecked_nums.push_back(board[i][j].first);
            
            std::cout << board[i][j].first << std::endl;
        }
    }

    int sum = 0;
    for (auto n : unchecked_nums)
        sum += n;

    return sum;
}