/*
 * main.cpp

 *
 *  Created on: Sep 16, 2014
 *      Author: anross
 */

#include "k_mer.h"
#include "fastqParser.h"
#include <iostream>
#include <sstream>
#include <set>

int main(int argcv, char* argv[]){
	if(argcv == 7){
		std::istringstream ss(argv[2]);
		int k;
		ss >> k;
		const std::string fastq1 = argv[4];
		const std::string fastq2 = argv[6];
		kmers all_kmers = kmers();
		fastqParser::parseFastq(fastq1, all_kmers, k);
		std::set<std::string> ordered_kmers = all_kmers.get_all_kmers_ordered();
		std::set<std::string>::iterator iter;
		for(iter= ordered_kmers.begin(); iter != ordered_kmers.end(); ++iter)
		{
			std::cout << *iter << std::endl;	
		}
		all_kmers.print_all_kmers_with_adj();
	}
	else{
		std::cout << "usage: <jarfilename> -k <k> -r1 <fq file 1 name> -r2 <fq file 2 name>";
	}
}


