#pragma once
#include <vector>
#include <string>

#include "StaffMember.h"

class StaffList
{
private:
	int index;
	std::vector <StaffMember> staffMembers;
public:
	StaffList();
	~StaffList();

	int addMember(StaffMember* s);
	int removeMember(int index);

	bool showStaff();
	bool showMemberbyId(int index);
	bool showProfessors();

	int getNumberOfMembers();
};

