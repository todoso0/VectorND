/*
	
	N-Dimensional Vector math (class definition)

	Steven - svill175
	10-15-2026

*/

#include "../header/VectorND.hpp"
#include "../header/VectorND_Exception.hpp"

VectorND::VectorND(std::initializer_list<double> components) {

	//VectorND object initializer

	//Set the vector to the correct size for all components
	this->nd_vector.reserve(components.size());

	//Push all of the components into the vector
	for (double component : components) {
		 this->nd_vector.push_back(component);
	} 

	//!! throw error if trying to initialize zero vector!
	if (this->magnitude() == 0) {
		throw VectorND_Exception("VectorND Error: Cannot initialize vector with all zero components");
	}

}

void VectorND::displayVector() {
	
	//Print vector to cout in ordered tuple format

	std::cout << "{ ";
	for (unsigned int n = 0, countdown = this->dimensions(), max = countdown; n < max; n++, countdown--) {
		std::cout << this->nd_vector[n] << (countdown != 1 ? ", " : "");
	}
	std::cout << " }\n";

}

unsigned int VectorND::dimensions() {

	//Get the vector's dimensions
	return this->nd_vector.size();

}

double VectorND::magnitude() {

	//Get the magnitude/length/norm of the vector

	//Sum the squares of each component of the vector
	double sum_of_squares = 0;
	for (unsigned int n = 0; n < this->dimensions(); n++) {
		sum_of_squares += pow(this->nd_vector[n], 2);
	}

	return sqrt(sum_of_squares);

}

VectorND VectorND::unitVector() {

	//Get the unit vector for the current vector
	//Return the result as a new VectorND object

	double magnitude = this->magnitude();

	VectorND unit_vector = *this;
	//Divide each component of the current vector by the vector's magnitude
	for (unsigned int n = 0; n < unit_vector.dimensions(); n++) {
		unit_vector.nd_vector[n] /= magnitude;
	}

	return unit_vector;

}

VectorND VectorND::scalarMultiplication(double scalar) {

	//Return a new VectorND object that is the current vector multiplied by a scalar value
	
	VectorND multiplied_vector = *this;
	//Multiply each component of the current vector by the scalar
	for (unsigned int n = 0; n < multiplied_vector.dimensions(); n++) {
		multiplied_vector.nd_vector[n] *= scalar;
	}

	return multiplied_vector;

}

VectorND VectorND::addVectors(VectorND vector2) {

	//Add the current vector to an input vector
	//Return the result as a new VectorND object

	//!! throw error if not matching dimensions with vectors!
	if (this->dimensions() != vector2.dimensions()) {
		throw VectorND_Exception("VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions");
	}

	VectorND sum_vector = *this;
	for (unsigned int n = 0; n < sum_vector.dimensions(); n++) {
		sum_vector.nd_vector[n] += vector2.nd_vector[n];
	}

	return sum_vector;

}

VectorND VectorND::subtractVectors(VectorND vector2) {

	//Subtract the input vector from the current vector
	//Return the result as a new VectorND object

	//!! throw error if not matching dimensions with vectors!
	if (this->dimensions() != vector2.dimensions()) {
		throw VectorND_Exception("VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions");
	}

	VectorND difference_vector = *this;
	for (unsigned int n = 0; n < difference_vector.dimensions(); n++) {
		difference_vector.nd_vector[n] -= vector2.nd_vector[n];
	}

	return difference_vector;

}

double VectorND::dotProduct(VectorND vector2) {

	//Get the dot product of the current vector and the input vector returned as a double

	//!! throw error if not matching dimensions with vectors!
	if (this->dimensions() != vector2.dimensions()) {
		throw VectorND_Exception("VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions");
	}

	double sum_of_products = 0;
	//Get running sum of the products of the matching pairs of components of each vector
	for (unsigned int n = 0; n < this->dimensions(); n++) {
		sum_of_products += this->nd_vector[n] * vector2.nd_vector[n];
	}

	return sum_of_products;

}

