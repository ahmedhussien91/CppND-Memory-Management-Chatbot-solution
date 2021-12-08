// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector
#include <memory>

bool IsOdd (std::unique_ptr<int>& i) {
  std::cout << *i << std::endl;
  return ((*i%2)==1);
}

int main () {
  std::vector<std::unique_ptr<int>> myvector;

  myvector.push_back(std::make_unique<int>(10));
  myvector.push_back(std::make_unique<int>(25));
  myvector.push_back(std::make_unique<int>(40));
  myvector.push_back(std::make_unique<int>(55));
  myvector.push_back(std::make_unique<int>(25));

  auto&& it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
  std::cout << "The first odd value is " << **it << '\n';

  return 0;
}