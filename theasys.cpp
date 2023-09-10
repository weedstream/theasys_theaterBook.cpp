#include <iostream>
#include <windows.h>

using namespace std;

typedef struct node
{
	char seat_row;
	int seat_no;
	char book;
	struct node *next, *prev;
}node;

int main();
//variable global
int a = 350000, b=300000, c=250000, d=200000, e=250000;
int harga = 0;
int total = 0;

class theasys
{
	public:
		node * hn;
	theasys()
	{
		hn = NULL;
	}

	public:
		void create()
		{
			node *nn, *cn;
			int j = 1;
			char c = 'A';

			do {
				int i = 1;
				do {
					nn = new node();
					nn->next = nn->prev = NULL;
					nn->seat_row = c;
					nn->seat_no = i;
					nn->book = 'a';
					if (hn == NULL)
					{
						hn = nn;
						nn->next = nn->prev = hn;
					}
					else
					{
						cn = hn;

						while (cn->next != hn)
							cn = cn->next;

						cn->next = nn;
						nn->prev = cn;
						nn->next = hn;
						hn->prev = nn;
					}

					i++;
				} while (i <= 20);
				j++;
				c++;
			} while (j <= 5);
		}


	void harga_ticket ()
	{
		cout << "\n\n\t\tP R I C E  L I S T\n\n";
		cout << "\tA L P H A \t\t\t350000";
		cout << "\n\n\tB R A V O \t\t\t300000";
		cout << "\n\n\tC H A R L I E \t\t\t250000";
		cout << "\n\n\tD E L T A \t\t\t200000";
		cout << "\n\n\tE C H O \t\t\t250000\n\n";
	}

	void display_seat()
	{
		node * cn;
		cn = hn;
		setcolor(4);
		cout << "| A L P H A \t\t";
		if (cn->seat_row == 'A')
			while (cn->next != hn)
			{
				cout << cn->seat_row;
				cout << cn->seat_no;
				if (cn->book == 'a')
					cout << " - available  \t";
				else
					cout << " - filled  \t";
				if ((cn->next)->seat_row != cn->seat_row)
					cout << "|\n";
				if (cn->seat_row == 'A' && cn->seat_no == 20)
				{
					cout << "\n\n";
					setcolor(6);
					cout << "| B R A V O \t\t";
				}

				if (cn->seat_row == 'B' && cn->seat_no == 20)
				{
					cout << "\n\n";
					setcolor(2);
					cout << "| C H A R L I E \t";
				}

				if (cn->seat_row == 'C' && cn->seat_no == 20)
				{
					cout << "\n\n";
					setcolor(1);
					cout << "| D E L T A \t\t";
				}

				if (cn->seat_row == 'D' && cn->seat_no == 20)
				{
					cout << "\n\n";
					setcolor(5);
					cout << "| E C H O \t\t";
				}

				if (cn->seat_row == 'E' && cn->seat_no == 20)
				{
					cout << "\n\n";
				}

				cn = cn->next;
			}

		cout << cn->seat_row;
		cout << cn->seat_no;
		if (cn->book == 'a')
			cout << " - available  \t";

		else
			cout << " - filled  \t";

		cout << "|\n";
		setcolor(7);
	}

	void display1(node *tmp[20], int n)
	{
		cout << "\n\n\n";
		if (n != 1)
		{
			cout << "-------------------------------\n";
			cout << "SEAT SUCCESSFULLY FILLED\n";
			for (int i = 1; i < n; i++)

				cout << "\nTicket " << i << "\n  Seat No : " << tmp[i]->seat_row << tmp[i]->seat_no;
			cout << endl;
            cout << "\nTotal yang harus dibayar Rp."<<total<<endl;
			cout << "-------------------------------\n";

		}
		cout << "\n\n\n";

	}

