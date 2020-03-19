#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <windows.h>
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

/* Global variables */

// Date management
unsigned short year = 0, month = 0, day = 0;

const string months[12] = {
	"January", "Feburary", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};

const int daysOfMonth[12] = {
	31, 28, 31, 30, 31, 30, 
	31, 31, 30, 31, 30, 31
};

const int daysOfLeapMonth[12] = {
	31, 29, 31, 30, 31, 30, 
	31, 31, 30, 31, 30, 31
};

// Hotel Room Management
int room_selected;

const int room_type_count = 6;

int rooms_occupied[room_type_count] = {
	0,		// Standard 1 Bedroom
	0,		// Standard 2 Bedroom
	0,		// Deluxe 1 Bedroom
	0,		// Premier 2 Bedroom
	0,		// Premier 3 Bedroom
	0		// Premier 4 Bedroom
};

const short rooms_max[room_type_count] = {
	15,		// Standard 1 Bedroom
	15,		// Standard 2 Bedroom
	8,		// Deluxe 1 Bedroom
	6,		// Premier 2 Bedroom
	4,		// Premier 3 Bedroom
	4		// Premier 4 Bedroom
};

const short room_capacity[room_type_count] = {
	2,		// Standard 1 Bedroom
	4,		// Standard 2 Bedroom
	3,		// Deluxe 1 Bedroom
	5,		// Premier 2 Bedroom
	7,		// Premier 3 Bedroom
	8		// Premier 4 Bedroom
};

const short room_capacity_children[room_type_count] = {
	1,		// Standard 1 Bedroom
	2,		// Standard 2 Bedroom
	2,		// Deluxe 1 Bedroom
	3,		// Premier 2 Bedroom
	2,		// Premier 3 Bedroom
	2		// Premier 4 Bedroom
};

float rooms_price[room_type_count] = {
	2500,	// Standard 1 Bedroom
	3500,	// Standard 2 Bedroom
	3000,	// Deluxe 1 Bedroom
	4500,	// Premier 2 Bedroom
	6500,	// Premier 3 Bedroom
	7000	// Premier 4 Bedroom
};

string room_name[room_type_count] = {
	"Standard 1 Bedroom",	// Standard 1 Bedroom
	"Standard 2 Bedroom",	// Standard 2 Bedroom
	"Deluxe 1 Bedroom",		// Deluxe 1 Bedroom
	"Premier 2 Bedroom",	// Premier 2 Bedroom
	"Premier 3 Bedroom",	// Premier 3 Bedroom
	"Premier 4 Bedroom"		// Premier 4 Bedroom
};

