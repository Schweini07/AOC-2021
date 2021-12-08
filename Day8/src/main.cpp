#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

typedef std::vector<std::string> string_vector;

std::vector<std::pair<string_vector, string_vector> > getPuzzleInput();
bool hasChars(std::string sequence, std::vector<char> digit, int count = 3);
std::string getMissingChars(std::string sequence, std::string chars);
void printDigit(std::vector<char> digit);

int main()
{
    std::vector<std::pair<string_vector, string_vector> > input = getPuzzleInput();

    for (int i = 0; i < input.size(); i++)
    {

        std::unordered_map<int, std::string> unique_sequences;
        std::vector<std::string> five_sequences;
        std::vector<std::string> six_sequences;
        for (auto s : input[i].first)
        {
            switch (s.size())
            {
                case 2:
                    unique_sequences[1] = s;
                    continue;
                case 4:
                    unique_sequences[4] = s;
                    continue;
                case 3:
                    unique_sequences[7] = s;
                    continue;
                case 7:
                    unique_sequences[8] = s;
                    continue;
            }
            if (s.size() == 6)
            {
                if (std::find(six_sequences.begin(), six_sequences.end(), s) == six_sequences.end())
                    six_sequences.push_back(s);
            }
            if (s.size() == 5)
            {
                if (std::find(five_sequences.begin(), five_sequences.end(), s) == five_sequences.end())
                    five_sequences.push_back(s);
            }
        }

        // There are two places where the digits of the one could be
        for (int j = 0; j < 2; j++)
        {
            /*
            0:        ----  
            1:       -    -     :2
            1:       -    -     :2
            1:       -    -     :2
            3:        ----
            4:       -    -     :5
            4:       -    -     :5
            4:       -    -     :5
            6:        ----
            */
            std::vector<char> digit {0, 0, 0, 0, 0, 0, 0, 0, 0};

            digit[2] = j == 0 ? unique_sequences[1][0] : unique_sequences[1][1];
            digit[5] = j == 0 ? unique_sequences[1][1] : unique_sequences[1][0];

            digit[0] = getMissingChars(unique_sequences[7], unique_sequences[1])[0];

            for (int k = 0; k < 2; k++)
            {
                std::vector<char> digit_cpy = digit;
                std::string str_digit (digit_cpy.begin(), digit_cpy.end());

                std::string three;
                for (auto s : five_sequences)
                {
                    if (hasChars(s, digit_cpy))
                    {
                        three = s;
                        digit_cpy[3] = k == 0 ? getMissingChars(s, str_digit)[0] : getMissingChars(s, str_digit)[1];
                        digit_cpy[6] = k == 0 ? getMissingChars(s, str_digit)[1] : getMissingChars(s, str_digit)[0];
                    }
                }

                std::string new_str_digit (digit_cpy.begin(), digit_cpy.end());
                std::string five;
                for (auto s : five_sequences)
                {
                    if (hasChars(s, digit_cpy, 4) && s != three)
                    {
                        five = s;
                        digit_cpy[1] = getMissingChars(s, new_str_digit)[0];
                    }
                }

                std::string new_new_str_digit (digit_cpy.begin(), digit_cpy.end());
                for (auto s : five_sequences)
                {
                    if (s != three && s != five)
                    {
                        std::cout << new_new_str_digit << std::endl;
                        digit_cpy[4] = getMissingChars(s, new_new_str_digit)[0];
                    }
                }

                printDigit(digit_cpy);
            }

        }
    }

    return 0;
}

bool hasChars(std::string sequence, std::vector<char> digit, int count)
{
    for (auto d : digit)
    {
        if (sequence.find(d) != std::string::npos)
            count--;
    }
    return count == 0 ? true : false;
}

std::string getMissingChars(std::string sequence, std::string chars)
{
    std::string missing_chars;
    for (auto s : sequence)
    {
        if (chars.find(s) == std::string::npos)
            missing_chars += s;
    }

    return missing_chars;
}

void printDigit(std::vector<char> digit)
{
    for (int i = 0; i < digit.size(); i++)
    {
        if (i == 1 || i == 4)
        {
            std::cout << digit[i] << " " << digit[i+1] << std::endl;
            i++;
            continue;
        }
        std::cout << " " << digit[i] << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::pair<string_vector, string_vector> > getPuzzleInput()
{
    std::vector<std::pair<string_vector, string_vector> > puzzle_input;
    std::string line;
    std::ifstream f("test2.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            std::pair<string_vector, string_vector> sequences;
            std::string::size_type seperator = line.find("|");

            std::string sequence;
            for (int i = 0; i <= line.size(); i++)
            {
                if (line[i] == ' ' || i == line.size() || line[i] == '|')
                {
                    std::sort(sequence.begin(), sequence.end());
                    if (sequence.size() != 0)
                        i > seperator ? sequences.second.push_back(sequence) : sequences.first.push_back(sequence);
                    sequence.clear();
                    continue;
                }
                sequence += line[i];
            }
            puzzle_input.push_back(sequences);

            /*
            for (auto s : sequences.first)
                std::cout << s << " ";
            std::cout << "| ";
            for (auto s : sequences.second)
                std::cout << s << " ";
            std::cout << std::endl;
            */
        }
        
    }

    return puzzle_input;
}