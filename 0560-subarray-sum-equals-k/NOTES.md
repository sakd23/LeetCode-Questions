can think of sliding window but not possible as our array has -ve numbers. In sliding window we have a valid range. Till we are in our range we keep moving our right boundary forward. but when range is exceeded we starting moving left to come back in range.
but with negative numbers moving left can also some times cause our range to exceede.
​
here we use prefix sum. we know, prefix[j]-prefix[i]=sum of element from i+1 -->j.( j>i ).
​
so at any ith prefix sum, if there exist a prefix sum before such that prefix[i]-prefix[j]=k,
we have a possible answer.
​
so we keep pushing prefix sums in map.
​
for example , k=40  prefix[i]=50
​
we need prefix sum 10 before i to get sum=40.
​
10 -5 2 3 ....  suppose we have this array before, so at i=0 and i=3 we will get prefix sum 10
so for prefix[i]=50  we add 2 to answer.
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​
​