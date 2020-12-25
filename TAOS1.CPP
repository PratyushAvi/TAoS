#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fstream.h>

int isAnswerValid = 0, isAnswerValid2 = 0, i = 0, decider = 0;
char section[20], ans3[10], l[200], nameGivenToChief[200], name[200];
fstream f1, f2, f3; //File Streams

void invalidAnswer()
{
	cout << "What was that? Please try again!" << endl << endl;
}

void saveProgress(char a[20])
{
	f2.open("TAoSProgress.txt", ios::out|ios::in);
	f2 << a;
	f2.close();
}

void descBox()
{
	for(int i = 0; i < 79; i++)
	{
		cout << "=";
		delay(10);
	}
	cout << endl << endl;
}

int checkInventory(char p[200])
{
	f1.open("TAoSInventory.txt", ios::in);
	int j = 0;
	char q[200];
	while(!f1.eof())
	{
		f1 >> q;
		if(strcmpi(p, q) == 0)
		j = 1;
	}
	f1.close();
	return j;
}

void addToInventory(char p[200])
{
	if(checkInventory(p) == 0)
	{
		f1.open("TAoSInventory.txt", ios::app);
		f1 << p << endl;
		f1.close();
	}
}

void displayInventory()
{
	f1.open("TAoSInventory.txt", ios::in);
	cout << "INVENTORY" << endl;
	char l[200];
	f1.seekg(0, ios::cur);
	int position1 = f1.tellg();
	f1.seekg(0, ios::end);
	int position2 = f1.tellg();
	if(position1 == position2)
		cout << "EMPTY" << endl << endl;
	else
	{
		f1.seekg(0, ios::beg);
		while(!f1.eof())
		{
			f1 >> l;
			cout << l << endl;
		}
	}
	f1.close();
}

void title()
{
	clrscr();
	int x2 = 1, x3 = 80, y2 = 1, y3 = 25;
	for(int p = 0; p < 79; p++)
	{
		gotoxy(x2, 1);
		cout << (char)254;
		gotoxy(x3, 25);
		cout << (char)254u;
		x2++;
		x3--;
		delay(20);
	}
	for( p = 0; p < 24; p++)
	{
		gotoxy(1, y3);
		cout << (char)254u;
		gotoxy(80, y2);
		cout << (char)254u;
		y3--;
		y2++;
		delay(20);
	}
	clrscr();
	for(p = 0; p < 4; p++)
	{
		gotoxy(10, 8); //the letter T
		for(int i = 0; i < 12; i++)
			cout << (char)254u;
		int n = 9;
		for(i = 0; i < 6; i++)
		{
			gotoxy(15, n);
			cout << (char)254u << (char)254u << endl;
			n++;
		}
		n = 23;
		int m = 14;
		for(i = 0; i < 7; i++) //the letter A
		{
			gotoxy(n, m);
			cout << (char)254u << (char)254u;
			n++;
			m--;
		}
		m++;
		for(i = 0; i < 7; i++)
		{
			gotoxy(n, m);
			cout << (char)254u << (char)254u;
			n++;
			m++;
		}
		gotoxy(29, 11);
		for(i = 0; i < 3; i++)
			cout << (char)254u;
		m = 9;
		n = 41;
		for(i = 0; i < 5; i++) //the letter O
		{
			gotoxy(n, m);
			cout << (char)254u << (char)254u;
			m++;
		}
		m = 8;
		n = 42;
		int k = 14;
		for(i = 0; i < 8; i++)
		{
			gotoxy(n, m);
			cout << (char)254u;
			gotoxy(n, k);
			cout << (char)254u;
			n++;
		}
		n--;
		m++;
		for(i = 0; i < 5; i++)
		{
			gotoxy(n, m);
			cout << (char)254u << (char)254u;
			m++;
		}
		n = 56; //letter S
		m = 8;
		k = 11;
		int l = 14;
		for(i = 0; i < 7; i++)
		{
			gotoxy(n, m);
			cout << (char)254u;
			gotoxy(n, k);
			cout << (char)254u;
			gotoxy(n, l);
			cout << (char)254u;
			n++;
		}
		n = 55;
		m = 9;
		k = 12;
		l = 62;
		for(i = 0; i < 2; i++)
		{
			gotoxy(n, m);
			cout << (char)254u << (char)254u;
			gotoxy(l, k);
			cout << (char)254u << (char)254u;
			m++;
			k++;
		}
		x2 = 1, x3 = 80, y2 = 1, y3 = 25;
		for(int p = 0; p < 79; p++)
		{
			gotoxy(x2, 1);
			cout << (char)254;
			gotoxy(x3, 25);
			cout << (char)254u;
			x2++;
			x3--;
		}
		for( p = 0; p < 24; p++)
		{
			gotoxy(1, y3);
			cout << (char)254u;
			gotoxy(80, y2);
			cout << (char)254u;
			y3--;
			y2++;
		}
		gotoxy(63, 15);
		cout << "D E M O";
		delay(500);
		clrscr();
		delay(300);
	}
	gotoxy(28, 13);
	cout << "Press any key to continue";
	getch();
	clrscr();
}

