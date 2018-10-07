#include "lib.hpp"



int main()
{

	size_t number_of_entries = 5e6;
	auto start_read = std::chrono::steady_clock::now();
//	writeEntries_1(number_of_entries,6);
	produceAndWriteEntriesInBinaryWithSize(7,number_of_entries);
	auto vec_of_pairs = readBinFile_vector(number_of_entries);
	 auto end_read = std::chrono::steady_clock::now();
	auto diff_read = end_read - start_read;
	auto first_part_time = diff_read;
	std::cout <<"duration of produceAndWriteEntriesWithSize and readBinFile_vector :  "<< std::chrono::duration <double, std::milli> (diff_read).count() << " ms" << std::endl;
	start_read = std::chrono::steady_clock::now();
	sortVecOfPair(vec_of_pairs);
	writeSortedEntriesASCII(vec_of_pairs);
//	std::sort(vec_of_pairs.begin(),vec_of_pairs.end(),[](std::pair<int,std::string> _pair1,std::pair<int,std::string> _pair2)
//			{
//				return _pair1.first < _pair2.first;
//			});
//	for(const auto& pair : vec_of_pairs  )
//	{
//		std::cout <<pair.first<<"\t"<< pair.second <<std::endl;
//	}
	end_read = std::chrono::steady_clock::now();
	 diff_read = end_read - start_read;

	std::cout <<"duration of sort :  "<< std::chrono::duration <double, std::milli> ( diff_read).count() << " ms" << std::endl;

	std::cout <<"total duration :  "<< std::chrono::duration <double, std::milli> (first_part_time+diff_read).count() << " ms" << std::endl;

	return 0;
}
