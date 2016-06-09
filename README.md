# BranchAndBound
01 Knapsack Problem

The invasion of Earth has been a success. The attack fleet from your home planet easily
overcame the puny defences of the humans. The massive ooze-forming machines are rapidly
converting all land areas on the planet into the kind of oily, gelatinous mud in which your
species thrives.

There's just one problem: having been biologically altered to live on Earth, you will not be
able to survive once the planet has been converted (neither will any of the remaining humans
– oh well). Fortunately your Emperor, His Sublime Sliminess Muckgulper III, has offered to
relocate you to Mars and is providing you with a space ship to get you there. You'll be going
alone, it's a one-way trip, and Matt Damon will not be there to help you. All you will have is
what you take with you.

The Emperor has given you complete freedom to take whatever you like, so long as the total
mass of your choices does not exceed K kilograms. You have put together quite a long list of
things that you would like to take ... too many items to take them all. You've been able to
assign a “desirability value” to each object. You need to choose a set of objects that maximizes
the total value without exceeding the limit of K kilograms.

This is the implemention of a Branch & Bound algorithm to solve instances of this problem. 

Note: In order to run this you need to change the name of file to be read from in the soure.cpp file and make sure it's in the correct format:
The input should consist of a text file containing an instance of the problem. The
first line of the file contains a string that identifies the problem instance. The second line
contains an integer that specifies K (the capacity limit), and an integer that specifies the
number of items in the list. Each subsequent line of the file contain a trio of integers: an item's
ID number, value and mass.