void main()
{
	clrscr();
	title(); //Run title
	char ans1[100];
	while(isAnswerValid == 0)
	{
		clrscr();
		gotoxy(34, 12);
		cout << "Hello Outlaw!" << endl;
		delay(400);
		gotoxy(30, 13);
		cout << "New Game or Load Game: ";
		gotoxy(38, 14);
		gets(ans1);
		if(strcmpi(ans1, "New Game") == 0 || strcmpi(ans1, "New") == 0)
		{
			f1.open("TAoSInventory.txt", ios::out);
			f1.close();
			f3.open("TAoSUtilities.txt", ios::out|ios::in);
			isAnswerValid = 1; //Running New Game
		}
		else if(strcmpi(ans1, "Load Game") == 0 || strcmpi(ans1, "Load") == 0)
		{
			f3.open("TAoSUtilities.txt", ios::app|ios::in);
			isAnswerValid = 2; //Running Load Game
		}
		else
		{
			gotoxy(24, 14);
			invalidAnswer();
			getch();
		}
	}
	if(isAnswerValid == 2)
	{
		f2.open("TAoSProgress.txt", ios::in);
		f2.seekg(0, ios::cur);
		int position1 = f2.tellg();
		f2.seekg(0, ios::end);
		int position2 = f2.tellg();
		//Code for skipping to checkpoints
		if(position1 == position2)
			cout << "Load Game does not exist. Running New Game..." << endl;
		else
		{
			f3.seekg(0, ios::beg);
			f3.getline(l, 200);
			strcpy(name, l);
			gotoxy(32, 15);
			cout << "Welcome back, " << name << "!" << endl;
			delay(1600);
			clrscr();
			f2.seekg(0, ios::beg);
			f2.getline(l,20);
			char L=l[0];
			if(L == 'a')
				goto INTRO;
			else if(L == 'b')
				goto GWC;
			else if(L == 'c')
				goto CLEARING2;
			else if(L == 'd')
				goto GRAVEYARD;
			else if(L == 'e')
				goto TRIBALSANCTUARY;

		}
		f2.close();
	}
	//Game Beginning
	isAnswerValid = 0;
	char ans2[10];
	while(isAnswerValid == 0) //Takes user input of name
	{
		clrscr();
		gotoxy(32, 12);
		cout << "What's your name?" << endl;
		gotoxy(34, 13);
		gets(name);
		for(i = 0; i < 100; i++)
			name[i] = toupper(name[i]);
		gotoxy((40-(strlen(name) + 17)/2), 14);
		cout << "So your name is " << name << "?" << endl;
		gotoxy(34, 15);
		gets(ans2);
		if(strcmpi(ans2, "yes") == 0)
		{
			gotoxy((strlen(name) + 38)/2, 16);
			cout << "Welcome to the world of TAoS, outlaw " << name << "!";
			f3 << name << endl;
			isAnswerValid = 1;
		}
		else if(strcmpi(ans2,"no") == 0) //Incase of NO input, relaunches loop
		{
			gotoxy(16,16);
			cout << "Let's try again." << endl;
		}
		else
		{
			gotoxy(24, 15);
			invalidAnswer();
			getch();
		}
	}
	f3 << name << endl;
	strcpy(section, "a");
	saveProgress(section);
	//Beginning of Checkpoint A
	INTRO:
	getch();
	clrscr();
	cout << "You're in a tree. You own nothing but your trusty bow and arrows, the clothes onyour back, and your wits." << endl << endl;
	getch();
	cout << "You hear distant marching." << endl << endl;
	getch();
	cout << "Under the tree, there is a clearing to one side and dense bushes to another." << endl << endl;
	getch();
	cout << "The marching sounds get louder." << endl << endl;
	getch();
	cout << "Make a decision:" << endl;
	delay(800);
	cout << "A. Remain in the tree." << endl;
	delay(800);
	cout << "B. Rush into the clearing." << endl;
	delay(800);
	cout << "C. Hide in the bushes." << endl << endl;
	delay(800);
	isAnswerValid = 0; //To confirm A, B, or C input
	isAnswerValid2 = 0;
	while(isAnswerValid == 0)
	{
		gets(ans3);
		if(strcmpi(ans3, "A") == 0)
		{
			cout << "You remain in the tree, absolutely quietly." << endl << endl;
			getch();
			cout << "The army passes through the clearing, into the distance." << endl << endl;
			getch();
			cout << "You drop down to the road and see some items strewn on the pathway." << endl << endl;
			cout << "One of them is a sturdy sword." << endl;
			cout << "Collect?" << endl << endl;
			while(isAnswerValid2 == 0)
			{
				gets(ans2);
				if(strcmpi(ans2, "yes") == 0)
				{
					cout << "Sword added to inventory." << endl << endl;
					getch();
					addToInventory("Sword");
					isAnswerValid2 = 1;
				}
				else if(strcmpi(ans2,"no") == 0)
				{
					cout << "Left sword as it is." << endl << endl;
					isAnswerValid2 = 1;
				}
				else
					invalidAnswer();
			}
			isAnswerValid = 1;
			decider=1;
		}
		else if(strcmpi(ans3, "B") == 0)
		{
			isAnswerValid = 2; /*CPL*/
			cout << "You rush into the clearing." << endl << endl;
			getch();
			cout << "The army spots you and charges you." << endl << endl;
			getch();
			cout << "You attempt to fight them, but you are killed." << endl << endl;
			getch();
			goto DEATH; //Skips to the end of the program
		}
		else if(strcmpi(ans3, "C") == 0)
		{
			cout << "You climb out of the tree and hide in the bushes." << endl <<
			endl;
			getch();
			cout << "There are some herbs in the bush." << endl << endl;
			cout << "Would you like to collect them?" << endl;
			while(isAnswerValid2 == 0)
			{
				gets(ans2);
				if(strcmpi(ans2, "yes") == 0)
				{
					cout << "Herbs added to inventory." << endl;
					isAnswerValid2 = 1;
					addToInventory("Herbs");
				}
				else if(strcmpi(ans2,"no") == 0)
				{
					cout << "Left herbs as they are." << endl << endl;
					isAnswerValid2 = 1;
				}
				else
					invalidAnswer();
			}
			isAnswerValid = 3;
			decider = 2;
			getch();
		}
		else if(strcmpi(ans3, "i") == 0)
			displayInventory();
		else
			invalidAnswer();
	}
	isAnswerValid2 = 0;
	if(isAnswerValid == 3 || isAnswerValid == 1)
	{
		clrscr();
		cout << "You step onto the road" << endl << endl;
		CLEARING:
		cout << "Where would you like to go?" << endl;
		delay(900);
		cout << "A. Follow the army." << endl;
		cout << "B. Go in the opposite direction." << endl << endl;
		isAnswerValid2 = 0;
		while(isAnswerValid2 == 0)
		{
			gets(ans3);
			if(strcmpi(ans3, "A") == 0)
			{
				cout << "You follow the road and reach Grand West End City." << endl << endl;
				getch();
				isAnswerValid2 = 1;
				goto GWC;
			}
			else if(strcmpi(ans3, "B") == 0)
			{
				cout << "You bump into a construction crew that refuses to let you pass as of now." << endl << endl;
				getch ();
				cout << "You return to the clearing." << endl << endl;
				isAnswerValid2 = 1;
				goto CLEARING; //To ensure the user takes the path defined, irrespective of option chosen
			}
			else if(strcmpi(ans3, "i") == 0)
				displayInventory();
			else
				invalidAnswer();
		}
	}
	GWC:
	strcpy(section, "b");
	saveProgress(section);
	isAnswerValid2 = 0;
	isAnswerValid = 0;
	clrscr();
	descBox();
	cout << "Welcome to Grand West End City. The market is just opening, the shopkeepers" << endl << "spreading out their wares." << endl;
	cout << "The city is bustling with people- kids, women, shopkeepers, knights (steer clearof them, they don't like rule flouters!)" << endl << endl;
	descBox();
	getch();
	cout << "The GWC Mart is closed for now." << endl << endl;
	getch();
	cout << "A board in the city glorifies the Capitol and King Thaur." << endl << endl;
	getch();
	cout << "In the corner there is a WANTED poster with your face on it (you're worth a " << endl << "LOT!) Rip it off?" << endl;
	while(isAnswerValid2 == 0)
	{
		gets(ans2);
		if(strcmpi(ans2, "yes") == 0)
		{
			cout << "Poster ripped and added to inventory." << endl << endl;
			addToInventory("Poster");
			isAnswerValid2 = 1;
		}
		else if(strcmpi(ans2,"no") == 0)
		{
			cout << "Left poster as it is." << endl << endl;
			isAnswerValid2 = 2;
		}
		else if(strcmpi(ans3, "i") == 0)
			displayInventory();
		else
			invalidAnswer();
	}
	getch();
	cout << "What would you like to do?" << endl;
	delay(900);
	cout << "A. Explore the city" << endl;
	delay(900);
	cout << "B. Go back to the clearing." << endl << endl;
	isAnswerValid2 = 0;
	while(isAnswerValid2 == 0)
	{
		gets(ans3);
		if(strcmpi(ans3, "A") == 0)
		{
			clrscr();
			cout << "You come across an illegal ring of fights, where severe betting and killing" << endl << "occurs." << endl << endl;
			getch();
			cout << "Not yet prepared for it." << endl << endl;
			getch();
			cout << "Government officials looming. Safer to leave now!" << endl << endl;
			isAnswerValid2 = 1;
			getch();
		}
		else if(strcmpi(ans3, "B") == 0)
		{
			cout << "You return to the clearing." << endl << endl;
			strcpy(section, "c");
			saveProgress(section);
			CLEARING2:
			getch();
			cout << "You see the construction team leaving." << endl << endl;
			isAnswerValid2 = 2;
			getch();
		}
		else if(strcmpi(ans3, "i") == 0)
			displayInventory();
		else
			invalidAnswer();
	}
	if(isAnswerValid2 == 1)
	{
		cout << "You overhear talks of a special gauntlet being wagered in one of the rings." << endl << endl;
		getch();
		cout << "A man approaches you with an offer to fight." << endl << endl;
		getch();
		descBox();
		cout << "MUSTAFA : I shall sponsor you for your fights. If you win, the spoils will be" << endl << "shared between us and the gauntlet goes to you." << endl;
		getch();
		cout << "MUSTAFA : Are you interested?" << endl;
		while(isAnswerValid == 0)
		{
			gets(ans2);
			if(strcmpi(ans2, "yes") == 0)
			{
				cout << name << ": Indeed, I would like to throw my hat in the ring!" << endl << endl;
				getch();
				descBox();
				cout << "Mustafa registers you and gives you access to a variety of weapons." << endl;
				cout << "You're strapped into cheap and heavy armor, which you are not used to: It slows down your reflexes." << endl << endl;
				getch();
				cout << "The fight begins. " << name << " vs HALF GIANT" << endl << endl;
				descBox();
				getch();
				cout << "You were thoroughly under prepared and your skillset was dwarfed by the" << endl << "requirements of this tournament." << endl;
				getch();
				cout << "Your body lay in mangled pieces at the bottom of the ring as Mustafa watched hisinvestment fail miserably." << endl << endl;
				descBox();
				getch();
				isAnswerValid = 1;
				goto DEATH;
			}
			else if(strcmpi(ans2,"no") == 0)
			{
				cout << "Mustafa laughs and calls you a fool as you walk away." << endl << endl;
				getch();
				descBox();
				cout << "You return to the clearing before you are spotted by the officials." << endl << endl;
				getch();
				isAnswerValid = 2;
				goto CLEARING2;
			}
			else
				invalidAnswer();
		}
	}
	else if(isAnswerValid2 == 2)
	{
		if(decider == 2)
		{
			isAnswerValid = 0;
			cout << "There are some items strewn on the pathway." << endl << endl;
			getch();
			cout << "One of them is a sturdy sword." << endl;
			getch();
			cout << "Collect?" << endl;
			while(isAnswerValid == 0)
			{
				gets(ans2);
				if(strcmpi(ans2, "yes") == 0)
				{
					cout << "Sword added to inventory." << endl << endl;
					getch();
					addToInventory("Sword");
isAnswerValid = 1;
}
else if(strcmpi(ans2,"no") == 0)
{
cout << "Left sword as it is." << endl << endl;
isAnswerValid = 2;
}

else if(strcmpi(ans2, "i") == 0)
displayInventory();
else
invalidAnswer();
}
}
if(decider == 1)
{
cout << "The completion of the road has led to the displacement of an angry family of" << endl << "ferrets." << endl << endl;
getch();
cout << "One of them sees you approaching with your possessions and supplies." << endl << endl;
getch();
cout << "It grabs your bag and runs into the bushes." << endl << endl;
getch();
cout << "You chase after it and reclaim your bag." << endl << endl;
getch();
cout << "There are some herbs in the bush." << endl << endl;
getch();
cout << "Would you like to collect them?" << endl;
isAnswerValid = 0;
while(isAnswerValid == 0)
{
gets(ans2);
if(strcmpi(ans2, "yes") == 0)
{
cout << "Herbs added to inventory." << endl;
getch();
addToInventory("Herbs");
isAnswerValid = 1;
}
else if(strcmpi(ans2,"no") == 0)
{
cout << "Left herbs as they are." << endl;
isAnswerValid = 2;
}
else if(strcmpi(ans2, "i") == 0)
displayInventory();
else
invalidAnswer();
}
}
}
isAnswerValid = 0;
clrscr();
cout << "You set yourself down for a few minutes to rest." << endl << endl;
getch();
cout << "As you organize your belongings, a committee of vultures flying overhead catch" << endl << "the scent of your food." << endl << endl;

delay(700);
cout << "They attack." << endl << endl;
getch();
if(checkInventory("Sword") == 0)
{
cout <<  "Without any weapon or means to defend yourself, the vultures mercilessly tear" << endl << "you apart for their midday meal.";
getch();
goto DEATH;
}
else if(checkInventory("Sword") == 1)
{
cout << "You brandish your sword at them and attempt to fend them off." <<
endl << endl;
getch();
cout << "The vultures claw at your flesh and rip your clothes, yet you manage to survive.";
getch();
}
strcpy(section, "d");
saveProgress(section);
GRAVEYARD:
clrscr();
cout << "You stumble into a graveyard with severe injuries and pass out on a log."
<< endl << endl;
for(i = 0; i < 3; i++) //dot... dot... dot...
{
cout << ". ";
delay(700);
}
cout << endl << endl;
descBox();
cout << "In a graveyard at night? Not the best of ideas." << endl;
getch();
cout << "Ghosts visibly roam about, minding their own business. Unless you touch one of" << endl;
cout << "them." << endl;
getch();
cout << "That is unpleasant for both of you." << endl;
getch();
cout << "Your arm goes numb as you try to limp your way to the exit." << endl;
getch();
cout << "Vines on the ground trip you. You touch ghosts. ";
getch();
cout << "Multiple." << endl;
getch();
cout << "A chill settles on your body and you fall into a dug grave." << endl;
getch();

cout << "You find sticks and stones beside you (you hope that is all they are)."
<< endl;
getch();
cout << "Ghosts close in." << endl << endl;
getch();
descBox();
cout << "The grave seems deeper than it did. You turn and see a hallway leading"
<< endl << "underground." << endl << endl;
getch();
cout << "Follow?" << endl;
while(isAnswerValid == 0)
{
gets(ans2);
if(strcmpi(ans2, "yes") == 0)
isAnswerValid = 1;
else if(strcmpi(ans2,"no") == 0)
{
cout << "The ghosts close in and take you to where they come from : the afterlife." << endl;
getch();
isAnswerValid = 2;
goto DEATH;
}
else if(strcmpi(ans2, "i") == 0)
displayInventory();
else
invalidAnswer();
}
strcpy(section, "e");
saveProgress(section);
TRIBALSANCTUARY:
clrscr();
cout << "You follow the hallway and reach a tribal sanctuary." << endl << endl;
getch();
cout << "The local tribe spots you and captures you. An intruder has not been seen in" << endl << "their midst for a long time, apparently." << endl << endl;
getch();
cout << "You are brought in front of their chief, who is tending to a young girl on a" << endl;
cout << "leafy bed, who is clearly ill." << endl << endl;
getch();
descBox();
cout << "CHIEF: Who are you?" << endl;
cout << name << ": I am but a lone traveller who goes by the name ";
cin >> nameGivenToChief;
if(strcmpi(nameGivenToChief, name) != 0)
f3 << nameGivenToChief << endl;
cout << "CHIEF: What is your purpose here?" << endl;

cout << name << ": Tired and injured, I fell into the grave that connects the world" << endl << "to your haven. I only came here by mistake, for which I deeply apologize." << endl;
getch();
cout << "CHIEF : Although your scars tell us you speak the truth, I cannot allow you to" << endl << "live as you are probable to tell the upper land dwellers about our peaceful" << endl << "abode. You must gain our trust if you are to live." << endl <<
endl;
getch();
descBox();
cout << "Guards are summoned to execute you. Think fast, what can you do?" <<
endl;
delay(900);
cout << "A.""I CAN HEAL YOUR DAUGHTER!""" << endl;
delay(900);
cout << "B.""I WILL FIGHT YOU ALL IF I MUST!"" And charge the tribe." << endl;
isAnswerValid = 0;
while(isAnswerValid == 0)
{
gets(ans3);
if(strcmpi(ans3, "A") == 0)
isAnswerValid = 1;
else if(strcmpi(ans3, "B") == 0)
{
cout << "You foolishly attack the entire tribe and are killed rather easily." << endl;
getch();
isAnswerValid = 2;
goto DEATH;
}
else if(strcmpi(ans3, "i") == 0)
displayInventory();
else
invalidAnswer();
}
descBox();
cout << "CHIEF : (to the guards) Guards, stop!" << endl;
getch();
cout << "(to you) Could you really heal my daughter? What sort of item or magic do you" << endl << "possess that would allow you to achieve such a feat?" << endl <<
endl;
getch();
isAnswerValid2 = 0;
if(checkInventory("Herbs") == 1)
{
descBox();
while(isAnswerValid2 == 0)
{
displayInventory();
cout << "USE: ";

gets(ans1);
if(strcmpi(ans1, "SWORD")==0 || strcmpi(ans1, "POSTER")==0)
cout << "No, that wouldn't work." << endl << endl;
else if(strcmpi(ans1, "HERBS")==0)
isAnswerValid2 = 1;
else
invalidAnswer();
}
cout << "You use the herbs you collected to make a paste which makes the daughter of the chief feel at rest." << endl << endl;
getch();
cout << "Thankful for your assistance, the chief allows you to rest for as long as it" << endl << "takes you to heal, then he assigns his best warriors to teach you various forms of battle. They teach you certain other things as well, such as the fatal" << endl << "weakness of their ghostly guardians: FIRE." << endl << endl;
getch();
}
else
{
cout << name << ": I possess the knowledge of a certain natural herb's location" << endl << "which will cure your child!" << endl;
getch();
cout << "CHIEF : I beseech you, tell me the location of this wondrous plant and I will" << endl;
cout << "provide you with great skills and items for your journey ahead." <<
endl << endl;
getch();
descBox();
cout << "Where are these herbs you speak of?" << endl;
delay(700);
cout << "A. GWC Mart" << endl;
cout << "B. Clearing" << endl;
cout << "C. Bushes" << endl;
cout << "D. Graveyard" << endl;
cout << "E. On top of the tree." << endl;
isAnswerValid2 = 0;
while(isAnswerValid2 == 0)
{
gets(ans3);
if(strcmpi(ans3, "A") == 0 || strcmpi(ans3, "B") == 0 || strcmpi(ans3,
"D") == 0 || strcmpi(ans3, "E") == 0)
{
cout << "The chief sent his attendants to the location you mentioned. They returned emptyhanded and you are executed for lying to the chief.";
getch();
isAnswerValid2 = 1;
goto DEATH;
}
else if(strcmpi(ans3, "C") == 0)
{

cout << "The chief sent his attendants to the location you mentioned. They returned with a collection of the herbs present there." << endl << endl;
cout << "You use the herbs you collected to make a paste which makes the daughter of the chief feel at rest." << endl << endl;
getch();
cout << "Thankful for your assistance, the chief allows you to rest for as long as it" << endl << "takes you to heal, then he assigns his best warriors toteach you various forms of battle. They teach you certain other things as well, such as the fatal" << endl << "weakness of their ghostly guardians: FIRE." << endl << endl;
getch();
isAnswerValid2 = 1;
getch();
}
else if(strcmpi(ans3, "i") == 0)
displayInventory();
}
}
cout << "Now fresh and ready for the next phase of your journey, you step out of the" << endl;
cout << "underground tribe's abode." << endl << endl;
getch();
clrscr();
delay(400);
gotoxy(22, 12);
cout << "TO GET ACCESS TO THE FULL STORY MODE";
gotoxy(31, 13);
cout << "PAY 50000 BITCOINS"; //Please fund!!!
getch();
gotoxy(1, 24);
cout << "©BearBerry Inc.TM 2018. All Rights Reserved Under Trade Mark." << endl;
cout << "Made by Hriday Pradhan and Pratyush Avi.";
getch();
DEATH:
clrscr();
gotoxy(36, 12);
cout << "GAME OVER";
f1.close();
f3.close();
getch();
}
//Copyright symbol ASCII value: 184 and Trademark symbol ASCII value: 169
//©BearBerry Inc.TM 2018. All Rights Reserved Under Trade Mark.
//Made by Hriday Pradhan and Pratyush Avi.