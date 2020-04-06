#include "IndividualPerson.h"
#include <iostream>

void IndividualPerson::Print()
{
	std::cout << "Физическое лицо. " << _firstName << " " << _secondName << "; " << _account;
}
