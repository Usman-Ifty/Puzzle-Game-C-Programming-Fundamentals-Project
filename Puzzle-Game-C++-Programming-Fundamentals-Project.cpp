#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<time.h> 
#include<fstream>
#include<string>
#include<cmath>
#include<Windows.h>
using namespace std;
const int ARROW_KEY_CHARACTER = 224;
const int ARROW_KEY_UP = 72;
const int ARROW_KEY_DOWN = 80;
const int ARROW_KEY_LEFT = 75;
const int ARROW_KEY_RIGHT = 77;
const int escape = 27;
bool is_solvable(int ar1[5][5], int ar2[5][5]);
void finale();
void init();
void initial_board();
void final_board();
void legal_moves(int array[5][5]);
void make_move();
bool is_goal();
void print_path();
void save(int array1[5][5], int array2[5][5]);
void load(int array1[5][5], int array2[5][5]);
int ar1[5][5], ar2[5][5];
int permanent1[5][5];
int permanent2[5][5];
char choice;
string path;
//inital


int main()
{
	srand(time(0));
	initial_board();
	cout << endl << endl;
	final_board();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			permanent1[i][j] = ar1[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			permanent2[i][j] = ar2[i][j];
		}
	}
	while (!is_solvable(permanent1, permanent2))
	{
		if (is_solvable(permanent1, permanent2))
			cout << "THE GOAL IS REACHABLE\n";
	}

	init();
	cout << endl << endl;
	finale();
	legal_moves(permanent1);
	while (1)
	{
		cout << "MAKE YOUR MOVE\n";
		init();
		legal_moves(permanent1);
		finale();
		cout << "Esc Key to save game\n";
		make_move();

		if (is_goal())
		{
			cout << "\tYou won the game congrats\n";
			cout << "\t\tYou did the following moves\n";
			print_path();
			break;
		}
		Sleep(2000);
		cout << endl << endl;
		system("cls");
	}
}

void initial_board()
{

	int temp;
	int ar[25];
	bool flag;
	for (int i = 0; i < 25; i++)
	{
		do
		{

			temp = rand() % 25;
			flag = true;
			for (int j = 0; j < i; j++)
			{
				if (ar[j] == temp)
				{
					flag = false;
				}
			}
		} while (!flag);
		ar[i] = temp;

	}
	int p = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			ar1[i][j] = ar[p];
			p++;
		}

	}


}
//final
void final_board()
{

	int temp;
	int ar[25];
	bool flag;
	for (int i = 0; i < 25; i++)
	{
		do
		{

			temp = rand() % 25;
			flag = true;
			for (int j = 0; j < i; j++)
			{
				if (ar[j] == temp)
				{
					flag = false;
				}
			}
		} while (!flag);
		ar[i] = temp;

	}
	int p = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			ar2[i][j] = ar[p];
			p++;
		}

	}




}
//solvable
bool is_solvable(int ar1[5][5], int ar2[5][5])
{
	int temp_1[25], temp_2[25];
	int  k = 0, p = 0, count1 = 0, count2 = 0, sum1 = 0, sum2 = 0;
	bool res = false;
	//first bogus array 
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{

			temp_1[k] = ar1[i][j];
			k++;
		}

	}
	// second bogus array
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{

			temp_2[p] = ar2[i][j];
			p++;
		}

	}
	//inversions of first bogus array
	for (int i = 0; i < 25; i++)
	{
		count1 = 0;
		for (int j = 0; j < 25; j++)
		{
			if (temp_1[i] > temp_1[j])
			{
				count1++;

			}

		}
		sum1 += count1;
	}
	//inversions of second bogus array
	for (int i = 0; i < 25; i++)
	{
		count2 = 0;
		for (int j = 0; j < 25; j++)
		{
			if (temp_2[i] > temp_2[j])
			{
				count2++;

			}

		}
		sum2 += count2;
	}
	// solvable or not
	if ((sum1 % 2 == 0 && sum2 % 2 == 0) || (sum1 % 2 != 0 && sum2 % 2 != 0))
	{

		res = true;
		return res;
	}
	else
		return res;
}
void init()
{
	cout << "----------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (permanent1[i][j] < 10)
			{
				if (permanent1[i][j] != 0)
					cout << "|" << " " << permanent1[i][j];
				else
					cout << "|  ";
			}
			else
			{
				cout << "|" << permanent1[i][j];
			}
		}
		cout << "|";
		cout << endl;
		cout << "----------------" << endl;

	}
}
void finale()
{
	cout << endl;
	cout << "FINAL BOARD IS :\n";
	cout << "----------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (permanent2[i][j] < 10)
			{
				if (permanent2[i][j] != 0)
					cout << "|" << " " << permanent2[i][j];
				else
					cout << "|  ";
			}
			else
				cout << "|" << permanent2[i][j];

		}
		cout << "|";
		cout << endl;
		cout << "----------------" << endl;

	}

}
void legal_moves(int array[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (array[i][j] == 0)
			{
				if (i == 0 && j == 0)
				{
					cout << "Legal Moves at this position are:\n" << "LEFT\n" << "UP\n";
				}
				else if ((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 0 && j == 3))
					cout << "Legal Moves at this position are:\n" << "RIGHT\n" << "LEFT\n" << "UP\n";
				else if ((i == 0 && j == 4))
					cout << "Legal Moves at this position are:\n" << "RIGHT\n" << "UP\n";
				else if ((i == 1 && j == 0) || (i == 2 && j == 0) || (i == 3 && j == 0))
					cout << "Legal Moves at this position are:\n" << "RIGHT\n" << "UP\n" << "DOWN\n";
				else if ((i == 1 && j == 4) || (i == 2 && j == 4) || (i == 3 && j == 4))
					cout << "Legal Moves at this position are:\n" << "LEFT\n" << "UP\n" << "DOWN\n";
				else if ((i == 4 && j == 0))
					cout << "Legal Moves at this position are:\n" << "LEFT\n" << "DOWN\n";
				else if ((i == 4 && j == 1) || (i == 4 && j == 2) || (i == 4 && j == 3))
					cout << "Legal Moves at this position are:\n" << "RIGHT\n" << "LEFT\n" << "DOWN\n";
				else if (i == 4 && j == 4)
					cout << "Legal Moves at this position are:\n" << "RIGHT\n" << "DOWN\n";
				else
					cout << "Legal Moves at this position are:\n" << "RIGHT\n" << "LEFT\n" << "UP\n" << "DOWN\n";
			}

		}

	}
}

