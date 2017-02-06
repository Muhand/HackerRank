#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <fstream>
using namespace std;

////////////////////////////////////
//Structures
////////////////////////////////////
struct spaceship
{
	int id = -1;
	int startTime = -1;
	int endTime = -1;
	int score = 0;
};

////////////////////////////////////
//Prototypes
////////////////////////////////////
bool validateNumberOfShips(int numberOfShips);
bool validID(int id);
bool validStartTime(int startTime, int endTime);
bool validEndTime(int endTime, int startTime);
bool noDuplicates(int id, int startTime, int endTime, vector<spaceship> spaceships);
bool compTimeInfo(const spaceship sp1, const spaceship sp2);
bool compWinInfo(const spaceship sp1, const spaceship sp2);
void score(vector<spaceship> spaceships, int startIndex, int endIndex);
void print(vector<spaceship> spaceships);							//For debug only!!!!

////////////////////////////////////
//Global Variables
////////////////////////////////////
vector<spaceship> winners(0);
int main() {
	int numOfSpaceShips;											//Hold the number of spaceships
	vector<spaceship> spaceships(0);								//Create a vector with size 0
	cin >> numOfSpaceShips;											//Read the number of spaceships
	

	//Check if the number of ships is valid otherwise exit
	if (validateNumberOfShips(numOfSpaceShips))
	{
		spaceships.resize(numOfSpaceShips);							//Resize the vector to hold the correct size
		//winners.resize(numOfSpaceShips);
	}
	//else
		//goto EXIT;
	ifstream file;
	file.open("test.txt");

	if (!file.is_open())
		cout << "error" << endl;
	//Loop through all the sapceships and read their information
	int i = 0;
	while (!file.eof())
	{
		
		/////////////////////////////////////
		//Get info in tmep variables
		//In order to validate them
		//Then insert them to the vector
		/////////////////////////////////////
		int tempID, tempStartTime, tempEndTime;						//Temp variables
		file >> tempID >> tempStartTime >> tempEndTime;				//Input the data


		//Check if all values are valid then continue, otherwise exit
		if (validID(tempID) && validStartTime(tempStartTime, tempEndTime) && validEndTime(tempEndTime, tempStartTime) && noDuplicates(tempID, tempStartTime, tempEndTime, spaceships))
		{
			spaceships[i].id = tempID;
			spaceships[i].startTime = tempStartTime;
			spaceships[i].endTime = tempEndTime;
		}
		/*else
			goto EXIT;*/

		i++;
	}
	sort(spaceships.begin(), spaceships.end(), compTimeInfo);
	score(spaceships, 0, spaceships.size());
	
	//Sort the score
	sort(winners.begin(), winners.end(), compWinInfo);


	//Print result
	for (int i = 0; i < spaceships.size(); i++)
		cout << winners[i].id << " " << winners[i].score<<endl;

	////DEBUG ONLY!!
	//print(winners);

	//EXIT:
	return 0;
}

bool validateNumberOfShips(int numberOfShips)
{
	if (numberOfShips >= 0 && numberOfShips <= 70000)
		return true;
	return false;
}
bool validID(int id) 
{
	if (id >= 0 && id <= pow(10, 9))
		return true;
	return false;
}
bool validStartTime(int startTime, int endTime)
{
	if (startTime >= 0 && startTime < endTime && endTime <= pow(10, 18))
		return true;
	return false;
}
bool validEndTime(int endTime, int startime)
{
	if(endTime <= pow(10, 18) && endTime > startime && startime >= 0)
		return true;
	return false;
}
bool noDuplicates(int id, int startTime, int endTime, vector<spaceship> spaceships)
{
	bool valid = true;

	for (int i = 0; i < spaceships.size(); i++)
	{
		if (spaceships[i].id == id || spaceships[i].startTime == startTime || spaceships[i].endTime == startTime)
		{
			valid = false;
			break;
		}
	}

	return valid;
}

bool compTimeInfo(const spaceship sp1, const spaceship sp2) {
	return sp1.startTime > sp2.startTime;
}
bool compWinInfo(const spaceship sp1, const spaceship sp2) {
	bool result = false;
	if (sp1.score < sp2.score)
		result = true;
	else if (sp1.score > sp2.score)
		result = false;
	else if (sp1.score == sp2.score)
	{
		if (sp1.id < sp2.id)
			result = true;
		else
			result = false;
	}

	return result;
}
void score(vector<spaceship> spaceships, int startIndex, int endIndex)
{
	if (startIndex != endIndex)
	{
		int in = startIndex;
		if (winners.empty())
		{
			winners.resize(1);
			spaceships[0].score = 0;
			winners[startIndex] = spaceships[0];
			in++;
			score(spaceships, in, endIndex);
		}
		else
		{
			spaceship highest = spaceships[startIndex];
			for (int i = winners.size()-1; i >= 0; i--)
			{
				if (highest.startTime < winners[i].startTime)
				{
					if (highest.endTime > winners[i].endTime)
						highest.score++;
					
				}
			}
			winners.resize(winners.size() + 1);
			winners[winners.size() - 1] = highest;
			in++;
			score(spaceships, in, endIndex);
		}
	}
}

/////////////////////////////
//For debug purposes only!
/////////////////////////////
void print(vector<spaceship> spaceships)
{
	cout << left << setw(18) << "SpaceShip ID" << setw(16) << "Start Time" << setw(11) <<"End Time"<<"Score\n";
	
	for (int i =0; i < spaceships.size(); i++)
		cout << left << setw(18) << spaceships[i].id << setw(16) << spaceships[i].startTime<<setw(11) << spaceships[i].endTime<<spaceships[i].score << endl;
}