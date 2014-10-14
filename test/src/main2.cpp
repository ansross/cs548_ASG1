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
	std::cout<<"running"<<std::endl;
	if(argcv == 9){
		std::string fastq1;
		std::string fastq2;
		int k;
		int d;		
		bool valid_args = true; 
		for(int i = 1; i<9; ++i){
			// parse arguments
			switch(argv[i][1]){
			case 'd':{
				++i;
				std::istringstream ss(argv[i]);
				ss >> d;
				break;}
			case 'k':{
				++i;
				std::istringstream ss(argv[i]);
				ss >> k;
				break;}
			case 'f':{
				if(argv[i][2] == '1'){
					fastq1 = argv[++i];
				} else if (argv[i][2] == '2'){
					fastq2 = argv[++i];
				}
				else{
					valid_args = false;		
				}
				break;}
			}

		}
		if(valid_args){
			kmers all_kmers = kmers();
			std::cout<<"k = "<<k<<std::endl;
			std::cout<<"parsing first file "<<fastq1<<std::endl;
			fastqParser::parseFastq(fastq1, all_kmers, k);
			std::cout<<"parsing second file "<<fastq2<<std::endl;
			fastqParser::parseFastq(fastq2, all_kmers, k);
			std::cout<<"num_k_minus_one_mers: "<<all_kmers.get_size()<<std::endl;
			std::string outfile_name = std::to_string(k)+"_mers.txt";
			std::ofstream outfile;
			outfile.open(outfile_name);
			outfile<<"num k-1-mers: "<<all_kmers.get_size()<<std::endl;
			std::cout<<"building A-bruijn graph by merging similar (k-1)-mers"<<std::endl;
			
			
			
			/*			
			std::cout<<"getting all ordered kmers"<<std::endl;
			std::set<std::string> ordered_kmers = all_kmers.get_all_kmers_ordered();
			std::set<std::string>::iterator iter;
			std::cout<<"printing all k-1-mers in lexographical order in "<<outfile_name<<'\n'<<"k = "<<k<<std::endl;
			outfile<<"printing all k-1-mers in lexographical order"<<'\n'<<"k = "<<k<<std::endl;
		
			for(iter= ordered_kmers.begin(); iter != ordered_kmers.end(); ++iter)
			{
				outfile << *iter << " weight: " << all_kmers.get_kmer(*iter).get_weight()<<std::endl;	
			}
			//all_kmers.print_all_kmers_with_adj("test_w_adjs.txt");
			all_kmers.build_A_bruijn_graph(d);
			std::cout<<"getting all ordered collapsed kmers"<<std::endl;
			ordered_kmers = all_kmers.get_all_kmers_ordered();
			std::cout<<"printing all k-mers in lexographical order in "<<outfile_name<<'\n'<<"k = "<<k<<std::endl;
			outfile << "--------------------------------------------------------------------"<<std::endl;
			*/
			all_kmers.build_A_bruijn_graph(d);
			std::cout<<"getting all ordered kmers"<<std::endl;
			std::set<std::string> ordered_kmers2 = all_kmers.get_all_kmers_ordered();
			std::set<std::string>::iterator iter2;	
			std::cout<<"printing all k-mers in lexographical order in "<<outfile_name<<'\n'<<"k = "<<k<<'\n'<<"d = "<<d<<std::endl;		
			outfile<<"printing all k-mers in lexographical order"<<'\n'<<"k = "<<k<<'\n'<<"d = " << d<< std::endl;
		
			for(iter2= ordered_kmers2.begin(); iter2 != ordered_kmers2.end(); ++iter2)
			{
				outfile << *iter2 <<std::endl;	
			}
			outfile.close();
			//all_kmers.print_all_kmers_with_adj("k_minus_one_mers_w_adjs.txt");
			//all_kmers.print_all_kmers_with_adj("post_test_w_adjs.txt");
			return 0;
		}
	}
	std::cout << "usage: <exe_name> -d <d> -k <k> -r1 <fq file 1 name> -r2 <fq file 2 name>"<<std::endl;
}


