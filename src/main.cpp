#include "lib.hpp"



int main()
{

	size_t number_of_entries = 5e1;

    
    auto start_read = std::chrono::steady_clock::now();
//	writeEntries_1(number_of_entries,6);
	produceAndWriteEntriesInBinaryWithSize(7,number_of_entries);
    auto end_read = std::chrono::steady_clock::now();
    auto diff_read_1 = end_read - start_read ;
	std::cout <<"duration of produceAndWriteEntriesWithSize  :  "<< std::chrono::duration <double, std::milli> (diff_read_1).count() << " ms" << std::endl;
    
    
    start_read = std::chrono::steady_clock::now();
	auto vec_of_pairs = readBinFile_vector(number_of_entries);
	end_read = std::chrono::steady_clock::now();
	auto diff_read_2 = end_read - start_read;
    std::cout <<"duration of readBinFile_vector :  "<< std::chrono::duration <double, std::milli> (diff_read_2).count() << " ms" << std::endl;
	
    
    start_read = std::chrono::steady_clock::now();
	sortVecOfPair(vec_of_pairs);
	end_read = std::chrono::steady_clock::now();
	auto diff_read_3 = end_read - start_read;
	std::cout <<"duration of sort :  "<< std::chrono::duration <double, std::milli> ( diff_read_3).count() << " ms" << std::endl;
	
    start_read = std::chrono::steady_clock::now();
	writeSortedEntriesASCII(vec_of_pairs);
	end_read = std::chrono::steady_clock::now();
	auto diff_read_4 = end_read - start_read;
	std::cout <<"duration of writeSortedEntriesASCII :  "<< std::chrono::duration <double, std::milli> (diff_read_4).count() << " ms" << std::endl;

	std::cout <<"total duration :  "<< std::chrono::duration <double, std::milli> (diff_read_1 + diff_read_2 + diff_read_3 + diff_read_4).count() << " ms" << std::endl;

	return 0;
 }
