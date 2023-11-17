#include <bits/stdc++.h>


#include "forcepart.h"
#include "graph.h"

// project main namespace
namespace NetToMag
{
    int ForcePlace(Graph* wGraph)
    {
        // call in forcepart namespace
        using namespace ai0;
        int returndimensions = ForcePlaceAI0(wGraph);
        return returndimensions;
    }
};

// namespace for forcepart implementation
namespace ai0
{
    int size,condition,conditionp;
    int SPRING_CONST, SCALAR_CONST;
    Graph wGraph;
    map<int,int> grid;
    map<int,int> uplaced;
    multimap<int,int> empty;

    int ForcePlaceAI0(Graph graphI)
    {
        wGraph = graphI;
        GetGridSize(wGraph->nodes.size());
        InitialPlacement();
        ItterateNodes();
        //PrintGrid();
        //NetToMag::PrintNodes(*wGraph);
        return size;
    }

    // return celling sqrt nodes
    void GetGridSize(int nodes)
    {
        size = sqrt(nodes) + 1;
        SPRING_CONST = pow(2*size,2);
        SCALAR_CONST = pow(size,2) * SCALAR_RATIO_CONST;
        std::ofstream log;
        log.open("logs/runlog.txt",std::ios::app);
        log     << "placethrough cells: "
                << pow(size,2) - nodes
                << endl;
        log.close();
    }

    void InitialPlacement()
    {
        int k;
        int l = -2*size-1;
        // set node coordinates
        for(int i=0; i<size; i++)
        {
            for(int j=0; j<size; j++)
            {
                k = size*i+j;
                if(k < wGraph->nodes.size())
                {
                    grid.insert(index(k,wGraph->nodes[k].id));
                    // set x coordinate
                    wGraph->nodes[k].origin[0] = i;
                    // set y coordinate
                    wGraph->nodes[k].origin[1] = j;
                }
                else
                    grid.insert(index(k,-1));
            }
        }
    }

    void ItterateNodes()
    {
        int temp, recall1, recall2;
        map<int,int>::iterator itr;
        condition = 1;

        while(true)
        {
            conditionp = condition;
            condition = 0;
            empty.clear();
            uplaced.clear();
            //PrintMultiMap(grid);
            for(itr=grid.begin(); itr!=grid.end(); itr++)
            {
                temp = itr->first;
                if(itr->second == -1)
                    empty.insert(index(temp%size+temp/size,temp));
                else
                    uplaced.insert(index(itr->first,itr->second));
            }
            while(true)
            {
                if(uplaced.empty())
                    break;

                if(recall2 == uplaced.size())
                    uplaced.erase(uplaced.begin());

                itr = uplaced.begin();
                recall2 = recall1;
                recall1 = uplaced.size();
                RecursiveNodes(
                        grid.find(itr->first)->first,
                        grid.find(itr->first)->second
                        );
            }
            if(condition - conditionp < size) 
                break;
        }
    }