void make_move()
{
	int r = 0, c = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (permanent1[i][j] == 0)
			{

				r = i;
				c = j;
			}
		}
	}
	char decision;
	unsigned char char_read = _getch();
	if (char_read == ARROW_KEY_CHARACTER)
	{
		unsigned char arrow_read = _getch();
		switch (arrow_read)
		{
		case ARROW_KEY_UP:
			if (r == 4 && (c == 0 || c == 1 || c == 2 || c == 3 || c == 4))
			{
				cout << "Error Illegal move\n";
			}
			else
			{
				swap(permanent1[r][c], permanent1[r + 1][c]);
				path += "U, ";
			}
			break;
		case ARROW_KEY_DOWN:
			if (r == 0 && (c == 0 || c == 1 || c == 2 || c == 3 || c == 4))
			{
				cout << "Error Illegal move\n";
			}
			else
			{
				swap(permanent1[r][c], permanent1[r - 1][c]);
				path += "D, ";
			}
			break;
		case ARROW_KEY_LEFT:
			if ((r == 0 || r == 1 || r == 2 || r == 3 || r == 4) && c == 4)
			{
				cout << "Error Illegal move\n";
			}
			else
			{
				swap(permanent1[r][c], permanent1[r][c + 1]);
				path += "L, ";
			}
			break;
		case ARROW_KEY_RIGHT:
			if ((r == 0 || r == 1 || r == 2 || r == 3 || r == 4) && c == 0)
			{
				cout << "Error Illegal move\n";
			}
			else
			{
				swap(permanent1[r][c], permanent1[r][c - 1]);
				path += "R, ";
			}
			break;
		}

	}
	else
	{
		if (char_read == escape)
		{
			save(permanent1, permanent2);
			cout << endl;
			cout << "Your game has been saved\n";
			cout << "Do you want to continue? Y or N?\n";
			decision = _getch();
			if (decision == 'Y')
			{
				load(permanent1, permanent2);
			}
		}
	}
}
bool is_goal()
{
	bool is_goal_res = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			if (permanent1[i][j] == permanent2[i][j])
			{
				is_goal_res = true;
			}
			else
				is_goal_res = false;
			return false;
		}
	}
	return true;
}
void print_path()
{
	for (int i = 0; path[i] != '\0'; i++)
		cout << path[i];
}
void save(int array1[5][5], int array2[5][5])
{
	//initial array saver
	ofstream saver1;

	saver1.open("saveini.txt", ios_base::out);
	if (!saver1)
	{
		cout << "Error";
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				saver1 << permanent1[i][j] << " ";
			}
		}
		saver1.close();
	}

	//final array saver
	ofstream saver2;

	saver2.open("savefinal.txt", ios_base::out);
	if (!saver2)
	{
		cout << "Error";
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				saver2 << permanent2[i][j] << " ";
			}
		}
		saver2.close();
	}
}
void load(int array1[5][5], int array2[5][5])
{
	//initial array loader
	string _char1;
	ifstream loader1;
	loader1.open("saveini.txt", ios::in);
	if (!loader1)
	{
		cout << "Error";
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				loader1 >> _char1;
				if (_char1 != " ")
				{

					permanent1[i][j] = atoi(_char1.c_str());
				}
			}
		}


	}
	//final array loader
	string _char2;
	ifstream loader2;
	loader2.open("savefinal.txt", ios::in);
	if (!loader2)
	{
		cout << "Error";
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				loader2 >> _char2;
				if (_char2 != " ")
				{

					permanent2[i][j] = atoi(_char2.c_str());
				}
			}
		}

	}

}