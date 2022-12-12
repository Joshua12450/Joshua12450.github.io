/*JOSHUA MULLER
NOVEMBER 2ND 2022 
FIRST GAME ON C++*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	float userscore = 0;
	float cpuscore = 0;
	int usertotal = 0;
	int computertotal = 0;
	char highorlow;
	int randomnumber = -1;
	int usercard1 = 0;
	int usercard2 = 0;
	int cpucard1 = 0;
	int cpucard2 = 0;
	int usercards = 0;
	int cpucards = 0;
	bool ishigh; //ishigh will be used to give the computer low cards if the user picked high, or low cards if the user picked high
	bool whowins; //used to store whether the highest or lowest wins.
	int cputotal = 0;
	bool cpuwon = false;
	bool userwon = false;
	bool tie = false;
	char anykey;
	srand(time(0));
	enum highcards {
		KING = 7,
		BLUE = 6,
		RED = 1,
		ACE = 0,
	};
	enum lowcards {
		CYAN = 5,
		GREEN = 4,
		YELLOW = 3,
		ORANGE = 2,
	};
	do
	{
		usercards = 0;
		cpucards = 0;
		usertotal = 0;
		computertotal = 0;
		highorlow = 'p';
		randomnumber = 0;
		usercard1 = 0;
		usercard2 = 0;
		cpucard1 = 0;
		cpucard2 = 0;
		ishigh = false;
		whowins = false;
		usertotal = 0;
		cputotal = 0;
		userwon = false;
		cpuwon = false;
		tie = false;

		cout << "\n\nDo you want low cards or high cards? H for high, L for low, or enter q to quit. \n\nRULES: \nlow cards are cards between 2-5 and high cards are cards 0, 1, 6, and 7\nYour opponent will get high if you pick low, and vice versa. \nNote that if you pick low, you will get 2.5 points if you win, but if you pick high, the computer will instead! \nIf the one who has high cards wins, they will get 1 point.\nIn a tie, low will get 0.5 points\nFirst to 10 points will win!" << endl;
		cin >> highorlow;
		switch (highorlow) {
		case 'H': //fallthrough so it works if user types capital or lowercase H, same with L down below

		case 'h':
			ishigh = true;
			for (usercards = 0; usercards != 2;)
			{
				randomnumber = (rand() % 11);

				if ((randomnumber == ACE || randomnumber == RED || randomnumber == BLUE || randomnumber == KING) && usercards == 0)
				{


					usercards++;
					usercard1 = randomnumber;


				}
				else if ((randomnumber == ACE || randomnumber == RED || randomnumber == BLUE || randomnumber == KING) && usercards == 1 && randomnumber != usercard1)
				{

					usercards++;
					usercard2 = randomnumber;


				}


			}
			break;




		case 'L':

		case 'l':
			ishigh = false;
			for (usercards = 0; usercards != 2;)
			{
				randomnumber = (rand() % 5 + 1);

				if ((randomnumber == ORANGE || randomnumber == YELLOW || randomnumber == GREEN || randomnumber == CYAN) && usercards == 0)
				{


					usercards++;
					usercard1 = randomnumber;


				}
				else if ((randomnumber == ORANGE || randomnumber == YELLOW || randomnumber == GREEN || randomnumber == CYAN) && usercards == 1 && randomnumber != usercard1)
				{


					usercards++;
					usercard2 = randomnumber;


				}
			}
			break;
		default:
			cout << "ERROR: Please enter value within expected range.";
			return 1;
		}
		switch (ishigh) {
		case true:
			for (cpucards = 0; cpucards != 2;)
			{
				randomnumber = (rand() % 5 + 1);

				if ((randomnumber == ORANGE || randomnumber == YELLOW || randomnumber == GREEN || randomnumber == CYAN) && cpucards == 0)
				{


					cpucards++;
					cpucard1 = randomnumber;


				}
				else if ((randomnumber == ORANGE || randomnumber == YELLOW || randomnumber == GREEN || randomnumber == CYAN) && cpucards == 1 && randomnumber != cpucard2)
				{


					cpucards++;
					cpucard2 = randomnumber;


				}
			}

			break;
		case false:
			for (cpucards = 0; cpucards != 2;)
			{
				randomnumber = (rand() % 11);

				if ((randomnumber == ACE || randomnumber == RED || randomnumber == BLUE || randomnumber == KING) && cpucards == 0)
				{


					cpucards++;
					cpucard1 = randomnumber;


				}
				else if ((randomnumber == ACE || randomnumber == RED || randomnumber == BLUE || randomnumber == KING) && cpucards == 1 && randomnumber != cpucard2)
				{


					cpucards++;
					cpucard2 = randomnumber;


				}
			}

			break;
		}
		usertotal = usercard1 + usercard2;
		cputotal = cpucard1 + cpucard2;
		cout << "GAME START! Your cards are: " << usercard1 << " and " << usercard2 << endl;
		cout << "Would you rather have the highest win or the lowest win? type 1 for highest, 0 for lowest." << endl;
		cin >> whowins;
		cout << "Your card score was " << usertotal << " and the cpu's card score was " << cputotal << endl;

		switch (whowins)
		{
		case true:

			if (cputotal > usertotal) {
				cout << "The computer wins!" << endl;
				cpuwon = true;
				break;
			}
			else if (usertotal > cputotal) {
				cout << "You win!" << endl;
				userwon = true;
				break;
			}
			else {
				cout << "There was a tie! The one who has low cards will win." << endl;
				tie = true;
				break;
			}
			break;
		case false:
			if (cputotal < usertotal) {
				cout << "The computer wins!" << endl;
				cpuwon = true;
				break;
			}
			else if (usertotal < cputotal) {
				cout << "You win!" << endl;
				userwon = true;
				break;
			}
			else {
				cout << "There was a tie! The one who has low cards will win." << endl;
				tie = true;
				break;
			}
			break;
		}
		if (cpuwon == true && ishigh == true) {
			cout << "The cpu won with low cards, and will get 2.5 points" << endl;
			cpuscore += 2.5;
		}
		else if (cpuwon == true && ishigh == false) {
			cout << "The cpu won with high cards, and will get 1 point." << endl;
			cpuscore++;
		}
		else if (userwon == true && ishigh == false) {
			cout << "You won with low cards! You will get 2.5 points." << endl;
			userscore += 2.5;
		}
		else if (userwon == true && ishigh == true) {
			cout << "You won with high cards, and will get 1 point." << endl;
			userscore++;
		}
		else if (tie == true)
		{
			switch (ishigh) {
			case false:
				cout << "Since you have low cards, you win the tie, and get 0.5 points." << endl;
				userscore += 0.5;
				break;
			case true: {
				cout << "Since the cpu has low cards, they win the tie, and get 0.5 points." << endl;
				cpuscore += 0.5;
				break;
			}





			}
		}
		cout << "\nYour total score so far is:\n" << userscore << "\nThe cpu's total score so far is:\n" << cpuscore <<  endl;
		cout << "enter any letter to continue";
		cin >> anykey;
		cout << "\033[2J\033[1;1H"; //My linux using friend wants to play the game system("CLS); does not work for him. this code is used in place of that to make it non windows-dependent. For the purpose of marking, please pretend this is just system("CLS");
		if (cpuscore >= 10) {
			cout << "You lost! Better luck next time!" << endl;
			return 0;
		}
		else if (userscore >= 10) {
			cout << "CONGLATURATION !!! \n\nYOU HAVE COMPLETED \nA GREAT GAME. \n\nAND PROOVED THE JUSTICE\nOF OUR CULTURE. \n\nNOW GO AND REST OUR\nHEROES  !" << endl;
			return 0;
		}
	} while (true);

}
