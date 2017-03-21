#include<bits/stdc++.h>
using namespace std;


vector<int> computePreviousPossibleLocations ( const vector<int>&
    validLocations,
    const int& minDistanceAllowed )
{
  vector<int> previousPossibleLocations ( validLocations.size(), -1 );
  int backPointer = ( int ) validLocations.size() - 1;
  int frontPointer = backPointer;

  while ( frontPointer >= 0 )
  {
    while ( ( frontPointer >= 0 ) &&
            ( validLocations[backPointer] - validLocations[frontPointer] <=
              minDistanceAllowed ) )
    {
      frontPointer--;
    }
    previousPossibleLocations[backPointer--] = frontPointer;
  }

  return previousPossibleLocations;
}


int getPreviousPossibleLocation ( const vector<int>& previousPossibleLocations,
                                  const int& locationIndex )
{
  return previousPossibleLocations[locationIndex];
}


int getAnsFor ( const vector<int>& maxRevenueTill, const int& pos )
{
  int ans = 0;
  if ( pos >= 0 )
  {
    ans = maxRevenueTill[pos];
  }
  return ans;
}


int maxRevenue ( const vector<int>& validLocations, const vector<int>& revenues,
                 const int& minDistanceAllowed )
{
  int ans = 0;
  vector<int> maxRevenueTill ( validLocations.size(), -1 );

  vector<int> previousPossibleLocations = computePreviousPossibleLocations (
      validLocations, minDistanceAllowed );

  for ( int i = 0; i < validLocations.size(); i++ )
  {
    int previousPossibleLocation = getPreviousPossibleLocation (
                                     previousPossibleLocations,
                                     i );
    maxRevenueTill[i] = max ( getAnsFor ( maxRevenueTill, i - 1 ),
                              getAnsFor ( maxRevenueTill, previousPossibleLocation ) + revenues[i] );
  }

  ans = maxRevenueTill[maxRevenueTill.size() - 1];
  return ans;
}


int main()
{
  int t;
  cin >> t;
  while ( t-- )
  {
    // This is not actually used anywhere, but is given in the input spec, so had to take it.
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

    int ans = maxRevenue ( validLocations, revenues, minDistanceAllowed );
    cout << ans << "\n";
  }
}
