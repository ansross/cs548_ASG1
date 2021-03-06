/*
 * fastaParser.cpp
 *
 *  Created on: Sep 21, 2014
 *      Author: anross
 */

#include "fastqParser.h"
#include "kmers.h"
#include <fstream>
//takes in a fastq file at filename and reads the sequence reads to insert into data_struct
void fastqParser::parseFastq(const std::string &filename, kmers &data_struct, const int k)
{
	std::string line;
	int lineCount = 0;
	std::ifstream file(filename);
	if (file.is_open())
	{
		while( getline(file,line)){
			//every fourth line is a sequence read
			if(lineCount%4==1){
				parseLine(line, data_struct, k, lineCount);
			}
			++lineCount;
			//prints out to ensure the program is making progress
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
		// all except first (k-1)-mer is an adjacent (k-1)-mer of the previous (k-1)-mer
		if(i!=0){
			data_struct.add_adjacent(line.substr(i-1,(k-1)), line.at(i+k-1-1), lineNum);
		}
	}
}



