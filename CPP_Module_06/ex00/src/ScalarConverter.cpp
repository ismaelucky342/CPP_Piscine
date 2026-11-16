#include "../includes/ScalarConverter.hpp"
#include <iomanip>

static bool isCharLiteral(const std::string& str)
{
	if (str.length() != 1)
		return false;
	char c = str[0];
	if (c >= 33 && c <= 126 && !std::isdigit(c))
		return true;
	return false;
}

static bool isPseudoLiteral(const std::string& str)
{
	return (str == "nan" || str == "nanf" ||
			str == "+inf" || str == "+inff" ||
			str == "-inf" || str == "-inff");
}

static bool isDisplayable(char c)
{
	return (c >= 32 && c <= 126);
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	// 1. Char literal: single printable non-digit character
	if (isCharLiteral(literal))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}

	// 2. Pseudo-literals
	if (isPseudoLiteral(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		{
			std::cout << "float: " << literal << std::endl;
			std::string dbl = literal.substr(0, literal.length() - 1);
			std::cout << "double: " << dbl << std::endl;
		}
		else
		{
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		return;
	}

	// 3. Numeric literals: parse once with strtod
	char* end = NULL;
	double value = std::strtod(literal.c_str(), &end);

	// Check if entire string was consumed
	if (*end != '\0')
	{
		// Allow 'f' suffix only if there's a decimal point in the parsed number
		if (*end == 'f' && *(end + 1) == '\0' && literal.find('.') != std::string::npos)
			end++;
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}
	if (end == literal.c_str())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// Char conversion
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if (isDisplayable(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}

	// Int conversion
	if (std::isnan(value) || std::isinf(value) ||
		value > static_cast<double>(INT_MAX) ||
		value < static_cast<double>(INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// Float conversion
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value))
		std::cout << "float: " << (value < 0 ? "-inff" : "inff") << std::endl;
	else if (value > static_cast<double>(FLT_MAX) || value < -static_cast<double>(FLT_MAX))
		std::cout << "float: impossible" << std::endl;
	else
	{
		float f = static_cast<float>(value);
		if (f == static_cast<int>(f))
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}

	// Double conversion
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value))
		std::cout << "double: " << (value < 0 ? "-inf" : "inf") << std::endl;
	else
	{
		if (value == static_cast<int>(value))
			std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
		else
			std::cout << "double: " << value << std::endl;
	}
}
