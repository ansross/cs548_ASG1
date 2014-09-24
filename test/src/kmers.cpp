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

void kmers::print_all_kmers_with_adj(void)
{
	std::cout<<"printing all kmers"<<std::endl;
	std::set<std::string> sorted_kmers = kmers::get_all_kmers_ordered();
	for(auto iter = sorted_kmers.begin(); iter!=sorted_kmers.end(); ++iter)
	{
		std::cout << *iter <<": ";
		bool* adjs = all_kmers[*iter].get_adj();
		for(auto i = 0; i<5; ++i)
		{
			std::cout<<adjs[i]<<", ";
		}
		std::cout<<std::endl;
	}
}

void kmers::add_adjacent(std::string kmer, char kmer_adj){
	std::cout<<"1"<<std::endl;
	all_kmers[kmer].add_adjacent(kmer_adj);
	std::cout<<"2"<<std::endl;
}



