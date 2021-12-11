#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<std::string> getPuzzleInput();
std::vector<char> getCorruptBrackets(std::vector<std::string> input); // Part 1
std::vector<std::string> getCompleteBrackets(std::vector<std::string> input); // Part 2

int main()
{
    std::vector<std::string> input = getPuzzleInput();
    std::vector<char> corrupted_brackets = getCorruptBrackets(input);

    int corrupt_points = 0;
    for (auto c : corrupted_brackets)
    {
        switch(c)
        {
            case ')':
                corrupt_points += 3;
                break;
            case ']':
                corrupt_points += 57;
                break;
            case '}':
                corrupt_points += 1197;
                break;
            case '>':
                corrupt_points += 25137;
                break;
        }
    }

    std::cout << "Corrupt points are: " << corrupt_points << std::endl;

    std::vector<std::string> complete_brackets = getCompleteBrackets(input);

    std::vector<unsigned long long> complete_points_vec;
    for (auto s : complete_brackets)
    {
        unsigned long long complete_points = 0;
        for (auto c : s)
        {
            complete_points *= 5;

            switch (c)
            {
                case ')':
                    complete_points += 1;
                    break;
                case ']':
                    complete_points += 2;
                    break;
                case '}':
                    complete_points += 3;
                    break;
                case '>':
                    complete_points += 4;
                    break;
            }
        }
        complete_points_vec.push_back(complete_points);
    }

    std::sort(complete_points_vec.begin(), complete_points_vec.end());
    std::cout << "Complete Points are: " << complete_points_vec[(complete_points_vec.size()-1)/2] << std::endl;

    return 0;
}

std::vector<std::string> getCompleteBrackets(std::vector<std::string> input)
{
    std::vector<std::string> complete_brackets;

    for (auto s : input)
    {
        std::string str;

        std::stack<char> brackets;

        bool has_corrupted_bracket = false;
        for (auto c : s)
        {
            if (c == '[' || c == '{' || c == '(' || c == '<')
                brackets.push(c);
            else if (c == brackets.top()+1 || c == brackets.top()+2)
                brackets.pop();
            else
                has_corrupted_bracket = true;
        }

        if (has_corrupted_bracket)
            continue;

        while (!brackets.empty())
        {
            if (brackets.top() == '(')
                str += ')';
            else
                str += brackets.top()+2;
            brackets.pop();
        }

        complete_brackets.push_back(str);
    }

    return complete_brackets;
}


std::vector<char> getCorruptBrackets(std::vector<std::string> input)
{
    std::vector<char> corrupted_brackets;

    for (auto s : input)
    {
        std::stack<char> brackets;

        for (auto c : s)
        {
            if (c == '[' || c == '{' || c == '(' || c == '<')
                brackets.push(c);
            else if (c == brackets.top()+1 || c == brackets.top()+2)
                brackets.pop();
            else
            {
                corrupted_brackets.push_back(c);
                goto break_loop;
            }
        }

        break_loop:
            continue;
    }

    return corrupted_brackets;
}

std::vector<std::string> getPuzzleInput()
{
    std::vector<std::string> puzzle_input;
    std::string line;
    std::ifstream f("puzzle_input.txt");

    if (f.is_open())
    {
        while (getline(f, line))
        {
            puzzle_input.push_back(line);
        }
        
    }

    return puzzle_input;
}