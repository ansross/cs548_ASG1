/*
 * fastaParser.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: anross
 */

#include "fastqParser.h"
#include "kmers.h"
#include <fstream>
#include <iostream>
	void fastqParser::parseFastq(const std::string &filename, kmers &data_struct, const int k)
	{
		std::string line;
		int lineCount = 0;
		std::ifstream file(filename);
		if (file.is_open())
		{
			while( getline(file,line)){
				if(lineCount%4==1){
					std::cout<<"line: "<<line<<std::endl;
					parseLine(line, data_struct, k);
				}
				++lineCount;
			}
			file.close();
		}



	}
	
	

	void  fastqParser::parseLine(std::string line, kmers &data_struct, const int k){
		//getting all (k-1)-mers
		const int k_minus_one = k-1;
		std::cout<<"line size: "<<line.size()<<std::endl;
		for(unsigned i=0; i<line.size()-(k_minus_one); ++i){
			std::cout<<"kmer: "<<line.substr(i, k-1)<<std::endl;
			data_struct.add_kmer(line.substr(i,k-1));
			std::cout<<"i: "<<i<<std::endl;
			if(i!=0){
				std::cout<<line.substr(i-1, k-1)<<" adding "<<line.at(i+k-1)<<std::endl;
				data_struct.add_adjacent(line.substr(i-1,(k-1)), line.at(i+k-1));
				std::cout<<"added"<<std::endl;
			}
		}
	}



