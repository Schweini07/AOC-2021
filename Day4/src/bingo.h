#ifndef _BINGO_
#define _BINGO_

#include <vector>

class Bingo
{
    public:
        Bingo(std::vector<int> nums_to_draw, std::vector<std::vector<std::vector<std::pair<int, int> > > > boards_vec);
    
    private:
        std::vector<int> draw_nums;
        std::vector<std::vector<std::vector<std::pair<int, int> > > > boards;

        void start();
        void checkNumbersOnBoard(int drawn_num, int board);
        bool checkForWin(std::vector<std::vector<std::pair<int, int> > > board);
        int sumOfAllUncheckedNums(std::vector<std::vector<std::pair<int, int> > > board);
};

#endif