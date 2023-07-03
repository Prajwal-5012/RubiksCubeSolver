# Rubiks Cube Solver
•	Modeled a virtual Rubik’s Cube (3x3) using 3 different classes/models using standard data structures present in C++
•	The 3D Rubik Cube is Visualized as 2D planar structure which is as follows:
         UP
LEFT FRONT RIGHT BACK
	         DOWN
Each cell of the cube is recognized by its Face, row, col. Each starting from index 0.	
•	The first model is implemented using 3D Array of size 6 x 3 x 3, which would look something like 
cube [Face][Row][Col] representing the color of the corresponding cubie (small cubes that makes the whole 3x3 cube).
•	The second model is implemented using 1D Array of size 54 since it is easier to store and operations are faster as compare to 3D Array. cube[i] represent the color of ith cubie when indexed sequentially.
•	The third model is implemented using bits since it is faster and more compact. The 6 unique colors of the Rubik Cube are represented in 8 bits format. As centre is always fixed each face of the cube can be represented using remaining 8 cubie. Therefore, each face of the cube can be represented a using 64-bit number(8(faces)*8(bits)) and whole cube can be just represented using an array of size 6.
•	To solve the Rubik cube Graph Algorithms such as DFS, BFS and IDDFS were used. IDDFS turns out to be faster among the other two algorithms with solving time under 10 seconds when jumbled 8 times.
