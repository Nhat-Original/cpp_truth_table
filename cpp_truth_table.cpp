/**
 * include library
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "./customization.cpp"

/**
 * global variables
 */
bool out = 0;

/**
 * function declarations
 */
std::string input();
std::string removeSpace(std::string str);
void process(std::string str);
void output();

/**
 * start
 */
int main()
{
  do
  {
    std::string inp = input();
    process(inp);
    output();
  } while (!out);

  return 0;
}

/**
 * helper functions
 */
void bubbleSort(std::vector<char> &arr)
{
  for (int i = 0; i < arr.size(); ++i)
  {
    for (int j = 0; j < arr.size() - i - 1; ++j)
    {
      if (arr[j] > arr[j + 1])
        std::swap(arr[j], arr[j + 1]);
    }
  }
}

/**
 * main functions
 */
std::string input()
{
  std::string str;
  std::cout << "Enter str or enter '" << escapeSequence << "' to escape: ";

  getline(std::cin, str);

  if (str == escapeSequence)
  {
    out = 1;
    return "";
  }

  str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
  std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
                 { return std::tolower(c); });

  // std::cout << str << std::endl;
  // std::cout << str.length() << std::endl;

  return str;
}

void process(std::string str)
{
  std::vector<char> vars;

  for (int i = 0; i < str.length(); ++i)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      vars.push_back(str[i]);
    }
  }

  bubbleSort(vars);

  // for (int i = 0; i < str.length(); ++i)
  // {
  //   std::cout << vars[i] << " ";
  // }

  if (out)
    return;
}

void output()
{
  if (out)
    return;
}
