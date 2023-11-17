#pragma once

#include <bits/stdc++.h>
#include "graph.h"

namespace NetToMag
{
    // call into namespace ai0
    int ForcePlace(Graph*);
};

namespace ai0 
{
    //make SPRING_CONST and SCALAR_CONST scale based on dimensions
    const int REPULSE_CONST = 1;
    const int SCALAR_RATIO_CONST = 20;
    const int BREAK_RATIO1 = 3; 
    const int BREAK_RATIO2 = 2;

    extern int SPRING_CONST;
    extern int SCALAR_CONST;

    using std::cout;
    using std::endl;
    using std::setw;

    using std::array;
    using std::string;
    using std::map;
    using std::multimap;
    using std::pair;

    using std::pow;

    struct Box;

    typedef NetToMag::Graph* Graph;
    typedef pair<int,int> index;

    extern int size;
    extern int condition;

    extern Graph wGraph;
    extern map<int,int> grid;
    extern map<int,int> uplaced;
    extern multimap<int,int> empty;

    // algorithm initialization
    int ForcePlaceAI0(Graph);
    void GetGridSize(int);
    void InitialPlacement(void);

    // implementation of algorithm
    void ItterateNodes(void);
    void RecursiveNodes(int,int);
    array<int,2> GetNodeForces(int);

    // IO
    void PrintGrid(void);
    void PrintMap(map<int,int>);
    void PrintMap(multimap<int,int>);
};
