#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <map>
#include <array>
#include <cstdio>
#include <iterator>
#include "omp.h"
#if defined(_MSC_VER) && __cplusplus >= 201500
    #pragma message "parallel sorting active , need -fopenmp flag" 
    #include <execution>
    #include <algorithm>
    #define par_exe_msvc
#elif defined(__GNUG__) && __cplusplus >= 201500
    #pragma message "parallel sorting active , need -fopenmp flag" 
    #include <parallel/algorithm>
    #define par_exe_gcc
#else
    #pragma message "for parallel sorting, need -std=c++17 and -fopenmp flag" 
    #include <algorithm>
#endif

static const char alpha[] =
	        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	        "abcdefghijklmnopqrstuvwxyz'/?.!%$&;<>=:";



void produceAndWriteEntriesInBinaryWithSize(int size,int number_of_entries);

std::vector<std::pair<int,std::string>> readBinFile_vector(int size, int number_of_entries);



void sortVecOfPair(std::vector<std::pair<int,std::string>>&);

void writeSortedEntriesASCII(const std::vector<std::pair<int,std::string>> &  to_be_written);

