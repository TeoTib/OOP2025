#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator()(pair<string, int> a, pair<string, int> b) //daca a e lower priority fata de b? true/false. la false se face schimbarea
	{
		if (a.second != b.second)
			return a.second < b.second;
		return a.first > b.first;
	}
};

ifstream fin("propozitie.txt");

int main()
{
	string prop;
	getline(fin, prop);
	string separators = " ,?!.";
	map<string, int> cuvinte; //deci stringu e keyu, intu e valoarea
	size_t start = prop.find_first_not_of(separators);
	size_t end;
	while (start != string::npos)
	{
		end = prop.find_first_of(separators, start); //in propozitie, cauta de la pozitia start prima aparitie a separatorilor
		// prop.substr(start, end - start); e cuvantul cautat pe care il mapez
		string word = prop.substr(start, end - start);
		//il fac lowercase
		for (char& c : word)
		{
			if (c >= 'A' && c <= 'Z')
				c = c - ('A' - 'a');
		}
		cuvinte[word]++;
		start=prop.find_first_not_of(separators, end); //de la end, cauta prima pozitie care nu e separator
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
	for (auto pereche : cuvinte)
	{
		pq.push(make_pair(pereche.first, pereche.second));
	}
	while (!pq.empty())
	{
		cout << pq.top().first << " => " << pq.top().second<<endl;
		pq.pop();
	}
	return 0;
}