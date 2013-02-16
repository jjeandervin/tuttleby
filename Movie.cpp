/*
  Movie.cpp

  Definition file for Movie class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#include "Movie.hpp"

// constructor
Movie::Movie(const std::string& title, int price_code)
{
	_title = title;
	setPriceCode(price_code);
}

// movie title
const std::string& Movie::getTitle() const { return _title; }

// movie price code
int Movie::getPriceCode() const { return _price_code->getPriceCode(); }

// set movie price code
void Movie::setPriceCode(int new_price_code)
{
	switch(new_price_code)
	{
		case Movie::CHILDRENS:
			_price_code = new ChildrensPrice();
			break;
		case Movie::NEW_RELEASE:
			_price_code = new NewReleasePrice();
			break;
		default:
			_price_code = new RegularPrice();
			break;
	}
}

// get the charge amount
double Movie::getCharge(int numberOfDays) const
{
	double thisAmount = 0;
	switch(getPriceCode())
	{
		case Movie::REGULAR:
			thisAmount += 2;
			if (numberOfDays > 2) thisAmount += (numberOfDays - 2) * 1.5;
			break;
		case Movie::NEW_RELEASE:
			thisAmount += numberOfDays * 3;
			break;
		case Movie::CHILDRENS:
			thisAmount += 1.5;
			if (numberOfDays > 3) thisAmount += (numberOfDays - 3) * 1.5;
			break;
	}

	return thisAmount;
};
