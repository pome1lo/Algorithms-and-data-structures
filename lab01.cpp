#include <iostream>

using namespace std;

void hanoi(int Quanity, int From, int To);

void main()
{
	int Quanity;
	int Start;
	int End;
	bool check;

	do
	{
		check = true;

		cout << "Enter the number of disks: ";
		cin >> Quanity;
		
		cout << "Enter the initial position of the disks: ";
		cin >> Start;
		
		cout << "Enter the column you want to move to: ";
		cin >> End;
		
		if (cin.get() != (int)'\n')
		{
			cout << "Incorrect input... Repeat again\n" << endl;
			check = false;
			
			cin.clear();
			cin.ignore(32444, '\n');
		}
		else if (Quanity < 0 || Quanity > 30 || End <= 1 || End > 3 || Start < 1 || Start > 3)
		{
			cout << "Incorrect input... Repeat again\n" << endl;
			check = false;
		}
	} while (!check);

	hanoi(Quanity, Start, End);
}

void hanoi(int Quanity, int From, int To)
{
	if (Quanity == 1)
	{
		cout << "Move disk 1 from " << From << " to column " << To << endl;
	}
	else
	{
		int temp = 6 - From - To;

		hanoi(Quanity - 1, From, temp);

		cout << "Move disk " << Quanity << " from " << From << " to column " << To << endl;

		hanoi(Quanity - 1, To, temp);
	}
}