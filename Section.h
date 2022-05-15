#pragma once
#include"Vector.hpp"
#include"Product.h"

class Section
{
	static const int numberOfShelves = 10;
	static const int shelfWidth = 100;
	static const int shelfHeight = 100;
	static const int shelfLength = 200;
	
	Vector<Product> shelf[numberOfShelves];
	
	size_t findPosition(size_t&, size_t&, size_t&) const;
public:
	
	const int& getNumberOfShelves() const;
	const int& getNumberOfWidth() const;
	const int& getNumberOfLength() const;
	const int& getNumberOfHeight() const;
	
	bool insertProductOnShelf(Product&);
	void eraseProducts(const Date&);
	void removeProductFromShelf(const Product&, size_t);
};