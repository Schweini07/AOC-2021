#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::string> string_vector;

std::vector<std::pair<string_vector, string_vector> > getPuzzleInput();

int main()
{
    std::vector<std::pair<string_vector, string_vector> > input = getPuzzleInput();

    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (auto s : input[i].second)
        {
            switch (s.size())
            {
                case 2:

                case 3:

                case 4:

                case 7:
                    count += 1;
                    break;
                default:
                    break;
            }
        }
    }

    std::cout << "Count is: " << count << std::endl;

    return 0;
}

std::vector<std::pair<string_vector, string_vector> > getPuzzleInput()
{
    std::vector<std::pair<string_vector, string_vector> > puzzle_input;
    std::string line;
    std::ifstream f("puzzle_input.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            std::pair<string_vector, string_vector> sequences;
            std::string::size_type seperator = line.find("|");

            std::string sequence;
            for (int i = seperator+2; i <= line.size(); i++)
            {
                if (line[i] == ' ' || i == line.size())
                {
                    sequences.second.push_back(sequence);
                    sequence.clear();
                    continue;
                }
                sequence += line[i];
            }
            puzzle_input.push_back(sequences);
        }
        
    }

    return puzzle_input;
}