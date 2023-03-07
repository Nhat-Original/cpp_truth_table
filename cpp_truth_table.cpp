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
 * helper functions
 */
void printArr(std::vector<char> arr)
{
  for (int i = 0; i < arr.size(); ++i)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

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

void addToVariablesArr(std::vector<char> &arr, std::vector<char> copy)
{
  for (int i = 0; i < copy.size(); ++i)
  {
    if (arr.empty() || arr[arr.size() - 1] != copy[i])
    {
      arr.push_back(copy[i]);
    }
  }
}

void modifyVariablesArr(std::vector<char> &variablesArr, std::string str)
{
  std::vector<char> copy;

  for (int i = 0; i < str.length(); ++i)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
    {
      copy.push_back(str[i]);
    }
  }

  bubbleSort(copy);

  addToVariablesArr(variablesArr, copy);
}

void addInitialVarsCols(std::vector<std::vector<int>> &table, int &col, std::vector<char> variablesArr)
{
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

  return str;
}

void output()
{
  if (out)
    return;
}

void process(std::string str)
{
  if (out)
    return;

  int col = 0;
  std::vector<std::vector<int>> table;

  std::vector<char> variablesArr;
  modifyVariablesArr(variablesArr, str);

  addInitialVarsCols(table, col, variablesArr);

  output();
}

/**
 * start
 */
int main()
{
  do
  {

    std::string inp = input();
    process(inp);

  } while (!out);

  return 0;
}