    void RecursiveNodes(int oriz, int orid)
    {
        array<int,2> original, modified;
        array<int,2> forces = GetNodeForces(orid);
        int modz, modi, modd, orii;

        //remove node
        uplaced.erase(oriz);

        //store original and modified values
        original = wGraph->nodes[orid].origin;
        modified = original;
        modified[0] += forces[0];
        modified[1] += forces[1];

        //check for overflow
        if(modified[0] < 0)
            modified[0] = 0;
        else if(modified[0] > size-1)
            modified[0] = size-1;

        if(modified[1] < 0)
            modified[1] = 0;
        else if(modified[1] > size-1)
            modified[1] = size-1;

        //case 1: if placing in an empty node
        modz = modified[0]*size + modified[1];
        modi = modz%size+modz/size;
        if(grid.find(modz)->second==-1)
        {
            //cout << "method 1 called " << endl;

            //PrintMap(grid);
            //PrintMap(empty);
            //PrintMap(uplaced);
            //NetToMag::PrintNodes(*wGraph);

            //set graph coordinates
            wGraph->nodes[orid].origin = modified;
            
            //swap nodes
            grid.erase(oriz);
            grid.erase(modz);

            grid.insert(index(modz,orid));
            grid.insert(index(oriz,-1));

            //update wLists
            orii = oriz%size+oriz/size;
            auto range = empty.equal_range(modi);
            for(auto i = range.first; i != range.second; ++i)
            {
                if(i->second == modz)
                {
                    empty.erase(i);
                    break;
                }
            }
            empty.insert(index(orii,oriz));
            //PrintGrid();
            //PrintMap(empty);
        }

        //case 2: node doesn't move
        else if(oriz == modz)
        {
            //cout << "method 2 called " << endl;

            condition++;
        } 

        //case 3: swap nodes 
        else if(uplaced.count(modz))
        {
            //cout << "method 3 called" << endl;

            modd = grid.find(modz)->second;
            //switch graph coordinates
            wGraph->nodes[orid].origin = modified;
            wGraph->nodes[modd].origin = original;

            //swap nodes 
            grid.erase(oriz);
            grid.erase(modz);
        
            grid.insert(index(oriz,modd));
            grid.insert(index(modz,orid));

            //update wLists
            uplaced.insert(index(oriz,orid));
        }

        //case 4: node is locked 
        else 
        {
            //cout << "method 4 called " << endl;
            multimap<int,int>::iterator itr;

           //find nearest empty
           itr = empty.lower_bound(modi);
           if(itr == empty.end())
           {
               condition++;
               return;
           }

            orii = oriz%size+oriz/size;

            modified[0] = itr->second%size;
            modified[1] = itr->second/size;

            //get new keys
            modz = itr->second;
            modi = modz%size+modz/size;

            //set graph coordinates
            wGraph->nodes[orid].origin = modified;
            
            //swap nodes
            grid.erase(oriz);
            grid.erase(modz);

            grid.insert(index(oriz,-1));
            grid.insert(index(modz,orid));

            //update wLists
            empty.erase(empty.find(modi));
            empty.insert(index(orii,oriz));
        }
    }

    array<int,2> GetNodeForces(int idA)
    {
        array<int,2> forces = {0,0};
        int idB; 
        // calculate all attractive forces
        for(int i=0; i<4; i++)
        {
            idB = wGraph->nodes[idA].terminals[i];
            if(idB > -1)
            {
                forces[0] += SPRING_CONST * (wGraph->nodes[idB].origin[0]
                    - wGraph->nodes[idA].origin[0]);
                forces[1] += SPRING_CONST * (wGraph->nodes[idB].origin[1]
                    - wGraph->nodes[idA].origin[1]);
            }
        }

        // calculate all repulsive forces
        for(int i=0; i<wGraph->nodes.size(); i++)
        {
            forces[0] +=  REPULSE_CONST * (wGraph->nodes[idA].origin[0]
                - wGraph->nodes[i].origin[0]);
            forces[1] +=  REPULSE_CONST * (wGraph->nodes[idA].origin[1]
                - wGraph->nodes[i].origin[1]);
        }

        forces[0] /= SCALAR_CONST;
        forces[1] /= SCALAR_CONST;
        return forces;
    }
                            
    void PrintGrid()
    {
        if(!grid.size() == 0)
        {
            // print out the grid
            for(int i=0; i<size; i++)
            {
                for(int j=0; j<size; j++)
                {
                    int k = i*size+ j;
                    if(grid.count(k))
                        cout    << setw(5) 
                                << grid.find(k)->second+1
                                << "|";
                    else
                        cout    << setw(5)
                                << 0
                                << "|";
                }
                cout << endl;
            }
            cout << endl;
        }
        else
            cout << "Grid was not created yet" << endl;
    }

    void PrintMap(map<int,int> m)
    {
        map<int,int>::iterator itr;
        cout << "Printing Multi-Map" << endl;
        for(itr = m.begin(); itr != m.end(); ++itr)
            cout    << setw(5) << itr->first
                    << setw(5) << itr->second+1 
                    << endl;
        cout << endl;
    }

    void PrintMap(multimap<int,int> m)
    {
        multimap<int,int>::iterator itr;
        cout << "Printing Multi-Map" << endl;
        for(itr = m.begin(); itr != m.end(); ++itr)
            cout    << setw(5) << itr->first
                    << setw(5) << itr->second+1 
                    << endl;
        cout << endl;
    }
};