	void book_seat()
	{
		node *cn, *temp[20];
		int n, z;
		char row;
		int seat;
		char ch;
		do {
			z = 1;
			cout << "\n\tEnter number your ticket purchase : ";
			cin >> n;

			cout << "\n\tEnter seat number : \n";

			for (int i = 1; i <= n; i++)
			{
			  pilih :
				cout << "Ticket " << i << endl;
				cout << "   Seat No " << i << " = ";
				cin >> row >> seat;
				cn = hn;
				//inisialisasi harga
				switch(row)
				{
                case 'A':
                    harga = a;
                    break;
                case 'B':
                    harga = b;
                    break;
                case 'C':
                    harga = c;
                    break;
                case 'D':
                    harga = d;
                    break;
                case 'E':
                    harga = e;
                    break;

				}

				if (row >= 'A' && row <= 'E')
				{
					while (cn->next != hn)
					{
						if (cn->seat_row == row && cn->seat_no == seat)
						{
							if (cn->book == 'a')
							{
								cn->book = 'b';
								temp[z] = cn;
								z++;
								//menjumlah harga
                                total+=harga;
                            }
							else
							{
								// cout << "INVALID CHOISE!\n";
								cout << cn->seat_row << cn->seat_no << " Seat Filled \n";
								goto pilih;
							}
						}
						cn = cn->next;

					}

					if (cn->seat_row == row && cn->seat_no == seat)
					{
						if (cn->book == 'a')
						{
							cn->book = 'b';
							temp[z] = cn;
							z++;
						}
						else
						{
							// cout << "INVALID CHOISE!\n";
							cout << cn->seat_row << cn->seat_no << " Seat Filled\n";
						}
					}
				}
				else
				{
					while (cn->prev != hn)
					{
						if (cn->seat_row == row && cn->seat_no == seat)
						{
							if (cn->book == 'a')
							{
								cn->book = 'b';
								temp[z] = cn;
								z++;
							}
							else
							{
								// cout << "INVALID CHOISE!\n";
								cout << cn->seat_row << cn->seat_no << " Seat Filled \n";
							}
						}

						cn = cn->prev;
					}

					if (cn->seat_row == row && cn->seat_no == seat)
					{
						if (cn->book == 'a')
						{
							cn->book = 'b';
							temp[z] = cn;
							z++;
						}
						else
						{
							// cout << "INVALID CHOISE!\n";
							cout << cn->seat_row << cn->seat_no << " Seat Filled\n";
						}
					}
				}

			}

			display1(temp, z);
		} while (ch == '2');
	}

	void check_seat ()
	{
		int ch;
		cout << "Press Key 1 To Check Your Seat\n";
					cin >> ch;

					if (ch == 1)
					{
						display_seat ();
						cout << "\n\n";
						cout << "Press 1 To Main Menu\n";
						cout << "Press 2 To Book Ticket\n";
						cin >> ch;

						if (ch == 1)
						{
						    system("cls");
						    total =0;
							ch_1 ();
						}
						else if (ch == 2)
						{
						    system("cls");
						    total =0;
							ch_2_1 ();

						}
						else
						{
							system("clear");
						}
					}
	}

	void ch_1 ()
	{
		int ch;

		cout << "\t\t\tT\tH\tE\tA\tS\tY\tS\n\n";
		cout << "\t\t\tP R A H A  T H E A T E R  S Y S T E M  O R D E R\n\n\n";
		show_playing ();
		cout << "1. S E A T  C H E C K\n";
		cout << "2. B O O K I N G  T I C K E T\n";
		cout << "0. E X I T\n\n";

		cout << "Enter your choice : ";
			cin >> ch;
			switch (ch)
			{
				case 1:
				    system("cls");
					ch_1_1 ();
					break;
				case 2:
				    system("cls");
					ch_2_1 ();
					// check_seat ();
					break;
			}
	}

	void ch_1_1 ()
	{
		int ch;
		// system("clear");
		cout << "\t\t\tT\tH\tE\tA\tS\tY\tS\n\n";
		cout << "\t\t\tP R A H A  T H E A T E R  S Y S T E M  O R D E R\n\n\n";
		show_playing ();
		cout << "\t\t\tS E A T  L I S T\n\n";
		display_seat ();
		harga_ticket ();
		cout << "Press Key 1 To Back\n";
		cin >> ch;
		if (ch == 1)
		{
			ch_1 ();
			// system("clear");
		}
	}

	void ch_2_1 ()
	{
		int ch;

		// system("clear");
		cout << "\t\t\tT\tH\tE\tA\tS\tY\tS\n\n";
		cout << "\t\t\tP R A H A  T H E A T E R  S Y S T E M  O R D E R\n\n";
		cout << "\n\n\t\t\t\tB O O K I N G  T I C K E T\n\n\n";
		cout << "\t\tPress Key 0 For Display Seat and Key 1 For Booking Ticket ";
		cin >> ch;

		cout << "\n\n";
		if (ch == 0)
		{
		    system("cls");
			display_seat ();
			cout << "\n\n";
			book_seat ();
		}
		else if (ch == 1)
		{
		    system("cls");
			book_seat ();
		}
		else
		{
			cout << "INVALID INPUT!!!!!\n\n\n";
			ch_2_1 ();
		}
		// sys.display_seat ();
		// sys.book_seat ();

		check_seat ();
	}

	void show_playing ()
	{
		cout << "\t\tN O W  P L A Y I N G\n\n";
		cout << "\t\tLONG DAY'S JOURNEY INTO NIGHT\n\n\n\n";
	}

	void setcolor(unsigned short color)
	{
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hCon,color);
	}
};

int main()
{

	int ch;

	theasys sys;
	sys.create ();

	cout << "\n\n";

	cout << "\t\t\tT\tH\tE\tA\tS\tY\tS\n\n";
	cout << "\t\t\tP R A H A  T H E A T E R  S Y S T E M  O R D E R\n\n";
	cout << "\t\t\t\tCreated By Tectonia and Fauzi\n";
	cout << "\n\n";
	sys.show_playing ();


	cout << "Press Key 1 To Continue\n";
	cin >> ch;

	switch (ch)
	{
		case 1:
		    system("cls");
			sys.ch_1 ();
			break;

		case 0:
			system("cls");
			break;
	}
}
