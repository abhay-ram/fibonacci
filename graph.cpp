#include "graph.hpp"
#include <algorithm>
#include <iomanip>
#include <math.h>
#define BAR_WIDTH 120

//custom comparison function for algorithm.math.max 
bool comp(fibonacciEntry& a, fibonacciEntry& b) {
    return a.value < b.value;
}

//function to get maximum value in given entry array
double getMax(std::vector<fibonacciEntry> values,int start, int end)
{
    //iterators with given start and end values
    std::vector<fibonacciEntry>::iterator begin_it = values.begin() + start-1;
    std::vector<fibonacciEntry>::iterator end_it = values.begin() + end;
    //use alogrithm lib to find max
    auto max = std::max_element(begin_it, end_it, comp);
    return max->value;
}

void Graph::print(std::vector<fibonacciEntry> values, int start, int end) 
{
  auto max = getMax(values,start,end);
  // std::cout << max << std::endl; 
  for(int index=start-1; index<end; index++)
  {
    //iterate entries
    auto number = values[index];
    printLine(number,max);
  }
};



void Graph::printLine(fibonacciEntry number,double max)
{
  printBar(number,max);
};
void Graph::printBar(fibonacciEntry value,double max)
{
  //print position with filled bar. bar width calculated per max value
  std::cout << std::setw(3) << value.position << "|[" << std::setfill('#') << std::setw(value.value/max*BAR_WIDTH +1) << "] " << value.value <<std::endl;
};

;