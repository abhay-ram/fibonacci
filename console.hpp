#ifndef CONSOLE_HPP
#define CONSOLE_HPP
#include <iostream>
#include "console.hpp"
#include <string>

//utils for command line input and validation

//define command types, given in assignment
enum class CommandType
{
  FULL_OUTPUT,
  INDEX_OUTPUT,
  SUM,
  HELP,
  ASCII,
  QUIT,
  INVALID
};

//checks if command type is quit, used as running condition
bool isQuit(CommandType input)
{
  return (input == CommandType::QUIT);
}

//promts the user for a input with given prompt, returns string
std::string getInput(const std::string &prompt)
{
  std::string input;
  std::cout << prompt;
  std::getline(std::cin, input);
  return input;
}

// removes whitespaces and lowercases the string
std::string removeWhitespace(const std::string &str)
{
  std::string result;
  for (char c : str)
  {
    if (!isspace(c))
    {
      if (isupper(c))
      {
        c = tolower(c);
      }
      result += c;
    }
  }
  return result;
}

//validades if string is a valid integer value , bool return
bool isValidInteger(const std::string &str)
{
  for (char c : str)
  {
    if (!isdigit(c))
    {
      return false;
    }
  }
  return true;
}
//similar to prompt user string input, but with whitespace removal and integer validation
int getIntegerInput(const std::string prompt)
{
  std::string input;
  while (true)
  {
    input = getInput(prompt);
    input = removeWhitespace(input);
    if (isValidInteger(input))
    {
      return std::stoi(input);
    }
    else
    {
      std::cout << "Invalid input. Please enter a valid integer.\n";
    }
  }
}


//prompts user to enter valid command. returns a command type. returns CommandType::INVALID if no hits.
CommandType getCommand()
{
  auto input = removeWhitespace(getInput("Enter Command or 'help':"));
  if (input.compare("quit") == 0)
  {
    return CommandType::QUIT;
  }
  else if (input.compare("complete") == 0)
  {
    return CommandType::FULL_OUTPUT;
  }
  else if (input.compare("index") == 0)
  {
    return CommandType::INDEX_OUTPUT;
  }
  else if (input.compare("help") == 0)
  {
    return CommandType::HELP;
  }
  else if (input.compare("sum") == 0)
  {
    return CommandType::SUM;
  }
  else if (input.compare("ascii") == 0)
  {
    return CommandType::ASCII;
  }

  return CommandType::INVALID;
}

#endif