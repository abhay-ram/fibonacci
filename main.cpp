#include "graph.hpp"
#include "console.hpp"

const std::string HELPMSG = "Commands:\n help - help msg\n sum - sum in range\n index - return at index\n complete - print full range\n ascii - print ascii graph\n";

int main()
{
  fibonacci sequence;
  sequence.calculateSequence();
  CommandType command;
  while (!isQuit(command = getCommand()))
  {
    switch (command)
    {
    case CommandType::HELP:
      std::cout << HELPMSG;
      break;
    case CommandType::FULL_OUTPUT:
      sequence.printSequence();
      break;
    case CommandType::INDEX_OUTPUT:
    {
      int index = getIntegerInput("Input an Index to get the value at:");
      sequence.printIndex(index);
      break;
    }
    case CommandType::SUM:
    {
      int start = getIntegerInput("Input a start index:");
      int end = getIntegerInput("Input a end index:");
      sequence.printSum(start, end);
      break;
    }
    case CommandType::ASCII:
    {
      int start = getIntegerInput("Input a start index:");
      int end = getIntegerInput("Input a end index:");
      if (!fibonacci::checkRange(start) || !fibonacci::checkRange(end) || !fibonacci::isGreater(start, end))
      {
        std::cout << "integer input out of range!\n";
        break;
      }
      Graph graph;
      graph.print(sequence.getSequence(), start, end);
      break;
    }
    default:
      std::cout << "invalid cmd!\n";
      break;
    }
  }

  return 0;
};
