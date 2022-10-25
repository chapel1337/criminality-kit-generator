#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <windows.h>

using std::cout; using std::cin; using std::string; using std::to_string; using std::getline; using std::ws; using std::vector;

// written by chapel1337
// made on 10/24/2022
// took bailey on a walk, so this took longer to make than usual
// finally stopped using system() because it's bad practice
// made this for a friend
// 651 lines!!

// manually wrote all of this
vector<string> gunsList{ "beretta", "g-17", "tec-9", "m1911", "fnp-45", "deagle", "magnum", "g-18", "uzi", "mac-10", "mp-7", "ump-45", "tommy gun", "sawn-off", "super-shorty", "ithaca 37", "aks-74u", "m4a1", "akm", "mare's leg", "scout", "bfg-50", "sks", "fn-fal", "m320", "rpg" };
vector<string> pistols{ "beretta", "g-17", "tec-9", "m1911", "fnp-45", "deagle", "magnum", "g-18" };
vector<string> smgs{ "uzi", "mac-10", "mp-7", "ump-45", "tommy gun" };
vector<string> shotguns{ "sawn-off", "super-shorty", "ithaca 37" };
vector<string> automatics{ "aks-74u", "m4a1", "akm" };
vector<string> snipers{ "mare's leg", "scout", "bfg-50" };
vector<string> dmrs{ "sks", "fn-fal" };
vector<string> gunExplosives{ "m320", "rpg" }; // "hallow's launcher"

vector<string> throwablesList{ "flashbangs", "stun grenade", "cs grenade", "smoke grenade", "incendiary", "frag grenade", "molotov", "c4", "airstrike", "ms grenade" };
vector<string> lethalThrowables{ "incendiary", "frag grenade", "molotov", "c4", "airstrike", "ms grenade"};
vector<string> nonLethalThrowables{ "flashbangs", "stun grenade", "cs grenade", "smoke grenade" }; // "snowball"

vector<string> meleesList{ "wrench", "crowbar", "golf club", "shovel", "bat", "baton", "metal bat", "shiv", "bayonet", "taiga", "balisong", "rambo", "machete", "katana", "fists", "knuckledusters", "nunchucks", "fire axe", "chainsaw" };
vector<string> blunts{ "wrench", "crowbar", "golf club", "shovel", "bat", "baton", "metal bat" }; // "hammer"
vector<string> blades{ "shiv", "bayonet", "taiga", "balisong", "rambo", "machete", "katana" }; // "cursed dagger", "slayer's II", "ERADICATOR", "hallow's blade", "slayer's sword"
vector<string> specials{ "fists", "knuckledusters", "nunchucks", "fire axe", "chainsaw" };

vector<string> miscList{ "splint", "bandage", "medkit", "rage dose", "antidote", "the cure", "flashlight", "lockpick", "coal", "pepper spray" };
vector<string> healingItems{ "splint", "bandage", "medkit" };
vector<string> consumables{ "rage dose", "antidote", "the cure" };
vector<string> tools{ "flashlight", "lockpick" };
vector<string> weapons{ "coal", "pepper spray" }; // "hl-mk-II", "sbl-mk-I", "sbl-mk-II"

vector<string> currentGunsList{ gunsList };
vector<string> currentMeleesList{ meleesList };
vector<string> currentThrowablesList{ throwablesList };
vector<string> currentMiscList{ miscList };


// ------- \\

void returnTo(string returnFunction);

void clear()
{
	#ifdef _WIN32
		system("cls");
	#elif (__LINUX__)
		system("clear");
	#endif
}

void title(string title)
{
	SetConsoleTitleA(("criminality kit generator - " + title).c_str());
}

void title()
{
	SetConsoleTitleA("criminality kit generator");
}

void title(string title, int i)
{
	SetConsoleTitleA(("criminality kit generator - " + title + to_string(i)).c_str()); // many paranthesis
}

void sleep(auto time)
{
	Sleep(time * 1000);
}

void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetTextColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 7 being white
}

int getRandom(int minimum, int maximum)
{
	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution random{ minimum, maximum };

	return random(mt);
}

void pause()
{
	cout << "\npress any key to continue . . .\n";

	cin.get();
	cin.ignore();
}

void invalidInput(string message, string returnFunction)
{
	clear();
	title("invalid input");

	cout << "invalid input: " << message << '\n';

	sleep(1);
	returnTo(returnFunction);
}

