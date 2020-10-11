#include <iostream>
#include <ctime>
#include <limits>
#include <string>
#include <Windows.h>
using namespace std;


const int COLS = 10; //Columns
const int ROWS = 10; //Rows
const int CARRIER = 5; //Carrier Ship
const int BATTLE_SHIP = 4; //Battle Ship
const int CRUISER = 3; //Crussier Ship
const int SUBMARINE = 3; //Submarines
const int PATROL = 2; //Patrol Ships


void playerSetUp(HANDLE, char[][COLS], int, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]);
void mapGenerator(char[][COLS], int, int carrier[], int battleShip[], int cruiser[], int submarine[], int patrol[]);
void displayScoreBoard(HANDLE, char[][COLS], char[][COLS], int, int enemyCarrier[], int enemyBattleShip[], int enemyCruiser[], int enemySubmarine[], int enemyPatrol[], int &, int &, int &, int &, int &, int &, int &, int &, int &, int &, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]);
void placeCursor(HANDLE, int, int);
int winCondition(int, int);
int startMenu();
int shipCheck(char[][COLS], int, int ship[], int);
int letterVal(char);
int numValidation(int);
void displayBoard(HANDLE, char[][COLS], int);
void playerTurn(HANDLE, char[][COLS], char[][COLS], int);
void enemyTurn(HANDLE, char[][COLS], int, int);
void stringInputCheck(HANDLE, string, int&, int&, int, int);

