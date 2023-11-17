#include <bits/stdc++.h>

#include "hadlock.h"
#include "forcepart.h"

using namespace NetToMag;

int main(int argc, char** argv)
{
    string input, output;
    input = argv[argc-2];
    output = argv[argc-1];

    Graph wGraph = ParseNetList(input);
    
    // export to Magic
    int dimension = ForcePlace(&wGraph);
    //PrintEdges(wGraph);
    //PrintNodes(wGraph);
    
    cubeGrid wGrid;
    wGrid = HadLock(&wGraph,dimension);
    PrintToMagic(wGrid,output);

    return 0;
}
