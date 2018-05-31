//
// Language.cpp -- Stores arrays of trigrams for different languages and 
//		   normalizes frequencies
//		by: Vivian Hong
//    date: 11/29/2015
//
#include <iostream>
#include <fstream>
using namespace std;
#include "langlist.h"
#include <fstream>
//
// Language -- constructor: initializes class variables
//	args: none
//	rets: none
//
Language::Language()
{
	shared = NULL;
	known_normalized = NULL;
	unknown_normalized = NULL;
	similarity = NULL;
	sim_capacity = 0;
	sim_used = 0;
	capacity = 0;
	used = 0;
}
//
// get_trigram -- calls get trigram function
//	args: filename
//	rets: none
//
void Language::get_trigram(string fName)
{
	tri.get_trigram(fName);
}
//
// get_store -- returns invidiual trigram functions
//	args: int to specify whcih trigram
//	rets: string trigram
//
string Language::get_store(int i)
{
	return tri.store[i];
}
//
// get_repeat -- returns individual counts
//	args: int to specify which count
//	rets: int count
//
int Language::get_repeat(int i)
{
	return tri.repeat[i];
}
//
// get_capacity -- returns capacity
//	args: none
//	rets: int capacity
//
int Language::get_capacity()
{
	return tri.capacity;
}
//
// get_used -- returns used
//	args: none
//	rets: int used
//
int Language::get_used()
{
	return tri.used;
}
//
// get_class -- returns TrigramVector class
//	args: none
//	rets: class
//
TrigramVector Language::get_class()
{
	return tri;
}

//
// add_shared -- adds trigrams to shared array and class 
//		 add_normalized
//	args: one string trigram, for ints for add_normalized
//	rets: none
//
void Language::add_shared(string s, float known, float unknown, float k_used, float u_used)
{
	if (used == capacity){
		add_expand();
	}
	shared[used] = s;
	add_normalized(known, unknown, k_used, u_used);
	used++;
}
//
// add_normalized -- adds normalized frequencies to arrays 
//		     of normalized frequencies for the unknown
//		     and known file
//	args: four floats, two are counts, two are used
//	rets: none
//
void Language::add_normalized(float i, float j, float k, float l)
{
	float known_norm = i/k;
	float unknown_norm = j/l;
	known_normalized[used] = known_norm;
	unknown_normalized[used] = unknown_norm;
}
//
// add_similarity -- adds similarities as compared to different
// 		     unknown files to similarity array
//	args: one float similarity
//	rets: none
//
void Language::add_similarity(float s)
{
	if (sim_used == sim_capacity){
		sim_expand();
	}
	similarity[sim_used] = s;
	used++;
}
//
// add_expand -- expands shared and normalities arrays
//	args: none
//	rets: none
//		note: commented out delete[] becuase gave glibc error
//
void Language::add_expand()
{
	int i;
	string *bigger_array = new string[capacity*2 +1];
	if (shared != NULL){
		for (i=0; i<capacity; i++){
			bigger_array[i] = shared[i];
		}
	}
	delete[] shared;
	shared = bigger_array;
	float *bigger = new float[capacity*2 +1];
	if (known_normalized != NULL){
		for (i=0; i<capacity; i++){
			bigger[i] = known_normalized[i];
		}
	}
	delete[] known_normalized;
	known_normalized = bigger;
	float *big = new float[capacity*2 +1];
	if (unknown_normalized != NULL){
		for (i=0; i<capacity; i++){
			big[i] = unknown_normalized[i];
		}
	}
	delete[] unknown_normalized;
	unknown_normalized = big;
	capacity = capacity * 2 + 1;
}
//
// sim_expand -- expands similarites array
//	args: none
//	rets: none
void Language::sim_expand()
{
	int i;
	float *bigger_array = new float[capacity*2 +1];
	if (similarity != NULL){
		for (i=0; i<capacity; i++){
			bigger_array[i] = similarity[i];
		}
	}
	delete[] similarity;
	similarity = bigger_array;
}
