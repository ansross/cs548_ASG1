#include "kmers.h"

kmers::kmers(void){
	
}

kmers::~kmers(void){
}

void kmers::add_kmer(std::string kmer_string_arg){
	k_mer new_kmer = k_mer(kmer_string_arg);
	std::pair<std::string, k_mer> temp;
	temp = std::make_pair(kmer_string_arg, new_kmer);
	all_kmers.insert(temp);
}

std::set<std::string> kmers::get_all_kmers_ordered(void)
{
	std::set<std::string> sorted_kmers = std::set<std::string>();
	for(auto it = all_kmers.begin(); it != all_kmers.end(); ++it)
	{
		sorted_kmers.insert(it->first);
	}
	return sorted_kmers;
}

void kmers::print_all_kmers_with_adj(std::string outfile_name)
{
	std::ofstream outfile;
	outfile.open(outfile_name);
	std::cout<<"printing all k-1-mers with adjacencies"<<std::endl;
	outfile<<"printing all k-1-mers with adjacencies"<<std::endl;
	std::set<std::string> sorted_kmers = kmers::get_all_kmers_ordered();
	for(auto iter = sorted_kmers.begin(); iter!=sorted_kmers.end(); ++iter)
	{
		outfile << *iter <<": ";
		std::vector<std::string> adjs = all_kmers[*iter].get_adj();
		for(auto i = adjs.begin(); i != adjs.end(); ++i)
		{
			outfile<<*i<<", ";
		}
		outfile<<std::endl;
	}
	outfile.close();
}

void kmers::add_adjacent(std::string kmer, char kmer_adj){
	all_kmers[kmer].add_adjacent(kmer_adj);
}



