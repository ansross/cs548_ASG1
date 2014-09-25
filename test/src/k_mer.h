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


class k_mer{
	private:
		std::string k_mer_string;
		enum bases {A=0, C=1, T=2, G=3, N=4};
		bool adjacent_kmer_end [5];
	public:
	k_mer(void);
	k_mer(const std::string k_mer_arg);
	~k_mer(void);
	void add_adjacent(char adj_arg);
	std::vector<std::string> get_adj();
	std::string get_k_mer();

};



#endif /* K_MER_STRUCT_H_ */
