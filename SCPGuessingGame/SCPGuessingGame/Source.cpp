#include <iostream>
#include "NumberGen.h"
#include "SCP.h"

using namespace std;

int main() {
	cout << "\n\tWelcome To The SCP Guessing Game!\n" << endl;
	cout << "For those who know of SCP, this might be a bit easier since you should be familiar with the various SCPs, so put your knowledge to the test\nFor those who do not know of SCP, then this will serve as a great memory game as well\n" << endl;
	cout << "Your Job:\nYou'll be given the alternate name of these SCPs and you're to input the number associated with them\n" << endl;

	cout << "Do you want to start the game? Y/N - ";
	char understand = 'N';
	cin >> understand;
	understand = toupper(understand);
	do {
		if (understand != 'Y' && understand != 'N')
		{
			cout << "\nThis is a Y/N Question\nPlease Try Again\n" << endl;
			cout << "Do you want to start the game? Y/N - ";
			cin >> understand;
			understand = toupper(understand);
		}
	} while (understand != 'Y' && understand != 'N');
	cout << "\n";

	if (understand == 'N')
	{
		system("pause");
		return 0;
	}

	cout << "Please enter your name: ";
	string uName;
	cin >> uName;
	User Player("Hopefully not a D-Boi", uName);
	cout << "\nWelcome " << Player.getName() << ", Let's begin!\n\n";

	int simulationNumber = 0;
	int correct = 0;
	int outOf = 0;

	SCP Sculpture("173", "The Sculpture");
	SCP htdReptile("682", "The Hard-To-Destroy Reptile");
	SCP RadicalLarry("106", "The Old Man - Aka - Radical Larry");
	SCP Polariod("978", "The Polaroid");
	SCP hStar("1548", "The Hateful Star");
	SCP Farmhouse("1983", "The Farmhouse");
	SCP Mother("597", "The Mother");

	string SCPcodes[7]{
		Sculpture.getCode(),
		htdReptile.getCode(),
		RadicalLarry.getCode(),
		Polariod.getCode(),
		hStar.getCode(),
		Farmhouse.getCode(),
		Mother.getCode()
	};

	string SCPnames[7]{
		Sculpture.getName(),
		htdReptile.getName(),
		RadicalLarry.getName(),
		Polariod.getName(),
		hStar.getName(),
		Farmhouse.getName(),
		Mother.getName()
	};

	string Prizes[3]{
		"Cookie",
		"Cake",
		"Pie"
	};

	int randomPrizes = RandomizeNumber(&randomPrizes, 3);
	string randomPrize = Prizes[randomPrizes];

	char startAgain = 'N';
	do {
		int randomNumber = RandomizeNumber(&randomNumber, 7);

		simulationNumber++;

		string SCPcode = SCPcodes[randomNumber];
		string SCPname = SCPnames[randomNumber];

		cout << "Name: " << SCPname << endl;
		cout << "SCP-";
		string guess;
		cin >> guess;

		outOf++;

		if (guess == SCPcode)
		{
			cout << "\nThat's Right, " << Player.getName() << "! SCP-" << guess << " is " << SCPname << "\n" << endl;
			correct++;
		}
		else
		{
			cout << "\nNo, I'm Sorry " << Player.getName() << ". " << guess << " is not the assigned number of SCP-" << SCPcode << ", " << SCPname << "\n" << endl;
		}

		cout << "Start Again? Y/N - ";
		cin >> startAgain;
		startAgain = toupper(startAgain);

		do {
			if (startAgain != 'Y' && startAgain != 'N')
			{
				cout << "\nThis is a Y/N Question\nPlease Try Again\n" << endl;
				cout << "Start Again? Y/N - ";

				cin >> startAgain;
				startAgain = toupper(startAgain);
			}
		} while (startAgain != 'Y' && startAgain != 'N');
		cout << "\n";
	} while (startAgain == 'Y');

	if (startAgain == 'N')
	{
		cout << "This is the end of the game\n" << endl;
		cout << "You ran " << simulationNumber << " Simulations" << endl;
		cout << "And got " << correct << "/" << outOf << " of the SCPs correct\n" << endl;
		cout << Player.getName() << ", Here's Your Prize: " << randomPrize << "\n" << endl;
	}

	system("pause");
	return 0;
}