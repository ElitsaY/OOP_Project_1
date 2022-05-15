#pragma once 
#include "String.h"
#include "Date.h"

class Product
{
	MyString name;
	MyString producer;
	//------------------
	Date validityDate;
	Date enterDate;
	//------------------
	size_t quantityInStock;
	size_t height;
	size_t lenght;
	size_t width;
	//---------------
	size_t section;
	size_t shelf;
	size_t id;

public:
	Product();

	const MyString& getName() const;
	const MyString& getProducer() const;

	const Date& getValidityDate() const;
	const Date& getEnterDate() const;

	const size_t& getQuantityInstock() const;
	const size_t& getHeight() const;
	const size_t& getLength() const;
	const size_t& getWidth() const;
	
	const size_t& getSection() const;
	const size_t& getShelf() const;
	const size_t& getId() const;

	void setName(const MyString&);
	void setProducer(const MyString&);
	
	void setEnterDate(const Date&);
	void setValidityDate(const Date&);

	void setQuantityInStock(size_t);

	void setHeight(size_t);
	void setWidth(size_t);
	void setLength(size_t);

	void setSection(size_t);
	void setShelf(size_t);
	void setId(size_t);

	bool operator ==(const Product&) const;
	bool operator !=(const Product&) const;
	bool operator <(const Product&) const;

	bool validProductDates() const;
	friend std::ostream& operator <<(std::ostream&, const Product&);
	friend std::istream& operator >>(std::istream&, Product&);
};
