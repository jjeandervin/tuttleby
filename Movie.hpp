/*
  Movie.hpp

  Include file for Movie class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#ifndef PRICE_H
#define PRICE_H
class Price
{
	public:
		virtual int getPriceCode() = 0;
};
#endif

#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie
{
	public:
		static const int REGULAR      = 0;
		static const int NEW_RELEASE  = 1;
		static const int CHILDRENS    = 2;

		Movie(const std::string& title, int price_code);

		// movie title
		const std::string& getTitle() const;

		// movie price code
		int getPriceCode() const;

		// set movie price code
		void setPriceCode(int new_price_code);

		// get the charge amount
		double getCharge(int numberOfDays) const;

	private:
		std::string _title;
		Price* _price_code;
};

#endif

#ifndef REGPRICE_H
#define REGPRICE_H
class RegularPrice : public Price
{
	public:
		virtual int getPriceCode() { return Movie::REGULAR; }
};
#endif

#ifndef CHILDPRICE_H
#define CHILDPRICE_H
class ChildrensPrice : public Price
{
	public:
		virtual int getPriceCode() { return Movie::CHILDRENS; }
};
#endif

#ifndef NEWRELPRICE_H
#define NEWRELPRICE_H
class NewReleasePrice : public Price
{
	public:
		virtual int getPriceCode() { return Movie::NEW_RELEASE; }
};
#endif
