#!/usr/bin/env python3
from random import randint


num_testcases = 2000
num_locations_max = 100
location_max = 100
revenue_max = 100


def main():
    print(num_testcases)
    for _ in range(1, num_testcases + 1):
        print(num_locations_max)
        num_locations = randint(1, num_locations_max)
        locations = []
        for _ in range(num_locations):
            location = randint(1, location_max)
            if location not in locations:
                locations.append(location)
        locations.sort()
        num_locations = len(locations)
        print(num_locations)
        for location in locations:
            print(location, end=" ")
        print("")
        for _ in range(num_locations):
            revenue = randint(1, revenue_max)
            print(revenue, end=" ")
        print("")
        min_distance_allowed = randint(1, location_max)
        print(min_distance_allowed)


if __name__ == '__main__':
    main()
