# trails while working

## iterators

read about iterators
[iterators](https://www.geeksforgeeks.org/introduction-iterators-c/)
also read the answer
[auto &&](https://stackoverflow.com/questions/13230480/what-does-auto-tell-us)


## find_if function

`auto&&` var = <initializer> you are saying: I will accept any initializer regardless of whether it is an lvalue or rvalue expression and I will preserve its constness.

here the iterator is something like a pointer, `find_if()` returns an iterator.
we take the iterator and derefrance it twice to get the `int` value.

`IsOdd()` takes a refrance to a unique pointer and access the `i` using `*`

```c++
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
```

