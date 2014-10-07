
#include "k_mer.h"
#include <iostream>
//using namespace std;

//default weight=0 since will be incremented after insertion 
k_mer::k_mer(void): vertex_weight(0)  {
	for(int i=0; i<5; ++i){
		adjacent_kmer_end[i] = false;
	}
}

k_mer::k_mer(const std::string k_mer_arg): k_mer_string(k_mer_arg), vertex_weight(0) {
	for(int i=0; i<5; ++i){
		adjacent_kmer_end[i] = false;
	}

}

k_mer::~k_mer(void)
{
}

// mark true in the array corresponding to the last base of 
// the adjacent k-1-mer
void k_mer::add_adjacent(char adj_arg, int lineNum){
	int index = 0;
	bool valid = true;
	switch (adj_arg)
	{
	case 'A':
		index = k_mer::A;
		break;
	case 'C':
		index = k_mer::C;
		break;
	case 'G':
		index = k_mer::G;
		break;
	case 'T':
		index = k_mer::T;
		break;
	case 'N':
		index = k_mer::N;
		break;
	default:
		std::ofstream ss;
		ss.open("err.txt", std::ios::out | std::ios::app );
		ss<<"ERROR!!! Invalid base "<<adj_arg<<" from "<<lineNum<<std::endl;
		valid = false;
		ss.close();
	}
	if(valid){
		adjacent_kmer_end[index] = true;
	}
}

// return a set of strings based on the 
// ending base of the adjacent (k-1)-mers 
// and the overlapping portion of the current (k-1)-mer
std::vector<std::string> k_mer::get_adj(){
	std::vector<std::string> adj_kmers;
	for(int i=0; i<5; ++i)
	{
		bool valid = true;
		if(adjacent_kmer_end[i]){
			char base;
			switch(i){
			case k_mer::A:
				base = 'A';
				break;
			case k_mer::C:
				base = 'C';
				break;
			case k_mer::G:
				base='G';
				break;
			case k_mer::T:
				base = 'T';
				break;
			case k_mer::N:
				base = 'N';
				break;
			default:
				base='!';
				std::cout<<"ERROR!!!! Invalid base: "<<i<<std::endl;
				valid=false;
				break;
			}
			// an overlap of k_minus_one_mer[1:end] between the k-1-mer 
			// and its adjacent mers. 
			if(valid){
				adj_kmers.push_back(k_mer_string.substr(1, k_mer_string.length()-1) + base);
			}
		}

	}
	return adj_kmers;
}

void k_mer::increment_weight(int inc_by){
	vertex_weight += inc_by; 
}

const int k_mer::get_weight(){
	const int ret_weight = vertex_weight;
	return ret_weight;
}

std::string k_mer::get_k_mer(){
	return k_mer_string;
}

