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
static const char alpha[] =
	        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	        "abcdefghijklmnopqrstuvwxyz";
static const char num[] = "0123456789";

std::string  produceEntry(size_t);
void writeEntries_1(size_t number_of_entries,size_t size_of_entry);

std::vector<std::string> produceNumberOfEntries(size_t number_of_entries);
void writeEntries_2(const std::vector<std::string>& vec_strings);

void produceAndWriteEntriesInBinaryWithSize(int size,int number_of_entries);

std::map<int,std::string> readBinFile_map(int number_of_entries);
std::vector<std::pair<int,std::string>> readBinFile_vector(int number_of_entries);



void sortVecOfPair(std::vector<std::pair<int,std::string>>&);

void writeSortedEntriesASCII(const std::vector<std::pair<int,std::string>> &  to_be_written);

int fast_char_to_int(const char *p); 
std::multimap<int,std::string> readBinFile_multi_map(int number_of_entries);
void writeSortedEntriesASCII_mmap(const std::multimap<int,std::string>&  mmap);
