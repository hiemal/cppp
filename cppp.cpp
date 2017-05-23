#include "cppp.h"


Pool::Pool()
{
    concurentThreadsSupported = std::thread::hardware_concurrency();
    std::cout << "Setting nthreads to " << concurentThreadsSupported << std::endl;
}

Pool::Pool(unsigned num_threads){
    concurentThreadsSupported = num_threads;
    std::cout << "Setting nthreads to " << concurentThreadsSupported << std::endl;
}