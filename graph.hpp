#ifndef GRAPH_HPP
#define GRAPH_HPP
// #include "graph.cpp"
#include <iostream>
#include "fibonacci.hpp"
//prints graph given an fibonacci entry array in the following format:
//position > [#########################]          [value]

class Graph
{
  private:
  public:
  static void print(std::vector<fibonacciEntry> values, int start, int end);
  static void printLine(fibonacciEntry value,double max);
  static void printBar(fibonacciEntry value,double max);
  static void printBar(int length);
};

#endif