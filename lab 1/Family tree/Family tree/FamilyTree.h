#pragma once
#include "FamilyMember.h"
#include <string>


class FamilyTree {

private:
	FamilyMember* familyFounder;

public:
	FamilyTree();
	FamilyTree(string familyFounderName);
	FamilyMember* getFamilyFounder();
};

