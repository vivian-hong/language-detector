//
// TrigramVector.cpp -- reads in input and converts test to trigrams,
//			removes non alpha chars, condenses spaces,
//			converts all uppercase letters to lowercase
//	by: Vivian Hong
//    date: 11/14/2015
//
#include <iostream>
#include <fstream>
using namespace std;
#include "trigram.h"

//
// Trigram -- constructor: initializes class variables
//	args: none
//	rets: none
//
TrigramVector::TrigramVector()
{
	capacity = 0;
	store = NULL;
	repeat = NULL;
	used = 0;
}
//
// add -- adds trigrams to string
//	args: string of a single trigram
//	rets: none
//
void TrigramVector::add (string t)
{
	int i;
	if (used == capacity){
		expand();
	}
	if (used == 0){
		store[used]= t;
		repeat[used]= 1;
		used++;
	}
	else{
		if (is_in(t)==true){
			for (i = 0; i < used; i++){
			      if (store[i] == t){
				    repeat[i] = repeat[i]+1;
			      }
			}
		}
		else{
		      for (i = used; i > 0; i--){
			      if (store[i -1] > t){
				      store[i] = store[i-1];
				      repeat[i] = repeat[i-1];
			      }
			      else if (store[i-1] < t){
				      store[i] = t;
				      repeat[i] = 1;
				      used++;
				      break;
			      }
		      }
		      if (i == 0){
			      store[i] = t;
			      repeat[i] = 1;
			      used++;
		      }
		}
	}
}
//
// expand -- expands array when needed
//	args: none
//	rets: none
//
void TrigramVector::expand ()
{
    int i;
    string *bigger_array = new string[capacity*2 + 1];
	if (store != NULL){
       		for (i=0; i<capacity; i++){
       			bigger_array[i] = store[i];
       		}
	}
	delete[] store;
    store = bigger_array;
    int *bigger = new int[capacity*2 + 1];
	if (repeat != NULL){
       		for (i=0; i<capacity; i++){
       			bigger[i] = repeat[i];
       		}
	}
	delete[] repeat;
    repeat = bigger;
    capacity = capacity * 2 + 1;

}
//
// get_trigram -- splits file up into trigrams
//	args: string
//	rets: string
//
void TrigramVector::get_trigram(string fName)
{
	ifstream finput;
	string trigram;
	char c;
	int count = 0; 
	char space = ' ';
	finput.open(fName.c_str());
	while ( finput.get(c)){
		if (count == TRIGRAM_LENGTH){
			add(trigram);
			char first = trigram[1];
			char second = trigram[2];
			trigram = "";
			trigram = first;
			trigram = trigram + second;
			count = 2;
		}
		if (isalpha(c)){
			c = tolower(c);
			trigram = trigram + c;
			count ++;
		}
	    else if (isspace(c)){
			if (count !=0){
				if (isspace(trigram[count-1])){
					trigram = trigram;
				}
				else{
					trigram = trigram + space;
					count ++;
				}
			}
			else{
				trigram = trigram + space;
				count ++;
			}
		}
	}
	add(trigram);
}
bool TrigramVector::is_in(string t)
{
	for (int i=0; i<used; i++){
		if (store[i]==t){
		  return true;
		}
	}
	return false;
}
void TrigramVector::print_freq()
{
	for (int i = 0; i< used; i++){
		cout << repeat[i]<<" " <<store[i]<< endl;
	}
}
