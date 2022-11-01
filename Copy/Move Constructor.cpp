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
using namespace std;
using namespace std::chrono;
template<typename T>
class Vector
{
public:
	Vector() = default;
	explicit Vector(size_t size);
	Vector(const Vector& other);
Vector(Vector&& other);
void operator=(const Vector& other);
void operator=(Vector&& other);
	~Vector();
	T& operator[](const size_t index);
	 T* begin();
	T* end();
	const T* begin() const;
	const T* end() const;
	int size();
	int capacity();
private:
T* Data = nullptr;
size_t Size = 0;
size_t Capacity = 0;
};
template<typename T>
Vector<T>::Vector(size_t  size) : Size(size), Data(new T[size]), Capacity(size){}
template<typename T>
Vector<T>::Vector(const Vector<T>& other) : Data(new T[other.Capacity]), Size(other.Size), Capacity(other.Capacity)
{
	copy(other.begin(), other.end(), begin());
}
template<typename T>
Vector<T>::~Vector()
	{
		delete[] Data;
	}
template<typename T>
T& Vector<T>::operator[](const size_t index)
{
	return *(Data + index);
}
template<typename T>
void Vector<T>::operator=(const Vector<T>& other)
{
	delete[] Data;
	Data = new T[other.Capacity];
	Size = other.Size;
	Capacity = other.Capacity;
	copy(other.begin(), other.end(), begin());
}
template<typename T>
void Vector<T>::operator=(Vector<T>&& other)
{
	delete[] Data;
	Data = other.Data;
	Size = other.Size;
	Capacity = other.Capacity;
	other.Data = nullptr;
	other.Size = other.Capacity = 0;
}
template<typename T>
Vector<T>::Vector(Vector&& other) : Data(other.Data), Size(other.Size), Capacity(other.Capacity)
{
	other.Data = nullptr;
	other.Size = other.Capacity = 0;
}
template<typename T>
T* Vector<T>::begin()
{
	return Data;
}
template<typename T>
T* Vector<T>::end()
{
	return Data +Size;
}
template<typename T>
const T* Vector<T>::begin() const
{
	return Data;
}
template<typename T>
const T* Vector<T>::end() const
{
	return Data + Size;
}
template<typename T>
int Vector<T>::size()
{
	return Size;
}
template<typename T>
int Vector<T>::capacity()
{
	return Capacity;
}
int main()
{
Vector<int>rus(5);
Vector<int> q(4);
q = move(rus);
cout << rus.size() << ' ' << q.size();
return 0;
}

