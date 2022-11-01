#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<tuple>
#include<map>
#include<stdexcept>
#include<cmath>
#include<utility>
#include<iterator>
#include<limits>
#include<deque>
#include<memory>
#include<string>
#include<chrono>
#include<random>
#include<cstdint>
#include<numeric>
#include<future>
#include<string_view>
#include<mutex>
#include<thread>
#include<unordered_set>
#include<cctype>
using namespace std;
using namespace std::chrono;

vector<string_view> Parser(const string& rus)
{
	string_view res = rus;
	vector<string_view> result;
	auto start = 0;
	auto end = res.npos;
	while(true)
	{
		size_t space = res.find(' ', start);
		result.push_back(space == end ? res.substr(start) : res.substr(start, space - start));
		if(space == end)
		{
			break;
		} else
		{
			start = space + 1;
		}
	}
	return result;
}
int main()
{
string rus = "a b c d";
vector<string_view> result = Parser(rus);
for(auto i : result)
{
	cout << i;
}
	return 0;

}
/*
 * vector<string_view> Parser(string& rus)
{
	string_view res = rus;
	vector<string_view> result;
	while(true)
	{
		auto space = res.find(' ', 0);
		result.push_back(res.substr(0, space));
		if(space == res.npos)
		{
			break;
		} else
		{
			res.remove_prefix(space + 1);
		}
	}
	return result;
}
 */


