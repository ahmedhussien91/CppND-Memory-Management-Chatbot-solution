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

## task 4

In files

- `chatlogic.h` / `chatlogic.cpp`
- `graphnode.h` / `graphnode.cpp`


change the ownership of all instances of `GraphEdge` in a way such that each instance of `GraphNode` exclusively owns the outgoing `GraphEdges` and holds non-owning references to incoming `GraphEdges`.

Use appropriate smart pointers and where required, make changes to the code such that data structures and function parameters reflect the changes. 

When transferring ownership from class `ChatLogic`, where all instances of `GraphEdge` are created, into instances of `GraphNode`, make sure to use move semantics.

## task 5

In file `chatlogic.cpp`, 

- create a local `ChatBot` instance on the stack at the bottom of function `LoadAnswerGraphFromFile`.
- Then, use move semantics to pass the `ChatBot` instance into the root node.
- Make sure that `ChatLogic` has no ownership relation to the `ChatBot` instance
  and thus is no longer responsible for memory allocation and deallocation.
  
- Note that the member `_chatBot` of `ChatLogic` remains so it can be used as a communication handle between GUI and `ChatBot` instance.
- Make all required changes in files 
  `chatlogic.h` / `chatlogic.cpp` 
  and `graphnode.h` / `graphnode.cpp`.
  
When the program is executed, messages on which part of the Rule of Five components of `ChatBot` is called should be printed to the console. When sending a query to the `ChatBot`, the output should look like the following:
```
ChatBot Constructor
ChatBot Move Constructor
ChatBot Move Assignment Operator
ChatBot Destructor
ChatBot Destructor 
```
