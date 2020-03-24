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

public:

	static FamilyMember* currentFamilyMember;	//Позволит перемещаться между членами семьи

	FamilyMember();
	FamilyMember(string name);
	FamilyMember(const FamilyMember& family);

	void setName(string name);
	string getName();

	void addChild(FamilyMember child);

	void showChildren();

	FamilyMember* getChild(string name);

	void showCurrentFamilyMember();
	void showCurrentFamilyMenberFullInfo();
};

