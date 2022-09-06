#include <time.h>
#include "Controller.h"
#include "MyException.h"

int main()
{
	srand(time(NULL));
	try
	{
		Controller c;
		c.run();
		return 0;
	}
	catch (MyException & e)//אם הקובץ לא נפתח
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch (...) {}
}
