#include "FamilyMember.h"
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

FamilyMember* FamilyMember::currentFamilyMember;

FamilyMember::FamilyMember() {
	this->name = "not initialized";
	this->parent = this;
	this->numberOfChildren = 0;
}

FamilyMember::FamilyMember(string name) {
	this->name = name;
	this->parent = this;
	this->numberOfChildren = 0;
}

FamilyMember::FamilyMember(const FamilyMember& family) {
	this->name = family.name;
	this->parent = family.parent;
	this->numberOfChildren = family.numberOfChildren;
	this->children = family.children;
}

void FamilyMember::setName(string name) {
	this->name = name;
}

string FamilyMember::getName() {
	return name;
}

vector <FamilyMember> FamilyMember::getChildren() {
	return children;
}

void FamilyMember::addChild(FamilyMember child) {
	numberOfChildren++;
	
	children.push_back(child);
	children[children.size() - 1].parent = this;
}

void FamilyMember::showChildren() {
	cout << "Children of a family member named " << getName() << ":" << endl;
	for (int i = 0; i < children.size(); i++) {
		cout << "\t" << i << ". " << children[i].getName() << "; " << endl;
	}
}

FamilyMember* FamilyMember::getChild(string name) {
	for (int i = 0; i < children.size(); i++) {
		if (children[i].name == name) {
			return &children[i];
		}
	}
}


void FamilyMember::showCurrentFamilyMember() {
	SetConsoleCP(1251);	
	SetConsoleOutputCP(1251);

	cout << "Current family member: " << currentFamilyMember->getName();
}

void FamilyMember::showCurrentFamilyMenberFullInfo() {
	currentFamilyMember->showChildren();
}

void FamilyMember::goToParent() {
	currentFamilyMember = parent;
}

void FamilyMember::goToChild(int childIndex) {
	if (childIndex < numberOfChildren) {
		currentFamilyMember = &children[childIndex];
	}
}

void FamilyMember::showTypeOfRelationship(string firstName, string secondName, FamilyMember* familyFounderPtr) {
	
	vector <FamilyMember*> firstVector;
	firstVector.push_back(familyFounderPtr);

	vector <FamilyMember*> secondVector;
	secondVector.push_back(familyFounderPtr);

	bool firstFlag = false, secondFlag = false;

	traversePreorder(familyFounderPtr, firstVector, secondVector, firstName, secondName, &firstFlag, &secondFlag);

	cout << "Vec1" << endl;
	for (int i = 0; i < firstVector.size(); i++) {
		cout << firstVector[i]->getName() << endl;
	}

	cout << "Vec2" << endl;
	for (int i = 0; i < secondVector.size(); i++) {
		cout << secondVector[i]->getName() << endl;
	}
}

void FamilyMember::traversePreorder(FamilyMember* node, vector <FamilyMember*> firstVector,
	vector <FamilyMember*> secondVector, string firstName, string secondName,
	bool* firstFlag, bool* secondFlag) {

	vector <FamilyMember> temp = node->getChildren();
	cout << "vec1" << endl;
	for (int i = 0; i < firstVector.size(); i++) {
		cout << firstVector[i]->getName() << endl;
	}

	cout << "vec2" << endl;
	for (int i = 0; i < secondVector.size(); i++) {
		cout << secondVector[i]->getName() << endl;
	}

	if (*firstFlag == false) {
		if (node->getName() == firstName) {
			*firstFlag = true;
		} else {
			firstVector.push_back(node);
		}
	}

	if (*secondFlag == false) {
		if (node->getName() == secondName) {
			*secondFlag = true;
		}
		else {
			secondVector.push_back(node);
		}
	}

	if ((*firstFlag == false) || (*secondFlag == false)) {
		for (int i = 0; i < temp.size(); i++) {
				traversePreorder(&temp[i], firstVector, secondVector, firstName, secondName, firstFlag, secondFlag);
		}
	}

	if (*firstFlag == false) {
		firstVector.pop_back();
	}

	if (*secondFlag == false) {
		secondVector.pop_back();
	}
}