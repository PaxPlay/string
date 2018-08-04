#include <iostream>
#include "../string.h"

using pax::string;

/**
 * Some stupid tests. Tested for memory leaks with valgrind.
 */

int main()
{
    std::cout << "Starting tests." << std::endl;

    {
        string s1("Hello.");
        string s2(s1);

        std::cout << s2.c_str() << std::endl;

        std::cout << s2.length() << std::endl;
    }

    {
        string s1;
        s1 = "Hello.";
        string s2 = s1;

        s2 = "Test 123";

        std::cout << s2.c_str() << std::endl;

        std::cout << s2.length() << std::endl;
    }

    {
        string s1;
        s1.append("Hello ");

        std::cout << s1.c_str() << std::endl;

        string s2("this is a test!");
        s1.append(s2);

        std::cout << s1.c_str() << std::endl;

        s1.append(" and apperently this works.", 27);

        std::cout << s1.c_str() << std::endl;
    }

    return 0;
}