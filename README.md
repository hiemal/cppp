# CPPP

A python's Pool().map style wrapper for C++11.

## Why
People like me who come from a scientific computing backgroud always miss python's elegant `multiprocessing.Pool().map` while coding in C++. So I tried to replicate exactly the same API call in C++11 using `async` wrapper over threads.

## Usage
```c++
# include "cppp.h"

// has to be currying function.
returntype f(inputtype arg);
// vector of args.
std::vector<inputtype> vecInputs = { ... };

auto pool = cppp::Pool();
// vector of returns, ordered as inputs.
std::vector<returntype> results = pool.map(f, vecInputs);
```