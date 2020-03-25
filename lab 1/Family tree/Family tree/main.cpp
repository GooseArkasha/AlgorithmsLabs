#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "FamilyMember.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int menueMode = 1;
	string buffer;

	FamilyMember familyFounder;
	FamilyMember::currentFamilyMember = &familyFounder;
	cout << "Enter the name of the originator of the family: ";
	cin >> buffer;
	familyFounder.setName(buffer);

	
	
	
	while (menueMode != 0) {

		system("cls");
		FamilyMember::currentFamilyMember->showCurrentFamilyMember();

		cout << endl;
		cout << "Select an action:" << endl;
		cout << "\tEnter or change the name of the current family member\t1" << endl;
		cout << "\tAdd a child for the current family member\t2" << endl;
		cout << "\tGo to parent\t3" << endl;
		cout << "\tGo to child\t4" << endl;
		cout << "\tGet information about the type of relationship\t5" << endl;
		cout << "\tGet full information about a family member\t6" << endl;
		cout << "\tExit application\t0" << endl;
		cout << endl << "Your choice: ";

		cin >> menueMode;

		switch (menueMode) {
		case 0: 
			break;
		case 1:
			system("cls");
			cout << "Enter the name: ";
			cin >> buffer;
			FamilyMember::currentFamilyMember->setName(buffer);
			system("pause");
			break;
		case 2: {
			system("cls");
			cout << "Enter the child's name: ";
			cin >> buffer;
			FamilyMember tempFamilyMember(buffer);
			FamilyMember::currentFamilyMember->addChild(tempFamilyMember);
		}
			break;
		case 3:
			FamilyMember::currentFamilyMember->goToParent();
			break;
		case 4:
		{
			FamilyMember::currentFamilyMember->showCurrentFamilyMenberFullInfo();
			cout << "Enter the index of the child you want to switch to: ";
			int childIndex;
			cin >> childIndex;
			FamilyMember::currentFamilyMember->goToChild(childIndex);
		}
			break;
		case 5:
		{
			string firstName, secondName;
			cout << "Enter the fist name:";
			cin >> firstName;
			cout << "Enter the stcond name: ";
			cin >> secondName;
			FamilyMember::showTypeOfRelationship(firstName, secondName, &familyFounder);
			system("pause");
		}
			break;
		case 6:
			system("cls");
			FamilyMember::currentFamilyMember->showCurrentFamilyMenberFullInfo();
			system("pause");
			break;
		default:
			cout << "Entry mistake" << endl;
			system("pause");
		}
	}

	return 0;
}