// Room occupied management
bool roomsOccupied[6][20] = {
	{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
	{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
	{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
	{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
	{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false},
	{false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}
};

// Reservation codes
string discount_15_off[] = {
	"d15off", "ennowan", "itamlaunch"
};

string discount_20_off[] = {
	"d20off", "feutech"
};

/* Function Prototypes */
void setup();
void reserve_page();

int reservation();
int splash();
int logo_tab();
int home_menu ();
int logo ();
int tab();
int home();
int rooms();
int facilities ();
int promos();
int about_us();
int bottom_room_choice1();
int bottom_room_choice2();
int bottom_promo_choice1();
int bottom_promo_choice2();
int final_bottom_option();
int program_exit();

void syscls() {
	system("cls");
}

void gotoxy (short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);
}

int main () {
	system("color 2e");
	//setup();
	//splash();
	home();
	return 0;
}

int splash() {
	gotoxy (40, 1);cout << "                  ***                    " << endl;
	gotoxy (40, 2);cout << "               *********                 " << endl;
	gotoxy (40, 3);cout << "             ************                " << endl;
	gotoxy (40, 4);cout << "             |#********* | **            " << endl;
	gotoxy (40, 5);cout << "             |####***    |   **          " << endl;
	gotoxy (40, 6);cout << "             |#####|     |     **        " << endl;
	gotoxy (40, 7);cout << "             **####|    **   ** |        " << endl;
	gotoxy (40, 8);cout << "               **##|  **   **   |        " << endl;
	gotoxy (40, 9);cout << "               ** ***    **     |        " << endl;
	gotoxy (40, 10);cout << "             **       **        |        " << endl;
	gotoxy (40, 11);cout << "           **       **         **        " << endl;
	gotoxy (40, 12);cout << "         **       **         **          " << endl;
	gotoxy (40, 13);cout << "       **       **         **            " << endl;
	gotoxy (40, 14);cout << "       |#**   **          *              " << endl;
	gotoxy (40, 15);cout << "       |###***           |               " << endl;
	gotoxy (40, 16);cout << "       |####|            |               " << endl;
	gotoxy (40, 17);cout << "       |####|     *|     |               " << endl;
	gotoxy (40, 18);cout << "       **###|   **#|     |               " << endl;
	gotoxy (40, 19);cout << "         **#| **###|     |               " << endl;
	gotoxy (40, 20);cout << "           ***#####|     |               " << endl;
	gotoxy (40, 21);cout << "             |#####|     |               " << endl;
	gotoxy (40, 22);cout << "             |#####|     |               " << endl;
	gotoxy (40, 23);cout << "             **####|    **               " << endl;
	gotoxy (40, 24);cout << "               **##|  **                 " << endl;
	gotoxy (40, 25);cout << "                  ***                    " << endl;
	
	gotoxy (42, 29);cout << "                                         " << endl;
	gotoxy (42, 30);cout << "     @  ---+---    /\\     |\\    /|     " << endl;
	gotoxy (42, 31);cout << "           |      /  \\    | \\  / |     " << endl;
	gotoxy (42, 32);cout << "     |     |     |====|   |  \\/  |      " << endl;
	gotoxy (42, 33);cout << "     |     |     |    |   |      |       " << endl;
	gotoxy (42, 34);cout << "                                         " << endl;
	gotoxy (42, 35);cout << "                                         " << endl;
	gotoxy (42, 36);cout << "   +--   + +   -+-   -+-   +--   +--     " << endl;
	gotoxy (42, 37);cout << "   |     | |    |     |    |     |       " << endl;
	gotoxy (42, 38);cout << "   +-+   | |    |     |    +--   +-+     " << endl;
	gotoxy (42, 39);cout << "     |   | |    |     |    |       |     " << endl;
	gotoxy (42, 40);cout << "   --+   +-+   -+-    +    +--   --+     " << endl;
	
	Sleep (4000);

	return 0;
}

int logo_tab()
{
	logo();
	tab();
	
}

int home_menu ()
{
	char menu_choice;
	
	gotoxy (10, 10); cout << "[1] HOME";
	gotoxy (24, 10); cout << "[2] ROOMS";
	gotoxy (39, 10); cout << "[3] FACILITIES";
	gotoxy (59, 10); cout << "[4] PROMOS";
	gotoxy (75, 10); cout << "[5] RESERVATION";
	gotoxy (96, 10); cout << "[6] ABOUT US";
	
	cout << endl << endl;
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (50, 13); cout << "I T A M S U I T E S\n\n\n";
	SetConsoleTextAttribute(color, 0x2E);
	cout << endl << endl;
	gotoxy (30, 15); cout << "iTam Suites is a place designed to make customers feel like they are";
	gotoxy (25, 16); cout << "at home yet feel a world away from life\'s bustle as each short retreat is ";
	gotoxy (25, 17); cout << "transformed into the perfect escape.";
	
	gotoxy (30, 19); cout << "Indulge in an affordable holiday made more delightful with an array ";
	gotoxy (25, 20); cout << "of practical treats offered in-room. Utilize our first class facilities by";
	gotoxy (25, 21); cout << "holding productive conversations in our deluxe function hall or in our res-";
	gotoxy (25, 22); cout << "taurant that serves delectable dishes. Prioritize your own welfare by swimming";
	gotoxy (25, 23); cout << "or hitting the gym. Pamper yourself with relaxing treatments at our spa.";
	
	//TERMS AND CONDITIONS
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (39, 27); cout << "T E R M S  A N D  C O N D I T I O N S";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (20, 29); cout << "1. Strictly follow the number of guests to check-in that corresponds";
	gotoxy (20, 30); cout << "   to the capacity of the availed room.";
	gotoxy (20, 31); cout << "2. The room inspection before checking out will be mandated by the";
	gotoxy (20, 32); cout << "   management to assure all furnitures in the room are not damaged";
	gotoxy (20, 33); cout << "   by the guests";
	gotoxy (20, 34); cout << "3. Breakfast stabs are strictly not passable to other guests that have";
	gotoxy (20, 35); cout << "   accomodated other rooms.";
	gotoxy (20, 36); cout << "4. Present two valid IDs for security and verification purposes.";
	gotoxy (20, 37); cout << "5. Unruly behavior and bad conduct could subject to the guest(s) being";
	gotoxy (20, 38); cout << "   banned from the hotel's premises.";
	gotoxy (20, 39); cout << "6. Personal data gathered for record purposes during reservation will be";
	gotoxy (20, 40); cout << "   kept confidential and secured in our system.";
	gotoxy (20, 41); cout << "7. Payment must be made a day or two after reservation (Credit Card and Cash ONLY).";
	gotoxy (20, 42); cout << "8. Strictly no pets are allowed inside the premises.";
	gotoxy (20, 43); cout << "9. Deadly weapons and flammable products will be confiscated by the administration.";
	gotoxy (20, 44); cout << "10. Do not take home the products seen inside the rooms and facilities.";	
	
	cout << "\n\n[X] Exit program" << endl;
	cout << "Enter choice: ";
	cin >> menu_choice;
	
	while (menu_choice != '1' && menu_choice != '2' && menu_choice != '3' && menu_choice != '4' && menu_choice != '5' &&
			menu_choice != '6' && menu_choice != '7' && menu_choice != 'x' && menu_choice != 'X') {
		cout << "\nINVALID INPUT. TRY AGAIN" << endl;
		cout << "Enter choice: ";
		cin >> menu_choice;
	}
	
	switch (menu_choice)
	{
		case '1':
			home ();
			break;
		case '2':
			rooms ();
			break;
		case '3':
			facilities ();
			break;
		case '4':
			promos ();
			break;
		case '5':
			reserve_page();
			break;
		case '6':
			about_us ();
			break;
		case 'x':
		case 'X':
			syscls();
			program_exit();
			syscls();
			splash();
			exit(0);
			break;
			
	}
	return 0;
}

int logo ()
{
	syscls();
	gotoxy (35, 0); cout << "________________________________________________ " << endl;
    gotoxy (35, 1); cout << "|     _____                                    | " << endl;
	gotoxy (35, 2); cout << "|     |___|       _____  _____  ___    __   __ | " << endl;
	gotoxy (35, 3); cout << "|   _________       |      |   /___\\   | \\ / | | " << endl;
	gotoxy (35, 4); cout << "|   |2 0 1 9|     __|__    |   |   |   |  V  | | " << endl;
	gotoxy (35, 5); cout << "|   |__   __|     ____      ___ ___ ___ ___    | " << endl;
	gotoxy (35, 6); cout << "|     |   |       |__  |  |  |   |  |_  |__    | " << endl;
	gotoxy (35, 7); cout << "|     |___|       ___| |__| _|_  |  |__ ___|   | " << endl;
	gotoxy (35, 8); cout << "|______________________________________________| " << endl;
	return 0;
}

int tab()
{
	gotoxy (10, 10); cout << "[1] HOME";
	gotoxy (24, 10); cout << "[2] ROOMS";
	gotoxy (39, 10); cout << "[3] FACILITIES";
	gotoxy (59, 10); cout << "[4] PROMOS";
	gotoxy (75, 10); cout << "[5] RESERVATION";
	gotoxy (96, 10); cout << "[6] ABOUT US\n\n\n";
}

int home ()
{
	logo ();
	home_menu ();
}

int rooms () {
	syscls();
	
	logo_tab();
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (53, 13); cout << "R  O  O  M  S\n\n";
	gotoxy (10, 16); cout << "TYPES";
	gotoxy (54, 16); cout << "DESCRIPTION";
	gotoxy (98, 16); cout << "PRICE";
	gotoxy (95, 17); cout << "(per night)";
			
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (2, 19); cout << "[A] Standard 1 Bedroom";
	gotoxy (2, 20); cout << "(" <<  rooms_max[0] - rooms_occupied[0] << " available room/s left)";
	gotoxy (35, 19); cout << "A room designed for three people. Has one bedroom";
	gotoxy (92, 19); cout << "P2,500 + tax/night";
	gotoxy (35, 20); cout << "with one bed.";
	gotoxy (35, 21); cout << "It can accommodate 2 adults and 1 children."; 
			
	gotoxy (2, 23); cout << "[B] Standard 2 Bedroom";
	gotoxy (2, 24); cout << "(" <<  rooms_max[1] - rooms_occupied[1] << " available room/s left)";
	gotoxy (35, 23); cout << "A room with two bedrooms and a living room.";
	gotoxy (92, 23); cout << "P3,500 + tax/night";
	gotoxy (35, 24); cout << "It can accommodate 4 adults and 2 children.";
			
	gotoxy (2, 26); cout << "[C] Deluxe 1 Bedroom";
	gotoxy (2, 27); cout << "(" <<  rooms_max[2] - rooms_occupied[2] << " available room/s left)";
	gotoxy (35, 26); cout << "A room with a studio bed -- a couch that can be";
	gotoxy (92, 26); cout << "P3,000 + tax/night";
	gotoxy (35, 27); cout << "converted into a bed. May have an additonal bed.";
	gotoxy (35, 28); cout << "It can accommodate 3 adults and 2 children.";
			
	gotoxy (2, 30); cout << "[D] Premier 2 Bedroom";
	gotoxy (2, 31); cout << "(" <<  rooms_max[3] - rooms_occupied[3] << " available room/s left)";
	gotoxy (35, 30); cout << "A parlour or living room connected to one or more";
	gotoxy (92, 30); cout << "P4,500 + tax/night";
	gotoxy (35, 31); cout << "bedrooms. Includes living room and a mini bar.";
	gotoxy (35, 32); cout << "It can accommodate 5 adults and 3 children.";
			
	gotoxy (2, 34); cout << "[E] Premier 3 Bedroom";
	gotoxy (2, 35); cout << "(" <<  rooms_max[4] - rooms_occupied[4] << " available room/s left)";
	gotoxy (35, 34); cout << "A premier room that is connected to three bedrooms,";
	gotoxy (92, 34); cout << "P6,500 + tax/night";
	gotoxy (35, 35); cout << "has a living room, private king-sized ";
	gotoxy (35, 36); cout << "bed and a mini bar";
	gotoxy (35, 37); cout << "It can accommodate 7 adults and 2 children.";
	
	gotoxy (2, 39); cout << "[F] Premier 4 Bedroom";
	gotoxy (2, 40); cout << "(" <<  rooms_max[5] - rooms_occupied[5] << " available room/s left)";
	gotoxy (35, 39); cout << "A premier room that is connected to four bedrooms,";
	gotoxy (92, 39); cout << "P7,800 + tax/night";
	gotoxy (35, 40); cout << "has a living room, private king-sized bed a mini";
	gotoxy (35, 41); cout << "bar. You can choose the penthouse view.";
	gotoxy (35, 42); cout << "It can accommodate 8 adults and 2 children.";
	
	bottom_room_choice1();
	return 0;
}

int facilities ()
{
	syscls();
	logo_tab();
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (48, 13); cout << "F  A  C  I  L  I  T  I  E  S";
	
	gotoxy (10, 16); cout << "Upheaval Room";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (18, 18); cout << "A large room where formal dinners or parties can be held. It is ideal for business ";
	gotoxy (18, 19); cout << "conferences and special occasions. The function room has a modern sound system and ";
	gotoxy (18, 20); cout << "a bar. The function room can be adapted for many different types of events.";
	
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (10, 22); cout << "iTam Server";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (18, 24); cout << "iTam Server is an indoor trendy restaurant that opens to an outdoor terrace with ";
	gotoxy (18, 25); cout << "four gazeebos leading to the iconic lagoon shape poolside the hotel is famous for. ";
	gotoxy (18, 26); cout << "One could literally watch the sun, the moon and the stars in the sky from the cei- ";
	gotoxy (18, 27); cout << "ling in the comfort of a glass enclosed lounge.";

	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (10, 29); cout << "Case Lounge";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (18, 31); cout << "Case Lounge is a haven combining a bistro, patisserie and library. It offers a French "; 
	gotoxy (18, 32); cout << "bistro a la carte menu set in a plush lounge of stylish elegance with mahogany interiors, ";
	gotoxy (18, 33); cout << "deep brown leather seats and the rich interplay of visual textures. Intimate evening ga- ";
	gotoxy (18, 34); cout << "therings are enhanced by live musical entertainment as guests indulge in Case Lounge\'s ";
	gotoxy (18, 35); cout << "wealth of gastronomic offerings.";

	SetConsoleTextAttribute(color, 0xE2);	
	gotoxy (10, 37); cout << "Major Gym";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (18, 39); cout << "Major Gym provides holistic, up-to-the-minute wellness programs with the finest cardio ";
	gotoxy (18, 40); cout << "machines from Life Fitness. Free weights and training machine, Kinesis are available for ";
	gotoxy (18, 41); cout << "an invigorating full-body workout. Featured group classes such as yoga, Zumba and boxing ";
	gotoxy (18, 42); cout << "are available in the aero studio for alternative workout options. A sanctuary for health, ";
	gotoxy (18, 43); cout << "wellness and desired fitness, Major offers membership packages to meet clients\' unique ";
	gotoxy (18, 44); cout << "requirements. Major\'s fitness experts are on hand daily to assist in achieving optimum ";
	gotoxy (18, 45); cout << "physical performance. Kinesis restores the proper balance between mind and body, thereby ";
	gotoxy (18, 46); cout << "helping to improve quality of life. Private instruction may be arranged.";
	
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (10, 48); cout << "Sparadise";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (18, 50); cout << "A wellness sanctuary where refined French elegance and the warm Filipino touch revive the ";
	gotoxy (18, 51); cout << "mind, body and spirit, Sparadise treatments ranging from traditional eastern to modern western";
	gotoxy (18, 52); cout << "techniques, Sparadise is home to novelties including the Filipino ancient art of healing - the ";
	gotoxy (18, 53); cout << "Hilot Secret. Weaving harmony within natural elements such as Philippine shells, dark wood and ";
	gotoxy (18, 54); cout << "earth accents to serve as an oasis for the soul,Sparadise\'s interior mix with modern facilities";
	gotoxy (18, 55); cout << "ensure the most luxurious wellness escape. An opulent lounge, dry and wet sauna, foot massage ";
	gotoxy (18, 56); cout << "nine treatment suites that include a duo suite with huge bath tub, and a spa suite create an ";
	gotoxy (18, 57); cout << "area, unforgettable experience of rest, relaxation and rejuvenation.";
	
	final_bottom_option();
	return 0;
}

int promos ()
{
	syscls();
	logo_tab();
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (54, 13); cout << "P  R  O  M  O  S";
	
	gotoxy (42, 15); cout << "CHOOSE A PROMO TO REVEAL THE PROMO CODE";
	SetConsoleTextAttribute(color, 0x2E);
	
	gotoxy (32, 18); cout << "[A] Free Red Wine in our Standard 1 Bedroom Suites (November 5)";
	gotoxy (32, 20); cout << "[B] Free Massage in our Deluxe 1 Bedroom Suites (November 5-10)";
	gotoxy (32, 22); cout << "[C] 20\% off on all our rooms (October 31-November 15)";
	gotoxy (32, 24); cout << "[D] Your 4th night is on us (November 5-20)";
	gotoxy (32, 26); cout << "[E] Early Bird Promo (30 days before the check-in date";
	gotoxy (36, 27); cout << "Available until June 2020)";
	bottom_promo_choice1();
	return 0;
}

int reservation() {

	cout << fixed << setprecision(2);
	syscls();
	logo_tab();
	
	// Customer Input
	
	string name, discount_code, entry;
	float discount = 0.0f, total_price = 0.0f;
	int room_price, last_room, room_number;
	short reserveYear, reserveMonth, reserveDay, stayUntilYear, stayUntilMonth, stayUntilDay, nights;

	for(int i = 1; i <= rooms_max[room_selected]; i++) {
		if(!roomsOccupied[room_selected][i-1]) {
			last_room = i;
			break;
		}
	}
	
	room_price = rooms_price[room_selected];
	room_number = ((room_selected + 1) * 100) + (last_room);
	
	cout << "You will now be reserving the room " << room_number << "." << endl;
	cout << "Enter your name: ";
	cin.ignore();
	getline(cin, name);

	syscls();
	logo_tab();

	cout << "Hello, " << name << "!" << endl;

	bool isAnswerValid = false;
	string input;

	do {
		input = "";
		cout << "Enter year of reservation (" << year<< " - " << year + 5 << ", or enter for current year): ";
		getline(cin, input);

		if(input.empty()) {
			reserveYear = year;
			isAnswerValid = true;
		} else {
			istringstream(input) >> reserveYear;
			if(reserveYear >= year && reserveYear <= year + 5) isAnswerValid = true;
			else cout << "You can't reserve this room on the year " << year << "." << endl;
		}
	} while(!isAnswerValid);

	isAnswerValid = false;

	do {
		input = "";
		cout << "Enter month of reservation (1 for January, 12 for December, Enter for current month): ";
		getline(cin, input);

		if(input.empty()) {
			reserveMonth = month;
			isAnswerValid = true;
		} else {
			istringstream(input) >> reserveMonth;
			if((reserveMonth > 0 && reserveMonth <= 12)){
				reserveMonth -= 1;

				if(reserveYear == year) {
					if(reserveMonth >= month) isAnswerValid = true;
					else cout << "You can't reserve for the month of " << months[reserveMonth] << " this year!" << endl;
				} else isAnswerValid = true;

			} else cout << "There's no month " << reserveMonth << "!" << endl;
		}
		
	} while(!isAnswerValid);

	isAnswerValid = false;

	input = "";
	do {
		int dayCheck = year % 4 == 0 ? daysOfLeapMonth[month] : daysOfMonth[month];

		cout << "Enter day (1 to " << dayCheck << ", enter for current day): ";
		getline(cin, input);

		if(input.empty()) {
			reserveDay = day;
			isAnswerValid = true;
		} else {
			istringstream(input) >> reserveDay;
			if(reserveDay > 0 && reserveDay <= dayCheck) {
				if(reserveDay >= day) isAnswerValid = true;
				else cout << "You can't reserve for the day of " << reserveDay << " this " << months[reserveMonth] << "!" << endl;
			} else cout << "There is no day " << reserveDay << " in the month of " << months[reserveMonth] << endl;
		}

	} while(!isAnswerValid);

	cout << endl;

	cout << "Alright, the room will be reserved on " << months[reserveMonth] << " " << reserveDay <<", " << reserveYear << endl;
	cout << "A night on " << room_name[room_selected] << " costs PHP" << rooms_price[room_selected] << ", plus tax." << endl;
	cout << "How many nights will you stay in a room? (max. 25 days): ";
	cin >> nights;

	stayUntilDay = reserveDay + nights;
	stayUntilMonth = reserveMonth;
	stayUntilYear = reserveYear;
	if(reserveYear % 4 == 0) {
		// Leap year check
		if(stayUntilDay > daysOfLeapMonth[reserveMonth]) {
			stayUntilMonth += 1;
			stayUntilDay -= daysOfLeapMonth[reserveMonth] - 1;
			if(stayUntilMonth > 11) {
				stayUntilYear += 1;
				stayUntilMonth -= 11;
			}
		}
	} else {
		// year check
		if(stayUntilDay > daysOfMonth[reserveMonth]) {
			stayUntilMonth += 1;
			stayUntilDay -= daysOfMonth[reserveMonth] - 1;
			if(stayUntilMonth > 11) {
				stayUntilYear += 1;
				stayUntilMonth -= 11;
			}
		}
	}

	cout << endl;
	cout << "You will be staying until " << months[stayUntilMonth] << " " << stayUntilDay << ", " << stayUntilYear << endl;

	Sleep(2000);

	syscls();
	logo_tab();

	cout << "Please wait, we are checking any promos for this reservation..." << endl << endl;

	if(day == 4 && month == 10) {
		// Implement current room check here
		cout << "======================================================================================" << endl;
		cout << "You can request for a red wine today for free! Ask the info desk for more information." << endl;
		cout << "Liquor laws will still apply. Must be 18 or above." << endl;
	}

	if((day >= 2 || day <= 5) && month == 10) {
		// Implement current room check here
		cout << "======================================================================================" << endl;
		cout << "You can get a free message today! Ask the info desk for more information." << endl;
	}

	if((day == 31 && month == 9) || ((day >= 1 || day <= 5) && month == 10)) {
		discount += 0.20;
		cout << "======================================================================================" << endl;
		cout << "20% discount applied: 20\% off on all our rooms (October 31-November 5) " << endl;
	}

	if(((day >= 3 || day <= 5) && month == 10) && nights >= 4) {
		nights -= 1;
		cout << "======================================================================================" << endl;
		cout << "Your 4th night is on us! (November 3-5)" << endl;
	}

	cout << "======================================================================================" << endl << endl;

	cout << "Room price (after discounts): " << (room_price -= (room_price * discount)) << endl;
	cout << endl;
	
	cout << "Do you have any discount codes? If so, type it here now and press enter. " << endl;
	cout << "Else, leave blank and press enter." << endl;
	cout << "Code > ";

	cin.ignore();
	
	while(true) { // this loops until the discount code is correct or left blank! 
		getline(cin, discount_code);
		
		if(discount_code.empty()) break;

		else {
			cout << "Checking discount code..." << endl;

			bool discount_applied = false;

			for(int i = 0; i < 3; i++) {
				if(!discount_applied && discount_code == discount_15_off[i]) {
					discount += 0.15;
					cout << "15% Discount has been applied!" << endl;
					discount_applied = true;
				}
			}

			for(int i = 0; i < 2; i++) {
				if(!discount_applied && discount_code == discount_20_off[i]) {
					discount += 0.2;
					cout << "20% Discount has been applied!" << endl;
					discount_applied = true;
				}
			}			

			if(discount_applied) {
				Sleep(3000);
				break;
			} else {
				cout << "The code " << discount_code << " didn't work! The codes are case sensitive." << endl;
				cout << "Re-enter the code here, or leave it blank, and press enter: ";
			}
		}
	}

	cout << endl;

	bool isReady = false;
	while(!isReady) {
		syscls();
		logo_tab();
		
		cout << "Alright, " << name << ", you have requested for the following room: " << endl << endl;
		cout << "Room number: " << room_number << endl;
		cout << "Room type: " << room_name[room_selected] << endl;
		cout << "Adult capacity: " << room_capacity[room_selected] << endl;
		cout << "Children capacity: " << room_capacity[room_selected] << endl;
		cout << "Check in date: " << months[reserveMonth] << " " << reserveDay << ", " << reserveYear << endl;
		cout << "Staying until: " << months[stayUntilMonth] << " " << stayUntilDay << ", " << stayUntilYear << endl;
		cout << endl;

		total_price = (room_price * nights) + (room_price * 0.12) + (room_price * 0.1);

		cout << "==========================================" << endl;
		cout << "Total Price:\t\t" << setw(10) << (float) (room_price * nights) << endl;
		cout << "Value-Added Tax (12%):\t" << setw(10) << (float) (room_price * 0.12) << endl;
		cout << "Service fee (10%):\t" << setw(10) << (float) (room_price * 0.1) << endl;
		cout << "==========================================" << endl;
		cout << "Payment:\t\t" << setw(10) << total_price << endl;
		cout << "==========================================" << endl;
		cout << endl;
		cout << "To finalize, type 'finalize' and press enter to check in!" << endl;
		cout << "To cancel, type 'cancel' to return to the rooms page. Your reservation will not be saved, however!" << endl;
		cout << "Enter command > ";
		
		getline(cin, entry);
		if(entry == "finalize") {
			roomsOccupied[room_selected][last_room - 1] = true;
			rooms_occupied[room_selected] += 1;
			isReady = true;
		} else if(entry == "cancel"){
			cout << "Your reservation has been canceled! Returning to the main menu.";
			Sleep(3000);
			home();
		}
	}
	
	cout << "Alright " << name << ", your reservation for " << months[reserveMonth] << " " << reserveDay << ", " << reserveYear << " is now saved!" << endl;
	cout << "Bring the receipt on the day of check-in to the counter and they will take care of the rest!" << endl;
	system("pause");
	home();

	return 0;
}

int about_us ()
{
	syscls();
	logo_tab();
	///ABOUT US
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (55, 13); cout << "A B O U T  U S";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (40, 15); cout << "\tiTam Suites and Resorts is a luxury";
	gotoxy (40, 16); cout << "hotel chain brand with properties mainly in";
	gotoxy (40, 17); cout << "large cities. iTam Suites is headquarted in";
	gotoxy (40, 18); cout << "Bonifacio Global City, Taguig City.";
	//LOCATION
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (55, 21); cout << "L O C A T I O N";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (40, 23); cout << "Located in the heart of Manila's precious new";
	gotoxy (40, 24); cout << "diamond, iTam Suites sits squarely among the";
	gotoxy (40, 25); cout << "budding steel-clad skycrappers and tree-lined";
	gotoxy (40, 26); cout << "boulevards of Bonifacio Global City.";
	
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (40, 28); cout << "AIRPORT TRANSFER SERVICE";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (44, 29); cout << "A shuttle service from the airport can be";
	gotoxy (44, 30); cout << "arranged for guests upon request. Additio-";
	gotoxy (44, 31); cout << "nal charges apply.";

	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (40, 33); cout << "From Ninoy Aquino International Airport:";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (44, 34); cout << "By Taxi: It takes approximately 20 minutes";
	gotoxy (44, 35); cout << "by taxi and costs about Php 300 to get to";
	gotoxy (44, 36); cout << "the residence, but rate is dependent on tra-";
	gotoxy (44, 37); cout << "ffic situation.";
	//ADDRESS
	
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (39, 40); cout << "****";
	gotoxy (37, 41); cout << "********";
	gotoxy (37, 42); cout << "**"; gotoxy (43, 42); cout << "**";
	gotoxy (37, 43); cout << "**"; gotoxy (43, 43); cout << "**";
	gotoxy (38, 44); cout << "******";
	gotoxy (39, 45); cout << "****";
	gotoxy (40, 46); cout << "**";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (46, 42); cout << "1st Avenue Corner, 50th Street";
	gotoxy (46, 43); cout << "Bonifacio Global City, Taguig City (1634)";
	gotoxy (46, 44); cout << "Philippines";
	
	//CONTACT US
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (55, 49); cout << "C O N T A C T  U S";
	gotoxy (37, 51); cout << "**";
	gotoxy (36, 52); cout << "***";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (46, 52); cout << "Phone Number: +63-02-9113169";
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (36, 53); cout << "*";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (46, 53); cout << "Email: iTamSuites@gmail.com";
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (37, 54); cout << "*";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (46, 54); cout << "Facebook: https://web.facebook.com/iTamSuites";
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (38, 55); cout << "*";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (46, 55); cout << "Twitter: https://twitter.com/iTamSuites";
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (39, 56); cout << "*****";
	gotoxy (41, 57); cout << "**";
	SetConsoleTextAttribute(color, 0x2E);
	
	
	
	
	/*
	gotoxy (37, 40); cout << "   ****    ";
	gotoxy (37, 41); cout << " ********  ";
	gotoxy (37, 42); cout << " **    **  " << "1st Avenue Corner, 50th Street";
	gotoxy (37, 43); cout << " **    **  " << "Bonifacio Global City, Taguig City (1634)";
	gotoxy (37, 44); cout << "  ******   " << "Philippines";
	gotoxy (37, 45); cout << "   ****    ";
	gotoxy (37, 46); cout << "    **     ";
	gotoxy (37, 47); cout << "           ";
	
	//CONTACT US
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy (55, 49); cout << "C O N T A C T  U S";
	SetConsoleTextAttribute(color, 0x2E);
	gotoxy (36, 51); cout << "  **       ";
	gotoxy (36, 52); cout << " ***       " << "Phone Number: +63-02-9113169";
	gotoxy (36, 53); cout << " *         " << "Email: iTamSuites@gmail.com";
	gotoxy (36, 54); cout << "  *        " << "Facebook: https://web.facebook.com/iTamSuites";
	gotoxy (36, 55); cout << "   *       " << "Twitter: https://twitter.com/iTamSuites";
	gotoxy (36, 56); cout << "    *****  ";
	gotoxy (36, 57); cout << "      **   ";
	*/
	final_bottom_option();
	return 0;
}

int bottom_room_choice1()
{
	char room_choice;
	cout << "\n\n[X] Exit program" << endl;
	
	cout << "Enter Choice: ";
	cin >> room_choice;
	
	while (room_choice != 'A' &&  room_choice != 'B' && room_choice != 'C' && room_choice != 'D' 
			&& room_choice != 'E' && room_choice != 'F' && room_choice != '1' && room_choice != '2'
			&& room_choice != '3' && room_choice != '4' && room_choice != '5' && room_choice != '6'
			&& room_choice != 'x' && room_choice != 'X' && room_choice != 'a' && room_choice != 'b'
			&& room_choice != 'c' && room_choice != 'd' && room_choice != 'e' && room_choice != 'f')
	{
		cout << "\nINVALID INPUT. TRY AGAIN" << endl;
		cout << "Enter choice: ";
		cin >> room_choice;
	}
	
	
	switch (room_choice)
	{
		case 'a':
		case 'A':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "R  O  O  M  S";
			gotoxy (52, 16); cout << "STANDARD 1 BEDROOM";
			gotoxy (30, 18); cout << "DESCRIPTION";
			gotoxy (80, 18); cout << "PRICE";
			gotoxy (77, 19); cout << "(per night)";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (12, 21); cout << "A room designed for three people. Has one bedroom";
			gotoxy (73, 21); cout << "P2,500 + tax/night";
			gotoxy (12, 22); cout << "with one bed.";
			gotoxy (12, 24); cout << "Size: 39 sqm.";
			gotoxy (12, 25); cout << "Occupancy: 2 adults and 1 child";
			room_selected = 0;
			bottom_room_choice2();
			break;
		case 'b':
		case 'B':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "R  O  O  M  S";
			gotoxy (52, 16); cout << "STANDARD 2 BEDROOM";
			gotoxy (30, 18); cout << "DESCRIPTION";
			gotoxy (80, 18); cout << "PRICE";
			gotoxy (77, 19); cout << "(per night)";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (12, 21); cout << "A room with two bedrooms and a living room.";
			gotoxy (73, 21); cout << "P3,500 + tax/night";
			gotoxy (12, 23); cout << "Size: 56 sqm.";
			gotoxy (12, 24); cout << "Occupancy: 4 adults and 2 children";
			room_selected = 1;
			bottom_room_choice2();
			break;
		case 'c':
		case 'C':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "R  O  O  M  S";
			gotoxy (53, 16); cout << "DELUXE 1 BEDROOM";
			gotoxy (30, 18); cout << "DESCRIPTION";
			gotoxy (80, 18); cout << "PRICE";
			gotoxy (77, 19); cout << "(per night)";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (12, 21); cout << "A room with a studio bed -- a couch that can be";
			gotoxy (73, 21); cout << "P3,000 + tax/night";
			gotoxy (12, 22); cout << "converted into a bed. May have an additonal bed.";
			gotoxy (12, 24); cout << "Size: 51 sqm.";
			gotoxy (12, 25); cout << "Occupancy: 3 adults and 2 children";
			room_selected = 2;
			bottom_room_choice2();
			break;
		case 'd':
		case 'D':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "R  O  O  M  S";
			gotoxy (52, 16); cout << "PREMIER 2 BEDROOM";
			gotoxy (30, 18); cout << "DESCRIPTION";
			gotoxy (80, 18); cout << "PRICE";
			gotoxy (77, 19); cout << "(per night)";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (12, 21); cout << "A parlour or living room connected to one or more";
			gotoxy (73, 21); cout << "P4,500 + tax/night";
			gotoxy (12, 22); cout << "bedrooms. Includes living room and a mini bar.";
			gotoxy (12, 24); cout << "Size: 71 sqm.";
			gotoxy (12, 25); cout << "Occupancy: 5 adults and 2 children";
			room_selected = 3;
			bottom_room_choice2();
			break;
		case 'e':
		case 'E':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "R  O  O  M  S";
			gotoxy (52, 16); cout << "PREMIER 3 BEDROOM";
			gotoxy (30, 18); cout << "DESCRIPTION";
			gotoxy (80, 18); cout << "PRICE";
			gotoxy (77, 19); cout << "(per night)";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (12, 21); cout << "A premier room that is connected to three bedrooms,";
			gotoxy (73, 21); cout << "P6,500 + tax/night";
			gotoxy (12, 22); cout << "has a living room, private king-sized bed and a mini bar.";
			gotoxy (12, 24); cout << "Size: 98 sqm.";
			gotoxy (12, 25); cout << "Occupancy: 7 adults and 2 children";
			room_selected = 4;
			bottom_room_choice2();
			break;
		case 'f':
		case 'F':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "R  O  O  M  S";
			gotoxy (52, 16); cout << "PREMIER 4 BEDROOM";
			gotoxy (30, 18); cout << "DESCRIPTION";
			gotoxy (80, 18); cout << "PRICE";
			gotoxy (77, 19); cout << "(per night)";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (12, 21); cout << "A premier room that is connected to four bedrooms,";
			gotoxy (73, 21); cout << "P7,800 + tax/night";
			gotoxy (12, 22); cout << "has a living room, private king-sized bed a mini";
			gotoxy (12, 23); cout << "bar. You can choose the penthouse view.";
			gotoxy (12, 25); cout << "Size: 100 sqm.";
			gotoxy (12, 26); cout << "Occupancy: 8 adults and 2 children";
			room_selected = 5;
			bottom_room_choice2();
			break;
		case '1':
			home ();
			break;
		case '2':
			rooms ();
			break;
		case '3':
			facilities ();
			break;
		case '4':
			promos ();
			break;
		case '5':
			reserve_page();
			break;
		case '6':
			about_us ();
			break;
		case 'x':
		case 'X':
			syscls();
			program_exit();
			syscls();
			splash();
			exit(0);
			break;			

	}
return 0;
}

void reserve_page() {
	logo_tab();
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy(43, 13); cout << "R  E  S  E  R  V  A  T  I  O  N";
	gotoxy(33, 16); cout << "ROOMS";
	gotoxy(57, 16); cout << "PRICE";
	gotoxy(74, 16); cout << "AVAILABLE ROOMS";
	gotoxy(54, 17); cout << "(per night)" << endl << endl;
	SetConsoleTextAttribute(color, 0x2E);
    for(int i = 0; i < room_type_count; i++) {
        cout << "\t\t\t[" << char(i+65) << "]" << " " << room_name[i] << "\t\t" << "PHP" << rooms_price[i] <<
		"\t\t\t" << rooms_max[i] - rooms_occupied[i] << endl << endl;
    };
	
	SetConsoleTextAttribute(color, 0xE2);
	gotoxy(24, 32); cout << "Note: all rooms are subject to taxes and a 10% service charge";
	SetConsoleTextAttribute(color, 0x2E);
	cout << "\n\n[X] Exit program\n";
	
	bool readyForReservation = false;

    while(true) {
        cout << "Enter choice: ";
        char choice;
        cin >> choice;

        switch(choice) {
            case 'a':
            case 'A':
                room_selected = 0;
                break;
            case 'b':
            case 'B':
                room_selected = 1;
                break;
            case 'c':
            case 'C':
                room_selected = 2;
                break;
            case 'd':
            case 'D':
                room_selected = 3;
                break;
            case 'e':
            case 'E':
                room_selected = 4;
                break;
            case 'f':
            case 'F':
                room_selected = 5;
                break;
			case '1':
				home ();
				break;
			case '2':
				rooms ();
				break;
			case '3':
				facilities ();
				break;
			case '4':
				promos ();
				break;
			case '5':
				reserve_page();
				break;
			case '6':
				about_us();
				break;
			case 'x':
			case 'X':
				syscls();
				program_exit();
				syscls();
				splash();
				exit(0);
				break;
			default:
				cout << "Invalid choice! Try again." << endl;
				continue;
	}

        if(rooms_max[room_selected] - rooms_occupied[room_selected] > 0) {
            cout << "Are you sure you want to reserve the room " << room_name[room_selected] << "? [Y/N or any key]: ";
            cin >> choice;
            if(choice == 'y') {
				readyForReservation = true;
				break;
			} else continue;
        } else {
            cout << "There are no available rooms for " << room_name[room_selected] << "." << endl;
            continue;
        }
    }

	if(readyForReservation) reservation();
	else return;
}

int bottom_room_choice2()
{
	char choice;
	
	gotoxy(12, 27); cout << "Available rooms: " << rooms_max[room_selected] - rooms_occupied[room_selected];
	if(rooms_occupied[room_selected] < rooms_max[room_selected]) {
		gotoxy(12, 28); cout << "Book this room?";
		gotoxy(15, 29); cout << "[Y] Yes";
		gotoxy(15, 30); cout << "[N] No";
	} else {
		gotoxy(12, 28); cout << "This type of room is fully booked!";
	}
	cout << "\n\n[B] Back" << endl;
	cout << "[X] Exit program" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' &&
			choice != '5' && choice != '6' && choice != 'x' && choice != 'X' &&
			choice != 'b' && choice != 'B' && choice != 'Y' && choice != 'y' &&
			choice != 'n' && choice != 'N')
	{
		cout << "\nINVALID INPUT. TRY AGAIN" << endl;
		cout << "Enter choice: ";
		cin >> choice;
	}
	
	switch (choice)
	{
		case '1':
			home ();
			break;
		case '2':
			rooms ();
			break;
		case '3':
			facilities ();
			break;
		case '4':
			promos ();
			break;
		case '5':
			reserve_page();
			break;
		case '6':
			about_us ();
			break;
		case 'x':
		case 'X':
			syscls();
			program_exit();
			Sleep (3000);
			syscls();
			splash();
			exit(0);
			break;			
		case 'b':
		case 'B':
			rooms();
			break;
		case 'y':
		case 'Y':
			if(rooms_occupied[room_selected] < rooms_max[room_selected]) {
				reservation(); 
			} else {
				cout << "There are no rooms of this type left! Returning to rooms page.";
				Sleep(1500);
				rooms();
			}
			break;
		case 'n':
		case 'N':
			rooms();
			break;
	}
return 0;
}

int bottom_promo_choice1()
{
	int i;
	char A[] = {"WINEDINE115"};
	char B[] = {"MASSAGE11"};
	char C[] = {"ITAM20OFF"};
	char D[] = {"FREEON4TH"};
	char E[] = {"EARLYBIRD"};
	char promo_choice;
	
	cout << "\n\n[X] Exit program" << endl;
	
	cout << "Enter Choice: ";
	cin >> promo_choice;
	
	while (promo_choice != 'A' &&  promo_choice != 'B' && promo_choice != 'C' && promo_choice != 'D' 
			&& promo_choice != 'E' && promo_choice != '1' && promo_choice != '2'
			&& promo_choice != '3' && promo_choice != '4' && promo_choice != '5' && promo_choice != '6'
			&& promo_choice != 'x' && promo_choice != 'X' && promo_choice != 'a' && promo_choice != 'b'
			&& promo_choice != 'c' && promo_choice != 'd' && promo_choice != 'e')
	{
		cout << "\nINVALID INPUT. TRY AGAIN" << endl;
		cout << "Enter choice: ";
		cin >> promo_choice;
	}
	
	switch(promo_choice)
	{
		case 'A':
		case 'a':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "P  R  O  M  O  S";
			gotoxy (42, 16); cout << "CONGRATS! YOU HAVE UNLOCKED A PROMO CODE!";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (32, 18); cout << "A Free Red Wine in our Standard 1 Bedroom Suites (November 5)";
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (57, 20); cout << "PROMO CODE:";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (51, 21); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (51, 22); cout << "=                     =" << endl;
			gotoxy (51, 23); cout << "=                     =" << endl;
			gotoxy (51, 24); cout << "=                     =" << endl;
			gotoxy (51, 25); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (57, 23);
			SetConsoleTextAttribute(color, 0xE2);
			for (i=0; i<11; i++)
    			{
       				cout<< A[i];
        			Beep(1000,500);
   				}
  			SetConsoleTextAttribute(color, 0x2E);
   			bottom_promo_choice2();
			break;
		case 'B':
		case 'b':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "P  R  O  M  O  S";
			gotoxy (42, 16); cout << "CONGRATS! YOU HAVE UNLOCKED A PROMO CODE!";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (32, 18); cout << "A Free Massage in our Deluxe 1 Bedroom Suites (November 5-10)";
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (57, 20); cout << "PROMO CODE:";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (51, 21); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (51, 22); cout << "=                     =" << endl;
			gotoxy (51, 23); cout << "=                     =" << endl;
			gotoxy (51, 24); cout << "=                     =" << endl;
			gotoxy (51, 25); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (58, 23);
			SetConsoleTextAttribute(color, 0xE2);
			for (i=0; i<9; i++)
    			{
       				cout<< B[i];
        			Beep(1000,500);
   				}
   				SetConsoleTextAttribute(color, 0x2E);
   			bottom_promo_choice2();
			break;
		case 'C':
		case 'c':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "P  R  O  M  O  S";
			gotoxy (42, 16); cout << "CONGRATS! YOU HAVE UNLOCKED A PROMO CODE!";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (38, 18); cout << "20% off on all our rooms (October 31-November 15)";
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (57, 20); cout << "PROMO CODE:";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (51, 21); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (51, 22); cout << "=                     =" << endl;
			gotoxy (51, 23); cout << "=                     =" << endl;
			gotoxy (51, 24); cout << "=                     =" << endl;
			gotoxy (51, 25); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (58, 23);
			SetConsoleTextAttribute(color, 0xE2);
			for (i=0; i<9; i++)
    			{
       				cout<< C[i];
        			Beep(1000,500);
   				}
   			SetConsoleTextAttribute(color, 0x2E);
   			bottom_promo_choice2();
			break;
		case 'D':
		case 'd':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "P  R  O  M  O  S";
			gotoxy (42, 16); cout << "CONGRATS! YOU HAVE UNLOCKED A PROMO CODE!";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (43, 18); cout << "Your 4th night is on us (November 5-20)";
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (57, 20); cout << "PROMO CODE:";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (51, 21); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (51, 22); cout << "=                     =" << endl;
			gotoxy (51, 23); cout << "=                     =" << endl;
			gotoxy (51, 24); cout << "=                     =" << endl;
			gotoxy (51, 25); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (58, 23);
			SetConsoleTextAttribute(color, 0xE2);
			for (i=0; i<9; i++)
    			{
       				cout<< D[i];
        			Beep(1000,500);
   				}
   			SetConsoleTextAttribute(color, 0x2E);
   			bottom_promo_choice2();
			break;
		case 'E':
		case 'e':
			syscls();
			logo_tab();
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (54, 13); cout << "P  R  O  M  O  S";
			gotoxy (42, 16); cout << "CONGRATS! YOU HAVE UNLOCKED A PROMO CODE!";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (38, 18); cout << "Early Bird Promo (30 days before the check-in date";
			gotoxy (50, 19); cout << "Available until June 2020)";
			SetConsoleTextAttribute(color, 0xE2);
			gotoxy (57, 21); cout << "PROMO CODE:";
			SetConsoleTextAttribute(color, 0x2E);
			gotoxy (51, 22); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (51, 23); cout << "=                     =" << endl;
			gotoxy (51, 24); cout << "=                     =" << endl;
			gotoxy (51, 25); cout << "=                     =" << endl;
			gotoxy (51, 26); cout << "= = = = = = = = = = = =" << endl;
			gotoxy (58, 24);
			SetConsoleTextAttribute(color, 0xE2);
			for (i=0; i<9; i++)
    			{
       				cout<< E[i];
        			Beep(1000,500);
   				}
   			SetConsoleTextAttribute(color, 0x2E);
   			bottom_promo_choice2();
			break;
		case '1':
			home ();
			break;
		case '2':
			rooms ();
			break;
		case '3':
			facilities ();
			break;
		case '4':
			promos ();
			break;
		case '5':
			reserve_page();
			break;
		case '6':
			about_us ();
			break;
		case 'x':
		case 'X':
			syscls();
			program_exit();
			syscls();
			splash();
			exit(0);
			break;
	}
}

int bottom_promo_choice2()
{
	char choice;
	
	cout << "\n\n\n\n\n\n[B] Back" << endl;
	cout << "[X] Exit program" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' &&
			choice != '5' && choice != '6' && choice != 'x' && choice != 'X' &&
			choice != 'b' && choice != 'B')
	{
		cout << "\nINVALID INPUT. TRY AGAIN" << endl;
		cout << "Enter choice: ";
		cin >> choice;
	}
	
	switch (choice)
	{
		case '1':
			home ();
			break;
		case '2':
			rooms ();
			break;
		case '3':
			facilities ();
			break;
		case '4':
			promos ();
			break;
		case '5':
			reserve_page();
			break;
		case '6':
			about_us ();
			break;
		case 'x':
		case 'X':
			syscls();
			program_exit();
			syscls();
			splash();
			exit(0);
			break;			
		case 'b':
		case 'B':
			promos();
			break;
	}
return 0;
	
}

int final_bottom_option()
{
	char choice;
	
	cout << "\n\n[X] Exit program" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' &&
			choice != '5' && choice != '6' && choice != 'x' && choice != 'X')
	{
		cout << "\nINVALID INPUT. TRY AGAIN" << endl;
		cout << "Enter choice: ";
		cin >> choice;
	}
	
	switch (choice)
	{
		case '1':
			home ();
			break;
		case '2':
			rooms ();
			break;
		case '3':
			facilities ();
			break;
		case '4':
			promos ();
			break;
		case '5':
			reserve_page();
			break;
		case '6':
			about_us ();
			break;
		case 'x':
		case 'X':
			syscls();
			program_exit();
			syscls();
			splash();
			exit(0);
			break;
	}
	return 0;
}

