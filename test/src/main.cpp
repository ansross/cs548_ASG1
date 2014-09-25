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
		std::cout<<"k = "<<k<<std::endl;
		std::cout<<"parsing first file "<<fastq1<<std::endl;
		fastqParser::parseFastq(fastq1, all_kmers, k);
		std::cout<<"parsing second file "<<fastq2<<std::endl;
		fastqParser::parseFastq(fastq2, all_kmers, k);
		std::set<std::string> ordered_kmers = all_kmers.get_all_kmers_ordered();
		std::set<std::string>::iterator iter;
		std::string outfile_name = "k_minus_one_mers.txt";
		std::ofstream outfile;
		outfile.open(outfile_name);
		std::cout<<"printing all k-1-mers in lexographical order in "<<outfile_name<<'\n'<<"k = "<<k<<std::endl;
		outfile<<"printing all k-1-mers in lexographical order"<<'\n'<<"k = "<<k<<std::endl;
		
		outfile<<"num k-1-mers: "<<ordered_kmers.size()<<std::endl;
		for(iter= ordered_kmers.begin(); iter != ordered_kmers.end(); ++iter)
		{
			outfile << *iter << std::endl;	
		}
		outfile.close();
		all_kmers.print_all_kmers_with_adj("k_minus_one_mers_w_adjs.txt");

		return 0;
	}
	else{
		std::cout << "usage: <exe_name> -k <k> -r1 <fq file 1 name> -r2 <fq file 2 name>"<<std::endl;
	}
}


