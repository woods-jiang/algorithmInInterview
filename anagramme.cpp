
// 求词典中的所有变位词
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool charcomp(const char x, const char y)
{
	return  x < y;
}

// 输入文件名字
void anagramme(const string& filename)
{
	ifstream ifs(filename);
	ofstream ofs("output.txt");
	string word;
	map < string, set<string>> wordmap;

	// 读取词典
	while (ifs>>word)
	{
		string strTmp = word;
		sort(word.begin(), word.end(), charcomp);
		wordmap[word].insert(strTmp);
	}

	// 遍历输出
	map<string, set<string>>::iterator mapIt = wordmap.begin();

	for (; mapIt != wordmap.end(); ++mapIt)
	{
		set<string>::iterator setIt = (mapIt->second).begin();
		for (; setIt != (mapIt->second).end(); ++setIt)
		{
			cout << *setIt << " ";
			ofs << *setIt << " ";
		}
		cout << endl;
		ofs << "\n";
	}
	ifs.close();
	ofs.close();
}

int main()
{
	anagramme("dict.txt");

	return 0;
}