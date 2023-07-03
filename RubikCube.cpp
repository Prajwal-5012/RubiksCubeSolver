
#include "RubikCube.h"

char RubikCube::getColorLetter(COLOR color){
    char c=' ';
    switch(color){
        case COLOR::White : return 'W';
        case COLOR::Green: return 'G';
        case COLOR::Red: return 'R';
        case COLOR::Blue : return 'B';
        case COLOR::Orange: return 'O';
        case COLOR::Yellow: return 'Y';
    }
    return c;
}

/*Return the move in the string format*/
string RubikCube::getMove(MOVE ind){
    string str="";
    switch(ind){
        case MOVE::L : return "L";
        case MOVE::LP : return "L'";
        case MOVE::L2 : return "L2";

        case MOVE::F : return "F";
        case MOVE::FP : return "F'";
        case MOVE::F2 : return "F2";

        case MOVE::R : return "R";
        case MOVE::RP : return "R'";
        case MOVE::R2 : return "R2";

        case MOVE::B : return "B";
        case MOVE::BP : return "B'";
        case MOVE::B2 : return "B2";

        case MOVE::U : return "U";
        case MOVE::UP : return "U'";
        case MOVE::U2 : return "U2";

        case MOVE::D : return "D";
        case MOVE::DP : return "D'";
        case MOVE::D2 : return "D2";
    }
    return str;
}

/*Perform a move operation on using move index*/
RubikCube &RubikCube::move(MOVE ind){
    switch(ind){
        case MOVE::L : return this->l();
        case MOVE::LP : return this->lPrime();
        case MOVE::L2 : return this->l2();

        case MOVE::R : return this->r();
        case MOVE::RP : return this->rPrime();
        case MOVE::R2 : return this->r2();

        case MOVE::U : return this->u();
        case MOVE::UP : return this->uPrime();
        case MOVE::U2 : return this->u2();

        case MOVE::D : return this->d();
        case MOVE::DP : return this->dPrime();
        case MOVE::D2 : return this->d2();

        case MOVE::F : return this->f();
        case MOVE::FP : return this->fPrime();
        case MOVE::F2 : return this->f2();

        case MOVE::B : return this->b();
        case MOVE::BP : return this->bPrime();
        case MOVE::B2 : return this->b2();
    }
    return *this;
}

/*Invert a move*/
RubikCube &RubikCube::invert(MOVE ind){
    switch(ind){
        case MOVE::LP : return this->l();
        case MOVE::L : return this->lPrime();
        case MOVE::L2 : return this->l2();

        case MOVE::RP : return this->r();
        case MOVE::R : return this->rPrime();
        case MOVE::R2 : return this->r2();

        case MOVE::UP : return this->u();
        case MOVE::U : return this->uPrime();
        case MOVE::U2 : return this->u2();

        case MOVE::DP : return this->d();
        case MOVE::D : return this->dPrime();
        case MOVE::D2 : return this->d2();

        case MOVE::FP : return this->f();
        case MOVE::F : return this->fPrime();
        case MOVE::F2 : return this->f2();

        case MOVE::BP : return this->b();
        case MOVE::B : return this->bPrime();
        case MOVE::B2 : return this->b2();
    }
    return *this;
}

/*Printing a rubik cube in planar format*/
void RubikCube::print() const{
    cout<<"Rubik's Cube:\n\n";

    for(int row=0; row<=2; row++){
        for(int i=0; i<7; i++)cout<<" ";
        for(int col=0; col<=2; col++)
            cout<<getColorLetter(getColor(FACE::UP, row, col))<<" ";
        cout<<endl;
    }
    cout<<endl;

    for(int row=0; row<=2; row++){
        for(int col=0; col<=2; col++)
            cout<<getColorLetter(getColor(FACE::LEFT, row, col))<<" ";

        cout<<" ";

        for(int col=0; col<=2; col++){
            cout<<getColorLetter(getColor(FACE::FRONT, row, col))<<" ";
        }

        cout<<" ";

        for(int col=0; col<=2; col++)
            cout<<getColorLetter(getColor(FACE::RIGHT, row, col))<<" ";

        cout<<" ";

        for(int col=0; col<=2; col++)
            cout<<getColorLetter(getColor(FACE::BACK, row, col))<<" ";

        cout<<endl;
    }

    cout<<endl;

    for (int row = 0; row <= 2; row++) {
        for (int i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        }
        cout << endl;
    }
    cout << endl;
}


vector<RubikCube::MOVE>RubikCube::randomShuffleCube(unsigned int times){
    vector<MOVE>moves_performed;
    srand(time(0));
    for(unsigned int i=0; i<times; i++){
        unsigned int selectMove = (rand()%18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return moves_performed;
}

/*Function that return color of the corner cubie*/
string RubikCube::getCornerColorString(uint8_t ind) const{
    string str="";

    switch(ind){
        // UFR
        case 0:
            str+=getColorLetter(getColor(FACE::UP, 2, 2));
            str+=getColorLetter(getColor(FACE::FRONT, 0, 2));
            str+=getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

            // UFL
        case 1:
            str+=getColorLetter(getColor(FACE::UP, 2, 0));
            str+=getColorLetter(getColor(FACE::FRONT, 0, 0));
            str+=getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

            // UBL
        case 2:
            str+=getColorLetter(getColor(FACE::UP, 0, 0));
            str+=getColorLetter(getColor(FACE::BACK, 0, 2));
            str+=getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

            // UBR
        case 3:
            str+=getColorLetter(getColor(FACE::UP, 0, 2));
            str+=getColorLetter(getColor(FACE::BACK, 0, 0));
            str+=getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

            // DFR
        case 4:
            str+=getColorLetter(getColor(FACE::DOWN, 0, 2));
            str+=getColorLetter(getColor(FACE::FRONT, 2, 2));
            str+=getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

            // DFL
        case 5:
            str+=getColorLetter(getColor(FACE::DOWN, 0, 0));
            str+=getColorLetter(getColor(FACE::FRONT, 2, 0));
            str+=getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

            // DBR
        case 6:
            str+=getColorLetter(getColor(FACE::DOWN, 2, 2));
            str+=getColorLetter(getColor(FACE::BACK, 2, 0));
            str+=getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

            // DBL
        case 7:
            str+=getColorLetter(getColor(FACE::DOWN, 2, 0));
            str+=getColorLetter(getColor(FACE::BACK, 2, 2));
            str+=getColorLetter(getColor(FACE::LEFT, 2, 0));\
            break;
    }
    return str;
}

/*Returns the index of the corner*/
uint8_t RubikCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubikCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}
