#pragma once
#include"Vector.hpp"
#include"Section.h"
#include"Product.h"
#include"Pair.hpp"

//actions made
// 0 - add element
// 1 - remove element

class Storage
{
	static const int numberOfSections = 12;
	Section sections[numberOfSections];
	
	Vector< Pair<Product, bool> > actionsMade;
	Vector<Product> listOfValidProducts;
	Vector< Pair<MyString, int> > quantityOfProduct;
	
	bool executeCommand(const MyString&) const;
	void findSection(Product&);
	void storeInfo(Product&);
	void removeQuantity(const MyString&, size_t);
	void removeFromTotalQuantity(const MyString&, size_t);

public:
	void insertProduct();
	void cleanUp(const Date&);
	void printStocks();
	void productsAvailable(const Date&, const Date&);
	void getProduct();
};