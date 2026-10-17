#
#	N-Dimensional Vector math (Python main)
#
#	Steven - svill175
#	10-17-2026
#

from VectorND import VectorND
from VectorND_Exception import VectorND_Exception

try:

	#3D vector math samples

	print("###############################\n3D Vector Math Samples\n###############################\n")

	vec1 = VectorND( 1, 2, 3 )
	vec2 = VectorND( 0, 3, 4 )

	print("vec1: ", end = '')
	vec1.displayVector()
	print("vec2: ", end = '')
	vec2.displayVector()
	print("")

	print("sum of vec1 + vec2: ", end = '')
	sum_vec12 = vec1.addVectors(vec2)
	sum_vec12.displayVector()
	print("")

	print("subtraction of vec1 - vec2: ", end = '')
	sub_vec12 = vec1.subtractVectors(vec2)
	sub_vec12.displayVector()
	print("")

	print(f"Magnitudes/Lengths of vec1 and vec2: \n{vec1.magnitude()}\n{vec2.magnitude()}\n")

	print("Unit vector of vec2: ", end = '')
	unit_vec2 = vec2.unitVector()
	unit_vec2.displayVector()
	print("")

	print(f"Dot product of vec1 and vec2: {vec1.dotProduct(vec2)}\n")

	print("Cross product of vec1 and vec2: ", end = '')
	vec3 = vec1.crossProduct(vec2)
	vec3.displayVector()
	print("")

	vec4 = VectorND( 1, 2, 2 )
	vec5 = VectorND( 2, 3, 5 )
	print("vec4: ", end = '')
	vec4.displayVector()
	print("vec5: ", end = '')
	vec5.displayVector()

	print("scalar multiplication of vec4 by 3: ", end = '')
	multiplied_vec4 = vec4.scalarMultiplication(3)
	multiplied_vec4.displayVector()
	print("")

	print(f"Angle between vec4 and vec5 (in radians): {vec4.angleBetweenVectors(vec5)}")
	print("Projection of vec5 onto vec4: ", end = '')
	proj_vec5_onto_vec4 = vec4.projection(vec5)
	proj_vec5_onto_vec4.displayVector()
	print("")

	vecA = VectorND( 1, 2, 3 )
	vecB = VectorND( 2, 3, 3 )
	vecC = VectorND( -7, 8, -9 )
	vecA.displayVector()
	vecB.displayVector()
	vecC.displayVector()
	print(f"scalar triple product of the above three vectors in that order: {vecA.scalarTripleProduct(vecB, vecC)}")


	#4D vector math samples

	print("\n\n###############################\n4D Vector Math Samples\n###############################\n")

	vec6 = VectorND( 1, 3, 5, 7 )
	vec7 = VectorND( 2, 4, 6, 8 )

	print("vec6: ", end = '')
	vec6.displayVector()
	print("vec7: ", end = '')
	vec7.displayVector()
	print("")

	print("sum of vec6 + vec7: ", end = '')
	sum_vec67 = vec6.addVectors(vec7)
	sum_vec67.displayVector()
	print("")

	print("subtraction of vec6 - vec7: ", end = '')
	sub_vec67 = vec6.subtractVectors(vec7)
	sub_vec67.displayVector()
	print("")

	print(f"Magnitudes/Lengths of vec6 and vec7:\n{vec6.magnitude()}\n{vec7.magnitude()}")
	print("")

	print("Unit vector of vec7: ", end = '')
	unit_vec7 = vec7.unitVector()
	unit_vec7.displayVector()
	print("")

	print(f"Dot product of vec6 and vec7: {vec6.dotProduct(vec7)}\n")

	print("scalar multiplication of vec6 by 3:")
	multiplied_vec6 = vec6.scalarMultiplication(3)
	multiplied_vec6.displayVector()
	print("")

	print(f"Angle between vec6 and vec7 (in radians): {vec6.angleBetweenVectors(vec7)}")
	print("Projection of vec6 onto vec7:")
	proj_vec6_onto_vec7 = vec7.projection(vec6)
	proj_vec6_onto_vec7.displayVector()
	print("")


	#7D vector cross product sample

	print("\n###############################\n7D Vector Cross Product Sample\n###############################\n")

	vec7Da = VectorND( 1, -2, 3, -4, 5, -6, 7 )
	vec7Db = VectorND( 2, 4, 6, 8, 10, 12, 14 )

	print("vec7Da: ", end = '')
	vec7Da.displayVector()
	print("vec7Db: ", end = '')
	vec7Db.displayVector()
	print("")

	vec7D_ab_cross_product = vec7Da.crossProduct(vec7Db)
	print("Cross product of vec7Da and vec7Db: ", end = '')
	vec7D_ab_cross_product.displayVector()
	print("\n")

	vec7Dc = VectorND( 1, 2, 1, 2, 1, 2, 1 )

	print("vec7Dc: ", end = '')
	vec7Dc.displayVector()

	print(f"Scalar triple product of vec7Da, vec7Db, and vec7Dc in that order: {vec7Da.scalarTripleProduct(vec7Db, vec7Dc)}\n")

	#Exception handling examples (Commented out, uncomment each line that has an error message comment to see the exception in action)

	#zero_vector = VectorND( 0, 0, 0 ) #VectorND Error: Cannot initialize vector with all zero components

	v1 = VectorND( 1, 2, 3 )
	v2 = VectorND( 2, 4, 6, 8 )
	v3 = VectorND( 1, 3, 5, 7 )

	#invalid_sum = v1.addVectors(v2) #VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions

	#invalid_cross_product = v2.crossProduct(v3) #VectorND Error: Cross product may only be performed with vectors of 3 or 7 dimensions, vectors in use have 4

	#v4 = VectorND( 1, "derp", 3) #VectorND Error: Components of vector must be numbers
	
	num = 5
	#v1.addVectors(num) #VectorND Error: Input must be a VectorND object

except VectorND_Exception as e:
	print(f"VectorND Error: {e}")