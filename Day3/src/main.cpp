#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > getInput();
std::string coutBinary(std::vector<int> binary);
std::vector<int> getBinaryWithCriteria(std::vector<std::vector<int> > input, bool least_common);

int main()
{
    std::vector<std::vector<int> > input = getInput();
    std::vector<int> o2 = getBinaryWithCriteria(input, false);
    std::vector<int> co2 = getBinaryWithCriteria(input, true);

    std::cout << "\nO2: " << coutBinary(o2) << "\nCo2: " << coutBinary(co2) << std::endl;

    return 0;
}

std::vector<int> getBinaryWithCriteria(std::vector<std::vector<int> > input, bool least_common)
{
    std::vector<int> output;

    std::cout << std::endl;

    for (int bit = 0; bit < 12; bit++)
    {
        //std::cout << "Bit: " << bit << std::endl;
        int bit_count = 0;
        int most_common;
        std::cout << std::endl;
        for (int i = 0; i < input.size(); )
        {
            input[i][bit] == 0 ? bit_count -= 1 : bit_count += 1;

            bool erased = false;
            if (bit > 0)
            {
                std::cout << coutBinary(input[i]) << " " << input[i][bit-1] << " " << most_common << " " << i << ", ";
                if ((input[i][bit-1] != most_common && !least_common) || (input[i][bit-1] == most_common && least_common))
                {
                    erased = true;
                    input.erase(std::remove(input.begin(), input.end(), input[i]), input.end());
                }
                if (input.size() == 1)
                {
                    std::cout << " HIHIHFDISH" << std::endl;
                    for (auto b : input[0])
                    {
                        output.push_back(b);
                    }
                    return output;
                }
            }

            //std::cout << coutBinary(input[i]) << " " << input[i][bit-1] << ", ";

            if (!erased) i++;
        }
        //std::cout << "\nBit count: " << bit_count << std::endl;
        if (bit_count == 0)
            least_common ? most_common == 0 : most_common == 1;
        else
            bit_count > 0 ? most_common = 1 : most_common = 0;
    }

    std::cout << "\nInput Size: " << input.size() << std::endl;
    for (auto b : input[1])
    {
        output.push_back(b);
    }
    return output;
}

std::string coutBinary(std::vector<int> binary)
{
    std::string str;
    
    for (auto b : binary)
    {
        str += std::to_string(b);
    }
    
    return str;
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