#include "StaffList.h"

#include "StaffMember.h"

bool StaffList::showProfessors()
{
	int count = 0;
	for (int i = 0; i < this->getNumberOfObjects(); i++)
	{
		StaffMember* member = (StaffMember*)this->getObjectByHardIndex(i);
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