#include "lib.hpp"



int main(int argc, char** argv)
{
   if ( argc != 2) std::cerr << "number of arguments must be one, the number of entries " <<'\n';
	size_t number_of_entries = std::stoi(std::string(argv[1]));
	//size_t number_of_entries =5e7;

    
    std::cout <<"number of threads :" << omp_get_max_threads() << std::endl;
    auto start_read = std::chrono::steady_clock::now();
	produceAndWriteEntriesInBinaryWithSize(7,number_of_entries);
    auto end_read = std::chrono::steady_clock::now();
    auto produce_and_write_entries_time = end_read - start_read ;
	std::cout <<"Duration of produceAndWriteEntriesWithSize  :  "<< std::chrono::duration <double, std::milli> (produce_and_write_entries_time).count() << " ms" << std::endl;
    
    
    start_read = std::chrono::steady_clock::now();
	auto vec_of_pairs = readBinFile_vector(7, number_of_entries);
	end_read = std::chrono::steady_clock::now();
	auto read_bin_file_time = end_read - start_read;
    std::cout <<"Duration of readBinFile_vector :  "<< std::chrono::duration <double, std::milli> (read_bin_file_time).count() << " ms" << std::endl;
	
    
    start_read = std::chrono::steady_clock::now();
	sortVecOfPair(vec_of_pairs);
	end_read = std::chrono::steady_clock::now();
	auto sort_time = end_read - start_read;
	std::cout <<"Duration of sort :  "<< std::chrono::duration <double, std::milli> ( sort_time).count() << " ms" << std::endl;
	
    start_read = std::chrono::steady_clock::now();
	writeSortedEntriesASCII(vec_of_pairs);
	end_read = std::chrono::steady_clock::now();
	auto write_sorted_time = end_read - start_read;
	std::cout <<"Duration of writeSortedEntriesASCII :  "<< std::chrono::duration <double, std::milli> (write_sorted_time).count() << " ms" << std::endl;

	std::cout <<"Total duration :  "<< std::chrono::duration <double, std::milli> (produce_and_write_entries_time + read_bin_file_time + sort_time + write_sorted_time).count() << " ms" << std::endl;

	return 0;
 }