double VectorND::angleBetweenVectors(VectorND vector2) {

	//Return a scalar as a double that is the angle (in radians) between the current vector and the input vector

	//!! throw error if not matching dimensions with vectors!
	if (this->dimensions() != vector2.dimensions()) {
		throw VectorND_Exception("VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions");
	}

	return acos(this->dotProduct(vector2) / (this->magnitude() * vector2.magnitude()));
	
}

VectorND VectorND::projection(VectorND vector2) {

	//Return the projection of vector2 onto the current vector as a new VectorND object

	//!! throw error if not matching dimensions with vectors!
	if (this->dimensions() != vector2.dimensions()) {
		throw VectorND_Exception("VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions");
	}

	double scalar = (this->dotProduct(vector2) / pow(this->magnitude(), 2));

	VectorND projected_vector = this->scalarMultiplication(scalar);

	return projected_vector;
	
}

VectorND VectorND::crossProduct(VectorND vector2) {

	//Get the cross product of the current vector and the input vector
	//Returns the result as a new VectorND object

	//!! throw error if not matching dimensions with vectors!
	if (this->dimensions() != vector2.dimensions()) {
		throw VectorND_Exception("VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions");
	}

	//!! throw error if matching vector D but not 3D or 7D!
	if (this->dimensions() != 3 && this->dimensions() != 7) {
		throw VectorND_Exception("VectorND Error: Cross product may only be performed with vectors of 3 or 7 dimensions, vectors in use have " + std::to_string(this->dimensions()));
	}

	if (this->dimensions() == 3) {

		//Cross product for 3D vectors

		// i, j, k
		// 0, 1, 2
		double new_i = this->nd_vector[1] * vector2.nd_vector[2] - this->nd_vector[2] * vector2.nd_vector[1];
		double new_j = -(this->nd_vector[0] * vector2.nd_vector[2] - this->nd_vector[2] * vector2.nd_vector[0]);
		double new_k = this->nd_vector[0] * vector2.nd_vector[1] - this->nd_vector[1] * vector2.nd_vector[0];

		VectorND cross_product_vector = { new_i, new_j, new_k };

		return cross_product_vector;
	
	}

	//Cross product for 7D vectors
	//There is likely a much cleaner way to do this, but it works for now

	VectorND cross_product_vector = { 1, 1, 1, 1, 1, 1, 1 }; //Temp placeholder vector
	unsigned int indexes[12] = { 1, 3, 3, 1, 2, 6, 6, 2, 4, 5, 5, 4 };

	for(unsigned int n = 0; n < 7; n++) {

		//Produces the current next component (scalar) of the cross product vector
		cross_product_vector.nd_vector[n] =
		(this->nd_vector[indexes[0]] * vector2.nd_vector[indexes[1]] - this->nd_vector[indexes[2]] * vector2.nd_vector[indexes[3]])
		+
		(this->nd_vector[indexes[4]] * vector2.nd_vector[indexes[5]] - this->nd_vector[indexes[6]] * vector2.nd_vector[indexes[7]])
		+ 
		(this->nd_vector[indexes[8]] * vector2.nd_vector[indexes[9]] - this->nd_vector[indexes[10]] * vector2.nd_vector[indexes[11]]);

		//Increase all indexes by 1 for next loop, if 6 + 1 wrap around to 0
		for(unsigned int i = 0; i < 12; i++) {
			indexes[i] = (indexes[i] + 1) % 7;
		}
		
	}

	return cross_product_vector;

}

double VectorND::scalarTripleProduct(VectorND vector2, VectorND vector3) {

	//Compute the dot product of the current vector with the cross product of the 2 input vectors
	//Return the resulting scalar value as a double

	//!! throw error if not matching dimensions with vectors!
	if (this->dimensions() != vector2.dimensions() || this->dimensions() != vector3.dimensions()) {
		throw VectorND_Exception("VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions");
	}

	//!! throw error if matching vector D but not 3D or 7D!
	if (this->dimensions() != 3 && this->dimensions() != 7) {
		throw VectorND_Exception("VectorND Error: Cross product may only be performed with vectors of 3 or 7 dimensions, vectors in use have " + std::to_string(this->dimensions()));
	}

	VectorND cross_product_vector = vector2.crossProduct(vector3);

	return this->dotProduct(cross_product_vector);

}