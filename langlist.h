//
// langlist.h --  holds class LangugeList and class Language
//	  by: Vivian Hong
//	date: 11/15/2015
//
#include "trigram.h"
class Language
{
public:
	Language();
	void 			add(int);
	void 			expand();
	void 			get_trigram(string);
	string 			get_store(int);
	int 			get_repeat(int);
	int 			get_capacity();
	int 			get_used();
	TrigramVector 		get_class();;
	void 			add_similarity(float);
	void 			add_shared(string, float, float, float, float);
	void 			add_normalized (float, float, float, float);
	float 			*known_normalized;
	float 			*unknown_normalized;
	int 			 used;
	float		 	*similarity;
private:
	TrigramVector		tri;
	string 			*shared;
	int 			capacity;
	void 			add_normalized(int, int);
	void 			add_expand();
	int 			sim_used;
	int 			sim_capacity;
	void 			sim_expand();
};

class LanguageList
{
public:
	LanguageList();
	void		add(string, string);
	void 		print_freq();
	void 		calculate();
private:
	Language	*language;
	string 		*lang;
	void 		expand();
	int 		capacity;
	int 		used;
	void 		make_shared_array(TrigramVector, TrigramVector, int);
	float 		calculate_denom(int);
	float 		calculate_num(int);
	float 		square(float);
	float 		root(float);
	float 		numerator;
	float 		denominator;
	float 		similarity_num;
	void		print_similarity();
	float 		*in_order;
	int 		order_used;
	string 		*order_lang;
	int 		order_capacity;
	void 		order_expand();
	void 		order_add(float, string);
};
