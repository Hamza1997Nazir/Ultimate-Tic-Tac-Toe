#include<iostream>
using namespace std;
class tic
{
private:

	char **arr;
	int input;
	int size;
	//int DrawCount;
	//int finalvalue;
public:

	tic();
	~tic(); // deallocates the ** arr pointer
	void makearray(); // takes dimentions of array
	int turn1();
	void validity(int&, int&);
	bool winner(int&);
	//void inccount();
	void print(int row);
	//void setfinalvalue(int);

};
tic ::~tic()
{
	if (arr != nullptr)
	{
		for (int i = 0; i < 3 ;i++)
			delete[] arr[i];
		delete [] arr;
	}
}
tic::tic()
{
	input = 0;
	size = 0;
	//DrawCount = 0;
}

void tic::makearray()
{
	int k = 0;

	//cout << "Enter size of tic-tac-toe ";
	//cin >> k;
	k = 3;
	size = k;

	arr = new char *[size];
	for (int i = 0; i < size; i++)
		arr[i] = new char[size];    // 2D array created

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			arr[i][j] = '_';           // Array initialized 
	}
}

int tic::turn1()
{
	static int turncount;
	
	int k = 0;
	int ans = 0;
	int row = 0;
	
	{
		row = 0;
		if (turncount % 2 == 0)
			cout << "Player 1 turn : ";
		else cout << "Player 2 : ";

		cin >> k;  // input
		k--;
		while (k >= size*size)
		{
			cout << "Value bigger than board size, input again : \n";
			cin >> k;       // if value exceeds the board size
			k--;
		}

		while (k >= size)
		{
			k = k - size;
			row++;
		}
		validity(row, k);  // checking the move
		if (turncount % 2 == 0) // player turn
			arr[row][k] = 'X'; // updating
		else arr[row][k] = 'O';

		turncount++;
		ans = 3 * row + k;
		return ans; // returns the position of next box
}
}
void tic::validity(int& i, int& j)
{
	int p = 0;

	while (arr[i][j] == 'X' || arr[i][j] == 'O')
	{
		i = 0;
		cout << "Space already occupied \n Enter new Value : ";
		cin >> j;
		j--;
		p = j;
		while (j >= size)
		{
			j = j - size;
			i++;
		}

	}
	return;
}
bool tic::winner(int &player)
{
	
	int q = 0;
	int k = 0;
	int count = 0;
	int t = 0;
	//------------- row check----------------

	for (int i = 0; i < size; i++)
	{
		for (int l = 0; l < size; l++)
		{
			if (arr[i][0] == 'X' || arr[i][0] == 'O')
			{
				if (arr[i][0] == arr[i][l])
					count++;
			}
		}
		if (count == size)
		{
			if (arr[i][0] == 'X')
			{
				player = 1;
				cout << "Player 1 wins \n";
			}
			else {
				player = 2;
				cout << "Player 2 wins \n";
			}
			return true;
		}
		count = 0;


	}
	//-------------column check------------------
	for (int i = 0; i < size; k++, i++)
	{

		while (t<size)
		{
			if (arr[0][i] == 'X' || arr[0][i] == 'O')// we are checking the col so row will remain zero
			{
				if (arr[0][k] == arr[q][i])
					count++;
			}
			t++;
			q++;
		}
		if (count == size)
		{
			if (arr[i][k] == 'X')
			{
				player = 1;
				cout << "Player 1 wins \n";
			}
			else {
				player = 2;
				cout << "Player 2 wins \n";
			}
			return true;
		}

		q = 0;
		t = 0;
		count = 0;
	}
	k = 0;
	count = 0;
	// --------Diagnoal---Primary--------------

	for (int j = 0; j < size; j++)
	{
		if (arr[j][j] == 'X' || arr[j][j] == 'O')  // check on board
			if (arr[0][0] == arr[j][j])
				count++;
	}
	if (count == size)
	{
		if (arr[0][0] == 'X')
		{
			player = 1;
			cout << "Player 1 wins \n";
		}
		else {
			player = 2;
			cout << "Player 2 wins \n";
		}
		return true;
	}
	count = 0;
	// -------Diagnoal -- Secondary---------------
	int r = 0;
	int c = size - 1;
	int i = r;
	int j = c;
	while (t<size)
	{

		if (arr[r][c] == 'X' || arr[r][c] == 'O')
			if (arr[r][c] == arr[i++][j--])
				count++;

		t++;
	}

	if (count == size)
	{
		if (arr[0][size - 1] == 'X')
		{
			player = 1;
			cout << "Player 1 wins \n";
		}
		else {
			player = 2;
			cout << "Player 2 wins \n";
		}
		return true;
	}
	player = 0;
	//inccount();
	return false;
}
void tic::print(int row)
{
	
	for (int j = 0; j < size; j++)
		cout << arr[row][j] << " ";
	//cout << endl;

}
void printmesh(tic**a);
void callturn(tic **a);
bool bigtable(int*player);
void deallo(int*a,bool *c);
void main()
{


	tic **list = new tic*[9];
	for (int i = 0; i < 9; i++)
		list[i] = new tic;  // object array

							//Ultimate Q2

	for (int i = 0; i < 9; i++)
		(list[i][0]).makearray(); // creates tic tac array


	printmesh(list);
	callturn(list);

	system("pause");
}


