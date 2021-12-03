#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::vector<int> > getInput();

int main()
{
    std::vector<std::vector<int> > input = getInput();
    std::string gamma, epsilon;
    std::vector<std::vector<int> > o2, co2;

    int j = 0;
    for (int k = 0; k < 12; k++)
    {
        int one_count = 0;
        int zero_count = 0;
        for (int i = 0; i < input.size(); i++)
        {
            for (; j < input[i].size();)
            {
                //std::cout << i << ", " << j << " | ";
                input[i][j] == 0 ? zero_count++ : one_count++;
                break;
            }
        }
        //std::cout << std::endl;
        j++;

        if (one_count > zero_count)
        {
            gamma += "1";
            epsilon += "0";
        }
        else
        {
            gamma += "0";
            epsilon += "1";
        }
    }

    std::cout << gamma << " " << epsilon << std::endl;

    return 0;
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

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            std::cout << input[i][j];
        }
        std::cout << std::endl;
    }

    return input;
}