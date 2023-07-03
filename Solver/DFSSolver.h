
#include "bits/stdc++.h"
#include "../RubikCube.h"

#ifndef RUBIKSCUBESOLVER_DFSSOLVER_H
#define RUBIKSCUBESOLVER_DFSSOLVER_H

template <typename T, typename H>
class DFSSolver {
private:
    vector<RubikCube::MOVE>moves;
    int max_search_depth;

    /*Helper Function*/
    //DFS code to find solution
    bool dfs(int depth){
        if(rubiksCube.isSolved()) return true;
        if(depth>max_search_depth) return false;
        for(int i=0; i<18; i++){
            rubiksCube.move(RubikCube::MOVE(i));
            moves.push_back(RubikCube::MOVE(i));
            if(dfs(depth+1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubikCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth=8){
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<RubikCube::MOVE>solve(){
        dfs(1);
        return moves;
    }
};


#endif //RUBIKSCUBESOLVER_DFSSOLVER_H
