#include"Product.h"

Product::Product()
{
}

const MyString& Product::getName() const
{
	return name;
}
const MyString& Product::getProducer() const
{
	return producer;
}

const Date& Product::getValidityDate() const
{
	return validityDate;
}
const Date& Product::getEnterDate() const
{
	return enterDate;
}

const size_t& Product::getQuantityInstock() const
{
	return quantityInStock;
}
const size_t& Product::getHeight() const
{
	return height;
}
const size_t& Product::getLength() const
{
	return lenght;
}
const size_t& Product::getWidth() const
{
	return width;
}

const size_t& Product::getSection() const
{
	return section;
}
const size_t& Product::getShelf() const
{
	return shelf;
}
const size_t& Product::getId() const
{
	return id;
}

void Product::setName(const MyString& name)
{
	this->name = name;
}
void Product::setProducer(const MyString& producer)
{
	this->producer = producer;
}

void Product::setEnterDate(const Date& enterDate)
{
	this->enterDate = enterDate;
}
void Product::setValidityDate(const Date& validityDate)
{
	this->validityDate = validityDate;
}

void Product::setHeight(size_t height)
{
	this->height = height;
}
void Product::setWidth(size_t width)
{
	this->width = width;
}
void Product::setLength(size_t length)
{
	this->lenght = length;
}

void Product::setSection(size_t section)
{
	this->section = section;
}
void Product::setShelf(size_t shelf)
{
	this->shelf = shelf;
}
void Product::setId(size_t id)
{
	this->id = id;
}

bool Product::validProductDates() const 
{
	return !(validityDate < enterDate);
}
void Product::setQuantityInStock(size_t quantity)
{
	quantityInStock = quantity;
}

bool Product::operator ==(const Product& other) const
{
	if (!(name == other.name)) 
		return false;
	if (!(producer == other.producer))
		return false;
	if (!(validityDate == other.validityDate))
		return false;
	if (!(enterDate == other.enterDate))
		return false;
	if (quantityInStock != other.quantityInStock)
		return false;
	return true;
}
bool Product::operator !=(const Product& other) const
{
	return !(*this == other);
}
bool Product::operator <(const Product& other) const
{
	return validityDate < other.validityDate;
}

std::ostream& operator <<(std::ostream& out, const Product& product)
{
	out <<"Name:" <<product.name << "  Producer:"<<product.producer <<  std::endl;
	out <<"ValidityDate:" <<product.validityDate << " EnterDate:" << product.enterDate << std::endl;
	out <<"Section:"<<product.section << " Shelf:" << product.shelf << " Id:" << product.id << std::endl;
	return out;
}
std::istream& operator >>(std::istream& in, Product& p)
{
	in >> p.name >> p.producer;
	in >> p.enterDate >> p.validityDate;
	in >> p.quantityInStock;
	in >> p.lenght >> p.height >> p.width;
	return in;
}