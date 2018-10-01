#include "lib.hpp"

std::string produceEntry(size_t size_of_entry)
{
	std::string entry = std::string();


	std::mt19937 rng;

	rng.seed(std::random_device()());

	//std::uniform_int_distribution<std::mt19937::result_type> int_dist(1,9);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1,26);

	while(entry.size() != size_of_entry)
	{
		if(dist(rng) % 2)
			{
				int b = dist(rng);
				entry.append(1,static_cast<char>(b+96));
			}
		else
		{
			int int_number = dist(rng) % 10;
			entry.append(std::to_string(int_number));
		}
	}
	return entry;
}

std::vector<std::string> produceNumberOfEntries(size_t number_of_entries)
		{
	std::vector<std::string> vec_of_string;
		for (size_t i = 0 ; i< number_of_entries ; ++i)
		{
			vec_of_string.emplace_back(produceEntry(6));
		}
		return vec_of_string;
		}
void writeEntries_2(const std::vector<std::string>& vec_strings)
{
	std::ofstream outf("outfile2.bin",std::ios::binary);
	auto size = vec_strings[0].size();

	for(auto& strng : vec_strings)
	{
		outf.write(strng.c_str(),sizeof(char)*size+1);
	}
	outf.close();

}
void writeEntries_1(size_t number_of_entries,size_t size_of_entry)
{
	std::ofstream outf("outfile1.bin",std::ios::binary);
	for(size_t i = 0 ; i <number_of_entries ; ++i)
	{
		outf.write(produceEntry(size_of_entry).c_str(),sizeof(char)*size_of_entry +1);
//		outf << std::ios::binary<<produceEntry(size_of_entry) <<std::endl;
	}
	outf.close();
}

void produceAndWriteEntriesInBinaryWithSize(int size,int number_of_entries)
{


	std::string entry_str = std::string();
	entry_str.reserve(size);

	std::string entry_int = std::string();
	entry_int.reserve(size);

	std::mt19937 rng;

	rng.seed(std::random_device()());

	std::uniform_int_distribution<std::mt19937::result_type> dist(1,std::numeric_limits<int>::max());

	std::ofstream outf("outfile_final.bin",std::ios::binary);

	for(int ent = 0 ; ent < number_of_entries ; ++ent)
	{
		for (int i = 0; i < size; ++i) {
			entry_int[i] = num[dist(rng) % (sizeof(num) - 1)];
			//			entry_int.append(1,num[dist(rng) % (sizeof(num) - 1)]);
		}
		outf.write(entry_int.c_str(),sizeof(char)*size);
		outf<<"\t";

		for (int i = 0; i < size; ++i) {
			entry_str[i] = alpha[dist(rng) % (sizeof(alpha) - 1)];
			//			entry_str.append(1,alpha[dist(rng) % (sizeof(alpha) - 1)]);
		}
		outf.write(entry_str.c_str(),sizeof(char)*size);

		outf<<std::endl;

	}


	outf.close();
}


std::map<int,std::string> readBinFile_map(int number_of_entries)
		{
			std::ifstream inf("outfile_final.bin",std::ios::binary);
			std::string string_part = std::string();
			std::string int_part = std::string();
			std::map<int,std::string> readFile;

			for (int i = 0 ; i < number_of_entries ;++i)
			{
			inf >> int_part;
			inf >> string_part;
			readFile.insert(std::make_pair(std::stoi(int_part),string_part));
			}
			inf.close();
			return readFile;

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
	std::ifstream inf("outfile_final.bin",std::ios::binary);
	std::string string_part = std::string();
	std::string int_part = std::string();
	std::vector<std::pair<int,std::string>> vec_of_pairs;
	for (int i = 0 ; i < number_of_entries ;++i)
	{
		inf >> int_part;
		inf >> string_part;
		vec_of_pairs.emplace_back(std::make_pair(std::stoi(int_part),string_part));
	}
	inf.close();
	return vec_of_pairs;

		}

void writeSortedEntriesASCII(const std::vector<std::pair<int,std::string>> &  vec_to_be_written)
{
	std::ofstream outf("final_result_ascii.txt");

	for(const auto& int_string_pair : vec_to_be_written)
	{
		outf << int_string_pair.first<<"\t";
		for(const auto& a_char : int_string_pair.second)
		{
			outf<<(int)a_char;
		}
		outf<<std::endl;
	}
	outf.close();
}





