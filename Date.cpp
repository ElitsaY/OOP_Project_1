#include"Date.h"
#include<iostream>

Date::Date() 
	:day(0), month(0), year(0)
{}
Date::Date(size_t day, size_t month, size_t year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}
bool Date::validDate() const
{
	if (month < 1 || month > 12)
		return false;
	if (day < 1) return false;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		if (day > 31)
			return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	else
	{
		//Febryary
		if (year % 4 == 0 && year%100 != 0 || year%400 == 0)
		{
			//годината е високосна
			if (day > 29) 
				return false;
		}
		else
		{
			if (day > 28) 
				return false;
		}
	}
	return true;
}

const size_t& Date::getDay() const
{
	return day;
}
const size_t& Date::getMonth() const
{
	return month;
}
const size_t& Date::getYear() const
{
	return year;
}

bool Date::operator ==(const Date& otherDate) const
{
	if (day != otherDate.day) 
		return false;
	if (month != otherDate.month)
		return false;
	if (year != otherDate.year) 
		return false;
	return true;
}
bool Date::operator<(const Date& otherDate) const
{
	if (year < otherDate.year)
		return true;
	if (year == otherDate.year)
	{
		if (month < otherDate.month)
			return true;
		if (month == otherDate.month)
		{
			if (day < otherDate.day)
				return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Date& outDate)
{
	out << outDate.getDay() << "." << outDate.getMonth() << "." << outDate.getYear();
	return out;
}
std::istream& operator >>(std::istream& in, Date& inDate)
{
	in >> inDate.day;
	in >> inDate.month;
	in >> inDate.year;
	return in;
}