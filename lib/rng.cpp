// rng.cpp
// implementations of random number generator interfaces
//
// Oliver W. Laslett
// O.Laslett@soton.ac.uk

#include "../include/rng.hpp"
#include <stdexcept>

/*
  Mersenne twister and normal distribution
*/
RngMtNorm::RngMtNorm( const unsigned long int seed, const double std )
    : Rng()
    , dist( 0, std )
    , generator( seed )
{}
double RngMtNorm::get() { return dist( generator ); }


/*
   Wrapper to array of random numbers
*/
RngArray::RngArray( const double *_arr, size_t _arr_length, size_t _stride )
    : Rng()
    , arr( _arr )
    , max( _arr_length )
    , stride( _stride )
{}
double RngArray::get()
{
    if( i<max )
    {
        unsigned int tmp = i;
        i += stride;
        return arr[tmp];
    }
    else
        throw std::out_of_range( "Exceeded allocated random number array size" );
}
