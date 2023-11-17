#pragma once

#include <bits/stdc++.h>

namespace NetToMag
{
    struct Box;

    using std::cout;
    using std::endl;
    using std::setw;

    using std::time_t;
    using std::time;

    using std::vector;
    using std::string;
    using std::array;
    using std::string;
    using std::ofstream;

    typedef vector<vector<vector<Box>>> cubeGrid;

    // structure for the grid locations in the magic file
    struct Box
    {

        //-5 - via
        //-4 - m1
        //-3 - m2
        //-2 - empty
        //-1 - poly 
        //0+ - ID 
        int type=-2; 
        int ripple=INT_MAX;
    };

    // edge struct for edge list
    struct edge 
    {
        int id;
        // node A info
        int idA;
        int termA;
        // node B info
        int idB;
        int termB;
    };
    
    // node struct for node list
    struct node 
    {
        int id;
        array<int,4> terminals = {-1,-1,-1,-1};
        array<int,2> origin = {-1,-1};
    };
    
    // Graph class to be passed in between functions
    class Graph
    {
        public:
            Graph(int);
            void AddEdge(int,int,int,int,int);

            std::vector<edge> edges;
            std::vector<node> nodes;
    };

    Graph ParseNetList(std::string);
    void ExportToMagic(cubeGrid);
    void PrintNodes(Graph);
    void PrintEdges(Graph);
    void PrintToMagic(cubeGrid,double,string);
};
