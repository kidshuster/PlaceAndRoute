#pragma once

#include "graph.h"
#include <bits/stdc++.h>

namespace NetToMag
{
    // call into namespace ai1
    cubeGrid HadLock(Graph*,int);
};

namespace ai1
{
    const int CHANNEL_MIN = 10;
    using std::cout;
    using std::endl;
    using std::setw;
    using std::vector;
    using std::array;
    using std::string;
    using std::multimap;
    using NetToMag::Box;
    using NetToMag::node;

    typedef NetToMag::cubeGrid cubeGrid;
    typedef NetToMag::Graph* Graph;
    typedef std::pair<int,array<int,3>> index;
    typedef std::multimap<int,array<int,3>> map;

    struct uEdge 
    {
        int edgeID;
        array<int,3> S = {-1,-1,-1};
        array<int,3> T = {-1,-1,-1};
    };

    //Initialization
    cubeGrid HadLock(Graph,int);
    void SizeGrid(void);
    void PaintGrid(void);
    

    //Implementation
    void HadlockTop(void);
    void HadlockNode(array<int,3>,array<int,3>,bool*); 
    void searchQueue(int,int,int);
    void BTRecursive(array<int,3>,array<int,3>,array<int,3>);
    void ExpandNode(array<int,3>,array<int,3>,array<int,3>,int);
    bool IsCloser(array<int,3>,array<int,3>,array<int,3>);

    //IO
    void PrintGrid(void);
    void PrintQueue(void);
    void PrintWave(void);
};
