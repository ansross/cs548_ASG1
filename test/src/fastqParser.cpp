/*
 * fastaParser.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: anross
 */

#include "fastqParser.h"
#include "kmers.h"
#include <fstream>
void fastqParser::parseFastq(const std::string &filename, kmers &data_struct, const int k)
{
	std::string line;
	int lineCount = 0;
	std::ifstream file(filename);
	if (file.is_open())
	{
		while( getline(file,line)){
			if(lineCount%4==1){
				parseLine(line, data_struct, k, lineCount);
			}
			++lineCount;
			if(lineCount%10000000==0){
				std::cout<<"line: "<<lineCount<<std::endl;
			}
		}
		file.close();
	}



}



void  fastqParser::parseLine(std::string line, kmers &data_struct, const int k, int lineNum){
	//getting all (k-1)-mers
	const int k_minus_one = k-1;
	for(unsigned i=0; i<=line.size()-(k-1); ++i){
		data_struct.add_kmer(line.substr(i,k-1));
		if(i!=0){
			data_struct.add_adjacent(line.substr(i-1,(k-1)), line.at(i+k-1-1), lineNum);
		}
	}
}