// ------- \\

int previousMeleeRandom{};
int previousGunRandom{};
int previousThrowableRandom{};
int previousMiscRandom{};

void randomMelee()
{
	int random{ getRandom(0, currentMeleesList.size() - 1) };

	if (previousMeleeRandom == random)
	{
		randomMelee();
	}
	else
	{
		previousMeleeRandom = random;
		cout << "melee: " << currentMeleesList.at(random) << '\n';
	}
}

void randomGun()
{
	int random{ getRandom(0, currentGunsList.size() - 1) };

	if (previousGunRandom == random)
	{
		randomGun();
	}
	else
	{
		previousGunRandom = random;

		cout << "gun: " << currentGunsList.at(random) << '\n';
	}
}

void randomThrowable()
{
	int random{ getRandom(0, currentThrowablesList.size() - 1) };

	if (previousThrowableRandom == random)
	{
		randomThrowable();
	}
	else
	{
		previousThrowableRandom = random;
		cout << "throwable: " << currentThrowablesList.at(random) << '\n';
	}
}

int chosenRandomArmor{};
void randomArmor()
{
	int random{ getRandom(1, 4) };
	chosenRandomArmor = random;

	cout << "armor: ";

	switch (random)
	{
	case 1:
		cout << "tier 1\n";
		break;

	case 2:
		cout << "tier 2\n";
		break;

	case 3:
		cout << "tier 3\n";
		break;

	case 4:
		cout << "none\n";
		break;
	}
}

void randomHelmet()
{
	cout << "helmet: ";

	if (chosenRandomArmor == 3)
	{
		cout << "none\n";
	}
	else
	{
		switch (getRandom(1, 3))
		{
		case 1:
			cout << "tier 1\n";
			break;

		case 2:
			cout << "tier 2\n";
			break;

		case 3:
			cout << "none\n";
			break;
		}
	}
}

void randomMisc()
{
	int random{ getRandom(0, currentMiscList.size() - 1) };

	if (previousMiscRandom == random)
	{
		randomMisc();
	}
	else
	{
		previousMiscRandom = random;
		cout << "misc: " << currentMiscList.at(random) << "\n\n";
	}
}

void randomBackpack()
{
	cout << "backpack: ";

	switch (getRandom(1, 2))
	{
	case 1:
		cout << "yes\n";
		break;

	case 2:
		cout << "no\n";
		break;
	}
}

// ------- \\

void start()
{
	clear();
	title();

	randomGun();
	randomMelee();
	randomThrowable();
	randomMisc();
	randomArmor();
	randomHelmet();
	randomBackpack();

	pause();
	returnTo("menu");
}

// ------- \\

void listGunTypes()
{
	cout << "1. pistols\n";
	cout << "2. smgs\n";
	cout << "3. shotguns\n";
	cout << "4. automatics\n";
	cout << "5. snipers\n";
	cout << "6. dmrs\n";
	cout << "7. gun explosives\n";
	cout << "8. exit\n\n";
}

void chooseGunType()
{
	clear();
	title("choose gun type");

	char response{};

	listGunTypes();
	cout << "input gun type: \n";

	cout << "> ";
	cin >> response;

	currentGunsList.clear();

	switch (response)
	{
	case '1':
		currentGunsList = pistols;
		break;

	case '2':
		currentGunsList = smgs;
		break;

	case '3':
		currentGunsList = shotguns;
		break;

	case '4':
		currentGunsList = automatics;
		break;

	case '5':
		currentGunsList = snipers;
		break;

	case '6':
		currentGunsList = dmrs;
		break;

	case '7':
		currentGunsList = gunExplosives;
		break;

	case '8':
		returnTo("settings");
		break;

	default:
		invalidInput("please specify 1, 2, 3, 4, 5, 6, 7, or 8", "chooseGunType");
		break;
	}

	returnTo("settings");
}

// ------- \\

void listMeleeTypes()
{
	cout << "1. blunts\n";
	cout << "2. blades\n";
	cout << "3. specials\n";
	cout << "4. exit\n\n";
}

