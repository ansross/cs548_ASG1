/*
 * k_mer_struct.h
 *
 *  Created on: Sep 16, 2014
 *      Author: anross
 */

#ifndef K_MER_STRUCT_H_
#define K_MER_STRUCT_H_
#include<string>
#include<vector>
#include<sstream>
#include <ios>
#include <iostream>
#include<fstream>
class k_mer{
	private:
		std::string k_mer_string;
		int vertex_weight;
		enum bases {A=0, C=1, T=2, G=3, N=4};
		bool adjacent_kmer_end [5];
	public:
	k_mer(void);
	k_mer(const std::string k_mer_arg);
	~k_mer(void);
	void add_adjacent(char adj_arg, int lineNum);
	std::vector<std::string> get_adj();
	std::string get_k_mer();
	const int get_weight();
	void increment_weight(int increment_by);

};



#endif /* K_MER_STRUCT_H_ */
