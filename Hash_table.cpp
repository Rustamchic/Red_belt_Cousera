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
using namespace std;
using namespace std::chrono;
struct Logger
{
	int number;
	char A;
	string rus;
};
struct Hash
{
	size_t operator()(const Logger& log) const
	{
		size_t r1 = log.number;
		size_t r2 = log.A - 'A';
		size_t r3 = log.rus.size();
		size_t x = 307;
		return r1*r1* x + r2 * x + r3;
	}
};
struct MyHash
{
	double d;
	string rus;
	Logger logrus;
};
struct MyHasher
{
	size_t operator()(const MyHash& h)
	{
		size_t r1 = dhash(h.d);
		size_t r2 = shash(h.rus);
		size_t r3 = log(h.logrus);
		size_t x = 307;
		return r1*r1* x + r2 * x + r3;
	}
	hash<double> dhash;
	hash<string> shash;
	Hash log;
};
int main()
{
	unordered_set<Logger, Hash> setter;
	unordered_set<MyHash, MyHasher> ser;
return 0;
}

