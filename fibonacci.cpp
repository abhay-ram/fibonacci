#include "fibonacci.hpp"
#include <iostream>

#define MIN_INT 1
#define MAX_INT 100

fibonacci::fibonacci() : start_(0), end_(0)
{
}

void fibonacci::setStart(int start)
{
  if (start < MIN_INT)
  {
    std::cout << "invalid start integer\n";
    return;
  }
  start_ = start;
}

void fibonacci::setEnd(int end)
{
  if (end > MAX_INT)
  {
    std::cout << "invalid end integer\n";
    return;
  }
  end_ = end;
}
void fibonacci::calculateSequence()
{
  auto numberarray = value_array_;
  fibonacciEntry first;
  fibonacciEntry second;
  first.position = 1;
  first.value = 1;
  second.position = 2;
  second.value = 1;
  value_array_.push_back(first);
  value_array_.push_back(second);
  for (int i = 2; i < MAX_INT; i++)
  {
    fibonacciEntry num;
    num.position = i + 1;
    num.value = value_array_[i - 2].value + value_array_[i - 1].value;
    value_array_.push_back(num);
  }
}
void fibonacci::printSequence()
{
  for (const auto num : value_array_)
  {
    std::cout << "Position: " << num.position << ", Value: " << num.value << std::endl;
  }
}

bool fibonacci::checkRange(int index)
{
  if(index>=MIN_INT && index <= MAX_INT){
    return true;
  }
  std::cout << "index out of range!" << std::endl;
  return false;
}
bool fibonacci::isGreater(int first, int second)
{
  if(second<first)
  {
    std::cout << "end is < start!";
    return false;
  }
  return true;
}

void fibonacci::printIndex(int index)
{
  //check index 
  if(!checkRange(index))
  {
    return;
  }
  auto num = value_array_[index-1];
  std::cout << "Position: " << num.position << ", Value: " << num.value << std::endl;
}

void fibonacci::printRange(int start, int end)
{
  //check index 
  if(!checkRange(start) || !checkRange(end) || !isGreater(start,end))
  {
    return;
  }

  for(int i = start-1; i < end; i++)
  {
    auto num = value_array_[i];
    std::cout << "Position: " << num.position << ", Value: " << num.value << std::endl;
  }
}

void fibonacci::printSum(int start, int end)
{
  //check index 
  if(!checkRange(start) || !checkRange(end) || !isGreater(start,end))
  {
    return;
  }

  double sum = 0;
  for(int i = start-1; i < end; i++)
  {
    // std::cout << i ;
    auto num = value_array_[i];
    sum = sum + num.value;
  }
  std::cout << "Sum: " << sum << std::endl;

}

;
