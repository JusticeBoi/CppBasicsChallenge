#include "lib.hpp"

void produceAndWriteEntriesInBinaryWithSize(int size,int number_of_entries)
{

    int entry_int;

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<std::mt19937::result_type> dist(std::pow(10, size), std::pow(10, size+1) - 1 );

	std::ofstream outf("outfile_final.bin", std::ios::binary );

	constexpr size_t size_alpha_str = sizeof(alpha) - 1 ;
    std::cout << "Generating random entries and writing them in binary ...\n";
    srand(time(NULL));

	for(int ent = 0 ; ent < number_of_entries ; ++ent)
	{
	    std::string entry_str;
        entry_int = dist(rng);
        outf.write(reinterpret_cast<const char*>(&entry_int), sizeof(int));

		for (int i = 0; i < size; ++i) 
        {
			entry_str += alpha[rand() % (size_alpha_str)];
		}
	    outf.write(entry_str.c_str(), size);

     for (double b = 0.1; b <= 1; b += 0.1) if (ent == static_cast<int>(b * number_of_entries)) std::cout << b * 100 << "% completed.\n";
     
	}
	outf.close();
}

void sortVecOfPair(std::vector<std::pair<int,std::string>>& to_be_sorted)
    {
        #ifdef par_exe_gcc
        std::cout <<"Parallel Sorting ... \n"; 
	    __gnu_parallel::sort(to_be_sorted.begin(), to_be_sorted.end());

        #elif par_exe_msvc
        std::cout <<"Parallel Sorting ... \n"; 
        std::sort(std::execution::par_unseq,to_be_sorted.begin(), to_be_sorted.end()); 

        #else
        std::cout <<"Serial Sorting ... \n"; 
        std::sort(to_be_sorted.begin(), to_be_sorted.end());
        #endif
    }

std::vector<std::pair<int,std::string>> readBinFile_vector(int size, int number_of_entries)
	{
	    std::ifstream inf("outfile_final.bin", std::ios::binary | std::ios::in);

	    std::string string_part(size, '\0');
        int int_part ;	

	    std::vector<std::pair<int,std::string>> vec_of_pairs;

	    vec_of_pairs.reserve(number_of_entries);

        std::cout << "Reading the binary file into a vector of pairs ... \n";

        if (inf.is_open())
            {
	        for (int i = 0 ; i < number_of_entries ;++i)
                {
	                inf.read(reinterpret_cast<char * >(&int_part),sizeof(int)); 

                    inf.read(&string_part[0],size); 

                    vec_of_pairs.emplace_back(int_part,string_part);
                        
                    for (double b = 0.1; b <= 1; b += 0.1) if (i == static_cast<int>(b * number_of_entries)) std::cout << b * 100 << "% completed.\n";
                }
            }
	    inf.close();

	    return vec_of_pairs;
	}


void writeSortedEntriesASCII(const std::vector<std::pair<int,std::string>> &  vec_to_be_written)
{
    std::FILE * fp = fopen("final_result_ascii.txt","w");

    std::cout <<"Writing sorted entries into final_result_ascii.txt file ...\n";
    for(const std::pair<int,std::string>& pair : vec_to_be_written)
    {
        fprintf(fp, "%7d\t%s\n", pair.first, pair.second.c_str());
    }
    //std::for_each(vec_to_be_written.begin(), vec_to_be_written.end(), [&b,&fp,&max](const std::pair<int,std::string>& pair)
    //{
    //    fprintf(fp, "%7d\t%s\n", pair.first, pair.second.c_str());
    //});
    std::fclose(fp);
}
