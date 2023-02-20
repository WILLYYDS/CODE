#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() 
{
    map<string, int> word_frequencies;
    set<string> stopwords;


    ifstream stopwords_file( "stopwords.txt" );
    string stopword;
    while(stopwords_file >> stopword) 
    {
        stopwords.insert(stopword);
    }


    ifstream input_file( "sample_doc.txt" );
    string word;
    while(input_file >> word) 
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if(stopwords.find(word) == stopwords.end()) {
            word_frequencies[word]++;
        }
    }

    ofstream output_file( "frequency.txt" );
    for (map<string, int>::iterator it = word_frequencies.begin(); it != word_frequencies.end(); it++)
    {
        output_file << it->first << " " << it->second << endl;
    }


    return 0;
}
