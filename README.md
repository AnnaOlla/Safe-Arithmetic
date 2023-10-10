# Safe-Arithmetic
A small “library” that provides overflow-safe operations for basic types: integers, unsigned integers and floating-points.

## Usage
* Add `Safe.hpp` to the project.
* Use `Safe::Add`, `Safe::Subtract`, `Safe::Multiply`, `Safe::Divide`.
* Keep in mind that operands must be of the same type.

## Example
```c++
#include "Safe.hpp"

#include <limits>
#include <stdexcept>
#include <iostream>

int main()
{
    int a = std::numeric_limits <int>::max();
    int b = 1;

    std::cout << a << " + " << b << " = ";

    try
    {
        std::cout << Safe::Add(a, b);
    }
    catch (const std::overflow_error& e)
    {
        std::cout << e.what();
    }

    return 0;
}
```

## Simplify
Any function of the “library” can be easily rewritten like this…
```c++
int Add(int a, int b)
{
    if (b > 0 && a > std::numeric_limits <int>::max() - b)
        throw std::overflow_error("Overflow");

    if (b < 0 && a < std::numeric_limits <int>::min() - b)
        throw std::overflow_error("Underflow");

    return a + b;
}
```
… and then copied to the code.

## Post Scriptum
* It is just a small development of an overflow-safe function.
* Free to copy.
