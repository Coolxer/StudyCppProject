#include "StaffList.h"

#include "StaffMember.h"

bool StaffList::showProfessors()
{
	int count = 0;
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		StaffMember* member = (StaffMember*)&this->objects[i];
		if (member->isProfessor())
		{
			member->show();
			count++;
		}
	}

	if (count > 0)
		return true;

	return false;
}