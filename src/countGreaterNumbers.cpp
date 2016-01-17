/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {

	int iterator = 0, count = 0;
	int iterator2 = 6;
	for (iterator = 0; iterator < len; iterator++)
	{
		while (iterator2 < 10)
		{
			if (Arr[iterator].date[iterator2] - 48 == date[iterator2] - 48)
				iterator2++;
			else if (Arr[iterator].date[iterator2] - 48 > date[iterator2] - 48)
			{
				return (len - iterator);
			}
			else
			{
				break;
			}
		}
		//printf("%d", iterator2);
		if (iterator2 == 10)
		{
			iterator2 = 3;
			while (iterator2 < 5)
			{
				if (Arr[iterator].date[iterator2] == date[iterator2])
					iterator2++;
				else if (Arr[iterator].date[iterator2] - 48 > date[iterator2] - 48)
				{
					return (len - iterator);
				}
				else
				{
					break;
				}
			}
		}
		if (iterator2 == 5)
		{
			iterator2 = 0;
			while (iterator2 < 2)
			{
				if (Arr[iterator].date[iterator2] == date[iterator2])
					iterator2++;
				else if (Arr[iterator].date[iterator2] - 48 > date[iterator2] - 48)
				{
					return (len - iterator);
				}
				else
					break;
			}
		}
	}
	return count;
}
