#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<int> readDepths();
int countIncrements(std::vector<int> depth_values);

int main()
{
    std::vector<int> depth_values;
    depth_values = readDepths();

    std::cout << countIncrements(depth_values) << std::endl;

    return 0;
}

std::vector<int> readDepths()
{
    std::vector<int> depth_values;
    std::string line;
    std::ifstream f("depths.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            depth_values.push_back(std::stoi(line));
        }
    }

    return depth_values;
}

int countIncrements(std::vector<int> depth_values)
{
    int count = 0;

    for (int i = 1; i < depth_values.size()-2; i++)
    {
        int default_value = depth_values[i] + depth_values[i+1];
        if ((default_value + depth_values[i+2]) > depth_values[i-1] + default_value)
            count++;
        
        std::cout << depth_values[i-1] << ", " << depth_values[i] << ", " << depth_values[i+1] << ", " << depth_values[i+2] << " | ";
    }

    return count;
}