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
#include<string_view>
using namespace std;
using namespace std::chrono;
template<typename T>
class Vector
{
	private:
	size_t size = 0;
	T* data = nullptr;
	size_t capacity = 0;
	public:
	Vector() = default;
	explicit Vector(size_t s) :  size(s), data(new T[size]), capacity(size){}
	Vector(const Vector& other): size(new T[other.size]), data(new T[other.data]), capacity(new T[other.capacity])
	{
		copy(other.begin(), other.end(), begin());
	}
	~Vector()
	{
		delete[] data;
	}
	size_t Size() const
	{
		return size;
	}
	size_t Capacity() const
	{
		return capacity;
	}
	T* begin()
	{
		return data;
	}
	T* end()
	{
		return data + size;
	}
	const T* begin() const
	{
		return begin();
	}
	const T* end() const
	{
		return end();
	}
	T& operator[](size_t index)
	{
		return *(data + index);
	}
void Push_Back(const T& value)
{
	if(size > capacity)
	{
		auto new_cap = capacity == 0 ? 1 : 2 * capacity;
		auto new_data = new T[new_cap];
		copy(begin(), end(), new_data);
		delete[] data;
		data = new_data;
		capacity = new_cap;
	}
	data[size++] = value;
}
};
int main()
{
Vector<int> rustic(3);
rustic[0] = 1;
rustic[1] = 2;
rustic[2] = 3;
Vector<int> target = rustic;
cout << target[1];
return 0;
}

