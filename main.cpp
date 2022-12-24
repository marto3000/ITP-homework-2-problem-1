#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 81;

void bagCheck(char* bags, int bagNum)
{
	if (strlen(bags) % 2)
	{
		cout << "bag " << bagNum + 1 << ": error - odd number of letters\n";
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
					return;
				}
			}
		}
		cout << "bag " << bagNum + 1 << ": error - repeating present not found\n";
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
	for (int i = 0; i < bagsCount; i++)
	{
		bagCheck(bags[i], i);
	}

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