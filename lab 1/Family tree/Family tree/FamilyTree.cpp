#include "FamilyTree.h"
#include <iostream>
using namespace std;

FamilyTree::FamilyTree() {
	familyFounder = nullptr;
}

FamilyTree::FamilyTree(string familyFounderName) {

	FamilyMember tempFamilyMember(familyFounderName);
	familyFounder = &tempFamilyMember;
}

FamilyMember* FamilyTree::getFamilyFounder() {
	return familyFounder;
}