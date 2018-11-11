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

void produceAndWriteEntriesInBinaryWithSize(int size,int number_of_entries)
{

	//std::string entry_int = std::string();
	//entry_int.reserve(size);
    int entry_int;

	std::mt19937 rng(std::random_device{}());
	//std::uniform_int_distribution<std::mt19937::result_type> dist(1,std::numeric_limits<int>::max());
	std::uniform_int_distribution<std::mt19937::result_type> dist(std::pow(10,size),std::pow(10,size+1)-1);

	std::ofstream outf("outfile_final.bin",std::ios::binary );

	//size_t size_str = sizeof(char) * size;
	constexpr size_t size_alpha_str = sizeof(alpha) - 1 ;
    std::cout << "Generating random entries and writing them in binary ...\n";
    srand(time(NULL));
    //#pragma omp parallel for  
	for(int ent = 0 ; ent < number_of_entries ; ++ent)
	{
	    std::string entry_str;
        entry_int = dist(rng);
        outf.write(reinterpret_cast<const char*>(&entry_int),sizeof(int));
		//outf.write(&tab,sizeof(char));
		for (int i = 0; i < size; ++i) {
			entry_str += alpha[rand() % (size_alpha_str)];
		}
        //std::cout << entry_str << std::endl;
        //std::cout <<sizeof(entry_str.c_str())<<std::endl;
	   outf.write(entry_str.c_str(),size);
        //entry_str.clear();
        //outf.write((char *)&entry_str,sizeof(entry_str));
		//outf.write(&endl,sizeof(char));
     for (double b = 0.1; b <= 1; b += 0.1) if (ent == static_cast<int>(b * number_of_entries)) std::cout << b * 100 << "% completed.\n";
     
	}
	outf.close();
}





void sortVecOfPair(std::vector<std::pair<int,std::string>>& to_be_sorted)
{
    std::cout <<"Sorting ... \n"; 
	std::sort(to_be_sorted.begin(),to_be_sorted.end(),[](std::pair<int,std::string>& _pair1,std::pair<int,std::string>& _pair2)
			{
		return _pair1.first < _pair2.first;
			});
}

std::vector<std::pair<int,std::string>> readBinFile_vector(int size, int number_of_entries)
		{
	std::ifstream inf("outfile_final.bin",std::ios::binary | std::ios::in);
	std::string string_part(size,'\0');
    int int_part ;	
    //std::string int_part = std::string();
	std::vector<std::pair<int,std::string>> vec_of_pairs;
	vec_of_pairs.reserve(number_of_entries);
    std::cout << "Reading the binary file into a vector of pairs ... \n";
    if (inf.is_open()){
	    for (int i = 0 ; i < number_of_entries ;++i)
        {
	    inf.read(reinterpret_cast<char * >(&int_part),sizeof(int)); 
            //inf >> int_part;
        inf.read(&string_part[0],size); 
        ////inf.read(reinterpret_cast<char * >(&string_part),sizeof(string_part)); 
        //std::cout <<"int part "<< int_part << " str part : "<< string_part << std::endl;
        vec_of_pairs.emplace_back(int_part,string_part);
            //vec_of_pairs[i] = {fast_char_to_int(int_part.c_str()),string_part};
            
     for (double b = 0.1; b <= 1; b += 0.1) if (i == static_cast<int>(b * number_of_entries)) std::cout << b * 100 << "% completed.\n";
        }
            }
	inf.close();
	return vec_of_pairs;
		}


void writeSortedEntriesASCII(const std::vector<std::pair<int,std::string>> &  vec_to_be_written)
{
	//std::ofstream outf("final_result_ascii.txt",std::ios::out);
    std::FILE * fp = fopen("final_result_ascii.txt","w");

    double b = 0.1;
    std::cout <<"Writing sorted entries into final_result_ascii.txt file ...\n";
    
    std::for_each(vec_to_be_written.begin(),vec_to_be_written.end(),[&b,&fp](const std::pair<int,std::string>& pair)
        {
        fprintf(fp, "%7d\t%s\n", pair.first, pair.second.c_str());
        if(pair.first > static_cast<int>(std::numeric_limits<int>::max() * b))
            {
                std::cout <<b * 100 <<"% completed.\n";
                b+=0.1;
            }
        });
    std::fclose(fp);
}
