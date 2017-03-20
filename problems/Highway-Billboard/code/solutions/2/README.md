Let `maxRevenueTill[i]`, 1 <= `i` <= `N`, where `N` is the number of valid locations, be the maximum revenue generated from the beginning to the `i`<sup>th</sup> valid location on the highway.  

For each such `i`, we can deduce if we should place a billboard at that location if [ *the answer for the previous most recent valid location* + *the revenue for the current location* ] is greater than the answer for `i-1` ( that is, the max revenue gained by not placing the billboard ).


Now, for finding the *the previous most recent valid location*, we can use the `lower_bound()` function.
