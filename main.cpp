#include <iostream>
using namespace std;
#include "RubiksCube3DArray.cpp"
#include "RubiksCube1DArray.cpp"
#include "RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"

int main() {

//    RubiksCubeBitboard objectbitboard;
//    RubiksCube3DArray object3DArray;
//    object3DArray.print();
//    RubiksCube1DArray object1DArray;
//    object1DArray.print();
//    objectbitboard.u();
//    objectbitboard.l();
//    objectbitboard.f();
//    objectbitboard.r();
//    objectbitboard.b();
//    objectbitboard.d();
//    objectbitboard.uPrime();
//    objectbitboard.lPrime();
//    objectbitboard.fPrime();
//    objectbitboard.rPrime();
//    objectbitboard.bPrime();
//    objectbitboard.dPrime();
//    objectbitboard.u2();
//    objectbitboard.l2();
//    objectbitboard.f2();
//    objectbitboard.r2();
//    objectbitboard.b2();
//    objectbitboard.d2();
//    objectbitboard.print();
//    if(objectbitboard.isSolved()) cout<<"SOLVED"<<endl;
//    else cout<<"NOT SOLVED"<<endl;

//    object1DArray.u();
//    object1DArray.l();
//    object1DArray.f();
//    object1DArray.r();
//    object1DArray.b();
//    object1DArray.d();
//    object1DArray.uPrime();
//    object1DArray.lPrime();
//    object1DArray.fPrime();
//    object1DArray.rPrime();
//    object1DArray.bPrime();
//    object1DArray.dPrime();
//    object1DArray.u2();
//    object1DArray.l2();
//    object1DArray.f2();
//    object1DArray.r2();
//    object1DArray.b2();
//    object1DArray.d2();

//    object3DArray.u();
//    object3DArray.l();
//    object3DArray.f();
//    object3DArray.r();
//    object3DArray.b();
//    object3DArray.d();
//    object3DArray.uPrime();
//    object3DArray.lPrime();
//    object3DArray.fPrime();
//    object3DArray.rPrime();
//    object3DArray.bPrime();
//    object3DArray.dPrime();
//    object3DArray.u2();
//    object3DArray.l2();
//    object3DArray.f2();
//    object3DArray.r2();
//    object3DArray.b2();
//    object3DArray.d2();
//    object3DArray.print();
//    cout<<getColor(RubikCube::FACE::FRONT, 1, 2)<<endl;
//    cout<<object3DArray.getColorLetter(object3DArray.getColor(RubikCube::FACE::DOWN, 1, 1))<<endl;
//    if(object3DArray.isSolved()) cout<<"SOLVED"<<endl;
//    else cout<<"NOT SOLVED"<<endl;
//    object1DArray.print();
//    if(object1DArray.isSolved()) cout<<"SOLVED"<<endl;
//    else cout<<"NOT SOLVED"<<endl;
//    object3DArray.lPrime();
//    if(object3DArray.isSolved()) cout<<"SOLVED"<<endl;
//    else cout<<"NOT SOLVED"<<endl;

//    vector<RubikCube::MOVE>moves_to_shuffle = object3DArray.randomShuffleCube(5);
//    for(auto move: moves_to_shuffle) cout<<object3DArray.getMove(move)<<" "; cout<<endl;
//    object3DArray.print();

//    cout<<objectbitboard.getColorLetter(objectbitboard.getColor(RubikCube::FACE::FRONT, 2, 1));

/*----Create two cubes-------------------------------------------*/
//    RubiksCube3DArray cube1;
//    RubiksCube3DArray cube2;

//    RubiksCube1DArray cube1;
//    RubiksCube1DArray cube2;

//    RubiksCubeBitboard cube1;
//    RubiksCubeBitboard cube2;

/*----Equality and Assignment of cubes---------------------------*/
//    cout<<"Cube1 after creating new one : "<<endl;
//    cube1.print();
//
//    cout<<"Cube2 after creating new one : "<<endl;
//    cube2.print();
//
//    if(cube1 == cube2)cout<<"IS EQUAL"<<endl;
//    else cout<<"NOT EQUAL"<<endl;
//
//    cube1.randomShuffleCube(1);
//
//    cout<<"Cube1 after shuffling : "<<endl;
//    cube1.print();
//    if(cube1==cube2) cout<<"IS EQUAl"<<endl;
//    else cout<<"NOT EQUAL"<<endl;
//
//    cube2=cube1;
//
//    cout<<"Cube2 after assigning : "<<endl;
//    cube2.print();
//    if(cube1==cube2) cout<<"IS EQUAL"<<endl;
//    else cout<<"NOT EQUAL"<<endl;

/*--Cubes using Unordered_map------------------------------------*/
//    unordered_map<RubiksCube3DArray, bool, Hash3d>m1;
//    unordered_map<RubiksCube1DArray, bool, Hash1d> mp1;
//    unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
//
//
//    mp1[cube1] = true;
//    cube2.randomShuffleCube(8);
//    if (mp1[cube1]) cout << "Cube1 is present\n";
//    else cout << "Cube1 is not present\n";
//
//    if (mp1[cube2]) cout << "Cube2 is present\n";
//    else cout << "Cube2 is not present\n";

/*--DFS Solver testing-----------------------------------------*/
//    RubiksCube3DArray cube;
//    RubiksCubeBitboard cube;
//    cube.print();
//
//    vector<RubikCube::MOVE> shuffle_moves = cube.randomShuffleCube(8);
//    for(auto move: shuffle_moves) cout<<cube.getMove(move)<<" ";
//    cout<<endl;
//
//    cube.print();
//
//    DFSSolver<RubiksCubeBitboard, HashBitboard> dfsSolver(cube, 8);
//    vector<RubikCube::MOVE>solve_moves = dfsSolver.solve();
//
//    for(auto move: solve_moves) cout<<cube.getMove(move)<<" ";
//    cout<<endl;
//
//    dfsSolver.rubiksCube.print();

/*--BFS Solver testing----------------------------------------*/
//    RubiksCube1DArray cube;
//    RubiksCubeBitboard cube;
//    cube.print();
//
//
//    vector<RubikCube::MOVE>shuffle_moves = cube.randomShuffleCube(7);
//    for(auto move: shuffle_moves) cout<<cube.getMove(move)<<" ";
//    cout<<endl;
//
//    cube.print();
//
//    BFSSolver<RubiksCubeBitboard, HashBitboard> bfssolver(cube);
//    vector<RubikCube::MOVE> solve_moves = bfssolver.solve();
//
//    for(auto move: solve_moves) cout<<cube.getMove(move)<<" ";
//    cout<<endl;
//
//    bfssolver.rubiksCube.print();

/*--IDDFS Solver testing---------------------------------------*/
    RubiksCubeBitboard cube;
//    cout<<"Initial State of a Rubik Cube\n\n";
//    cube.print();

    vector<RubikCube::MOVE>shuffle_moves = cube.randomShuffleCube(6);
    cout<<"\nShuffling moves: ";
    for(auto move: shuffle_moves) cout<<cube.getMove(move)<<" ";
    cout<<endl;

    cout<<"\nRubik Cube After Shuffling\n\n";
    cube.print();

    IDDFSSolver<RubiksCubeBitboard, HashBitboard>iddfssolver(cube, 20);
    vector<RubikCube::MOVE>solve_moves = iddfssolver.solve();

    cout<<"\nSolution moves: ";
    for(auto move: solve_moves) cout<<cube.getMove(move)<<" ";
    cout<<endl;

    cout<<"Final State of Rubik cube after Solving\n";
    iddfssolver.rubikscube.print();

    return 0;
}
