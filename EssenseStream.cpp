#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <filesystem>

class Conversion {
public:
	template<typename Converse>
	Converse convert(const Converse& variableToOtherType) {
		try {
			Converse value = static_cast<Converse>(variableToOtherType);
			return value;
		}
		catch (std::invalid_argument& e) {
			std::string eWhat = e.what();
			throw std::runtime_error("Conversion error from one type to other type: " + eWhat);
		}
	}

	template<typename Converse>
	std::string toString(const Converse& variableToString) {
		try {
			std::ostringstream convertToString;
			convertToString << variableToString;
			std::string convertResult = convertToString.str();
			return convertResult;
		}
		catch (std::invalid_argument& e) {
			std::string eWhat = e.what();
			throw std::runtime_error("Conversion error from another type to string: " + eWhat);
		}
	}

	template<typename Converse>
	Converse fromStringToOtherType(const std::string& toVariableOfOtherType) {
		try {
			std::istringstream toOtherType{ toVariableOfOtherType };
			Converse otherType;
			toOtherType >> otherType;
			return otherType;
		}
		catch (std::invalid_argument& e) {
			std::string eWhat = e.what();
			throw std::runtime_error("Conversion error from one type to other type: " + eWhat);
		}
	}
};

class Boolean {
private:
	enum LogicOperations {
		LESS, MORE, LESS_OR_EQUAL, MORE_OR_EQUAL, NOT_EQUAL, EQUAL
	};
public:
	template<typename Bool>
	void valueOf(Bool* hasValue) {
		if (hasValue == nullptr) throw std::runtime_error("Null value");
		std::cout << (*hasValue) << std::endl;
	}
	template<typename Bool>
	bool isBool(Bool checkBool) {
		return typeid(checkBool) == typeid(bool);
	}
	template<typename Bool>
	bool comparison(Bool firstValue, LogicOperations logic_operator, Bool secondValue) {
		switch (logic_operator) {
		case LogicOperations::LESS:
			return (firstValue < secondValue);
			break;
		case LogicOperations::MORE:
			return (firstValue > secondValue);
			break;
		case LogicOperations::LESS_OR_EQUAL:
			return (firstValue <= secondValue);
			break;
		case LogicOperations::MORE_OR_EQUAL:
			return (firstValue >= secondValue);
			break;
		case LogicOperations::NOT_EQUAL:
			return (firstValue != secondValue);
			break;
		case LogicOperations::EQUAL:
			return (firstValue == secondValue);
			break;
		default:
			throw std::runtime_error("Unknown operator");
			break;
		}
	}

	LogicOperations logicOperator(const std::string operation) {
		if (operation == "<") return LogicOperations::LESS;
		if (operation == ">") return LogicOperations::MORE;
		if (operation == "<=") return LogicOperations::LESS_OR_EQUAL;
		if (operation == ">=") return LogicOperations::MORE_OR_EQUAL;
		if (operation == "!=") return LogicOperations::NOT_EQUAL;
		if (operation == "==") return LogicOperations::EQUAL;
	}
};

class ArithmeticStream {
private:
	enum ArithmeticSystems {
		BINARY, DECIMAL, OCTAL, HEXADECIMAL, DUODECIMAL, VIGESIMAL
	};
	enum ArithmeticTypes {
		INT, SHORT, LONG, FLOAT, DOUBLE
	};
public:
	template<typename stream>
	stream convertstream(stream convert, ArithmeticTypes convertToOtherType) {
		try {
			if (std::is_arithmetic(convert)) {
				switch (convertToOtherType) {
				case INT:
					int intResult = static_cast<stream>(convert);
					return intResult;
					break;
				case SHORT:
					short shortResult = static_cast<stream>(convert);
					return shortResult;
					break;
				case LONG:
					long longResult = static_cast<stream>(convert);
					return longResult;
					break;
				case FLOAT:
					float floatResult = static_cast<stream>(convert);
					return floatResult;
					break;
				case DOUBLE:
					double doubleResult = static_cast<stream>(convert);
					return doubleResult;
					break;
				default:
					throw std::runtime_error("Unknown type");
					break;
				}
			}
			else {
				throw std::runtime_error("Type is not arithmetic");
			}
		}
		catch (std::invalid_argument& e) {
			std::string eWhat = e.what();
			throw std::runtime_error("Convertise type error: " + eWhat);
		}
	}

	int digitCount(unsigned int variable, int digit) {
		if (variable == 0) return 1;
		if (variable < 0) variable -= variable;
		int count = 0;
		while (variable > 0) {
			variable /= digit;
			++count;
		}
		return count;
	}

	template<typename whatType>
	bool checkType(whatType variable, std::string type) {
		if (type == "int") return typeid(variable) == typeid(int);
		if (type == "short") return typeid(variable) == typeid(short);
		if (type == "long") return typeid(variable) == typeid(long);
		if (type == "float") return typeid(variable) == typeid(float);
		if (type == "double") return typeid(variable) == typeid(double);
		throw std::runtime_error("Unknown type");
	}

