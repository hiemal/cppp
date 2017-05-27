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

namespace cppp
{
class Pool
{
  public:
    Pool() { concurentThreadsSupported = std::thread::hardware_concurrency(); }
    Pool(unsigned num_threads) { concurentThreadsSupported = num_threads; }

    template <class T_INPUT, class T_RETURN>
    std::vector<T_RETURN> map(T_RETURN (*f)(T_INPUT), std::vector<T_INPUT> &);

    unsigned concurentThreadsSupported;
};

template <class T_INPUT, class T_RETURN>
std::vector<T_RETURN> Pool::map(T_RETURN (*f)(T_INPUT), std::vector<T_INPUT> &inputs)
{
    std::vector<T_RETURN> results;

    std::vector< std::vector<T_INPUT> > groups;
    std::vector<T_INPUT> group;
    unsigned counter = 1;
    for (auto const &input : inputs)
    {
        group.push_back(input);
        if (counter % concurentThreadsSupported == 0)
        {
            groups.push_back(group);
            group.clear();
        }
        counter++;
    }
    // if input size < nthreads, need to push.
    if (group.size() > 0)
    {
        groups.push_back(group);
    }

    // std::cout << "groups size:" << groups.size() << std::endl;

    for (auto groupidx = 0; groupidx < groups.size(); groupidx++)
    {
        std::vector<std::future<T_RETURN>> futures;
        auto const &group = groups[groupidx];
        // std::cout << "processing group "<<groupidx
        // <<" of size " << group.size() <<std::endl;
        for (auto i = 0; i < group.size(); i++)
        {
            futures.push_back(std::async(std::launch::async, f, group[i]));
        }

        for (auto &res : futures)
        {
            auto tmp = res.get();
            results.push_back(tmp);
        }
    }

    return results;
}
}
#endif