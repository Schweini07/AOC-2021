#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

std::vector<std::vector<int> > getInput();

int main()
{
    std::string gamma, epsilon;
    std::vector<std::vector<int> > o2 = getInput();
    std::vector<std::vector<int> > co2 = o2;

    for (int vecs = 0; vecs < 2; vecs++)
    {
        std::vector<std::vector<int> > &vec = vecs == 0 ? o2 : co2;
        int j = 0;
        for (int bit = 0; bit < 12; bit++)
        {
            int one_count = 0;
            int zero_count = 0;

            for (int i = 0; i < vec.size(); i++)
            {
                for (; j < vec[i].size();)
                {
                    if (bit > 0)
                    {
                        if (vec.size() == 1) break;
                        if ((gamma == "1" && vecs == 0) || (gamma == "0" && vecs == 0))
                            vec.erase(std::remove(vec.begin(), vec.end(), vec[i]), vec.end());
                    }
                    vec[i][j] == 0 ? zero_count++ : one_count++;
                    break;
                }
            }
            j++;

            int count_difference = one_count - zero_count;
            gamma += count_difference >= 0 ? "1" : "0";
            epsilon += gamma == "0" ? "1" : "0";
            std::cout << gamma << " | " << epsilon << std::endl;
        }
    }

    std::cout << "O2: ";
    for (auto b : o2[0])
    {
        std::cout << b;
    }
    std::cout << "\nCO2: ";
    for (auto b : co2[0])
    {
        std::cout << b;
    }
    std::cout << std::endl;

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

    return input;
}