// GuestGeneration.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

float variance(float maxVariance)
{
	float a = rand() % (int)(maxVariance * 1000 * 2);
	a -= (int)(maxVariance * 1000);
	a /= 1000.0;
	return a;
}

float clamp(float in) //Clamps to 1.0 if more than 1, clamps to 0.0 if less than 0
{
	if (in > 1.0)
		return 1.0;
	if (in < 0.0)
		return 0.0;
	return in;
}

int main()
{
	srand(time(NULL));

	//Capture the variables
	cout << "__--==Welcome to Motanum's Guest Clone Generation for Parkitect!==--__\n\n";
	cout << "What's the start ID for guests? (Integer, recommend 5000): ";
	int iStartID;
	cin >> iStartID;
	
	cout << "How many clones do you want? (Integer): ";
	int iCloneSize;
	cin >> iCloneSize;

	cout << "What is the clones' First Name? (String): ";
	string sFName;
	cin.ignore();
	getline(cin, sFName);

	cout << "Clones' Last Name? (String): ";
	string sLName;
	getline(cin, sLName);


	cout << "\nMaximum Variance for Clones' properties? \n(float, 0 is no variance, 0.0 < X < 1.0): ";
	float fMaxVar;
	cin >> fMaxVar;

	cout << "nausea Tolerance? (float, 0.0 < X < 1.0): ";
	float fNauseaTol;
	cin >> fNauseaTol;
	cout << "Minimum Intensity? (float, 0.0 < X < 1.0): ";
	float fMinIntensity;
	cin >> fMinIntensity;
	cout << "Maximum Intensity? (float, 0.0 < X < 1.0): ";
	float fMaxIntensity;
	cin >> fMaxIntensity;
	
	cout << "\nPatience? (float, 0.0 < X < 1.0): ";
	float fPatience;
	cin >> fPatience;
	cout << "Grumpiness? (float, 0.0 < X < 1.0): ";
	float fGrump;
	cin >> fGrump;
	cout << "Tidiness? (float, 0.0 < X < 1.0): ";
	float fTidy;
	cin >> fTidy;
	cout << "Generosity? (float, 0.0 < X < 1.0): ";
	float fGen;
	cin >> fGen;



	//ready to check out
	ofstream textOut;
	textOut.open("GuestName.txt");

	//Template
	//{\"@type\":\"Guest\",\"@id\":\"5000\",\"pos\":[3.52857471,3.,9.132595],\"rot\":[0.,0.,0.,1.],\"@c\":[[0.882352948,0.6745098,0.5882353],[0.0481615141,0.00326693058,0.7974111]],\"tilesWalked\":10,\"guestNumber\":0,\"moneySpent\":0.,\"parkEnterTime\":0,\"Happiness\":0.649817765,\"Tiredness\":0.184731886,\"Hunger\":0.0649227,\"Thirst\":0.0528742746,\"ToiletUrgency\":0.07982846,\"Nausea\":0.,\"NauseaTolerance\":0.48,\"SugarBoost\":0.,\"Money\":78.03635,\"MinIntensity\":0.111366414,\"MaxIntensity\":0.379782766,\"Patience\":0.29,\"Grumpiness\":0.3672264,\"Tidiness\":0.285902023,\"Generosity\":0.166157886,\"spawnedAtTime\":11658,\"dirtEncountered\":0.,\"parkEntranceFeePaid\":-1.,\"lastMoneySpentTime\":11658.,\"tiredStartTime\":11669.,\"angryStartTime\":11669.,\"priceSatisfactionSum\":0.,\"priceSatisfactionCount\":0,\"happinessBeforeEnteringAttraction\":0.,\"experienceLog\":{\"@type\":\"ExperienceLog\",\"experiences\":[]},\"forename\":\"Roger\",\"surname\":\"Clone\",\"nickname\":\"\",\"gender\":\"MALE\",\"headstyle\":0,\"torsostyle\":1,\"legsstyle\":1,\"hairstyle\":0,\"eyesstyle\":6,\"browsstyle\":15,\"uniqueID\":-1,\"triggerExperienceNotifications\":false,\"behaviour\":{\"@type\":\"RoamingBehaviour\"},\"inventory\":[\"\"]}

	for (int i = 0; i < iCloneSize; i++)
	{
		textOut << "{\"@type\":\"Guest\",\"@id\":\"" << iStartID + i << "\",\"pos\":[3.52857471,3.,9.132595],\"rot\":[0.,0.,0.,1.],\"@c\":[[0.882352948,0.6745098,0.5882353],"
			<< "[0.0481615141,0.00326693058,0.7974111]],\"tilesWalked\":10,\"guestNumber\":0,\"moneySpent\":0.,\"parkEnterTime\":0,"
			<< "\"Happiness\":1.0,\"Tiredness\":0.0,\"Hunger\":0.0,\"Thirst\":0.0,\"ToiletUrgency\":0.0,"
			<< "\"Nausea\":0.0,\"NauseaTolerance\":" << clamp(fNauseaTol + variance(fMaxVar)) << ",\"SugarBoost\":0.0,\"Money\":250,"
			<< "\"MinIntensity\":" << clamp(fMinIntensity + variance(fMaxVar)) << ",\"MaxIntensity\":" << clamp(fMaxIntensity + variance(fMaxVar)) << ","
			<< "\"Patience\":" << clamp(fPatience + variance(fMaxVar)) << ",\"Grumpiness\":" << clamp(fGrump + variance(fMaxVar)) << ","
			<< "\"Tidiness\":" << clamp(fTidy + variance(fMaxVar)) << ",\"Generosity\":" << clamp(fGen + variance(fMaxVar)) << ","
			<< "\"spawnedAtTime\":11658,\"dirtEncountered\":0.,"
			<< "\"parkEntranceFeePaid\":-1.,\"lastMoneySpentTime\":11658.,\"tiredStartTime\":11669.,\"angryStartTime\":11669.,\"priceSatisfactionSum\":0.,"
			<< "\"priceSatisfactionCount\":0,\"happinessBeforeEnteringAttraction\":0.,\"experienceLog\":{\"@type\":\"ExperienceLog\",\"experiences\":[]},"
			<< "\"forename\":\"" << sFName << "\",\"surname\":\"" << sLName << "\",\"nickname\":\"\",\"gender\":\"MALE\",\"headstyle\":0,\"torsostyle\":1,\"legsstyle\":1,\"hairstyle\":0,"
			<< "\"eyesstyle\":6,\"browsstyle\":15,\"uniqueID\":-1,\"triggerExperienceNotifications\":false,\"behaviour\":{\"@type\":\"RoamingBehaviour\"},\"inventory\":[\"\"]}\n";
	}	
	textOut.close();
	cout << "\nDone!\n";
	system("pause");
    return 0;
}

