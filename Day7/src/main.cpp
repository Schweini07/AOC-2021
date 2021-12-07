#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> getPuzzleInput();

// Completely inefficient performance-wise, this was just the solution that could be done the fastest
int main()
{
    std::vector<int> input = getPuzzleInput();

    unsigned int lowest_fuel = UINT32_MAX;
    for (int i = 0; i < *std::max_element(input.begin(), input.end()); i++)
    {
        int fuel = 0;
        for (int j = 0; j < input.size(); j++)
        {
            if (input[j] == i) continue;

            int steps = input[j] > i ? input[j] - i : i - input[j];
            for (int k = 1; k <= steps; k++)
                fuel += k;
        }
        if (fuel < lowest_fuel) lowest_fuel = fuel;
    }

    std::cout << lowest_fuel << std::endl;

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
            std::string::size_type n = line.find(",");
            puzzle_input.push_back(std::stoi(line.substr(0, n)));

            int last_found_pos = n;
            while (n != std::string::npos)
            {
                n = line.find(",", n+1);
                puzzle_input.push_back(std::stoi(line.substr(last_found_pos+1, n-last_found_pos)));
                last_found_pos = n;
            }
            
        }
        
    }

    return puzzle_input;
}