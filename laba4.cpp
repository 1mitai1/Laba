#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

class casino
{
	int vznos;
	string name;

public:
	casino()
	{
		vznos = 0;
		name = '-';
	}
	~casino() {}
	void show_1()
	{
		cout << "name:" << name << endl;
	}
	int open()
	{
		cout << "your name" << endl;
		cin >> name;
		cout << "your rate" << endl;
		cin >> vznos;
		return vznos;
	}
};

class kartochnie : virtual public casino
{
	int koll_kart;
public:
	kartochnie()
	{
		koll_kart = 0;
	}
	~kartochnie() {}
	void show_21()
	{
		show_1();
		cout << "kolichestvo kart v kolode:" << koll_kart << endl;
	}
};

class poker : public kartochnie
{
	string krupie;
	int nach_stavka;
	int win;
	int rate;
public:
	poker()
	{
		krupie = '-';
		nach_stavka = 0;
	}
	~poker() {}
	void show_31()
	{
		show_21();
		cout << "krupie:" << krupie << endl;
		cout << "nachalnaia stavka:" << nach_stavka << endl;

	}
	string k1(int k1)
	{
		string k;
		switch (k1)
		{
		case 0:
			k = "Pair";
			break;
		case 1:
			k = "Two Pair";
			break;
		case 2:
			k = "Three of a Kind";
			break;
		case 3:
			k = "Staight";
			break;
		case 4:
			k = "Flush";
			break;
		case 5:
			k = "Full House";
			break;
		case 6:
			k = "Four of a Kind";
			break;
		case 7:
			k = "Straight Flush";
			break;
		case 8:
			k = "Royal Flush";
			break;
		}
		return k;
	}

	int game_1(int r)
	{
		rate = r;
		int your_komb = rand() % 8;
		fflush(stdin);
		int bot_komb = rand() % 8;
		cout << your_komb << k1(your_komb) << endl << bot_komb << k1(bot_komb) << endl;
		if (your_komb > bot_komb)
		{
			cout << "you win"; return r;
		}
		if (your_komb < bot_komb)
		{
			cout << "you lose"; return -r;
		}
		if (your_komb == bot_komb)
		{
			cout << "draw"; return 0;
		}
	}
};

class random_game : virtual public casino
{
	string name_game;
public:
	random_game()
	{
		name_game = ' ';
	}
	~random_game() {}
	void show_22()
	{
		show_1();
		cout << "net release ears:" << name_game << endl;
	}
};

class ruletka : public random_game
{
	int rate;
public:
	ruletka()
	{
	}
	~ruletka() {}
	void show_32()
	{
		show_22();
	}
	int game_2(int r)
	{
		rate = r;
		cout << endl <<"red or black (0/1)" << endl;
		int x;
		do 
		{
			fflush(stdin);
			cin >> x;
		} while (x != 0 && x != 1);
		int random_x = rand() % 1;
		if (x == random_x)
		{
			cout << "you win" << endl;
			return r;
		}
		else { cout << "you lose" << endl; return -r; }
	}
};

class game : public ruletka, poker
{
	int bank;
	int rate;
public:
	game()
	{
		bank = 0;
	}
	~game() {}
	void show_4()
	{
		show_1();
		cout << "bank=" << bank;
	}
	void game_3()
	{
		rate = open();
		int g;
		do {
			cout << "choose game" << endl << "1.poker" << endl << "2.role" << endl << "3.end" << endl;
			do
			{
				cin >> g;
			} while (g != 1 && g != 2 && g != 0 && !g);
			switch (g)
			{
			case 1:
				bank += game_1(rate);
				break;
			case 2:
				bank += game_2(rate);
				break;
			case 0:
				cout << endl << "end."<< endl;
				break;
			}
		} while (g != 0);
	}

};



int main()
{
	srand(time(NULL));
	game c;
	c.game_3();
	c.show_4();
	return 0;
}
