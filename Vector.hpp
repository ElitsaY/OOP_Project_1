#pragma once
#include<iostream>
#include<exception>

template<typename T>
class Vector
{
	static const size_t INITIAL_CAPACITY;
	static const int GROWTH_COEFFICIENT;

	int size;
	int capacity;
	T* container;

	void copyFrom(const Vector<T>&);
	void free();
	void allocateMemory();
public:
	Vector();
	~Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator= (const Vector<T>& other);

	const int& getSize() const;

	void push_back(const T&);
	void pop_back(const T&);
	void print() const;
	void sort();

	T& operator[](int);
};

template <typename T>
const std::size_t Vector<T>::INITIAL_CAPACITY = 8;

template <typename T>
const int Vector<T>::GROWTH_COEFFICIENT = 2;

template<typename T>
const int& Vector<T>::getSize() const
{
	return size;
}

template<typename T>
void Vector<T>::push_back(const T& newElement)
{
	if (size + 1 >= capacity)
	{
		allocateMemory();
	}
	container[size] = newElement;
	size++;
}

template<typename T>
void Vector<T>::pop_back(const T& removeElement)
{
	/*int i = 0;
	while (container[i] != removeElement && i < size) i++;//operator !=
	if (i == size)
		throw std::logic_error("the element does not exist");
	container[i] = container[size - 1];*/
	int i = 0;
	while (container[i] != removeElement && i < size) i++;//operator !=
	if (i == size)
		throw std::logic_error("the element does not exist");
	for (int j = i; j < size - 1; j++)
	{
		container[j] = container[j + 1];
	}
	size--;
}

template<typename T>
void Vector<T>::copyFrom(const Vector<T>& other)
{
	//обектът не съществува
	container = new T[other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		container[i] = other.container[i];
	}
	size = other.size;
	capacity = other.capacity;
}

template<typename T>
void Vector<T>::free()
{
	delete[] container;
}

template<typename T>
void Vector<T>::allocateMemory()
{
	T* tempContainer = new T[GROWTH_COEFFICIENT * capacity];
	for (int i = 0; i < size; i++)
	{
		tempContainer[i] = container[i];
	}
	delete[] container;
	container = tempContainer;
	capacity = GROWTH_COEFFICIENT * capacity;
}

template<typename T>
Vector<T>::Vector()
	: size(0), capacity(INITIAL_CAPACITY)
{
	container = new T[INITIAL_CAPACITY];
}

template<typename T>
Vector<T>::~Vector()
{
	free();
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template<typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
void Vector<T>::print() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
	return container[index];
}

template<typename T>
void Vector<T>::sort()
{
	//selection sort
	for (int i = 0; i < size; i++)
	{
		T minElement = container[i];
		size_t minElementIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (container[j] < minElement)
			{
				minElementIndex = j;
				minElement = container[j];
			}
		}
		if (i != minElementIndex)
		{
			T temp = container[i];
			container[i] = minElement;
			container[minElementIndex] = temp;
		}
	}
}