
# Segment Trees

Must solve this Leetcode problem to tickle your brain:
https://leetcode.com/problems/longest-balanced-subarray-ii/?envType=daily-question&envId=2026-02-11

I have a doubt in my submission, for this problem:
> Inside the function, `__rangeUpdate` why is it necessary to do `__propagate()` first and then the non-overlapping condition (`if(segR < scopeL || scopeR < segL) return;`)?
> As per my understanding, non-overlapping scopes (since not useful to the segment) can be processed later as well.
> However, when I reverse the condition, I get an error for the following testcase:
> `[69,35,70,70,69,46,49,39,62,42,7,4,51,51,43,49,70,61,24,22]`


