//Lisbeth Lazala 
//CSC 212


#include <iostream>
#include <cassert>
#include "stats.h"

namespace main_savitch_2c
{
	statistician::statistician() : count(0),total(0), tinyest(0), largest(0){}

//Postcondition: will move code through sequence of numbers one at a time
	void statistician::next(double r)
	{
		if (count <= 0)
		{
			count = 1;
			total = r;
			tinyest = r;
			largest = r;
			return;
		}
		count = count + 1;
		total +=r;
		if (r < tinyest)
		{
			tinyest = r;
		}
		if (largest < r)
		{
			largest = r;
		}
	}

  void statistician::reset( )
  {
  count = 0; // resets all values back to 0
  tinyest = 0;
  largest = 0;
  total = 0;
  }

	double statistician::abs_maximum( ) const
	{
		assert(length() > 0);
		a= f_abs(largest);
		b= f_abs(tinyest);
		if (a>b)
		{
			return a;
		}
		else (a<b)
		{
			return b;
		}
	}

  int statistician::length() const //should return the number of times next function was used
  {
    return count;
  }

  double statistician::sum() const
  {
    return total;
  }

  double statistician::mean() const
  {
    return total/count; // mean = total divided by the number of numbers
  }

  double statistician::minimum() const
  { // min = tinyest number
    return tinyest;
  }

  double statistician::maximum() const
  {
    return largest; // maximum = largest number
  }

  bool operator ==(const statistician& s1, const statistician& s2)
  { if (s1.length() == 0 && s2.length() == 0)
        return true;
    // if it reaches here, it means one of their lengths, or both of their lengths is not 0
    if (s1.length() == s2.length())
    {
        if ((s1.mean() == s2.mean()) && (s1.minimum() == s2.minimum())
            && (s1.maximum() == s2.maximum()) && (s1.sum() == s2.sum())
            return true;
        else
            return false;
    	}
  	}

  statistician operator + (const statistician & s1, const statistician & s2)
  {
    statistician s3;
    s3.next(s1.sum() + s2.sum()); //combines two classes and returns their joint value
    return s3;
  }

  statistician operator * (double scale, const statistician & s2)
  {
    return s2;
  }
}
