This solution is almost the same as the previous solution, the only difference being the method used to find the previous nearest possible location to place a billboard.

Instead of using `lower_bound()`, we are using a *sliding-window* approach:

Let there be two *pointers* `backPointer` and `frontPointer`, where `frontPointer <= backPointer` is always satisfied.

Here, `frontPointer` will point to the previous nearest possible billboard location for a billboard placed at the location `backPointer`.

Since, the answer for a location `j` is always less than the answer for a location `i`, where `j < = i`, the 2 pointers will always travel in a single direction (reverse, in our case). 

-----

**Algorithmic complexity:**

```
O(n)
```

where:

 - `n` -> The number of possible billboard locations.
