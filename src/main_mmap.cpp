#include "lib.hpp"



int main()
{

	size_t number_of_entries = 5e7;
	auto start_read = std::chrono::steady_clock::now();
//	writeEntries_1(number_of_entries,6);
	produceAndWriteEntriesInBinaryWithSize(7,number_of_entries);
	auto mmap= readBinFile_multi_map(number_of_entries);
	auto end_read = std::chrono::steady_clock::now();
	auto diff_read = end_read - start_read;
	auto first_part_time = diff_read;
	std::cout <<"duration of produceAndWriteEntriesWithSize and readBinFile_mmap :  "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;
	start_read = std::chrono::steady_clock::now();
	writeSortedEntriesASCII_mmap(mmap);

    std::cout <<"hello world " <<std::endl;

	end_read = std::chrono::steady_clock::now();
	 diff_read = end_read - start_read;


	std::cout <<"total duration :  "<< std::chrono::duration <double, std::milli> (first_part_time+diff_read).count() << " ms" << std::endl;

	return 0;
 }
