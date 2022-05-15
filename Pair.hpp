#pragma once
#include<iostream>

template<typename T, typename D>
class Pair
{
	T first;
	D second;
public:
	Pair() = default;
	Pair(const T& first, const D& second);
	const T& getFirst() const;
	const D& getSecond() const;

	void setFirst(const T& newValue);
	void setSecond(const D& newValue);

	bool operator ==(const Pair<T, D>&);
	bool operator !=(const Pair<T, D>&);
	//friend std::ostream& operator<<(std::ostream&, const Pair<T, D>&);
};

template<typename T, typename D>
Pair<T, D>::Pair(const T& first, const D& second) : first(first), second(second)
{}

template<typename T, typename D>
const T& Pair<T, D>::getFirst() const
{
	return first;
}
template<typename T, typename D>
const D& Pair<T, D>::getSecond() const
{
	return second;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(const T& newValue)
{
	first = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setSecond(const D& newValue)
{
	second = newValue;
}

template<typename T, typename D>
bool Pair<T, D>::operator ==(const Pair<T, D>& other)
{
	return (first == other.first && second == other.second);
}

template<typename T, typename D>
bool Pair<T, D>::operator !=(const Pair<T, D>& other)
{
	return !(*this == other);
}

/*template<typename T, typename D>
std::ostream& operator<<(std::ostream& out, const Pair<T, D>& pair)
{
	out << pair.first << " "<< pair.second;
	return out;
}*/