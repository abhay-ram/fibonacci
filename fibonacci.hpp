#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP
#include <vector>
#include <iostream>
#define MIN_INT 1
#define MAX_INT 100


struct fibonacciEntry
{
int position;
double value;
};
//class for fibonacci "functionality"
class fibonacci 
  {
    private:
    int start_; //unused
    int end_;  //unused
    static const int MAX = MAX_INT;
    static const int MIN = MIN_INT;
    std::vector<fibonacciEntry> value_array_;
    public:
    //setters
    void setEnd(int end);
    void setStart(int start);
    
    //const dest
    fibonacci();
    ~fibonacci() = default;
    //pre-calculates fibonacci sequence from given constant min to max
    void calculateSequence();
    //prints pre-calculated secquence
    void printSequence();
    //prints sum from given start to end
    void printSum(int start, int end);
    //gets entry value from a given index
    void printIndex(int index);
    //prints entry in a given range
    void printRange(int start, int end);
    //checks if an index is in range (definitions of MAX_INT, MIN_INT)
    static bool checkRange(int index);
    //util 
    static bool isGreater(int first, int second);
    //getters
    std::vector<fibonacciEntry> getSequence(){return value_array_;};
  };









#endif