#include<bits/stdc++.h>
using namespace std;


int maxRevenue ( const int& miles, vector<int> validLocations,
                 vector<int>& revenues, const int& minDistanceAllowed )
{
  // Array to store maximum revenue at each miles.
  vector<int> maxRevenueTill ( miles + 1, 0 );

  int numValidLocationsVisited = 0;
  for ( int mile = 1; mile <= miles; mile++ )
  {
    // Check if there are billboards to be placed.
    if ( numValidLocationsVisited < validLocations.size() )
    {
      // Check if we have billboard for this particular mile. If not, copy the previous maximum revenue.
      if ( validLocations[numValidLocationsVisited] != mile )
      {
        maxRevenueTill[mile] = maxRevenueTill[mile - 1];
      }

      // We do have a (possible) billboard for this mile.
      else
      {
        // We have 2 options, we either place a billboard at the current mile, or skip it.

        // If current position is less than or equal to the minimum allowed distance, then we can have only one billboard.
        if ( mile <= minDistanceAllowed )
        {
          maxRevenueTill[mile] = max ( maxRevenueTill[mile - 1],
                                       revenues[numValidLocationsVisited] );
        }

        // Else, we may have to remove the previously placed billboard
        else
        {
          maxRevenueTill[mile] = max ( maxRevenueTill[mile - minDistanceAllowed
                                       - 1] + revenues[numValidLocationsVisited],
                                       maxRevenueTill[mile - 1] );
        }
        numValidLocationsVisited++;
      }
    }
    else
    {
      maxRevenueTill[mile] = maxRevenueTill[mile - 1];
    }
  }

  return maxRevenueTill[miles];
}


int main()
{
  int t;
  cin >> t;
  while ( t-- )
  {
    int miles = 0;
    cin >> miles;

    int numValidLocations;
    cin >> numValidLocations;

    vector<int> validLocations;
    for ( int i = 0; i < numValidLocations; i++ )
    {
      int validLocation;
      cin >> validLocation;
      validLocations.push_back ( validLocation );
    }

    vector<int> revenues;
    for ( int i = 0; i < numValidLocations; i++ )
    {
      int revenue;
      cin >> revenue;
      revenues.push_back ( revenue );
    }

    int minDistanceAllowed;
    cin >> minDistanceAllowed;

    int ans = maxRevenue ( miles, validLocations, revenues, minDistanceAllowed );
    cout << ans << "\n";
  }
}
