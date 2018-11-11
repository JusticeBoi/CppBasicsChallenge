#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <map>
#include <parallel/algorithm>
#include <array>
#include <cstdio>
#include "omp.h"

static const char alpha[] =
	        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	        "abcdefghijklmnopqrstuvwxyz'/?.!%$&;<>=:";



void produceAndWriteEntriesInBinaryWithSize(int size,int number_of_entries);

std::vector<std::pair<int,std::string>> readBinFile_vector(int size, int number_of_entries);



void sortVecOfPair(std::vector<std::pair<int,std::string>>&);

void writeSortedEntriesASCII(const std::vector<std::pair<int,std::string>> &  to_be_written);

int fast_char_to_int(const char *p); 