	std::string toOtherSystemString(unsigned int value, ArithmeticSystems systemNotation) {
		if (value == 0) return "0";
		std::string systemString;
		switch (systemNotation) {
		case BINARY:
			while (value > 0) {
				systemString = std::to_string(value % 2) + systemString;
				value = value / 2;
			}
			return systemString;
			break;
		case OCTAL:
			while (value > 0) {
				systemString = std::to_string(value % 8) + systemString;
				value = value / 8;
			}
			return systemString;
			break;
		case DECIMAL:
			while (value > 0) {
				systemString = std::to_string(value % 10) + systemString;
				value = value / 10;
			}
			return systemString;
			break;
		case DUODECIMAL:
			while (value > 0) {
				systemString = std::to_string(value % 12) + systemString;
				value = value / 12;
			}
			return systemString;
			break;
		case HEXADECIMAL:
			while (value > 0) {
				systemString = std::to_string(value % 16) + systemString;
				value = value / 16;
			}
			return systemString;
			break;
		case VIGESIMAL:
			while (value > 0) {
				systemString = std::to_string(value % 20) + systemString;
				value = value / 20;
			}
			return systemString;
			break;
		default:
			throw std::runtime_error("Unknown system");
			break;
		}
	}

	ArithmeticSystems system(const std::string toOtherSystem) {
		if (toOtherSystem == "BINARY") return ArithmeticSystems::BINARY;
		if (toOtherSystem == "OCTAL") return ArithmeticSystems::OCTAL;
		if (toOtherSystem == "DECIMAL") return ArithmeticSystems::DECIMAL;
		if (toOtherSystem == "DUODECIMAL") return ArithmeticSystems::DUODECIMAL;
		if (toOtherSystem == "HEXADECIMAL") return ArithmeticSystems::HEXADECIMAL;
		if (toOtherSystem == "VIGESIMAL") return ArithmeticSystems::VIGESIMAL;
	}

	ArithmeticTypes type(const std::string toOtherType) {
		if (toOtherType == "int") return ArithmeticTypes::INT;
		if (toOtherType == "short") return ArithmeticTypes::SHORT;
		if (toOtherType == "long") return ArithmeticTypes::LONG;
		if (toOtherType == "float") return ArithmeticTypes::FLOAT;
		if (toOtherType == "double") return ArithmeticTypes::DOUBLE;
	}
};

template<typename IS_SIZE_T>
struct is_size_t : std::is_same<IS_SIZE_T, size_t> {};
template<typename IS_WCHAR_T>
struct is_wchar_t : std::is_same<IS_WCHAR_T, wchar_t> {};
template<typename IS_ERRNO_T>
struct is_errno_t : std::is_same<IS_ERRNO_T, errno_t> {};
template<typename IS_NULLPTR_T>
struct is_nullptr_t : std::is_null_pointer<IS_NULLPTR_T> {};

class Path {
public:
	std::filesystem::path getNamePath(const std::filesystem::path path_file_txt) {
		if (std::filesystem::exists(path_file_txt)) return path_file_txt.string();

		int call_error = errno;

		std::string WrongPathException = "WrongPathException: " + call_error;

		throw std::system_error(call_error, std::generic_category(), WrongPathException);
	}
	std::filesystem::path normalizePath(const std::filesystem::path pathFileTxt) {
		std::filesystem::path p = std::filesystem::absolute(pathFileTxt);
		std::filesystem::path normalized_path;
		for (const auto& part : p) {
			if (part == "..") {
				if (!normalized_path.empty()) {
					normalized_path.remove_filename();
				}
			}
			else if (part != ".") {
				normalized_path /= part;
			}
		}
		return normalized_path;
	}

	std::string addTrailingSlashInPath(const std::string pathFileTxt) {
		if (!pathFileTxt.empty() && pathFileTxt.back() != '/') {
			pathFileTxt.at(pathFileTxt.size() - 1) == '/';
		}
		return pathFileTxt;
	}

	char getTrailingSlashFromPath(const std::string pathFileTxt) {
		char getSlash;
		if (pathFileTxt.size() == 0) { throw std::runtime_error("System path to the file is empty"); }
		else if (pathFileTxt.at(pathFileTxt.size() - 1) != '/') { throw std::runtime_error("Trailing slash in the end of the path doesn't exist"); }
		else {
			auto findSlashInEndOfThePath = std::find(pathFileTxt.begin(), pathFileTxt.end(), pathFileTxt.at(pathFileTxt.size() - 1));
			getSlash = (*findSlashInEndOfThePath);
		};
		return getSlash;
	}
};

