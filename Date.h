#pragma once
#include<iostream>

class Date
{
	size_t day;
	size_t month;
	size_t year;
public:
	Date();
	Date(size_t, size_t, size_t);
	bool validDate() const;
	const size_t& getDay() const;
	const size_t& getMonth() const;
	const size_t& getYear() const;

	bool operator ==(const Date&) const;
	bool operator < (const Date&) const;
	 
	friend std::ostream& operator<<(std::ostream&, const Date&);
	friend std::istream& operator >>(std::istream&, Date&);
};