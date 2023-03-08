/**
 * include library
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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

void printArr2d(std::vector<std::vector<int>> table, int tableSize)
{
  for (int i = 0; i < tableSize; ++i)
  {
    for (int j = 0; j < table[0].size(); ++j)
    {
      std::cout << table[i][j] << " ";
    }
    std::cout << std::endl;
  }
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

std::string toBinary(int n)
{
  std::string r;
  while (n != 0)
  {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;
  }
  return r;
}

void addInitialVarsCols(std::vector<std::vector<int>> &table, std::vector<char> variablesArr)
{
  int i = 0;
  int stop = pow(2, variablesArr.size());

  for (int i = 0; i < variablesArr.size(); ++i)
  {
    table[i].resize(stop);
  }

  while (i < stop)
  {
    std::string varSequence = toBinary(i);

    while (varSequence.length() < variablesArr.size())
    {
      varSequence = '0' + varSequence;
    }

    for (int j = 0; j < variablesArr.size(); ++j)
    {
      table[j][i] = int(varSequence[j]) - 48;
    }

    ++i;
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

  return str;
}

void output(std::vector<std::vector<int>> table, int tableSize, std::vector<char> variablesArr)
{
  if (out)
    return;

  for (int j = 0; j < table[0].size() + 1; ++j)
  {
    std::cout << "====";
  }
  std::cout << "=" << std::endl;

  for (int i = 0; i < tableSize; ++i)
  {

    std::cout << "| " << variablesArr[i] << " | ";
    for (int j = 0; j < table[0].size(); ++j)
    {
      std::cout << table[i][j] << " | ";
    }
    std::cout << std::endl;
    for (int j = 0; j < table[0].size() + 1; ++j)
    {
      std::cout << "====";
    }
    std::cout << "=" << std::endl;
  }
}

void process(std::string str)
{
  if (out)
    return;

  std::vector<std::vector<int>> table;
  table.resize(100);

  std::vector<char> variablesArr;
  modifyVariablesArr(variablesArr, str);
  int tableSize = variablesArr.size();

  addInitialVarsCols(table, variablesArr);

  output(table, tableSize, variablesArr);
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
