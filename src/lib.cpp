#include "lib.hpp"

int fast_char_to_int(const char *p) {
        int x = 0;
        bool neg = false;
            if (*p == '-') {
                neg = true;
                ++p;
            }
            while (*p >= '0' && *p <= '9') {
                x = (x*10) + (*p - '0');
                ++p;
            }
            if (neg) {
                x = -x;
            }
            return x;
}

//std::vector<std::string> produceNumberOfEntries(size_t number_of_entries)
//		{
//	std::vector<std::string> vec_of_string;
//		for (size_t i = 0 ; i< number_of_entries ; ++i)
//		{
//			vec_of_string.emplace_back(produceEntry(6));
//		}
//		return vec_of_string;
//		}
//void writeEntries_2(const std::vector<std::string>& vec_strings)
//{
//	std::ofstream outf("outfile2.bin",std::ios::binary);
//	auto size = vec_strings[0].size();
//
//	for(auto& strng : vec_strings)
//	{
//		outf.write(strng.c_str(),sizeof(char)*size+1);
//	}
//	outf.close();
//
//}
//void writeEntries_1(size_t number_of_entries,size_t size_of_entry)
//{
//	std::ofstream outf("outfile1.bin",std::ios::binary);
//	for(size_t i = 0 ; i <number_of_entries ; ++i)
//	{
//		outf.write(produceEntry(size_of_entry).c_str(),sizeof(char)*size_of_entry +1);
////		outf << std::ios::binary<<produceEntry(size_of_entry) <<std::endl;
//	}
//	outf.close();
//}
//
void produceAndWriteEntriesInBinaryWithSize(int size,int number_of_entries)
{
	    std::string entry_str;
	    entry_str.reserve(size);

	//std::string entry_int = std::string();
	//entry_int.reserve(size);
    int entry_int;

	std::mt19937 rng(std::random_device{}());

	std::uniform_int_distribution<std::mt19937::result_type> dist(1,std::numeric_limits<int>::max());

	std::ofstream outf("outfile_final.bin",std::ios::binary | std::ios::trunc);
	char tab = '\t';
	char endl = '\n';

	//size_t size_str = sizeof(char) * size;
	size_t size_alpha_str = sizeof(alpha) - 1 ;
	for(int ent = 0 ; ent < number_of_entries ; ++ent)
	{
        entry_int = dist(rng);
        std::cout << entry_int << std::endl;
        outf.write(reinterpret_cast<const char*>(&entry_int),sizeof(entry_int));
		//outf.write(&tab,sizeof(char));

		for (int i = 0; i < size; ++i) {
			entry_str += alpha[dist(rng) % (size_alpha_str)];
		}
        std::cout << entry_str << std::endl;
	    outf << entry_str;
        entry_str.clear();
        //outf.write((char *)&entry_str,sizeof(entry_str));
		//outf.write(&endl,sizeof(char));

	}


	outf.close();
}





void sortVecOfPair(std::vector<std::pair<int,std::string>>& to_be_sorted)
{
	std::sort(to_be_sorted.begin(),to_be_sorted.end(),[](std::pair<int,std::string>& _pair1,std::pair<int,std::string>& _pair2)
			{
		return _pair1.first < _pair2.first;
			});
}

std::vector<std::pair<int,std::string>> readBinFile_vector(int number_of_entries)
		{
	std::ifstream inf("outfile_final.bin",std::ios::binary | std::ios::in);
	std::string string_part; 
    int int_part ;	
    //std::string int_part = std::string();
	std::vector<std::pair<int,std::string>> vec_of_pairs;
	vec_of_pairs.reserve(number_of_entries);
    if (inf.is_open()){
	    for (int i = 0 ; i < number_of_entries ;++i)
	    {
	    inf.read(reinterpret_cast<char * >(&int_part),sizeof(int)); 
        std::cout << "int part : "<< int_part << std::endl;
            //inf >> int_part;
	   inf >> string_part; 
        ////inf.read(reinterpret_cast<char * >(&string_part),sizeof(string_part)); 
        std::cout <<"int part "<< int_part << " str part : "<< string_part << std::endl;
            vec_of_pairs.emplace_back(int_part,string_part);
            //vec_of_pairs[i] = {fast_char_to_int(int_part.c_str()),string_part};
	    }
        }
	inf.close();
	return vec_of_pairs;

		}


std::multimap<int,std::string> readBinFile_multi_map(int number_of_entries){
	
    std::ifstream inf("outfile_final.bin",std::ios::binary);
	std::string string_part = std::string();
	std::string int_part = std::string();
    std::multimap<int,std::string> mmap;

    if (inf.is_open()){
	    for (int i = 0 ; i < number_of_entries ;++i)
	    {
	    	inf >> int_part;
	    	inf >> string_part;
            //vec_of_pairs.emplace_back(std::stoi(int_part),string_part);
            //-----BELOW IS POSSIBLY FASTER BUT LESS SAFE VERSION OF stoi, C.style.
            mmap.emplace(fast_char_to_int(int_part.c_str()),string_part);
	    }
        }
	inf.close();
	return mmap;

}
void writeSortedEntriesASCII(const std::vector<std::pair<int,std::string>> &  vec_to_be_written)
{
	std::ofstream outf("final_result_ascii.txt");


	char tab = '\t';
	char space = ' ';
	char endl ='\n';
	for(auto& int_string_pair : vec_to_be_written)
	{
		outf << int_string_pair.first;
		outf.write(&tab,sizeof(char));

		for( auto& a_char : int_string_pair.second)
		{
			outf<<(int)a_char;
			outf.write(&space,sizeof(char));
		}
		outf.write(&endl,sizeof(char));
	}
	outf.close();
}
void writeSortedEntriesASCII_mmap(const std::multimap<int,std::string>&  mmap)
{
	std::ofstream outf("final_result_ascii.txt");


	char tab = '\t';
	char space = ' ';
	char endl ='\n';
	for(auto& int_string_pair : mmap)
	{
		outf << int_string_pair.first;
		outf.write(&tab,sizeof(char));

		for( auto& a_char : int_string_pair.second)
		{
			outf<<(int)a_char;
			outf.write(&space,sizeof(char));
		}
//		outf<<end_line;
		outf.write(&endl,sizeof(char));
	}
	outf.close();
}


// previous trials with maps
//std::map<int,std::string> readBinFile_map(int number_of_entries)
//		{
//			std::ifstream inf("outfile_final.bin",std::ios::binary);
//			std::string string_part = std::string();
//			std::string int_part = std::string();
//			std::map<int,std::string> readFile;
//
//			for (int i = 0 ; i < number_of_entries ;++i)
//			{
//			inf >> int_part;
//			inf >> string_part;
//			readFile.insert(std::make_pair(std::stoi(int_part),string_part));
//			}
//			inf.close();
//			return readFile;
//
//		}
//
//

