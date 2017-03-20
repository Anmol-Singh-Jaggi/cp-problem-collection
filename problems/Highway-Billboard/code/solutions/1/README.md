Let `maxRevenueTill[i]`, 1 <= `i` <= `M`, be the maximum revenue generated from the beginning to `i` miles on the highway.  
Now for each mile on the highway, we need to check whether this mile has the option for any billboard; if not, then the maximum revenue generated till that mile would be same as maximum revenue generated till one mile before.  

But if that mile has the option for billboard, then we have 2 options:  

 1. Either we will place the billboard; ignore the billboard in previous `minDistanceAllowed` miles, and add the revenue of the billboard placed.
 2. Ignore this billboard. So `maxRevenueTill[i]` = `max(maxRevenueTill[i-minDistanceAllowed-1] + revenues[i], maxRevenueTill[i-1])`.
