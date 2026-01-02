#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    return 0;
}


// #include "ScalarConverter.hpp"
// #include <iostream>
// #include <limits>

// int main()
// {


//     std::cout << "\n========== CHAR TESTS ==========" << std::endl;
    
//     std::cout << "\nTest: './convert 'a''" << std::endl;
//     ScalarConverter::convert("'a'");
    
//     std::cout << "\nTest: './convert 'Z''" << std::endl;
//     ScalarConverter::convert("'Z'");
    
//     std::cout << "\nTest: './convert '0''" << std::endl;
//     ScalarConverter::convert("'0'");
    
//     std::cout << "\n========== INT TESTS ==========" << std::endl;
    
//     std::cout << "\nTest: './convert 0'" << std::endl;
//     ScalarConverter::convert("0");
    
//     std::cout << "\nTest: './convert 42'" << std::endl;
//     ScalarConverter::convert("42");
    
//     std::cout << "\nTest: './convert -42'" << std::endl;
//     ScalarConverter::convert("-42");
    
//     std::cout << "\nTest: './convert 127'" << std::endl;
//     ScalarConverter::convert("127");
    
//     std::cout << "\nTest: './convert 128'" << std::endl;
//     ScalarConverter::convert("128");
    
//     std::cout << "\n========== FLOAT TESTS ==========" << std::endl;
    
//     std::cout << "\nTest: './convert 0.0f'" << std::endl;
//     ScalarConverter::convert("0.0f");
    
//     std::cout << "\nTest: './convert 42.0f'" << std::endl;
//     ScalarConverter::convert("42.0f");
    
//     std::cout << "\nTest: './convert -4.2f'" << std::endl;
//     ScalarConverter::convert("-4.2f");
    
//     std::cout << "\nTest: './convert 4.2f'" << std::endl;
//     ScalarConverter::convert("4.2f");
    
//     std::cout << "\nTest: './convert 42.42f'" << std::endl;
//     ScalarConverter::convert("42.42f");
    
//     std::cout << "\n========== DOUBLE TESTS ==========" << std::endl;
    
//     std::cout << "\nTest: './convert 0.0'" << std::endl;
//     ScalarConverter::convert("0.0");
    
//     std::cout << "\nTest: './convert 42.0'" << std::endl;
//     ScalarConverter::convert("42.0");
    
//     std::cout << "\nTest: './convert -4.2'" << std::endl;
//     ScalarConverter::convert("-4.2");
    
//     std::cout << "\nTest: './convert 4.2'" << std::endl;
//     ScalarConverter::convert("4.2");
    
//     std::cout << "\n========== SPECIAL FLOAT TESTS ==========" << std::endl;
    
//     std::cout << "\nTest: './convert nanf'" << std::endl;
//     ScalarConverter::convert("nanf");
    
//     std::cout << "\nTest: './convert +inff'" << std::endl;
//     ScalarConverter::convert("+inff");
    
//     std::cout << "\nTest: './convert -inff'" << std::endl;
//     ScalarConverter::convert("-inff");
    
//     std::cout << "\n========== SPECIAL DOUBLE TESTS ==========" << std::endl;
    
//     std::cout << "\nTest: './convert nan'" << std::endl;
//     ScalarConverter::convert("nan");
    
//     std::cout << "\nTest: './convert +inf'" << std::endl;
//     ScalarConverter::convert("+inf");
    
//     std::cout << "\nTest: './convert -inf'" << std::endl;
//     ScalarConverter::convert("-inf");
    
//     std::cout << "\n========== EDGE CASES ==========" << std::endl;
    
//     std::cout << "\nTest: './convert 2147483647' (INT_MAX)" << std::endl;
//     ScalarConverter::convert("2147483647");
    
//     std::cout << "\nTest: './convert -2147483648' (INT_MIN)" << std::endl;
//     ScalarConverter::convert("-2147483648");
    
//     std::cout << "\nTest: './convert 300.5f' (out of char range)" << std::endl;
//     ScalarConverter::convert("300.5f");
    
//     std::cout << "\n========== INVALID TESTS ==========" << std::endl;
    
//     std::cout << "\nTest: './convert abc'" << std::endl;
//     ScalarConverter::convert("abc");
    
//     std::cout << "\nTest: './convert 42f' (no decimal)" << std::endl;
//     ScalarConverter::convert("42f");
    
//     std::cout << "\nTest: './convert \"\"' (empty)" << std::endl;
//     ScalarConverter::convert("");
    
//     std::cout << "\nTest: './convert 42.0.0'" << std::endl;
//     ScalarConverter::convert("42.0.0");
    
//     return 0;
// }
