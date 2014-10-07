
Annie Ross
CS548 Fall 2014
ASSIGNMENT 1

IMPORTANT: since the data structure stored (k-1)-mers, I printed out (k-1)-mers. If you need k-mers, use k+1 as imput.
to compile program:
	% c++ -std=c++11 k_mer.cpp kmers.cpp fastqParser.cpp main.cpp -o main_prog

to run the program:
	% main_prog -k <k> -f1 <fastq_file_name_1> -f2 <fastq_file_name_2>

output:
	the program will create a file named <k>_minus_one_mers.txt printing out all (k-1)-mers in lexographical order.
	The program will print progess messages to the terminal
