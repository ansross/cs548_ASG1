/*
 * kmers.h
 *
 *  Created on: Sep 21, 2014
 *      Author: anross
 */

#ifndef KMERS_H_
#define KMERS_H_
#include <set>
#include <unordered_map>
#include <utility>
#include "k_mer.h"
#include <iostream>
#include <fstream>

class comp_kmers_on_weights{
public:
bool operator()(const std::pair<int, std::string> &k1, const std::pair<int, std::string> &k2){
	return k1.first > k2.first;	
}
};

class kmers{
private:
	std::unordered_map<std::string, k_mer> all_kmers;


public:


	kmers(void);
	~kmers(void);
	void add_kmer(std::string kmer_arg);
	std::set<std::string> get_all_kmers_ordered(void);
	void add_adjacent(std::string kmer, char kmer_adj, int lineNum);
	void print_all_kmers_with_adj(std::string outfile_name);
	int get_size();
	void merge_kmers(k_mer, k_mer);
	void build_A_bruijn_graph(const int);
	k_mer get_kmer(std::string);
	std::vector<k_mer> find_close_matches(const int&, std::pair<int, std::string> , std::set<std::pair<int, std::string>, comp_kmers_on_weights> &); 	
	int get_hamming_dist(k_mer, k_mer);
};



#endif /* KMERS_H_ */
