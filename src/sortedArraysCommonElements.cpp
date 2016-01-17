/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int iterator, iterator2, iterator3, iterator4 = 0;
	for (iterator = 0; iterator < ALen; iterator++)
	{
		for (iterator2 = 0; iterator2 < BLen; iterator2++)
		{
			iterator3 = 6;
			while (iterator3 < 10)
			{
				if (A[iterator].date[iterator3] - 48 == B[iterator2].date[iterator3] - 48)
					iterator3++;
				else
					break;
			}
			if (iterator3 == 10)
			{
				iterator3 = 3;
				while (iterator3 < 5)
				{
					if (A[iterator].date[iterator3] - 48 == B[iterator2].date[iterator3] - 48)
						iterator3++;
					else
					{
						break;
					}
				}
			}
			if (iterator3 == 5)
			{
				iterator3 = 0;
				while (iterator3 < 2)
				{
					if (A[iterator].date[iterator3] - 48 == B[iterator2].date[iterator3] - 48)
						iterator3++;
					else
						break;
				}
			}
			if (iterator3 == 2)
			{
				result[iterator4] = A[iterator];
				iterator4++;
			}
		}
	}
	if (iterator4 == 0)
		return NULL;
	else
		return result;
}