
#ifndef RUBIKSCUBESOLVER_RUBIKCUBE_H
#define RUBIKSCUBESOLVER_RUBIKCUBE_H

#include "bits/stdc++.h"
using namespace std;

class RubikCube {
public:
    enum class FACE{
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class MOVE{
        U, UP, U2,
        L, LP, L2,
        F, FP, F2,
        R, RP, R2,
        B, BP, B2,
        D, DP, D2
    };

    enum class COLOR{
        White,
        Green,
        Red,
        Blue,
        Orange,
        Yellow
    };

    // Each cubie has some paramters such as color,
    // the side/face, (row, col) representation.
    // where row numbering starts from up to down
    // ans col from right to back. Starting index is 0.

    /*To get each of these parameters we define a function for them*/
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const=0;

    /*Returns the first character of the color*/
    static char getColorLetter(COLOR color);

    /*Returns the move in the string format*/
    static string getMove(MOVE ind);


    /*Prints the Rubik's cube in planar format.
        FACE NOTATION:
          U
        L F R B
          D
    */
    //check what if we use virtual void print() const;
    void print() const;

    /*Defining All the different 18 rotations
        u, u', u2,
        l, l', l2;
        f, f', f2,
        r, r', r2,
        b, b', b2,
        d, d', d2
    */
    virtual RubikCube &u() = 0;
    virtual RubikCube &uPrime() = 0;
    virtual RubikCube &u2() = 0;

    virtual RubikCube &l() = 0;
    virtual RubikCube &lPrime() = 0;
    virtual RubikCube &l2() = 0;

    virtual RubikCube &f() = 0;
    virtual RubikCube &fPrime() = 0;
    virtual RubikCube &f2() = 0;

    virtual RubikCube &r() = 0;
    virtual RubikCube &rPrime() = 0;
    virtual RubikCube &r2() = 0;

    virtual RubikCube &b() = 0;
    virtual RubikCube &bPrime() = 0;
    virtual RubikCube &b2() = 0;

    virtual RubikCube &d() = 0;
    virtual RubikCube &dPrime() = 0;
    virtual RubikCube &d2() = 0;

    /*Randomly shuffled the cube with moves given by times and returns the moves performed*/
    vector<MOVE> randomShuffleCube(unsigned int times);

    /*Perform moves on rubik cube*/
    RubikCube &move(MOVE ind);

    /*Invert a move*/
    RubikCube &invert(MOVE ind);

    virtual bool isSolved() const=0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;

};


#endif //RUBIKSCUBESOLVER_RUBIKCUBE_H
