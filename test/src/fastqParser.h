/*
 * fastaParser.h
 *
 *  Created on: Sep 21, 2014
 *      Author: anross
 */

#include <fstream>
#include "kmers.h"

#ifndef FASTQPARSER_H_
#define FASTQPARSER_H_
class fastqParser{
	public:
	static void parseFastq(const std::string &filename, kmers &data_struct, const int k);
	static void parseLine(std::string line, kmers &data_struct, const int k, int lineNum);
};

#endif /* FASTAPARSER_H_ */
