#ifndef VECTORND_HPP
#define VECTORND_HPP

/*

	N-Dimensional Vector math (class header)

	Steven - svill175
	10-15-2026

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <initializer_list>
#include <string>

class VectorND {

	std::vector<double> nd_vector;

	public:

		VectorND(std::initializer_list<double> components);
		
		//Vector property operations
		void displayVector();
		unsigned int dimensions();
		double magnitude();
		VectorND unitVector();

		//Vector operations
		VectorND scalarMultiplication(double scalar);
		VectorND addVectors(VectorND vector2);
		VectorND subtractVectors(VectorND vector2);
		double angleBetweenVectors(VectorND vector2);

		//More complex vector operations
		VectorND projection(VectorND vector2);
		double dotProduct(VectorND vector2);
		VectorND crossProduct(VectorND vector2);
		double scalarTripleProduct(VectorND vector2, VectorND vector3);

};

#endif