void chooseMeleeType()
{
	clear();
	title("choose melee type");

	char response{};

	listMeleeTypes();
	cout << "input melee type: \n";

	cout << "> ";
	cin >> response;

	currentMeleesList.clear();

	switch (response)
	{
	case '1':
		currentMeleesList = blunts;
		break;

	case '2':
		currentMeleesList = blades;
		break;

	case '3':
		currentMeleesList = specials;
		break;

	case '4':
		returnTo("settings");
		break;

	default:
		invalidInput("please specify 1, 2, 3, 4, 5, 6, 7, or 8", "chooseGunType");
		break;
	}

	returnTo("settings");
}

// ------- \\

void listThrowableTypes()
{
	cout << "1. lethal\n";
	cout << "2. non-lethal\n";
	cout << "3. exit\n\n";
}

void chooseThrowableType()
{
	clear();
	title("choose throwable type");

	char response{};

	listThrowableTypes();
	cout << "input throwable type: \n";

	cout << "> ";
	cin >> response;

	currentThrowablesList.clear();

	switch (response)
	{
	case '1':
		currentThrowablesList = lethalThrowables;
		break;

	case '2':
		currentThrowablesList = nonLethalThrowables;
		break;

	case '3':
		returnTo("settings");
		break;

	default:
		invalidInput("please specify 1, 2, or 3", "chooseGunType");
		break;
	}

	returnTo("settings");
}

// ------- \\

void listMiscTypes()
{
	cout << "1. healing items\n";
	cout << "2. consumables\n";
	cout << "3. tools\n";
	cout << "4. weapons\n";
	cout << "5. exit\n\n";
}

void chooseMiscType()
{
	clear();
	title("choose throwable type");

	char response{};

	listMiscTypes();
	cout << "input throwable type: \n";

	cout << "> ";
	cin >> response;

	currentMiscList.clear();

	switch (response)
	{
	case '1':
		currentMiscList = healingItems;
		break;

	case '2':
		currentMiscList = consumables;
		break;

	case '3':
		currentMiscList = tools;
		break;

	case '4':
		currentMiscList = weapons;
		break;

	case '5':
		returnTo("settings");
		break;

	default:
		invalidInput("please specify 1, 2, or 3", "chooseGunType");
		break;
	}

	returnTo("settings");
}

// ------- \\

void resetSettings()
{
	currentGunsList = gunsList;
	currentMeleesList = meleesList;
	currentThrowablesList = throwablesList;
	currentMiscList = miscList;
}

// ------- \\

void settings()
{
	clear();
	title("settings");

	char response{};

	cout << "1. choose gun type\n";
	cout << "2. choose melee type\n";
	cout << "3. choose throwable type\n";
	cout << "4. choose misc type\n";
	cout << "5. reset settings\n";
	cout << "6. back\n\n";

	cout << "> ";
	cin >> response;

	switch (response)
	{
	case '1':
		chooseGunType();
		break;

	case '2':
		chooseMeleeType();
		break;

	case '3':
		chooseThrowableType();
		break;

	case '4':
		chooseMiscType();
		break;

	case '5':
		resetSettings();
		break;

	case '6':
		returnTo("menu");
		break;

	default:
		invalidInput("please specify 1, 2, 3, or 4", "settings");
		break;
	}
}

void quit()
{
	clear();

	for (int i{ 3 }; i > 0; --i)
	{
		title("exiting in ", i);

		cout << "okay, exiting in " << i;

		sleep(1);
		clear();
	}

	exit(1);
}

// ------- \\

void menu()
{
	clear();
	title("menu");

	char response{};

	cout << "criminality kit generator\n\n";

	cout << "1. start\n";
	cout << "2. settings\n";
	cout << "3. quit\n\n";

	cout << "> ";
	cin >> response;

	switch (response)
	{
	case '1':
		start();
		break;

	case '2':
		settings();
		break;

	case '3':
		quit();
		break;

	default:
		invalidInput("please input 1 or 2", "menu");
		break;
	}
}

// ------- \\

void returnTo(string returnFunction)
{
	if (returnFunction == "menu")
	{
		menu();
	}
	else if (returnFunction == "start")
	{
		start();
	}
	else if (returnFunction == "settings")
	{
		settings();
	}

	else if (returnFunction == "chooseGunType")
	{
		chooseGunType();
	}
}

int main()
{
	title("credits");

	setTextColor(2);
	cout << "written by chapel1337\n";
	cout << "made on 10/24/2022\n";
	resetTextColor();

	sleep(2);
	menu();
}

// ------- \\