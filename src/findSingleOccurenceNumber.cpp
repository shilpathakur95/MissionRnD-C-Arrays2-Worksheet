/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {
	if (A==nullptr||len<0)
	return -1;
	int iterator,one=0,two=0,three;
	for (iterator = 0; iterator < len; iterator++)
	{
		two |= one & A[iterator];
		one ^= A[iterator];
		three = ~(one&two);
		one &= three;
		two &= three;
	}
	return one;
}