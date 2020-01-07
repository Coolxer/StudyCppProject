#pragma once
#include <vector>
#include <string>

#include "StaffMember.h"

class StaffList
{
private:
	int startId;
	std::vector <StaffMember> staffMembers;
public:
	StaffList();
	~StaffList();

	int addMember(StaffMember* s);
	int removeMember(int id);
	bool showStaff();
	bool showMemberbyId(int id);

	bool showProfessors();

	int getNumberOfMembers();
};

