#include "MyException.h"


const char* MyException::what() const noexcept
{
	return "The file did not open";
}