int main()
{
	/*Comuter's Map*/
	char computer[ROWS][COLS] = {
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
	};
	/*Map the playter will see for when game start*/
	char enemyDisplay[ROWS][COLS] = {
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
	};
	/*Player's Map*/
	char player[ROWS][COLS] = {
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
		{ 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O' },
	};
	int startNumber, gameOver;
	int enemyCarrier[7], enemyBattleShip[6], enemyCruiser[5], enemySubmarine[5], enemyPatrol[4];  //Hold Computer's point for Ship Location
	int playerCarrier[7], playerBattleShip[6], playerCruiser[5], playerPatrol[4];  //Hold Player's point for Ship Location
	int playerSubmarine[5];
	/*1 is Alive, 2 is Dead*/
	int enemyCarrierAlive = 1, enemyBattleShipAlive = 1, enemyCruiserAlive = 1, enemySubmarineAlive = 1, enemyPatrolAlive = 1;
	int playerCarrierAlive = 1, playerBattleShipAlive = 1, playerCruiserAlive = 1, playerSubmarineAlive = 1, playerPatrolAlive = 1;
	/*Holds Number 1-5 For How Many Ships are Left*/
	int enemyAlive, playerAlive;

	/*Diffrent Color for Cruser Patrol*/
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	/*Dificult Level*/
	startNumber = startMenu();
	if (startNumber == 1 || startNumber == 2) {
		system("CLS");
		playerSetUp(screen, player, ROWS, playerCarrier, playerBattleShip, playerCruiser, playerSubmarine, playerPatrol); //Sets Player's Ships Accordingly
		mapGenerator(computer, ROWS, enemyCarrier, enemyBattleShip, enemyCruiser, enemySubmarine, enemyPatrol); //Sets Computer Ships Randomly
		do {
			placeCursor(screen, 0, 0);   //Starting Points
			displayBoard(screen, enemyDisplay, ROWS); //Show's Computer's Map
			displayBoard(screen, player, ROWS);   //Shows Player's Map
			displayScoreBoard(screen, player, computer, ROWS, enemyCarrier, enemyBattleShip, enemyCruiser, enemySubmarine, enemyPatrol, enemyCarrierAlive, enemyBattleShipAlive, enemyCruiserAlive, enemySubmarineAlive, enemyPatrolAlive, playerCarrierAlive, playerBattleShipAlive, playerCruiserAlive, playerSubmarineAlive, playerPatrolAlive, playerCarrier, playerBattleShip, playerCruiser, playerSubmarine, playerPatrol);              //displays score board
			playerTurn(screen, computer, enemyDisplay, ROWS);  //Player's Point for Attack
			enemyTurn(screen, player, COLS, startNumber);   //Computer's Point to Atack
			enemyAlive = enemyCarrierAlive + enemyBattleShipAlive + enemyCruiserAlive + enemySubmarineAlive + enemyPatrolAlive; //Checks if Enemy Ships Alive
			playerAlive = playerCarrierAlive + playerBattleShipAlive + playerCruiserAlive + playerSubmarineAlive + playerPatrolAlive; //Checks if Player's Ships Alive
			gameOver = winCondition(enemyAlive, playerAlive);  //Checks if All Ships Destroyed
		}
		/*Win Lose*/
		while (gameOver == 1);
		/*If you Win*/
		if (gameOver == 2) {
			system("CLS");
			placeCursor(screen, 0, 0);
			cout << "You Win!" << endl;
			cin.get();
		}
		/*If you Lose*/
		else {
			system("CLS");
			placeCursor(screen, 0, 0);
			cout << "You Lost!" << endl;
			cin.get();
		}
	}
	/*Exit*/
	else {
		char quitKey;
		cout << "Press any key then enter to exit: ";
		cin >> quitKey;
	}


	return 0;
}
/*Game Menu*/
int startMenu() {
	int start;
	char choice;
	cout << "\t\tBattle Ship Game 1.0\n\n\n";
	cout << "This game is real beta stuff right now." << endl;
	cout << "Please press the maxmize screen button for best quality." << endl << endl << endl;
	/*Start or Quit*/
	cout << "A. Start \nB. Quit\nChoose: ";
	cin >> choice;
	while (!(choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' || choice == 'C' || choice == 'c')) {
		cout << "Invalid choice. Please select A, B, or C: ";
		cin >> choice;
	}
	/*PLay Against PC or Human*/
	if (choice == 'A' || choice == 'a') {
		cout << "Would you like to face the computer or another person?" << endl;
		cout << "A. Computer\nB. Human\nC. Quit" << endl;
		cout << "Your choice: ";
		cin >> choice;
		while (!(choice == 'A' || choice == 'a' || choice == 'B' || choice == 'b' || choice == 'C' || choice == 'c')) {
			cout << "Invalid choice. Please select A, B, or C: ";
			cin >> choice;
		}
		/*Dificult Level for PC*/
		if (choice == 'A' || choice == 'a') {
			cout << "What difficulty would you like?" << endl;
			cout << "A. Easy\nB. Medium\nC. Hard (Under Construction}" << endl;
			cout << "Your choice: ";
			cin >> choice;
			if (choice == 'A' || choice == 'a') {
				start = 1;
			}
			else if (choice == 'B' || choice == 'b') {
				start = 2;
			}
			else {
				cout << "Hard still under constuction. Loading Medium difficulty.";
				start = 2;
			}
		}
		else if (choice == 'B' || choice == 'b') {
			cout << "Still under construction. Now exiting program." << endl;
			start = 0;
		}
		else
			start = 0;
	}
	else
		start = 0;
	return start;
}
/*IT Will Print the Rows and Colums, Numbers*/
void displayBoard(HANDLE screen, char map[][COLS], int row) {
	cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "  -----------------------\n";
	for (int x = 0; x < 10; x++) {
		if (x == 0)
			cout << "A ";
		if (x == 1)
			cout << "B ";
		if (x == 2)
			cout << "C ";
		if (x == 3)
			cout << "D ";
		if (x == 4)
			cout << "E ";
		if (x == 5)
			cout << "F ";
		if (x == 6)
			cout << "G ";
		if (x == 7)
			cout << "H ";
		if (x == 8)
			cout << "I ";
		if (x == 9)
			cout << "J ";
		cout << "| ";
		for (int y = 0; y < 10; y++) {
			if (map[x][y] == 'O') {
				SetConsoleTextAttribute(screen, 7);
				cout << map[x][y] << " ";
			}
			else if (map[x][y] == 'A') {
				SetConsoleTextAttribute(screen, 1);
				cout << map[x][y] << " ";
				SetConsoleTextAttribute(screen, 7);
			}
			else if (map[x][y] == 'M') {
				SetConsoleTextAttribute(screen, 6);
				cout << map[x][y] << " ";
				SetConsoleTextAttribute(screen, 7);
			}
			else {
				SetConsoleTextAttribute(screen, 4);
				cout << map[x][y] << " ";
				SetConsoleTextAttribute(screen, 7);
			}
		}
		cout << "|";
		cout << endl;
	}
	cout << "  -----------------------\n";
}
/*Placeing the Ship On Array*/
void playerSetUp(HANDLE screen, char playerSetUp[][COLS], int rows, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]) {
	static int shipCount = 0;
	int place1 = 0, place2 = 0, place3 = 0, place4 = 0, shipSize, sizeDifference;
	string shipName, point;
	int overLapCheck = 1;
	char choice;


	displayBoard(screen, playerSetUp, ROWS);
	cout << "Welcome to BattleShip! This is your board where you get to place your ships!" << endl;
	cout << "Please type the letter followed by the number (example: a6) then press enter." << endl;
	cout << "Then type in the second coordinate in the same format. Please only place ships" << endl;
	cout << "from left to right or from up to down. The game will crash otherwise :(" << endl;
	cout << "Do you wish to place your ships manually or have a randomly generated board?" << endl;
	cout << "Type A to make your own board or B to have one make for you: ";
	cin >> choice;
	if (choice == 'A' || choice == 'a') {
		do {
			system("CLS");

			displayBoard(screen, playerSetUp, ROWS);

			if (shipCount == 0) {
				shipName = "carrier";
				shipSize = CARRIER;
			}
			else if (shipCount == 1) {
				shipName = "battle_ship";
				shipSize = BATTLE_SHIP;
			}
			else if (shipCount == 2) {
				shipName = "cruiser";
				shipSize = CRUISER;
			}
			else if (shipCount == 3) {
				shipName = "submarine";
				shipSize = SUBMARINE;
			}
			else if (shipCount == 4) {
				shipName = "patrol";
				shipSize = PATROL;
			}
			cout << "Placing " << shipName << " that is " << shipSize << " spaces long." << endl;
			cout << "Please type the letter first followed by the number\nfor one point followed by the other point" << endl;
			placeCursor(screen, 17, 0);
			cout << "First point(e.g. a5)" << endl;
			/*cin.ignore();*/
			stringInputCheck(screen, point, place1, place2, 18, 0);
			/*cin >> placer1;
			place1 = letterVal(placer1);
			cin >> placer2;
			place2 = numValidation(placer2);*/
			placeCursor(screen, 19, 0);
			cout << "                  " << endl;
			placeCursor(screen, 17, 0);
			cout << "Second point (e.g. a8)" << endl;
			/*cin.ignore();*/
			stringInputCheck(screen, point, place3, place4, 18, 0);
			/*cin >> placer3;
			place3 = letterVal(placer3);
			cin >> placer4;
			place4 = numValidation(placer4);*/
			if (place1 == place3) {
				sizeDifference = place4 - place2 + 1;
				if (sizeDifference == shipSize) {
					for (int x = place2; x <= place4; x++) {
						if (playerSetUp[place1][x] == 'O') {
							overLapCheck = 1;
						}
						else {
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1) {
						for (int x = place2, t = 2; x <= place4; x++, t++) {
							if (shipCount == 0) {
								playerCarrier[0] = 1;
								playerCarrier[1] = place1;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1) {
								playerBattleShip[0] = 1;
								playerBattleShip[1] = place1;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2) {
								playerCruiser[0] = 1;
								playerCruiser[1] = place1;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3) {
								playerSubmarine[0] = 1;
								playerSubmarine[1] = place1;
								playerSubmarine[t] = x;
							}
							else {
								playerPatrol[0] = 1;
								playerPatrol[1] = place1;
								playerPatrol[t] = x;
							}
							playerSetUp[place1][x] = 'A';
							system("CLS");
						}
					}
					else {
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
				else {
					do {
						system("CLS");
						cout << "Invalid size." << endl;
						displayBoard(screen, playerSetUp, ROWS);
						cout << "Placing " << shipName << " that is " << shipSize << " spaces long." << endl;
						cout << "Please type the letter first followed by the number\nfor one point followed by the other point" << endl;
						placeCursor(screen, 17, 0);
						cout << "First point(e.g. a5)" << endl;
						/*cin.ignore();*/
						stringInputCheck(screen, point, place1, place2, 18, 0);
						/*cin >> placer1;
						place1 = letterVal(placer1);
						cin >> placer2;
						place2 = numValidation(placer2);*/
						placeCursor(screen, 19, 0);
						cout << "                  " << endl;
						placeCursor(screen, 17, 0);
						cout << "Second point (e.g. a8): ";
						/*cin.ignore();*/
						stringInputCheck(screen, point, place3, place4, 18, 0);
						/*cin >> placer3;
						place3 = letterVal(placer3);
						cin >> placer4;
						place4 = numValidation(placer4);*/
						sizeDifference = place4 - place2 + 1;
					} while (sizeDifference != shipSize && overLapCheck == 2);
					for (int x = place2; x <= place4; x++) {
						if (playerSetUp[place1][x] == 'O') {
							overLapCheck = 1;
						}
						else {
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1) {
						for (int x = place2, t = 2; x <= place4; x++, t++) {
							if (shipCount == 0) {
								playerCarrier[0] = 1;
								playerCarrier[1] = place1;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1) {
								playerBattleShip[0] = 1;
								playerBattleShip[1] = place1;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2) {
								playerCruiser[0] = 1;
								playerCruiser[1] = place1;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3) {
								playerSubmarine[0] = 1;
								playerSubmarine[1] = place1;
								playerSubmarine[t] = x;
							}
							else {
								playerPatrol[0] = 1;
								playerPatrol[1] = place1;
								playerPatrol[t] = x;
							}
							playerSetUp[place1][x] = 'A';
							system("CLS");
						}
					}
					else {
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
			}
			else if (place2 == place4) {
				sizeDifference = place3 - place1 + 1;
				if (sizeDifference == shipSize) {
					for (int x = place1; x <= place3; x++) {
						if (playerSetUp[x][place2] == 'O') {
							overLapCheck = 1;
						}
						else {
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1) {
						for (int x = place1, t = 2; x <= place3; x++, t++) {
							if (shipCount == 0) {
								playerCarrier[0] = 2;
								playerCarrier[1] = place2;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1) {
								playerBattleShip[0] = 2;
								playerBattleShip[1] = place2;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2) {
								playerCruiser[0] = 2;
								playerCruiser[1] = place2;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3) {
								playerSubmarine[0] = 2;
								playerSubmarine[1] = place2;
								playerSubmarine[t] = x;
							}
							else {
								playerPatrol[0] = 2;
								playerPatrol[1] = place2;
								playerPatrol[t] = x;
							}
							playerSetUp[x][place2] = 'A';
							system("CLS");
						}
					}
					else {
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
				else {
					do {
						system("CLS");
						displayBoard(screen, playerSetUp, ROWS);
						cout << "Invalid size." << endl;
						cout << "Placing " << shipName << " that is " << shipSize << " spaces long." << endl;
						cout << "Please type the letter first followed by the number\nfor one point followed by the other point" << endl;
						placeCursor(screen, 17, 0);
						cout << "First point (e.g. a5)" << endl;
						/*cin.ignore();*/
						stringInputCheck(screen, point, place1, place2, 18, 0);
						/*cin >> placer1;
						place1 = letterVal(placer1);
						cin >> placer2;
						place2 = numValidation(placer2);*/
						placeCursor(screen, 19, 0);
						cout << "                  " << endl;
						placeCursor(screen, 17, 0);
						cout << "Second point (e.g. a8)" << endl;
						/*cin.ignore();*/
						stringInputCheck(screen, point, place3, place4, 18, 0);
						/*cin >> placer3;
						place3 = letterVal(placer3);
						cin >> placer4;
						place4 = numValidation(placer4);*/
						sizeDifference = place4 - place2 + 1;
					} while (sizeDifference != shipSize && overLapCheck == 2);
					for (int x = place1; x <= place3; x++) {
						if (playerSetUp[place1][x] == 'O') {
							overLapCheck = 1;
						}
						else {
							overLapCheck = 2;
							break;
						}
					}
					if (overLapCheck == 1) {
						for (int x = place1, t = 2; x <= place3; x++, t++) {
							if (shipCount == 0) {
								playerCarrier[0] = 2;
								playerCarrier[1] = place2;
								playerCarrier[t] = x;
							}
							else if (shipCount == 1) {
								playerBattleShip[0] = 2;
								playerBattleShip[1] = place2;
								playerBattleShip[t] = x;
							}
							else if (shipCount == 2) {
								playerCruiser[0] = 2;
								playerCruiser[1] = place2;
								playerCruiser[t] = x;
							}
							else if (shipCount == 3) {
								playerSubmarine[0] = 2;
								playerSubmarine[1] = place2;
								playerSubmarine[t] = x;
							}
							else {
								playerPatrol[0] = 2;
								playerPatrol[1] = place2;
								playerPatrol[t] = x;
							}
							playerSetUp[place1][x] = 'A';
							system("CLS");
						}
					}
					else {
						system("CLS");
						cout << "You already have a ship there!" << endl;
						shipCount--;
					}
				}
			}
			else {
				system("CLS");
				cout << "Must enter ships vertical or horizontal." << endl;
				cout << "Please enter the smaller point first followed by the bigger point." << endl;
				shipCount--;
			}
			shipCount++;
		} while (shipCount <= 4);
	}
	else {
		mapGenerator(playerSetUp, ROWS, playerCarrier, playerBattleShip, playerCruiser, playerSubmarine, playerPatrol);
		system("CLS");
	}
}
/*Place the Computers Ships Rondom Places*/
void mapGenerator(char setUp[][COLS], int rows, int carrier[], int battleShip[], int cruiser[], int submarine[], int patrol[]) {
	int computerShipDirection, computerPoint1, computerPoint2; //1 = horizontal 2 = vertical
	int overLapCheck;

	srand(time(0));
	/*Place Carrier*/
	computerShipDirection = rand() % 2 + 1;
	/*Horizontal*/
	if (computerShipDirection == 1) {              
		computerPoint1 = rand() % 10;
		computerPoint2 = rand() % 6;
		setUp[computerPoint1][computerPoint2] = 'A';
		setUp[computerPoint1][computerPoint2 + 1] = 'A';
		setUp[computerPoint1][computerPoint2 + 2] = 'A';
		setUp[computerPoint1][computerPoint2 + 3] = 'A';
		setUp[computerPoint1][computerPoint2 + 4] = 'A';
		carrier[0] = computerShipDirection;
		carrier[1] = computerPoint1;
		carrier[2] = computerPoint2;
		carrier[3] = computerPoint2 + 1;
		carrier[4] = computerPoint2 + 2;
		carrier[5] = computerPoint2 + 3;
		carrier[6] = computerPoint2 + 4;
	}
	/*Vertical*/
	else {                                               
		computerPoint1 = rand() % 6;
		computerPoint2 = rand() % 10;
		setUp[computerPoint1][computerPoint2] = 'A';
		setUp[computerPoint1 + 1][computerPoint2] = 'A';
		setUp[computerPoint1 + 2][computerPoint2] = 'A';
		setUp[computerPoint1 + 3][computerPoint2] = 'A';
		setUp[computerPoint1 + 4][computerPoint2] = 'A';
		carrier[0] = computerShipDirection;
		carrier[1] = computerPoint2;
		carrier[2] = computerPoint1;
		carrier[3] = computerPoint1 + 1;
		carrier[4] = computerPoint1 + 2;
		carrier[5] = computerPoint1 + 3;
		carrier[6] = computerPoint1 + 4;
	}
	/*Place Battleship*/
	do {
		computerShipDirection = rand() % 2 + 1;
		/*Horizontal*/
		if (computerShipDirection == 1) {                
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 7;
			for (int z = computerPoint2; z < computerPoint2 + 3; z++) {
				if (setUp[computerPoint1][z] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1][computerPoint2 + 1] = 'A';
				setUp[computerPoint1][computerPoint2 + 2] = 'A';
				setUp[computerPoint1][computerPoint2 + 3] = 'A';
				battleShip[0] = computerShipDirection;
				battleShip[1] = computerPoint1;
				battleShip[2] = computerPoint2;
				battleShip[3] = computerPoint2 + 1;
				battleShip[4] = computerPoint2 + 2;
				battleShip[5] = computerPoint2 + 3;
			}
		}
		/*Vertical*/
		else {                                          
			computerPoint1 = rand() % 7;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 3; z++) {
				if (setUp[z][computerPoint2] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1 + 1][computerPoint2] = 'A';
				setUp[computerPoint1 + 2][computerPoint2] = 'A';
				setUp[computerPoint1 + 3][computerPoint2] = 'A';
				battleShip[0] = computerShipDirection;
				battleShip[1] = computerPoint2;
				battleShip[2] = computerPoint1;
				battleShip[3] = computerPoint1 + 1;
				battleShip[4] = computerPoint1 + 2;
				battleShip[5] = computerPoint1 + 3;
			}


		}

	} while (overLapCheck == 2);
	/*Place Crruiser*/
	do {
		computerShipDirection = rand() % 2 + 1;
		/*Horizontal*/
		if (computerShipDirection == 1) {             
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 8;
			for (int z = computerPoint2; z < computerPoint2 + 2; z++) {
				if (setUp[computerPoint1][z] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1][computerPoint2 + 1] = 'A';
				setUp[computerPoint1][computerPoint2 + 2] = 'A';
				cruiser[0] = computerShipDirection;
				cruiser[1] = computerPoint1;
				cruiser[2] = computerPoint2;
				cruiser[3] = computerPoint2 + 1;
				cruiser[4] = computerPoint2 + 2;
			}
		}
		/*Vertical*/
		else {                                       
			computerPoint1 = rand() % 8;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 2; z++) {
				if (setUp[z][computerPoint2] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1 + 1][computerPoint2] = 'A';
				setUp[computerPoint1 + 2][computerPoint2] = 'A';
				cruiser[0] = computerShipDirection;
				cruiser[1] = computerPoint2;
				cruiser[2] = computerPoint1;
				cruiser[3] = computerPoint1 + 1;
				cruiser[4] = computerPoint1 + 2;
			}

		}
	} while (overLapCheck == 2);
	/*Place Submarine*/
	do {
		computerShipDirection = rand() % 2 + 1;
		/*Horizontal*/
		if (computerShipDirection == 1) {               
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 8;
			for (int z = computerPoint2; z < computerPoint2 + 2; z++) {
				if (setUp[computerPoint1][z] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1][computerPoint2 + 1] = 'A';
				setUp[computerPoint1][computerPoint2 + 2] = 'A';
				submarine[0] = computerShipDirection;
				submarine[1] = computerPoint1;
				submarine[2] = computerPoint2;
				submarine[3] = computerPoint2 + 1;
				submarine[4] = computerPoint2 + 2;
			}


		}
		/*Vertical*/
		else {       
			computerPoint1 = rand() % 8;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 2; z++) {
				if (setUp[z][computerPoint2] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1 + 1][computerPoint2] = 'A';
				setUp[computerPoint1 + 2][computerPoint2] = 'A';
				submarine[0] = computerShipDirection;
				submarine[1] = computerPoint2;
				submarine[2] = computerPoint1;
				submarine[3] = computerPoint1 + 1;
				submarine[4] = computerPoint1 + 2;
			}

		}
	} while (overLapCheck == 2);
	/*Place Patrol*/
	do {
		computerShipDirection = rand() % 2 + 1;
		/*Horizontal*/
		if (computerShipDirection == 1) {              
			computerPoint1 = rand() % 10;
			computerPoint2 = rand() % 9;
			for (int z = computerPoint2; z < computerPoint2 + 1; z++) {
				if (setUp[computerPoint1][z] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1][computerPoint2 + 1] = 'A';
				patrol[0] = computerShipDirection;
				patrol[1] = computerPoint1;
				patrol[2] = computerPoint2;
				patrol[3] = computerPoint2 + 1;
			}


		}
		/*Vertical*/
		else { 
			computerPoint1 = rand() % 9;
			computerPoint2 = rand() % 10;
			for (int z = computerPoint1; z < computerPoint1 + 1; z++) {
				if (setUp[z][computerPoint2] == 'O') {
					overLapCheck = 1;
				}
				else {
					overLapCheck = 2;
					break;
				}
			}
			if (overLapCheck == 1) {
				setUp[computerPoint1][computerPoint2] = 'A';
				setUp[computerPoint1 + 1][computerPoint2] = 'A';
				patrol[0] = computerShipDirection;
				patrol[1] = computerPoint2;
				patrol[2] = computerPoint1;
				patrol[3] = computerPoint1 + 1;
			}

		}
	} while (overLapCheck == 2);
}
/*It Will Print the Status Of the Ships*/
void displayScoreBoard(HANDLE screen, char playerBoard[][COLS], char enemyBoard[][COLS], int rows, int enemyCarrier[], int enemyBattleShip[], int enemyCruiser[], int enemySubmarine[], int enemyPatrol[], int& enemyCarrierAlive, int& enemyBattleShipAlive, int& enemyCruiserAlive, int& enemySubmarineAlive, int& enemyPatrolAlive, int& playerCarrierAlive, int& playerBattleShipAlive, int& playerCruiserAlive, int& playerSubmarineAlive, int& playerPatrolAlive, int playerCarrier[], int playerBattleShip[], int playerCruiser[], int playerSubmarine[], int playerPatrol[]) {

	int size;
	int alive;

	placeCursor(screen, 0, 38);
	cout << "-----Scoreboard-----" << endl; 
	// 1 = Horizontal 2 = Vertical 
	
	/*Enemy Ships*/
	/*This Will Print the Ships Status*/
	placeCursor(screen, 2, 30);
	cout << "Enemy Ships Left: " << endl;
	/*Carrier Status*/
	placeCursor(screen, 3, 30);
	size = 7;
	alive = shipCheck(enemyBoard, ROWS, enemyCarrier, size);
	if (alive == 1) {
		cout << "Carrier " << endl;
		enemyCarrierAlive = 1;
	}
	else {
		cout << "Carrier Destroyed!" << endl;
		enemyCarrierAlive = 0;
	}
	/*Battle Ship Status*/
	placeCursor(screen, 4, 30);
	size = 6;
	alive = shipCheck(enemyBoard, ROWS, enemyBattleShip, size);
	if (alive == 1) {
		cout << "Battle Ship " << endl;
		enemyBattleShipAlive = 1;
	}
	else {
		cout << "Battle Ship Destroyed!" << endl;
		enemyBattleShipAlive = 0;
	}
	/*Cruiser Status*/
	placeCursor(screen, 5, 30);
	size = 5;
	alive = shipCheck(enemyBoard, ROWS, enemyCruiser, size);
	if (alive == 1) {
		cout << "Cruiser " << endl;
		enemyCruiserAlive = 1;
	}
	else {
		cout << "Cruiser Destroyed!" << endl;
		enemyCruiserAlive = 0;
	}
	/*Submarine Status*/
	placeCursor(screen, 6, 30);
	size = 5;
	alive = shipCheck(enemyBoard, ROWS, enemySubmarine, size);
	if (alive == 1) {
		cout << "Submarine " << endl;
		enemySubmarineAlive = 1;
	}
	else {
		cout << "Submarine Destroyed!" << endl;
		enemySubmarineAlive = 0;
	}
	/*Patrol Status*/
	placeCursor(screen, 7, 30);
	size = 4;
	alive = shipCheck(enemyBoard, ROWS, enemyPatrol, size);
	if (alive == 1) {
		cout << "Patrol " << endl;
		enemyPatrolAlive = 1;
	}
	else {
		cout << "Patrol Destroyed!" << endl;
		enemyPatrolAlive = 0;
	}
	/*Player Ships*/
	/*This Will Print the Ships Status*/
	placeCursor(screen, 2, 53);
	cout << "Your Ships Left:" << endl;
	/*Carrier Status*/
	placeCursor(screen, 3, 53);
	size = 7;
	alive = shipCheck(playerBoard, ROWS, playerCarrier, size);
	if (alive == 1) {
		cout << "Carrier" << endl;
		playerCarrierAlive = 1;
	}
	else {
		cout << "Carrier Destroyed!" << endl;
		playerCarrierAlive = 0;
	}
	/*Battle Ship Status*/
	placeCursor(screen, 4, 53);
	size = 6;
	alive = shipCheck(playerBoard, ROWS, playerBattleShip, size);
	if (alive == 1) {
		cout << "Battle Ship" << endl;
		playerBattleShipAlive = 1;
	}
	else {
		cout << "Battle Ship Destroyed!" << endl;
		playerBattleShipAlive = 0;
	}
	/*Cruiser Status*/
	placeCursor(screen, 5, 53);
	size = 5;
	alive = shipCheck(playerBoard, ROWS, playerCruiser, size);
	if (alive == 1) {
		cout << "Cruiser" << endl;
		playerCruiserAlive = 1;
	}
	else {
		cout << "Cruiser Destroyed!" << endl;
		playerCruiserAlive = 0;
	}
	/*Submarine Status*/
	placeCursor(screen, 6, 53);
	size = 5;
	alive = shipCheck(playerBoard, ROWS, playerSubmarine, size);
	if (alive == 1) {
		cout << "Submarine" << endl;
		playerSubmarineAlive = 1;
	}
	else {
		cout << "Submarine Destroyed!" << endl;
		playerSubmarineAlive = 0;
	}
	/*Patrol Status*/
	placeCursor(screen, 7, 53);
	size = 4;
	alive = shipCheck(playerBoard, ROWS, playerPatrol, size);
	if (alive == 1) {
		cout << "Patrol" << endl;
		playerPatrolAlive = 1;
	}
	else {
		cout << "Patrol Destroyed!" << endl;
		playerPatrolAlive = 0;
	}
}
/*It Will Place the Ship Where We Want*/
void placeCursor(HANDLE screen, int row, int col) {
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}
//This function lets the player shoot at a point
void playerTurn(HANDLE screen, char enemyMap[][COLS], char enemyDisplayMap[][COLS], int rows) {
	string attack;
	int attack1, attack2, errorCount = 0;
	char holder;
	placeCursor(screen, 15, 30);
	cout << "Choose which point you would like to attack." << endl;
	stringInputCheck(screen, attack, attack1, attack2, 16, 30);
	holder = enemyMap[attack1][attack2];
	while (holder == 'M' || holder == 'X') {
		placeCursor(screen, 13, 30);
		cout << "You already attacked there!" << endl;
		placeCursor(screen, 17, 30);
		cout << "                    " << endl;
		stringInputCheck(screen, attack, attack1, attack2, 16, 30);
		holder = enemyMap[attack1][attack2];
	}
	if (holder == 'A') {
		enemyMap[attack1][attack2] = 'X';
		enemyDisplayMap[attack1][attack2] = 'X';
		system("CLS");
		placeCursor(screen, 23, 30);
		cout << "Direct hit!" << endl;
	}
	else {
		enemyMap[attack1][attack2] = 'M';
		enemyDisplayMap[attack1][attack2] = 'M';
		system("CLS");
		placeCursor(screen, 23, 30);
		cout << "You missed!" << endl;
	}
}
//This function lets the computer shoot at a point
void enemyTurn(HANDLE screen, char playerMap[][COLS], int rows, int difficulty) {
	//AI                                                functions that lets the computer have its turn
	srand(time(0));
	//Computer(Medium);
	static char computerLastAttack1, computerLastAttack2, computerMemory = 'O';
	int computerAttack1, computerAttack2, computerNewAttack1, computerNewAttack2;
	char computerHolder;
	if (difficulty == 2) {
		if (computerMemory == 'O') {
			computerAttack1 = rand() % 10;
			computerAttack2 = rand() % 10;
			computerHolder = playerMap[computerAttack1][computerAttack2];
			while (computerHolder == 'M' || computerHolder == 'X') {
				computerAttack1 = rand() % 10;
				computerAttack2 = rand() % 10;
				computerHolder = playerMap[computerAttack1][computerAttack2];
			}
			if (computerHolder == 'A') {
				playerMap[computerAttack1][computerAttack2] = 'X';
				placeCursor(screen, 24, 30);
				cout << "Computer(Medium) got a Direct hit!" << endl;
			}
			else {
				playerMap[computerAttack1][computerAttack2] = 'M';
				placeCursor(screen, 24, 30);
				cout << "Computer(Medium) missed!" << endl;
			}
			computerLastAttack1 = computerAttack1;
			computerLastAttack2 = computerAttack2;
			computerMemory = computerHolder;
		}
		//Computer Logic
		else {
			//Top Left Corner
			if (computerLastAttack1 == 0 && computerLastAttack2 == 0) {
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 + 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Bottom Right Corner
			else if (computerLastAttack1 == 9 && computerLastAttack2 == 9) {
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 - 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2 + 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Top Right Corner
			else if (computerLastAttack1 == 0 && computerLastAttack2 == 9) {
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 - 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2 + 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Bottom Left Corner
			else if (computerLastAttack1 == 9 && computerLastAttack2 == 0) {
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 + 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Top Wall
			else if (computerLastAttack1 == 0) {
				if (computerLastAttack2 == 9) {
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
				}
				else {
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 + 1;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Left Wall
			else if (computerLastAttack2 == 0) {
				if (computerLastAttack1 == 9) {
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
				}
				else {
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 + 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Right Wall
			else if (computerLastAttack2 == 9) {
				if (computerLastAttack1 == 8) {
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
				}
				else {
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//Bottom Wall
			else if (computerLastAttack1 == 9) {
				if (computerLastAttack2 == 8) {
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
				}
				else {
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 + 1;
				}
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}
			}
			//anywhere else on map
			else {
				computerNewAttack1 = computerLastAttack1;
				computerNewAttack2 = computerLastAttack2 + 1;
				computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1;
					computerNewAttack2 = computerLastAttack2 - 1;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				else if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 - 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				else if (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = computerLastAttack1 + 1;
					computerNewAttack2 = computerLastAttack2;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				while (computerHolder == 'M' || computerHolder == 'X') {
					computerNewAttack1 = rand() % 10;
					computerNewAttack2 = rand() % 10;
					computerHolder = playerMap[computerNewAttack1][computerNewAttack2];
				}
				if (computerHolder == 'A') {
					playerMap[computerNewAttack1][computerNewAttack2] = 'X';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) got a Direct hit!" << endl;
				}
				else {
					playerMap[computerNewAttack1][computerNewAttack2] = 'M';
					placeCursor(screen, 24, 30);
					cout << "Computer(Medium) missed!" << endl;
				}

			}
		}
	}
	//Computer(Easy);
	else {
		computerAttack1 = rand() % 10;
		computerAttack2 = rand() % 10;
		computerHolder = playerMap[computerAttack1][computerAttack2];
		while (computerHolder == 'M' || computerHolder == 'X') {
			computerAttack1 = rand() % 10;
			computerAttack2 = rand() % 10;
			computerHolder = playerMap[computerAttack1][computerAttack2];
		}
		if (computerHolder == 'A') {
			playerMap[computerAttack1][computerAttack2] = 'X';
			placeCursor(screen, 24, 30);
			cout << "Computer(Easy) got a Direct hit!" << endl;
		}
		else {
			playerMap[computerAttack1][computerAttack2] = 'M';
			placeCursor(screen, 24, 30);
			cout << "Computer(Easy) missed!" << endl;
		}
	}

}
//This function checks if there are any ships left
int winCondition(int enemy, int player) {

	if (enemy == 0) {
		return 2;
	}
	else if (player == 0) {
		return 3;
	}
	else {
		return 1;
	}
}

//This function checks which ships are alive or dead when called                
int shipCheck(char board[][COLS], int rows, int ship[], int size) {

	int holder;

	if (ship[0] == 1) {
		for (int x = 2; x < size; x++) {
			if (board[ship[1]][ship[x]] == 'A') {
				holder = 1;
				break;
			}
			else {
				holder = 2;
			}
		}
	}
	else {
		for (int x = 2; x < size; x++) {
			if (board[ship[x]][ship[1]] == 'A') {
				holder = 1;
				break;
			}
			else {
				holder = 2;
			}
		}
	}
	return holder;
}
//This function validates the player choice of where to attack
void stringInputCheck(HANDLE screen, string attack, int &attack1, int &attack2, int row, int col) {

	int errorCount = 0;

	do {
		if (errorCount > 0) {
			placeCursor(screen, row + 1, col);
			cout << "                       " << endl;
		}
		placeCursor(screen, row, col);
		cout << "Please type the letter first followed by" << endl;
		placeCursor(screen, row + 1, col);
		cout << "the number: ";
		cin.ignore();
		cin >> attack;
		errorCount++;
	} while (!(attack == "a0" || attack == "a1" || attack == "a2" || attack == "a3" || attack == "a4" || attack == "a5" || attack == "a6" || attack == "a7" || attack == "a8" || attack == "a9" || attack == "b0" || attack == "b1" || attack == "b2" || attack == "b3" || attack == "b4" || attack == "b5" || attack == "b6" || attack == "b7" || attack == "b8" || attack == "b9" || attack == "c0" || attack == "c1" || attack == "c2" || attack == "c3" || attack == "c4" || attack == "c5" || attack == "c6" || attack == "c7" || attack == "c8" || attack == "c9" || attack == "d0" || attack == "d1" || attack == "d2" || attack == "d3" || attack == "d4" || attack == "d5" || attack == "d6" || attack == "d7" || attack == "d8" || attack == "d9" || attack == "e0" || attack == "e1" || attack == "e2" || attack == "e3" || attack == "e4" || attack == "e5" || attack == "e6" || attack == "e7" || attack == "e8" || attack == "e9" || attack == "f0" || attack == "f1" || attack == "f2" || attack == "f3" || attack == "f4" || attack == "f5" || attack == "f6" || attack == "f7" || attack == "f8" || attack == "f9" || attack == "g0" || attack == "g1" || attack == "g2" || attack == "g3" || attack == "g4" || attack == "g5" || attack == "g6" || attack == "g7" || attack == "g8" || attack == "g9" || attack == "h0" || attack == "h1" || attack == "h2" || attack == "h3" || attack == "h4" || attack == "h5" || attack == "h6" || attack == "h7" || attack == "h8" || attack == "h9" || attack == "i0" || attack == "i1" || attack == "i2" || attack == "i3" || attack == "i4" || attack == "i5" || attack == "i6" || attack == "i7" || attack == "i8" || attack == "i9" || attack == "j0" || attack == "j1" || attack == "j2" || attack == "j3" || attack == "j4" || attack == "j5" || attack == "j6" || attack == "j7" || attack == "j8" || attack == "j9"));

	if (attack == "a0") {
		attack1 = 0;
		attack2 = 0;
	}
	if (attack == "a1") {
		attack1 = 0;
		attack2 = 1;
	}
	if (attack == "a2") {
		attack1 = 0;
		attack2 = 2;
	}
	if (attack == "a3") {
		attack1 = 0;
		attack2 = 3;
	}
	if (attack == "a4") {
		attack1 = 0;
		attack2 = 4;
	}
	if (attack == "a5") {
		attack1 = 0;
		attack2 = 5;
	}
	if (attack == "a6") {
		attack1 = 0;
		attack2 = 6;
	}
	if (attack == "a7") {
		attack1 = 0;
		attack2 = 7;
	}
	if (attack == "a8") {
		attack1 = 0;
		attack2 = 8;
	}
	if (attack == "a9") {
		attack1 = 0;
		attack2 = 9;
	}
	if (attack == "b0") {
		attack1 = 1;
		attack2 = 0;
	}
	if (attack == "b1") {
		attack1 = 1;
		attack2 = 1;
	}
	if (attack == "b2") {
		attack1 = 1;
		attack2 = 2;
	}
	if (attack == "b3") {
		attack1 = 1;
		attack2 = 3;
	}
	if (attack == "b4") {
		attack1 = 1;
		attack2 = 4;
	}
	if (attack == "b5") {
		attack1 = 1;
		attack2 = 5;
	}
	if (attack == "b6") {
		attack1 = 1;
		attack2 = 6;
	}
	if (attack == "b7") {
		attack1 = 1;
		attack2 = 7;
	}
	if (attack == "b8") {
		attack1 = 1;
		attack2 = 8;
	}
	if (attack == "b9") {
		attack1 = 1;
		attack2 = 9;
	}
	if (attack == "c0") {
		attack1 = 2;
		attack2 = 0;
	}
	if (attack == "c1") {
		attack1 = 2;
		attack2 = 1;
	}
	if (attack == "c2") {
		attack1 = 2;
		attack2 = 2;
	}
	if (attack == "c3") {
		attack1 = 2;
		attack2 = 3;
	}
	if (attack == "c4") {
		attack1 = 2;
		attack2 = 4;
	}
	if (attack == "c5") {
		attack1 = 2;
		attack2 = 5;
	}
	if (attack == "c6") {
		attack1 = 2;
		attack2 = 6;
	}
	if (attack == "c7") {
		attack1 = 2;
		attack2 = 7;
	}
	if (attack == "c8") {
		attack1 = 2;
		attack2 = 8;
	}
	if (attack == "c9") {
		attack1 = 2;
		attack2 = 9;
	}
	if (attack == "d0") {
		attack1 = 3;
		attack2 = 0;
	}
	if (attack == "d1") {
		attack1 = 3;
		attack2 = 1;
	}
	if (attack == "d2") {
		attack1 = 3;
		attack2 = 2;
	}
	if (attack == "d3") {
		attack1 = 3;
		attack2 = 3;
	}
	if (attack == "d4") {
		attack1 = 3;
		attack2 = 4;
	}
	if (attack == "d5") {
		attack1 = 3;
		attack2 = 5;
	}
	if (attack == "d6") {
		attack1 = 3;
		attack2 = 6;
	}
	if (attack == "d7") {
		attack1 = 3;
		attack2 = 7;
	}
	if (attack == "d8") {
		attack1 = 3;
		attack2 = 8;
	}
	if (attack == "d9") {
		attack1 = 3;
		attack2 = 9;
	}
	if (attack == "e0") {
		attack1 = 4;
		attack2 = 0;
	}
	if (attack == "e1") {
		attack1 = 4;
		attack2 = 1;
	}
	if (attack == "e2") {
		attack1 = 4;
		attack2 = 2;
	}
	if (attack == "e3") {
		attack1 = 4;
		attack2 = 3;
	}
	if (attack == "e4") {
		attack1 = 4;
		attack2 = 4;
	}
	if (attack == "e5") {
		attack1 = 4;
		attack2 = 5;
	}
	if (attack == "e6") {
		attack1 = 4;
		attack2 = 6;
	}
	if (attack == "e7") {
		attack1 = 4;
		attack2 = 7;
	}
	if (attack == "e8") {
		attack1 = 4;
		attack2 = 8;
	}
	if (attack == "e9") {
		attack1 = 4;
		attack2 = 9;
	}
	if (attack == "f0") {
		attack1 = 5;
		attack2 = 0;
	}
	if (attack == "f1") {
		attack1 = 5;
		attack2 = 1;
	}
	if (attack == "f2") {
		attack1 = 5;
		attack2 = 2;
	}
	if (attack == "f3") {
		attack1 = 5;
		attack2 = 3;
	}
	if (attack == "f4") {
		attack1 = 5;
		attack2 = 4;
	}
	if (attack == "f5") {
		attack1 = 5;
		attack2 = 5;
	}
	if (attack == "f6") {
		attack1 = 5;
		attack2 = 6;
	}
	if (attack == "f7") {
		attack1 = 5;
		attack2 = 7;
	}
	if (attack == "f8") {
		attack1 = 5;
		attack2 = 8;
	}
	if (attack == "f9") {
		attack1 = 5;
		attack2 = 9;
	}
	if (attack == "g0") {
		attack1 = 6;
		attack2 = 0;
	}
	if (attack == "g1") {
		attack1 = 6;
		attack2 = 1;
	}
	if (attack == "g2") {
		attack1 = 6;
		attack2 = 2;
	}
	if (attack == "g3") {
		attack1 = 6;
		attack2 = 3;
	}
	if (attack == "g4") {
		attack1 = 6;
		attack2 = 4;
	}
	if (attack == "g5") {
		attack1 = 6;
		attack2 = 5;
	}
	if (attack == "g6") {
		attack1 = 6;
		attack2 = 6;
	}
	if (attack == "g7") {
		attack1 = 6;
		attack2 = 7;
	}
	if (attack == "g8") {
		attack1 = 6;
		attack2 = 8;
	}
	if (attack == "g9") {
		attack1 = 6;
		attack2 = 9;
	}
	if (attack == "h0") {
		attack1 = 7;
		attack2 = 0;
	}
	if (attack == "h1") {
		attack1 = 7;
		attack2 = 1;
	}
	if (attack == "h2") {
		attack1 = 7;
		attack2 = 2;
	}
	if (attack == "h3") {
		attack1 = 7;
		attack2 = 3;
	}
	if (attack == "h4") {
		attack1 = 7;
		attack2 = 4;
	}
	if (attack == "h5") {
		attack1 = 7;
		attack2 = 5;
	}
	if (attack == "h6") {
		attack1 = 7;
		attack2 = 6;
	}
	if (attack == "h7") {
		attack1 = 7;
		attack2 = 7;
	}
	if (attack == "h8") {
		attack1 = 7;
		attack2 = 8;
	}
	if (attack == "h9") {
		attack1 = 7;
		attack2 = 9;
	}
	if (attack == "i0") {
		attack1 = 8;
		attack2 = 0;
	}
	if (attack == "i1") {
		attack1 = 8;
		attack2 = 1;
	}
	if (attack == "i2") {
		attack1 = 8;
		attack2 = 2;
	}
	if (attack == "i3") {
		attack1 = 8;
		attack2 = 3;
	}
	if (attack == "i4") {
		attack1 = 8;
		attack2 = 4;
	}
	if (attack == "i5") {
		attack1 = 8;
		attack2 = 5;
	}
	if (attack == "i6") {
		attack1 = 8;
		attack2 = 6;
	}
	if (attack == "i7") {
		attack1 = 8;
		attack2 = 7;
	}
	if (attack == "i8") {
		attack1 = 8;
		attack2 = 8;
	}
	if (attack == "i9") {
		attack1 = 8;
		attack2 = 9;
	}
	if (attack == "j0") {
		attack1 = 9;
		attack2 = 0;
	}
	if (attack == "j1") {
		attack1 = 9;
		attack2 = 1;
	}
	if (attack == "j2") {
		attack1 = 9;
		attack2 = 2;
	}
	if (attack == "j3") {
		attack1 = 9;
		attack2 = 3;
	}
	if (attack == "j4") {
		attack1 = 9;
		attack2 = 4;
	}
	if (attack == "j5") {
		attack1 = 9;
		attack2 = 5;
	}
	if (attack == "j6") {
		attack1 = 9;
		attack2 = 6;
	}
	if (attack == "j7") {
		attack1 = 9;
		attack2 = 7;
	}
	if (attack == "j8") {
		attack1 = 9;
		attack2 = 8;
	}
	if (attack == "j9") {
		attack1 = 9;
		attack2 = 9;
	}
}

