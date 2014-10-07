#ifndef ANNIE_HELPER_H_
#define ANNIE_HELPER_H_
#include "k_mer.h"
#include<string>
int get_hamming_dist(k_mer k_mer_one,k_mer k_mer_two){
	int hamming_dist = 0;
	std::string k_mer_str1 = k_mer_one.get_k_mer();
	std::string k_mer_str2 = k_mer_two.get_k_mer();
	for(unsigned i = 0; i<k_mer_str1.length(); ++i){
		if(k_mer_str1[i] != k_mer_str2[i]){
			++hamming_dist;
		}
	} 
	return hamming_dist;
}

#endif