void printmesh(tic**a)
{

	for (int i = 0; i < 3; i++)
	{
		a[0][0].print(i); cout << "			"; a[1][0].print(i); cout << "			"; a[2][0].print(i);
		cout << endl;
	}
	cout << endl; cout << endl;
	for (int i = 0; i < 3; i++)
	{
		a[3][0].print(i); cout << "			"; a[4][0].print(i); cout << "			"; a[5][0].print(i);
		cout << endl;
	}
	cout << endl; cout << endl;
	for (int i = 0; i < 3; i++)
	{
		a[6][0].print(i); cout << "			"; a[7][0].print(i); cout << "			"; a[8][0].print(i);
		cout << endl;
	}
}
void callturn(tic **a)
{
	int k = 0, count = 0;
	bool *check = new bool[9];  //To check whether table has been completed or not
	for (int i = 0; i < 9; i++)
		check[i] = false;

	int *player = new int[9];   // To determine which player has won in each table
	for (int i = 0; i < 9; i++)
		player[i] = 0;

	bool finalcheck = false;
	cout << "Enter the box number to begin\n";
	cin >> k;
	k--;
	while (k > 8 || k < 0)
	{
		cout << "Value out of range\n Enter again : \n";
		cin >> k;
		k--;
	}

	while (finalcheck == false)
	{

		if (k == 0)
		{

			if (check[0] == false)
			{
				k = a[0][0].turn1();
				check[0] = a[0][0].winner(player[0]);  // w0 tells which player won
				system("cls");
				printmesh(a);
			}
			else
			{
				cout << "Enter the box to move. \n Here player " << player[0] << "  has won \n";
				cin >> k;
				k--;
				while (k > 8 || k < 0)
				{
					cout << "Value out of range\n Enter again : \n";
					cin >> k;
					k--;
				}
			}
		}
		if (k == 1)
		{

			if (check[1] == false)
			{
				k = a[1][0].turn1();
				check[1] = a[1][0].winner(player[1]);

				system("cls");
				printmesh(a);
			}
			else
			{
				cout << "Enter the box to move. \n Here player " << player[1] << "  has won \n";
				cin >> k;
				k--;
				while (k > 8 || k < 0)
				{
					cout << "Value out of range\n Enter again : \n";
					cin >> k;
					k--;
				}
			}
		}

	
	if (k == 2)
	{

		if (check[2] == false)
		{
			k = a[2][0].turn1();
			check[2] = a[2][0].winner(player[2]);
			system("cls");
			printmesh(a);
		}
		else
		{
			cout << "Enter the box to move. \n Here player " << player[2] << "  has won \n";
			cin >> k;
			k--;
			while (k > 8 || k < 0)
			{
				cout << "Value out of range\n Enter again : \n";
				cin >> k;
				k--;
			}
		}
	}

	if (k == 3)
	{

		if (check[3] == false)
		{
			k = a[3][0].turn1();
			check[3] = a[3][0].winner(player[3]);
			system("cls");
			printmesh(a);
		}
		else
		{
			cout << "Enter the box to move. \n Here player " << player[3] << "  has won \n";
			cin >> k;
			k--;
			while (k > 8 || k < 0)
			{
				cout << "Value out of range\n Enter again : \n";
				cin >> k;
				k--;
			}
		}

	}

	if (k == 4)
	{

		if (check[4] == false)
		{
			k = a[4][0].turn1();
			check[4] = a[4][0].winner(player[4]);
			system("cls");
			printmesh(a);
		}
		else
		{
			cout << "Enter the box to move. \n Here player " << player[4] << "  has won \n";
			cin >> k;
			k--;
			while (k > 8 || k < 0)
			{
				cout << "Value out of range\n Enter again : \n";
				cin >> k;
				k--;
			}
		}
	}
	if (k == 5)
	{

		if (check[5] == false)
		{
			k = a[5][0].turn1();
			check[5] = a[5][0].winner(player[5]);
			system("cls");
			printmesh(a);
		}
		else
		{
			cout << "Enter the box to move. \n Here player " << player[5] << "  has won \n";
			cin >> k;
			k--;
			while (k > 8 || k < 0)
			{
				cout << "Value out of range\n Enter again : \n";
				cin >> k;
				k--;
			}
		}
	}
	if (k == 6)
	{

		if (check[6] == false)
		{
			k = a[6][0].turn1();
			check[6] = a[6][0].winner(player[6]);
			system("cls");
			printmesh(a);
		}
		else
		{
			cout << "Enter the box to move. \n Here player " << player[6] << "  has won \n";
			cin >> k;
			k--;
			while (k > 8 || k < 0)
			{
				cout << "Value out of range\n Enter again : \n";
				cin >> k;
				k--;
			}
		}
	}
	if (k == 7)
	{

		if (check[7] == false)
		{
			k = a[7][0].turn1();
			check[7] = a[7][0].winner(player[7]);
			system("cls");
			printmesh(a);
		}
		else
		{
			cout << "Enter the box to move. \n Here player " << player[7] << "  has won \n";
			cin >> k;
			k--;
			while (k > 8 || k < 0)
			{
				cout << "Value out of range\n Enter again : \n";
				cin >> k;
				k--;
			}
		}
	}
	if (k == 8)
	{

		if (check[8] == false)
		{
			k = a[8][0].turn1();
			check[8] = a[8][0].winner(player[8]);
			system("cls");
			printmesh(a);
		}
		else
		{
			cout << "Enter the box to move. \n Here player " << player[8] << "  has won \n";
			cin >> k;
			k--;
			while (k > 8 || k < 0)
			{
				cout << "Value out of range\n Enter again : \n";
				cin >> k;
				k--;
			}
		}
	}


		
		finalcheck = bigtable(player);  // checks who wins the tables in a row
		
		for (int i = 0; i < 9; i++)
		{
			if (check[i] == true)
				count++;
		}
		if (count == 9)
		{
			cout << "Its a Draw \n";
			break;
		}
		}
		deallo(player, check);
}
bool bigtable(int*player)
{
	int count = 0;
	// row check
	for (int i = 0; i < 9; i=i+3)
	{
		for (int j = 0; j < 3; j++)
		{
			if (player[i] == 1 || player[i] == 2)
			{
				if (player[i] == player[j])
					count++;
			}
		}
		if (count == 3)
		{
			if(player[i]==1)
			{
				cout << "Player 1 wins in Row\n"; 
			}
			else cout << "Player 2 wins in Row\n";
			return true;
		}
		count = 0;
	}
	count = 0; // reset value of count
	int k = 0, t = 0, q = 0;
	
	// column check
	for (int i = 0; i < 3; i++)
	{

		while (t < 3)
		{
			if (player[i] == 1 || player[i] == 2)// we are checking the col so row will remain zero
			{
				if (player[i] == player[i + q])
					count++;
			}
			t++;
			q = q + 3;
		}
		if (count == 3)
		{
			if (player[i] == 1)
				cout << "Player 1 wins in Col\n";
			else
				cout << "Player 2 wins in Col\n";

			return true;
		}
		q = 0; // resetting values
		t = 0;
		count = 0;
	}
	count = 0;
	k = t = q = 0;
	// Diagnoal check
	for (int i = 0; i < 9; i=i+4)
	{
		if (player[0] == 1 || player[0] == 2)
		{
			if (player[0] == player[i])
				count++;
		}
	}
	if (count == 3)
	{
		if (player[0] == 1)
			cout << "Player 1 has won in D\n";
		else cout << "Player 2 has won in D\n";
		return true;
	}
	count = 0;
	//Secodary Diagnoal check
	for (int i = 2; i < 7; i=i+2)
	{
		if (player[2] == 1 || player[2] == 2)
		{
			if (player[2] == player[i])
				count++;
		}
	}
	if (count == 3)
	{
		if (player[2] == 1)
			cout << "Player 1 wins in SD\n";
		else cout << "Player 2 wins in SD\n";
		return true;
	}
	return false;
}
void deallo(int*a, bool*b)
{

		delete[] a;
		delete[] b;
		a = NULL;
		b = NULL;


}