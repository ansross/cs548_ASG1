#include "kmers.h"

kmers::kmers(void){
	
}

kmers::~kmers(void){
}

void kmers::add_kmer(std::string kmer_string_arg){
	k_mer new_kmer = k_mer(kmer_string_arg);
	std::pair<std::string, k_mer> temp;
	temp = std::make_pair(kmer_string_arg, new_kmer);
	all_kmers.insert(temp);
	//increment vetex weight by one
	all_kmers[kmer_string_arg].increment_weight(1);
}

//merges kmer2 into kmer1 by combining adjacenies and 
//adding the vertex weight of kmer2 to kmer1
// then deletes kmer2 from all_kmers
void kmers::merge_kmers(std::string kmer1str, std::string kmer2str){
	all_kmers[kmer1str].increment_weight(all_kmers[kmer2str].get_weight());
	std::vector<std::string> k2_adj = all_kmers[kmer2str].get_adj();
	for(auto it = k2_adj.begin(); it != k2_adj.end(); ++it){
		all_kmers[kmer1str].add_adjacent((*it)[(*it).size()-1], -1);
	}
	all_kmers.erase(kmer2str);
}

bool kmers::is_within_hamming_dist(k_mer k_mer_one,k_mer k_mer_two, int d){
	bool is_within_d = true;
	int hamming_dist = 0;
	std::string k_mer_str1 = k_mer_one.get_k_mer();
	std::string k_mer_str2 = k_mer_two.get_k_mer();
	for(unsigned i = 0; i<k_mer_str1.length(); ++i){
		if(k_mer_str1[i] != k_mer_str2[i]){
			++hamming_dist;
		}
		if(hamming_dist > d){
			is_within_d = false;
			break;	
		}
	} 
	return is_within_d;
}

void kmers::build_A_bruijn_graph(const int ham_dist){
	std::set<std::pair<int, std::string>, comp_kmers_on_weights> k_mer_in_process_order;
	//want to process in order of vertex weightsi
	int i = 0;
	for(auto it=all_kmers.begin(); it != all_kmers.end(); ++it){
		if(i%1000000 == 0){
			std::cout<<"ordering kmer: "<<i<<std::endl;
		}
		++i;
		std::pair<int, std::string> temp = std::make_pair(it->second.get_weight(), it->second.get_k_mer());
		k_mer_in_process_order.insert(temp);				
	}	
	//for each k_mer, find all k_mers within hamming distance ham_dist
	i=0;
	for(auto it = k_mer_in_process_order.begin(); it != k_mer_in_process_order.end(); ++it){
		if(i%1000000==0){
			std::cout<<"processing k_mer: "<<i<<std::endl;
		}
		++i;
		//if this kmer hasn't already been collapsed, try to collapse others into it
		if(all_kmers.find(it->second) != all_kmers.end()){
			std::vector<k_mer> within_hamming_k_mers = find_close_matches(ham_dist, *it, k_mer_in_process_order);
			for(k_mer k : within_hamming_k_mers){
				//std::cout<<"merging "<<it->second<<" and "<<k.get_k_mer()<<std::endl;
				merge_kmers(it->second, k.get_k_mer());
				//std::cout<<k.get_k_mer()<<'\n';
			}	
		}
	}

}


std::vector<k_mer> kmers::find_close_matches(const int &ham_dist, std::pair<int, std::string> start, std::set<std::pair<int, std::string>, comp_kmers_on_weights> &k_mer_set){
	std::vector<k_mer> matches;
	k_mer kmer_of_interest = all_kmers[start.second];
	auto it = k_mer_set.find(start);
	++it;
	while(it != k_mer_set.end()){
		if (all_kmers.find(it->second) != all_kmers.end()){
			if( is_within_hamming_dist(kmer_of_interest, all_kmers[it->second],ham_dist)){
				k_mer match = all_kmers[it->second];
				matches.push_back(match);
			}	
		}
		++it;
		
	}
	return matches;
}

//since the unorded_map that the k_minus_one_mers is not sorted
//enter them into a set to get the k-1-mers lexically ordered to print 
std::set<std::string> kmers::get_all_k_minus_one_mers_ordered(void)
{
	std::set<std::string> sorted_kmers = std::set<std::string>();
	for(auto it = all_kmers.begin(); it != all_kmers.end(); ++it)
	{
		sorted_kmers.insert(it->first);
	}
	return sorted_kmers;
}

std::set<std::string> kmers::get_all_kmers_ordered(void){
	std::set<std::string> sorted_kmers = std::set<std::string>();
	for(auto it = all_kmers.begin(); it != all_kmers.end(); ++it)
	{
		//take all k-1 mers and use adjacent k-1 mers to reconstruct k-mers
		for(std::string adj : it->second.get_adj()){
			sorted_kmers.insert(it->first+adj[adj.length()-1]);
		}
	}
	return sorted_kmers;
}

void kmers::print_all_kmers_with_adj(std::string outfile_name)
{
	std::ofstream outfile;
	outfile.open(outfile_name);
	std::cout<<"printing all k-1-mers with adjacencies"<<std::endl;
	outfile<<"printing all k-1-mers with adjacencies"<<std::endl;
	std::set<std::string> sorted_kmers = kmers::get_all_kmers_ordered();
	for(auto iter = sorted_kmers.begin(); iter!=sorted_kmers.end(); ++iter)
	{
		outfile << *iter <<": ";
		std::vector<std::string> adjs = all_kmers[*iter].get_adj();
		for(auto i = adjs.begin(); i != adjs.end(); ++i)
		{
			outfile<<*i<<", ";
		}
		outfile<<std::endl;
	}
	outfile.close();
}

k_mer kmers::get_kmer(std::string kmer_str){
	return all_kmers[kmer_str];
}

//find relevant k-1-mer and add the adjacent k-1-mer 
void kmers::add_adjacent(std::string kmer, char kmer_adj, int lineNum){
	all_kmers[kmer].add_adjacent(kmer_adj, lineNum);
}

int kmers::get_size(){
	return all_kmers.size();
}