class Buffer {
public:
	void write(const std::string value, const std::string& name_buffer_txt, const std::string& file_extension) {
		std::ofstream write;
		std::string fileName = name_buffer_txt + file_extension;
		write.open(fileName);
		try {
			if (!write.is_open()) {
				int call_error = errno;
				std::string FileOpenError = "FileOpenError: " + call_error;
				throw std::runtime_error(FileOpenError);
			}
			else {
				write << value;
				write.close();
			}
		}
		catch (const std::filesystem::filesystem_error& e) {
			std::string FileErrorException = e.what();
			throw std::runtime_error("FileErrorException: " + FileErrorException);
		}
	}
	void clearFile(const std::string nameBufferTxt) {
		std::ofstream cleanTheFile;
		if (std::filesystem::exists(nameBufferTxt)) {
			cleanTheFile.open(nameBufferTxt);
			try {
				if (!cleanTheFile.is_open()) {
					int call_error = errno;
					std::string FileOpenError = "FileOpenError: " + call_error;
					throw std::runtime_error(FileOpenError);
				}
				else {
					cleanTheFile << " ";
					cleanTheFile.close();
				}
			}
			catch (std::filesystem::filesystem_error& e) {
				std::string FileErrorException = e.what();
				throw std::runtime_error("FileErrorException: " + FileErrorException);
			}
		}
		else {
			throw std::runtime_error("This file doesn't exist");
		}
	}
	std::string readFromFile(const std::string name_buffer_txt) {
		std::ifstream readline;
		readline.open(name_buffer_txt);
		if (std::filesystem::exists(name_buffer_txt)) {
			try {
				if (!readline.is_open()) {
					int call_error = errno;
					std::string FileOpenError = "FileOpenError" + call_error;
					throw std::runtime_error(FileOpenError);
				}
				else {
					std::string dataFromFile;
					std::getline(readline, dataFromFile);
					return dataFromFile;
				}
			}
			catch (const std::filesystem::filesystem_error& e) {
				std::string FileErrorException = e.what();
				throw std::runtime_error("FileErrorException: " + FileErrorException);
			}
		}
		else {
			throw std::runtime_error("This file doesn't exist");
		}
	}
	void deleteFile(const std::string name_buffer_txt) {
		if (std::filesystem::exists(name_buffer_txt)) {
			int call_error = errno;
			std::string FileDeleteException = "FileDeleteException" + call_error;
			throw std::runtime_error(FileDeleteException);
		}
		else {
			std::cout << "File was deleted successfully" << std::endl;
			std::cout << std::filesystem::remove(name_buffer_txt) << std::endl;
		}
	}
};

class Bitwise {
private:
	enum BitwiseOperations {
		NOT, AND, OR, XOR, RIGHT_SHIFT, LEFT_SHIFT
	};
public:
	unsigned int bitRealize(unsigned int firstValue, BitwiseOperations bit_operator, unsigned int secondValue = 0) {
		if (firstValue < 0 && secondValue < 0) {
			std::exception e;
			std::string eWhat = e.what();
			throw std::runtime_error("Negative numbers: " + eWhat);
		}
		else {
			switch (bit_operator) {
			case NOT:
				return ~(firstValue);
				break;
			case AND:
				return (firstValue & secondValue);
				break;
			case OR:
				return (firstValue | secondValue);
				break;
			case XOR:
				return (firstValue ^ secondValue);
				break;
			case LEFT_SHIFT:
				return (firstValue << secondValue);
				break;
			case RIGHT_SHIFT:
				return (firstValue >> secondValue);
				break;
			default:
				throw std::runtime_error("Unknown operator");
				break;
			}
		}
	}
	BitwiseOperations bitOperator(const std::string operation) {
		if (operation == "~") return BitwiseOperations::NOT;
		if (operation == "&") return BitwiseOperations::AND;
		if (operation == "|") return BitwiseOperations::OR;
		if (operation == "^") return BitwiseOperations::XOR;
		if (operation == "<<") return BitwiseOperations::LEFT_SHIFT;
		if (operation == ">>") return BitwiseOperations::RIGHT_SHIFT;
	}
	size_t countBits(unsigned int bitValue) {
		std::string bitString = std::to_string(bitValue);
		return bitString.size();
	}
	std::string toBinaryString(unsigned int value) {
		if (value == 0) return "0";
		std::string binaryString;
		while (value > 0) {
			binaryString = (value % 2 == 0 ? "0" : "1") + binaryString;
			value = value / 2;
		}
		return binaryString;
	}
	std::pair<__int64, __int64> countOneAndZero(const std::string bitWiseNumber) {
		for (auto checkBit = 0; checkBit < bitWiseNumber.size(); ++checkBit) {
			if (bitWiseNumber.at(checkBit) != '0' && bitWiseNumber.at(checkBit) != '1') {
				throw std::runtime_error("Unknown bit");
			}
		}
		auto countOne = std::count_if(bitWiseNumber.begin(), bitWiseNumber.end(), [](char foundOne) {return foundOne == '1'; });
		auto countZero = std::count_if(bitWiseNumber.begin(), bitWiseNumber.end(), [](char foundZero) {return foundZero == '0'; });
		return{ countOne, countZero };
	}
};