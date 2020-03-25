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

void FamilyMember::addChild(FamilyMember child) {
	numberOfChildren++;
	
	children.push_back(child);
	children[children.size() - 1].parent = this;
}

void FamilyMember::showChildren() {
	cout << "Дети члена семьи по имени " << getName() << ":" << endl;
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
	SetConsoleCP(1251);			//Задаем кодировку для вывода символов в консоли
	SetConsoleOutputCP(1251);	//Задаем кодировку для ввода символов в консоли
	cout << "Текущий член семьи: " << currentFamilyMember->getName();
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