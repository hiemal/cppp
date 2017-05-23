/*
cppp: cpp parallel
The target of this project is to mimic python's multiprocessing.Pool().map function.
*/

#ifndef CPPP_H
#define CPPP_H

#include <future>
#include <vector>
#include <map>
#include <iostream>

class Pool
{
  public:
    Pool();
    Pool(unsigned);

    template <class T_INPUT, class T_RETURN>
    std::vector<T_RETURN> map(T_RETURN (*f)(T_INPUT), std::vector<T_INPUT> &);

  private:
    unsigned concurentThreadsSupported;
};

template <class T_INPUT, class T_RETURN>
std::vector<T_RETURN> Pool::map(T_RETURN (*f)(T_INPUT), std::vector<T_INPUT> &inputs)
{
    std::vector<T_RETURN> results;

    // TODO: copy object, too heavy.
    std::map<unsigned, std::vector<T_INPUT> > groups;

    // asign input vector to groups
    unsigned counter = 0;
    for (auto input : inputs)
    {
        auto mod = counter % concurentThreadsSupported;
        groups[mod].push_back(input); 
        counter++;
    }

    std::vector<std::future<T_RETURN>> futures;
    for (auto i=0; i<concurentThreadsSupported;i++){
        // TODO:
    }
    

    return results;
}

#endif