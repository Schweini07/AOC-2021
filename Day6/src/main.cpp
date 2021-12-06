#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<int, long long> getPuzzleInput();

int main()
{
    std::unordered_map<int, long long> input = getPuzzleInput();

    for (int i = 0; i < 256; i++)
    {
        std::cout << i << ": ";
        for (int j = 0; j < input.size(); j++)
        {
            std::cout << j << ": " << input[j] << ", ";
        }
        std::cout << std::endl;

        long long first_fish = input[0];
        bool add_first_fish = false;
        for (int j = 0; j < input.size(); j++)
        {
            if (input[j] > 0)
            {
                if (j == 0)
                {
                    add_first_fish = true;
                    input[0] = 0;
                }
                else
                {
                    input[j-1] += input[j];
                    input[j] = 0;
                }
            }
        }
        if (add_first_fish)
        {
            input[6] += first_fish;
            input[8] += first_fish;
        }
    }

    long long sum = 0;
    for (const auto fish_type : input)
    {
        sum += fish_type.second;
    }

    std::cout << "\nThere are " << sum << " laternfishs." << std::endl;

    return 0;
}

std::unordered_map<int, long long> getPuzzleInput()
{
    std::unordered_map<int, long long> puzzle_input;
    std::string line;
    std::ifstream f("puzzle_input.txt");

    for (int i = 0; i < 9; i++)
        puzzle_input[i] = 0;

    if (f.is_open())
    {
        while (getline(f, line))
        {
            std::string::size_type n = line.find(",");
            puzzle_input[std::stoi(line.substr(n-1, 1))]++;
            while (n != std::string::npos)
            {
                puzzle_input[std::stoi(line.substr(++n, 1))]++;
                n = line.find(",", ++n);
            }
        }
        
    }

    return puzzle_input;
}