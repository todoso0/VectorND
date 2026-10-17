#
#	N-Dimensional Vector math (Python class)
#
#	Steven - svill175
#	10-17-2026
#

from VectorND_Exception import VectorND_Exception
import math

class VectorND:

	def __init__(self, *components):

		#VectorND object constructor
		#*components variable length list of vector components

		#Raise exception if any components not a number
		for component in components:

			if not (isinstance(component, (int, float)) and not isinstance(component, bool)):
				raise VectorND_Exception("Components of vector must be numbers")

		self.nd_vector = list(components)

		#!! throw error if trying to initialize zero vector!
		if self.magnitude() == 0:
			raise VectorND_Exception("Cannot initialize vector with all zero components")

	def displayVector(self):

		#Print vector in ordered tuple format

		print(f"{{ {", ".join(map(str, self.nd_vector))} }}")

	def dimensions(self):

		#Get the vector's dimension (# of components)

		return len(self.nd_vector)

	def magnitude(self):

		#Get the magnitude/length/norm of the vector

		#Sum the squares of each component of the vector
		sum_of_squares = 0
		for component in self.nd_vector:
			sum_of_squares += math.pow(component, 2)

		return math.sqrt(sum_of_squares)

	def unitVector(self):

		#Get the unit vector for the current vector
		#Return the result as a new VectorND object

		magnitude = self.magnitude()
		components = [component / magnitude for component in self.nd_vector]
		
		return VectorND(*components)

	def scalarMultiplication(self, scalar):

		#Return a new VectorND object that is the current vector multiplied by a scalar value
		
		components = [component * scalar for component in self.nd_vector]

		return VectorND(*components)

	def addVectors(self, vector2):

		#Add the current vector to an input vector
		#Return the result as a new VectorND object

		if not isinstance(vector2, VectorND):
			raise VectorND_Exception("Input must be a VectorND object")			

		#!! raise exception if not matching dimensions with vectors!
		if (self.dimensions() != vector2.dimensions()):
			raise VectorND_Exception("Vector operations may only be performed with vectors of the same number of dimensions")
		
		sum_vector_components = [component1 + component2 for component1, component2 in zip(self.nd_vector, vector2.nd_vector)]

		return VectorND(*sum_vector_components)



	def subtractVectors(self, vector2):

		#Subtract the input vector from the current vector
		#Return the result as a new VectorND object

		if not isinstance(vector2, VectorND):
			raise VectorND_Exception("Input must be a VectorND object")			

		#!! raise exception if not matching dimensions with vectors!
		if (self.dimensions() != vector2.dimensions()):
			raise VectorND_Exception("Vector operations may only be performed with vectors of the same number of dimensions")
		
		sub_vector_components = [component1 - component2 for component1, component2 in zip(self.nd_vector, vector2.nd_vector)]

		return VectorND(*sub_vector_components)

	def dotProduct(self, vector2):

		#Get the dot product of the current vector and the input vector returned as a number

		if not isinstance(vector2, VectorND):
			raise VectorND_Exception("Input must be a VectorND object")		

		#!! raise exception if not matching dimensions with vectors!
		if (self.dimensions() != vector2.dimensions()):
			raise VectorND_Exception("Vector operations may only be performed with vectors of the same number of dimensions")

		#Get running sum of the products of the matching pairs of components of each vector
		sum_of_products = 0
		for component1, component2 in zip(self.nd_vector, vector2.nd_vector):
			sum_of_products += component1 * component2

		return sum_of_products

	def angleBetweenVectors(self, vector2):

		#Return a scalar as a number that is the angle (in radians) between the current vector and the input vector

		if not isinstance(vector2, VectorND):
			raise VectorND_Exception("Input must be a VectorND object")	

		#!! raise exception if not matching dimensions with vectors!
		if (self.dimensions() != vector2.dimensions()):
			raise VectorND_Exception("Vector operations may only be performed with vectors of the same number of dimensions")

		return math.acos(self.dotProduct(vector2) / (self.magnitude() * vector2.magnitude()))

	def projection(self, vector2):

		#Return the projection of vector2 onto the current vector as a new VectorND object

		if not isinstance(vector2, VectorND):
			raise VectorND_Exception("Input must be a VectorND object")	

		#!! raise exception if not matching dimensions with vectors!
		if (self.dimensions() != vector2.dimensions()):
			raise VectorND_Exception("Vector operations may only be performed with vectors of the same number of dimensions")		

		scalar = (self.dotProduct(vector2) / math.pow(self.magnitude(), 2))

		return self.scalarMultiplication(scalar)

	def crossProduct(self, vector2):

		#Get the cross product of the current vector and the input vector
		#Returns the result as a new VectorND object

		if not isinstance(vector2, VectorND):
			raise VectorND_Exception("Input must be a VectorND object")	

		#!! raise exception if not matching dimensions with vectors!
		if (self.dimensions() != vector2.dimensions()):
			raise VectorND_Exception("Vector operations may only be performed with vectors of the same number of dimensions")

		#!! raise exception if matching vector D but not 3D or 7D!
		if (self.dimensions() != 3 and self.dimensions() != 7):
			raise VectorND_Exception(f"Cross product may only be performed with vectors of 3 or 7 dimensions, vectors in use have {self.dimensions()}")
		
		if (self.dimensions() == 3):

			#Cross product for 3D vectors

			# i, j, k
			# 0, 1, 2
			new_i = self.nd_vector[1] * vector2.nd_vector[2] - self.nd_vector[2] * vector2.nd_vector[1]
			new_j = -(self.nd_vector[0] * vector2.nd_vector[2] - self.nd_vector[2] * vector2.nd_vector[0])
			new_k = self.nd_vector[0] * vector2.nd_vector[1] - self.nd_vector[1] * vector2.nd_vector[0]

			return VectorND(new_i, new_j, new_k)		

		#Cross product for 7D vectors
		#Seems a bit cleaner then the C++ version, but probably still a better way to do it

		cross_product_vector_components = []
		indexes = [ 1, 3, 3, 1, 2, 6, 6, 2, 4, 5, 5, 4 ]

		for n in range(7):

			a, b, c, d, e, f, g, h, i, j, k, l = list(indexes)
			cross_product_vector_components.append(
				(self.nd_vector[a] * vector2.nd_vector[b] - self.nd_vector[c] * vector2.nd_vector[d])
				+
				(self.nd_vector[e] * vector2.nd_vector[f] - self.nd_vector[g] * vector2.nd_vector[h])
				+ 
				(self.nd_vector[i] * vector2.nd_vector[j] - self.nd_vector[k] * vector2.nd_vector[l])
			)

			indexes = [(index + 1) % 7 for index in indexes]

		return VectorND(*cross_product_vector_components)

	def scalarTripleProduct(self, vector2, vector3):

		#Compute the dot product of the current vector with the cross product of the 2 input vectors
		#Return the resulting scalar value as a number

		if (not isinstance(vector2, VectorND)) or (not isinstance(vector3, VectorND)):
			raise VectorND_Exception("Inputs must be VectorND objects")	

		#!! raise exception if not matching dimensions with vectors!
		if self.dimensions() != vector2.dimensions() or self.dimensions() != vector3.dimensions():
			raise VectorND_Exception("Vector operations may only be performed with vectors of the same number of dimensions")
		
		#!! raise exception if matching vector D but not 3D or 7D!
		if self.dimensions() != 3 and self.dimensions() != 7:
			raise VectorND_Exception(f"Cross product may only be performed with vectors of 3 or 7 dimensions, vectors in use have {self.dimensions()}")
		
		cross_product_vector = vector2.crossProduct(vector3)

		return self.dotProduct(cross_product_vector)

	