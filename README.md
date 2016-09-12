# Dynamic-Programming
Dynamic-Prog-Problems

CoinChange Problem

Thought Process : If someone gets a benefit , please clone this repo.

The coin change problem is basically, you have to make a certain Sum (money sum) 'S' using given denomination of coins.  Let's number the coins from '1 to N' , Sum is 'S'.

Formulate problem:

What are the minimum number of ways we can make sum 'S' using coins that have numbers from `1 to N' ? [ 1,2,3,4, ... , N] 
So Problem State representation: 
1. Desired Sum
2. Set of coins that can be used.

Now make recurrence relation:
Consider coin 1
We will either use it OR we won't use it 
If we chose to NOT use it, we basically need to find out the number of ways we can make sum 'S' using coins that have numbers from '2 to N' ? []2,3,4,...N] 
If we chose to use coin 1 with value as v[1], for the first time (copy) usage of coin sum becomes 'S'-v[1]. , now , we basically need to find out the number of ways we can make sum 'S'-v[1] using coins '1 to N' .

This problem is first solved using the recurseive approach. In this approach we see a number of subproblems which are getting recalculated.

Then this problem is solved using the DP approach. 
