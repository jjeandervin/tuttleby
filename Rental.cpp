/*
  Rental.cpp

  Definition file for Rental class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#include "Rental.hpp"

// constructor
Rental::Rental(const Movie& movie, int days_rented) : movie(movie), days(days_rented) { }

// days rented
int Rental::getDaysRented() const { return days; }

// movie rented
const Movie& Rental::getMovie() const { return movie; }

double Rental::getCharge() const
{
	return getMovie().getCharge(getDaysRented());
}

int Rental::getFrequentRenterPoints() const
{
	//new releases rented for more than one night are worth 2 points, all other rentals are 1 point
	return getMovie().getPriceCode() == Movie::NEW_RELEASE && getDaysRented() > 1 ? 2 : 1;
}