#pragma once
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

#ifndef ESSENSESTREAM_H
#define ESSENSESTREAM_H 

class Conversion { // this class converts variable from one type to other type
public:
	template<typename Converse>
	Converse convert(const Converse& variableToOtherType);
	template<typename Converse>
	std::string toString(const Converse& variableToString); // the method for convertising variables to string
	template<typename Converse>
	Converse fromStringToOtherType(const std::string& toVariableOfOtherType); // the method for convertising from string to types
};

class Boolean { // this class for working with bool variables
private:
	enum LogicOperations { // logic operations for comparison two variables and values
		LESS, MORE, LESS_OR_EQUAL, MORE_OR_EQUAL, NOT_EQUAL, EQUAL
	};
public:
	template<typename Bool>
	void valueOf(Bool* hasValue); // Check value of the variable
	template<typename Bool>
	bool isBool(Bool checkBool);
	template<typename Bool>
	bool comparison(Bool firstValue, LogicOperations logic_operator, Bool secondValue); // this method includes all logic operations for comparison two variables and values
	LogicOperations logicOperator(const std::string operation);
};

class ArithmeticStream { // This class for working with the arithmetic types and values of the variables including short, long, int, float double types

private:
	enum ArithmeticSystems { // enumeration for defining system notations of the arithmetic variables and values
		BINARY, DECIMAL, OCTAL, HEXADECIMAL, DUODECIMAL, VIGESIMAL
	};
	enum ArithmeticTypes { // Arithmetic types themselves
		INT, SHORT, LONG, FLOAT, DOUBLE
	};
public:
	template<typename stream>
	stream convertstream(stream convert, ArithmeticTypes convertToOtherType); // for convertising from one arithmetic type to other arithmetic type
	int digitCount(unsigned int variable, int digit);
	template<typename whatType>
	bool checkType(whatType variable, std::string type); // for checking arithmetic types of the variables
	std::string toOtherSystemString(unsigned int value, ArithmeticSystems systemNotation);
	ArithmeticSystems system(const std::string toOtherSystem); // for transfering to other system notation
	ArithmeticTypes type(const std::string toOtherType);
};

// These traits for checking types 

template<typename IS_SIZE_T>
struct is_size_t : std::is_same<IS_SIZE_T, size_t> {};
template<typename IS_WCHAR_T>
struct is_wchar_t : std::is_same<IS_WCHAR_T, wchar_t> {};
template<typename IS_ERRNO_T>
struct is_errno_t : std::is_same<IS_ERRNO_T, errno_t> {};
template<typename IS_NULLPTR_T>
struct is_nullptr_t : std::is_null_pointer<IS_NULLPTR_T> {};

class Path { // This class includes working and correction file paths
public:
	std::string getNamePath(const std::filesystem::path path_file_txt); // Name of the path itself
	std::filesystem::path normalizePath(const std::filesystem::path pathFileTxt);
	std::string addTrailingSlashInPath(const std::string pathFileTxt); // this method adds slash to your path in the end 
	char getTrailingSlashFromPath(const std::string pathFileTxt); // for getting slash in the end
};

class Buffer { // this class includes simple writing the string data to buffer for saving data itself
public:
	void write(const std::string value, const std::string& name_buffer_txt, const std::string& file_extension);
	std::string readFromFile(const std::string name_buffer_txt);
	void clearFile(const std::string nameBufferTxt); // for clear the buffer itself
	void deleteFile(const std::string name_buffer_txt); // for deleting buffer like file
};

class Bitwise { // this class has bit operations and methods for working with 0 and 1 bits 
private:
	enum BitwiseOperations {
		NOT, AND, OR, XOR, RIGHT_SHIFT, LEFT_SHIFT
	};
public:
	unsigned int bitRealize(unsigned int firstValue, BitwiseOperations bit_operator, unsigned int secondValue = 0);
	BitwiseOperations bitOperator(const std::string operation);
	int countBits(unsigned int bitValue);
	std::string toBinaryString(unsigned int value);
	std::pair<__int64, __int64> countOneAndZero(const std::string bitWiseNumber);
};

#endif