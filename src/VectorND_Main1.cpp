/*

	N-Dimensional Vector math (main)

	Steven - svill175
	10-15-2026

*/

#include "../header/VectorND.hpp"
#include "../header/VectorND_Exception.hpp"

int main() {

    try {

        //3D vector math samples

        std::cout << "###############################\n3D Vector Math Samples\n###############################\n\n";

        VectorND vec1 = { 1, 2, 3 };
        VectorND vec2 = { 0, 3, 4 };

        std::cout << "vec1: ";
        vec1.displayVector();
        std::cout << "vec2: ";
        vec2.displayVector();
        std::cout << "\n";

        std::cout << "sum of vec1 + vec2: ";
        VectorND sum_vec12 = vec1.addVectors(vec2);
        sum_vec12.displayVector();
        std::cout << "\n";

        std::cout << "subtraction of vec1 - vec2: ";
        VectorND sub_vec12 = vec1.subtractVectors(vec2);
        sub_vec12.displayVector();
        std::cout << "\n";	

        std::cout << "Magnitudes/Lengths of vec1 and vec2: \n";
        std::cout << vec1.magnitude() << "\n";
        std::cout << vec2.magnitude() << "\n";
        std::cout << "\n";

        std::cout << "Unit vector of vec2: ";
        VectorND unit_vec2 = vec2.unitVector();
        unit_vec2.displayVector();
        std::cout << "\n";

        std::cout << "Dot product of vec1 and vec2: " << vec1.dotProduct(vec2) << "\n\n";

        std::cout << "Cross product of vec1 and vec2: ";
        VectorND vec3 = vec1.crossProduct(vec2);
        vec3.displayVector();
        std::cout << "\n";

        VectorND vec4 = { 1, 2, 2 };
        VectorND vec5 = { 2, 3, 5 };
        std::cout << "vec4: ";
        vec4.displayVector();
        std::cout << "vec5: ";
        vec5.displayVector();

        std::cout << "scalar multiplication of vec4 by 3: \n";
        VectorND multiplied_vec4 = vec4.scalarMultiplication(3);
        multiplied_vec4.displayVector();
        std::cout << "\n";

        std::cout << "Angle between vec4 and vec5 (in radians): " << vec4.angleBetweenVectors(vec5) << "\n";
        std::cout << "Projection of vec5 onto vec4: \n";
        VectorND proj_vec5_onto_vec4 = vec4.projection(vec5);
        proj_vec5_onto_vec4.displayVector();
        std::cout << "\n";

        VectorND vecA = { 1, 2, 3 };
        VectorND vecB = { 2, 3, 3 };
        VectorND vecC = {-7, 8, -9};
        vecA.displayVector();
        vecB.displayVector();
        vecC.displayVector();
        std::cout << "scalar triple product of the above three vectors in that order: " << vecA.scalarTripleProduct(vecB, vecC) << "\n";


        //4D vector math samples

        std::cout << "\n\n###############################\n4D Vector Math Samples\n###############################\n\n";

        VectorND vec6 = { 1, 3, 5, 7 };
        VectorND vec7 = { 2, 4, 6, 8 };

        std::cout << "vec6: ";
        vec6.displayVector();
        std::cout << "vec7: ";
        vec7.displayVector();
        std::cout << "\n";

        std::cout << "sum of vec6 + vec7: ";
        VectorND sum_vec67 = vec6.addVectors(vec7);
        sum_vec67.displayVector();
        std::cout << "\n";

        std::cout << "subtraction of vec6 - vec7: ";
        VectorND sub_vec67 = vec6.subtractVectors(vec7);
        sub_vec67.displayVector();
        std::cout << "\n";	

        std::cout << "Magnitudes/Lengths of vec6 and vec7: \n";
        std::cout << vec6.magnitude() << "\n";
        std::cout << vec7.magnitude() << "\n";
        std::cout << "\n";

        std::cout << "Unit vector of vec7: ";
        VectorND unit_vec7 = vec7.unitVector();
        unit_vec7.displayVector();
        std::cout << "\n";

        std::cout << "Dot product of vec6 and vec7: " << vec6.dotProduct(vec7) << "\n\n";

        std::cout << "scalar multiplication of vec6 by 3: \n";
        VectorND multiplied_vec6 = vec6.scalarMultiplication(3);
        multiplied_vec6.displayVector();
        std::cout << "\n";

        std::cout << "Angle between vec6 and vec7 (in radians): " << vec6.angleBetweenVectors(vec7) << "\n";
        std::cout << "Projection of vec6 onto vec7: \n";
        VectorND proj_vec6_onto_vec7 = vec7.projection(vec6);
        proj_vec6_onto_vec7.displayVector();
        std::cout << "\n";


        //7D vector cross product sample

        std::cout << "\n###############################\n7D Vector Cross Product Sample\n###############################\n\n";

        VectorND vec7Da = { 1, -2, 3, -4, 5, -6, 7 };
        VectorND vec7Db = { 2, 4, 6, 8, 10, 12, 14 };

        std::cout << "vec7Da: ";
        vec7Da.displayVector();
        std::cout << "vec7Db: ";
        vec7Db.displayVector();
        std::cout << "\n";

        VectorND vec7D_ab_cross_product = vec7Da.crossProduct(vec7Db);
        std::cout << "Cross product of vec7Da and vec7Db: ";
        vec7D_ab_cross_product.displayVector();
        std::cout << "\n\n";

        VectorND vec7Dc = { 1, 2, 1, 2, 1, 2, 1 };

        std::cout << "vec7Dc: ";
        vec7Dc.displayVector();

        std::cout << "Scalar triple product of vec7Da, vec7Db, and vec7Dc in that order: " << vec7Da.scalarTripleProduct(vec7Db, vec7Dc) << "\n\n";

        //Exception handling examples (Commented out, uncomment each line that has an error message comment to see the exception in action)

        //VectorND zero_vector = { 0, 0, 0 }; //VectorND Error: Cannot initialize vector with all zero components

        VectorND v1 = { 1, 2, 3 };
        VectorND v2 = { 2, 4, 6, 8 };
        VectorND v3 = { 1, 3, 5, 7 };

        //VectorND invalid_sum = v1.addVectors(v2); //VectorND Error: Vector operations may only be performed with vectors of the same number of dimensions

        //VectorND invalid_cross_product = v2.crossProduct(v3); //VectorND Error: Cross product may only be performed with vectors of 3 or 7 dimensions, vectors in use have 4
   
    }

	catch (VectorND_Exception err) {
		std::cout << err.what() << "\n";
		exit(1);
	}

    return 0;

}