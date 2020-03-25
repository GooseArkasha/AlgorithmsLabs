#pragma once
#include <string>
#include <iostream>
# include <vector>
using namespace std;

class FamilyMember
{
private:
	string name;
	FamilyMember *parent;
	int numberOfChildren;
	vector <FamilyMember> children;

	static void traversePreorder(FamilyMember* node, vector <FamilyMember*> firstVector,
		vector <FamilyMember*> secondVector, string firstName, string secondName,
		bool* firstFlag, bool *secondFlag);

public:

	static FamilyMember* currentFamilyMember;

	FamilyMember();
	FamilyMember(string name);
	FamilyMember(const FamilyMember& family);

	void setName(string name);
	string getName();

	vector <FamilyMember> getChildren();

	void addChild(FamilyMember child);

	void showChildren();

	FamilyMember* getChild(string name);

	void showCurrentFamilyMember();
	void showCurrentFamilyMenberFullInfo();

	void goToParent();
	void goToChild(int childIndex);


	static void showTypeOfRelationship(string firstName, string secondName, FamilyMember* familyFounderPtr);
};

