//
// language.h --  holds class language
//	  by: Vivian Hong
//	date: 11/29/2015
//
const int LANG_TRIGRAM_LENGTH = 3;

class Language
{
public:
	Language();
	bool	add(string);
	void	get_trigram(string);
	void	print_freq();
	ifstream finput;
private:
	void 	expand();
	string	*store;
	int		*repeat;
	int 	capacity;
	int 	used;
};

