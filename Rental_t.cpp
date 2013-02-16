/*
  Rental_t.cpp

  Test program for class Rental

  John I. Doe
  jdoe@cs.kent.edu
*/

#include <cassert>
#include <iostream>

#include "Rental.hpp"
#include "Movie.hpp"
using namespace std;

int main() {

  // TODO:  Add test cases
	Movie lotr("Lord of the Rings", Movie::REGULAR);
	Rental test(lotr, 4);
	cout << "Movie rented: " << test.getMovie().getTitle() << endl;
	cout << "Days rented: " << test.getDaysRented() << endl;
	cout << "Amount owed: " << test.getCharge() << endl;

  return 0;
}
