
#include "bits/stdc++.h"
#include "../RubikCube.h"
#include "DFSSolver.h"
#ifndef RUBIKSCUBESOLVER_IDDFSSOLVER_H
#define RUBIKSCUBESOLVER_IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver{
private:
    vector<RubikCube::MOVE> moves;
    int max_depth_search;

public:
    T rubikscube;

    IDDFSSolver(T _rubikscube,int _max_depth_search = 7){
        rubikscube = _rubikscube;
        max_depth_search = _max_depth_search;
    }

//    Used DFS Solver with increasing max depth search
    vector<RubikCube::MOVE>solve(){
        for(int i=1; i<=max_depth_search; i++){
            DFSSolver<T, H>dfsSolver(rubikscube, i);
            moves = dfsSolver.solve();
            if(dfsSolver.rubiksCube.isSolved()){
                rubikscube=dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif //RUBIKSCUBESOLVER_IDDFSSOLVER_H
