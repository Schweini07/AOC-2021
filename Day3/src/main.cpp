#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<std::vector<int> > getInput();
std::vector<int> getBinaryWithCriteria(std::vector<std::vector<int> > input, bool least_common);

int main()
{
    std::vector<std::vector<int> > input = getInput();
    std::vector<int> o2 = getBinaryWithCriteria(input, false);


    return 0;
}

std::vector<int> getBinaryWithCriteria(std::vector<std::vector<int> > input, bool least_common)
{
    std::vector<int> output;

    for (int bit = 0; bit < 12; bit++)
    {
        int bit_count = 0;
        bool most_common;
        for (int i = 0; i < input.size(); i++)
        {
            if (bit > 0)
            {
                if (least_common && most_common == 0) break;
                else if (!least_common && most_common == 1) break;
                input.erase(std::remove(input.begin(), input.end(), input[i]), input.end());
            }

            bit_count += input[i][bit] == 0 ? -1 : 1;
        }
        bit_count >= 0 ? most_common = 1 : most_common = 0;
        
        std::cout << most_common << std::endl;
    }

    return output;
}

std::vector<std::vector<int> > getInput()
{
    std::vector<std::vector<int> > input;
    std::string line;
    std::ifstream f("input.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            std::vector<int> binary;
            for (auto c : line)
            {
                binary.push_back(c-'0');
            }
            input.push_back(binary);
        }
    }

    return input;
}