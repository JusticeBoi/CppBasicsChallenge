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
#include "omp.h"
#if __cplusplus >= 201500
    #pragma message "parallel sorting active , need -fopenmp flag" 
    #include <parallel/algorithm>
    #define par_exe
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

int fast_char_to_int(const char *p); 
