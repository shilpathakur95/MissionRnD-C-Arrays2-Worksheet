/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int iterator, iterator2 = 0, iterator3, iterator4 = 0, count = 0;
	for (iterator = 0; iterator < ALen; iterator++)
	{
		if (iterator2 < BLen)
		{
			iterator3 = 6;
			while (iterator3 < 10&&iterator2<BLen)
			{
				if (A[iterator].date[iterator3] - 48 == B[iterator2].date[iterator3] - 48)
					iterator3++;
				else if (A[iterator].date[iterator3] - 48 > B[iterator2].date[iterator3] - 48)
				{
					while (count < iterator)
					{
						result[iterator4] = A[count];

						//printf("%d\n", result[iterator4].amount);
						count++;
						iterator4++;
					}
					result[iterator4] = B[iterator2];

					iterator4++;
					iterator2++;
				}
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
					else if (A[iterator].date[iterator3] - 48 > B[iterator2].date[iterator3] - 48)
					{
						while (count < iterator)
						{
							result[iterator4] = A[count];
							//printf("%d\n", result[iterator4].amount);
							count++;
							iterator4++;
						}
						result[iterator4] = B[iterator2];

						iterator4++;
						iterator2++;
					}
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
					else if (A[iterator].date[iterator3] - 48 > B[iterator2].date[iterator3] - 48)
					{
						while (count < iterator)
						{
							result[iterator4] = A[count];

							count++;
							iterator4++;
						}
						result[iterator4] = B[iterator2];

						iterator2++;
					}
					else
						break;
				}
			}
			if (iterator3 == 2)
			{
				while (count <= iterator)
				{
					result[iterator4] = A[count];

					count++;
					iterator4++;
				}
				result[iterator4] = B[iterator2];

				iterator4++;
				iterator2++;
			}
		}
	}
	while (count < ALen)
	{
		result[iterator4] = A[count];
		
		count++; iterator4++;
	}
	while (iterator2 < BLen)
	{
		result[iterator4] = B[iterator2];
		
		iterator2++; iterator4++;
	}
	return result;
}