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
class kmers{
private:
		std::unordered_map<std::string, k_mer> all_kmers;

public:
	kmers(void);
	~kmers(void);
	void add_kmer(std::string kmer_arg);
	std::set<std::string> get_all_kmers_ordered(void);
	void add_adjacent(std::string kmer, char kmer_adj);
	void print_all_kmers_with_adj(std::string outfile_name);
};



#endif /* KMERS_H_ */
