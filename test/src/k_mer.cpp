
#include "k_mer.h"
#include <iostream>
//using namespace std;

k_mer::k_mer(void){

}

k_mer::k_mer(const std::string k_mer_arg): k_mer_string(k_mer_arg) {

}

k_mer::~k_mer(void)
{
}

void k_mer::add_adjacent(char adj_arg){
	std::cout<<"check 1"<<std::endl;
	adjacent_kmer_end[adj_arg] = true;
	std::cout<<"check 2"<<std::endl;
}


bool* k_mer::get_adj(){
	return adjacent_kmer_end;
}

std::string k_mer::get_k_mer(){
	return k_mer_string;
}

