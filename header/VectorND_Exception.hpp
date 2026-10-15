/*

	N-Dimensional Vector math (exception class header)

	Steven - svill175
	10-15-2026

*/

#ifndef VECTORND_EXCEPTION_HPP
#define VECTORND_EXCEPTION_HPP

#include <exception>
#include <string>

class VectorND_Exception : public std::exception {
private:
	std::string errorMessage;
public:
	VectorND_Exception(std::string errMessage) : errorMessage(errMessage) {}
	virtual const char* what() { return errorMessage.c_str(); }
};

#endif