void setup() {
	bool isAnswerValid = false;

	cout << "Program setup" << endl;

	do {
		cout << "Enter year (1900 - 2020): ";
		cin >> year;

		if(year > 1900 && year <= 2020) isAnswerValid = true;
		else cout << "The year " << year << " is not compatible in our systems!" << endl;
	} while(!isAnswerValid);

	isAnswerValid = false;

	do {
		cout << "Enter month (1 to 12): ";
		cin >> month;

		if((month > 0 && month <= 12)){
			isAnswerValid = true;
			month -= 1;
		} else cout << "Try again!" << endl;
		
	} while(!isAnswerValid);

	isAnswerValid = false;

	do {
		int dayCheck = year % 4 == 0 ? daysOfLeapMonth[month] : daysOfMonth[month];

		cout << "Enter day (1 to " << dayCheck << "): ";
		cin >> day;
		if((day > 0 && day <= dayCheck)) isAnswerValid = true;
		else cout << "There is no day " << day << " in the month of " << months[month] << endl;

	} while(!isAnswerValid);

	cout << "Setup complete! The date today is: ";
	cout << day << " " << months[month] << " " << year << endl;
	system("pause");
	syscls();
}

int program_exit()
{
	gotoxy (30, 1); cout << "   _____         __               "; cout <<" \\   / _______            " << endl;
	gotoxy (30, 2); cout << "     |   |   |  /  \\  |\\  | | /  "; cout << "   \\ /  |     |  |     |  " << endl;
	gotoxy (30, 3); cout << "     |   |---| /____\\ | \\ | |/   "; cout << "    V   |     |  |     |  " << endl;
	gotoxy (30, 4); cout << "     |   |   | |    | |  \\| |\\   "; cout << "    |   |     |  |     |  " << endl;
	gotoxy (30, 5); cout << "     |   |   | |    | |   | | \\   "; cout << "   |   |_____|  |_____|  " << endl;

	gotoxy (25, 7);cout << "  _____ ______  ____   "; cout << "  \\       / _____ ____  _____ _____ _____        ______  " << "   |   " << endl;
	gotoxy (25, 8);cout << "  |     |    |  |   \\  "; cout << "   \\     /    |   |       |     |     |   |\\  | |      " << "     |   " << endl;
	gotoxy (25, 9);cout << "  |__   |    |  |   /  "; cout << "    \\   /     |   |___    |     |     |   | \\ | |   ___ " << "    |   " << endl;
	gotoxy (25, 10);cout << "  |     |    |  |  /   "; cout << "     \\ /      |       |   |     |     |   |  \\| |     | " << "    |   " << endl;
	gotoxy (25, 11);cout << "  |     |____|  |  \\   "; cout << "      V     __|__  ___| __|__   |   __|__ |   |  \\____| " << "    @   " << endl;

	Sleep (2000);
}
