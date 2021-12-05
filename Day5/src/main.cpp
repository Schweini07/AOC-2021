#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

typedef std::vector<int> spatial_vector;

std::vector<std::pair<spatial_vector, spatial_vector> > getPuzzleInput(); // 0,9 -> 5,9: (0 | 9) is first, (5 | 9) second
void initGrid();
void printGrid();
void placeLine(spatial_vector p1, spatial_vector p2);

std::vector<std::vector<int> > grid;
std::vector<spatial_vector> dangerous_points;

int main()
{
    std::vector<std::pair<spatial_vector, spatial_vector> > input = getPuzzleInput();

    initGrid();

    for (auto spatial_vectors : input)
    {
        placeLine(spatial_vectors.first, spatial_vectors.second);
    }

    //printGrid();

    std::cout << dangerous_points.size() << std::endl;

    return 0;
}

void initGrid()
{
    // 989 is the biggest x num; 988 the biggest y num
    for (int x = 0; x < 989; x++)
    {
        std::vector<int> new_row;
        grid.push_back(new_row);
        for (int y = 0; y < 988; y++)
        {
            grid[x].push_back(0);
        }
    }
}

void printGrid()
{
    for (int x = 0; x < 989; x++)
    {
        for (int y = 0; y < 988; y++)
        {
            std::cout << grid[x][y] << ",";
        }
        std::cout << std::endl;
    }
}

void placeLine(spatial_vector p1, spatial_vector p2)
{
    int increment_x = p1[0]-p2[0] > 0 ? -1 : 1;
    int increment_y = p1[1]-p2[1] > 0 ? -1 : 1;
    //std::cout << "Increment x: " << increment_x << " Increment y: " << increment_y << " P1: " << p1[0] << " " << p1[1] << " P2: " << p2[0] << " " << p2[1] << std::endl;

    while(p1 != p2)
    {
        grid[p1[1]][p1[0]]++;
        if (grid[p1[1]][p1[0]] == 2)
            dangerous_points.push_back(p1);
        
        if (p1[0] != p2[0]) p1[0] += increment_x;
        if (p1[1] != p2[1]) p1[1] += increment_y;
    }
    //std::cout << "P1: " << p1[0] << " " << p1[1] << std::endl << std::endl;

    grid[p1[1]][p1[0]]++;
    if (grid[p1[1]][p1[0]] == 2)
        dangerous_points.push_back(p1);
}

std::vector<std::pair<spatial_vector, spatial_vector> > getPuzzleInput()
{
    std::vector<std::pair<spatial_vector, spatial_vector> > spatials;

    std::string line;
    std::ifstream f("puzzle_input.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            spatial_vector vec1, vec2;

            std::string::size_type seperator = line.find("->");
            std::string::size_type comma = line.find(",");


            // First Spatial Vector
            vec1.push_back(std::stoi(line.substr(0, comma)));
            vec1.push_back(std::stoi(line.substr(comma+1, line.size() - seperator-5)));

            // Second Spatial Vector
            comma = line.find(",", comma+1);
            vec2.push_back(std::stoi(line.substr(seperator+3, line.size() - seperator-5)));
            vec2.push_back(std::stoi(line.substr(comma+1, line.size()-comma)));

            spatials.push_back(std::make_pair(vec1, vec2));
        }        
    }

    return spatials;
}