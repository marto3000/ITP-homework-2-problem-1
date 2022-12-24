#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 81;

char bagCheck(char* bags, int bagNum)
{
	if (strlen(bags) % 2)
	{
		cout << "bag " << bagNum + 1 << ": error - odd number of letters\n";
		return 0;
	}
	else
	{
		int presentsCount = strlen(bags) / 2;
		for (int i = 0; i < presentsCount; i++)
		{
			for (int j = presentsCount; j < presentsCount * 2; j++)
			{
				if (bags[i] == bags[j])
				{
					cout << "bag " << bagNum + 1 << ": " << bags[i] << endl;
					return bags[i];
				}
			}
		}
		cout << "bag " << bagNum + 1 << ": error - repeating present not found\n";
		return 0;
	}
}

int bagsPriority(char* bagsErrors, char* priority)
{
	int overallPriority = 0;
	for (int bag = 0; bag < strlen(bagsErrors); bag++)
	{
		for (int pos = 0; pos < strlen(priority); pos++)
		{
			if (bagsErrors[bag] == priority[pos])
			{
				overallPriority += (pos + 1);
			}
		}
	}
	return overallPriority;
}

bool findLetter(char letter, char* word)
{
	for (int i = 0; i < strlen(word); i++)
	{
		if (word[i] == letter)
		{
			return true;
		}
	}
	return false;
}

void findGroupsID(char** bags, int bagsCount)
{
	for (int groups = 0; groups < bagsCount; groups = groups + 3)
	{
		for (int i = 0; i < strlen(bags[groups]); i++)
		{
			if (findLetter(bags[groups][i], bags[groups + 1]) && findLetter(bags[groups][i], bags[groups + 2]))
			{
				cout << bags[groups][i] << endl;
				break;
			}
		}
	}
}

int main()
{
	int bagsCount;
	do
	{
		cin >> bagsCount;
	} while (bagsCount < 1);
	//new bags
	char** bags = new char* [bagsCount];
	for (int i = 0; i < bagsCount; i++)
	{
		bags[i] = new char[MAX_SIZE];
	}
	//

	/*
vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw
	*/

	cin.ignore();
	for (int i = 0; i < bagsCount; i++)
	{
		cin.getline(bags[i], MAX_SIZE);
	}

	//create errorsList
	char* errorsList = new char[bagsCount + 1];
	//

	for (int i = 0; i < bagsCount; i++)
	{
		errorsList[i] = bagCheck(bags[i], i);
	}
	errorsList[bagsCount] = '\0';

	char samplePriorityList[] = "abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ";
	cout << bagsPriority(errorsList, samplePriorityList) << endl;
	findGroupsID(bags, bagsCount);

	//delete errorsList
	delete[] errorsList;
	errorsList = nullptr;
	//

	//delete bags
	for (int i = 0; i < bagsCount; i++)
	{
		delete[] bags[i];
		bags[i] = nullptr;
	}
	delete[] bags;
	bags = nullptr;
	//

	return 0;
}