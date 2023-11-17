#include <bits/stdc++.h>

#include "hadlock.h"
#include "graph.h"

namespace NetToMag
{
    //double* qlacement percentage
    cubeGrid HadLock(Graph* wGraph, int dimensions)
    {   
        cubeGrid wGrid = ai1::HadLock(wGraph,dimensions);

        cout << "placement finished " << endl;
        return wGrid;
    }
};

namespace ai1
{   
    const double CHANNEL_INTERVAL = .2;
    const int CELL_DIMENSIONS = 6;
    int wDimensions;
    int n;
    int channelSize, channelInterval, channelMod;
    int wirelength, vias;

    int notDone=0;
    double percent=0;

    Graph wGraph;
    cubeGrid wGrid;
    vector<uEdge> edgeQueue;
    map pQueue;
    stack<Box*> rippled;

    cubeGrid HadLock(Graph graphI, int dimensionsI)
    {
        //sets global variables
        wDimensions = dimensionsI;
        wGraph = graphI;
        channelSize = CHANNEL_MIN;
        
        SizeGrid();
        PaintGrid();
        //PrintGrid();
        HadlockTop();
        //PrintGrid();
        //PrintEdges();
        //
        std::ofstream log;
        log.open("logs/runlog.txt",std::ios::app);
        log     << "total wire length is: "
                << wirelength *3
                << " lambda"
                << endl;
        log     << "total number of vias is: "
                << vias
                << endl;
        log.close();
        return wGrid;
    }

    void SizeGrid()
    {
        
        n = CELL_DIMENSIONS * wDimensions + channelSize * (wDimensions+1);
        wirelength = 0;
        vias = 0;
        channelMod = channelSize + wDimensions;
        channelInterval = channelSize * CHANNEL_INTERVAL;
        for(int i=0; i<2; i++)
            wGrid.push_back(vector<vector<Box>>(n, vector<Box>(n, Box())));
        std::ofstream log;
        log.open("logs/runlog.txt",std::ios::app);
        log     << "bounding box size: "
                << n * 3
                << " lambda"
                << endl;
        log.close();
    }

    void PaintGrid()
    {
        array<int,2> wCoordinate;
        int edgeID;
        for (int i=0; i< wGraph->nodes.size();i++)
        {
            node wNode = wGraph->nodes[i];
            wCoordinate = wNode.origin; 

            wCoordinate[0] = CELL_DIMENSIONS * wCoordinate[0] + channelSize * (wCoordinate[0] + 1);
            wCoordinate[1] = CELL_DIMENSIONS * wCoordinate[1] + channelSize * (wCoordinate[1] + 1);

            for (int j=0; j<6; j++)
            {
                for(int k=0; k<6; k++)
                {
                    wGrid[0][j + wCoordinate[0]][k + wCoordinate[1]].type = -1;
                    wGrid[1][j + wCoordinate[0]][k + wCoordinate[1]].type = -1;
                    if (j == 0 && k == 1)
                    {
                        if (wNode.terminals[0] > -1)
                            searchQueue(wNode.terminals[0], j + wCoordinate[0], k + wCoordinate[1]); 
                    }

                    else if (j == 0 && k == 4)
                    {
                        if (wNode.terminals[1] > -1)
                            searchQueue(wNode.terminals[1], j + wCoordinate[0], k + wCoordinate[1]);  
                    }

                    else if (j == 5 && k == 1)
                    {
                        if (wNode.terminals[2] > -1)
                            searchQueue(wNode.terminals[2], j + wCoordinate[0], k + wCoordinate[1]); 
                    }

                    else if (j == 5 && k == 4)
                    {
                        if (wNode.terminals[3] > -1)
                            searchQueue(wNode.terminals[3], j + wCoordinate[0], k + wCoordinate[1]);  
                    } 
                }
            }     
        }
    }

    void searchQueue(int id, int x, int y)
    {
        for (int l=0; l < edgeQueue.size(); l++)
        { 
            if (edgeQueue[l].edgeID == id)
            {
                edgeQueue[l].T[0] = 0;
                edgeQueue[l].T[1] = x;
                edgeQueue[l].T[2] = y;

                wGrid[0][x][y].type = -2;
                wGrid[0][x][y].ripple = INT_MAX;
                //PrintEdges();
                return;
            }
        }
        uEdge newEdge;
        newEdge.edgeID = id;
        newEdge.S[0] = 0;
        newEdge.S[1] = x;
        newEdge.S[2] = y;            
        wGrid[0][x][y].type = -2;
        edgeQueue.push_back(newEdge);
        wGrid[0][x][y].ripple = INT_MAX;
    }
    
    void HadlockTop()
    {
        //for(int i=0; i<edgeQueue.size(); i++)
        for(int i=0; i<edgeQueue.size(); i++)
        {
    
            uEdge wEdge = edgeQueue[i];           
            //initialize S
            Box* sBox = &wGrid[wEdge.S[0]][wEdge.S[1]][wEdge.S[2]];
            Box* tBox = &wGrid[wEdge.T[0]][wEdge.T[1]][wEdge.T[2]];

            sBox->ripple = 0;
            tBox->ripple = 0;
            //PrintGrid();
            //cout << sBox->ripple << endl;
            //cout << tBox->ripple << endl;

            //cout << "wEdge T" << " " << wEdge.T[0] << " " << wEdge.T[1] << " " << wEdge.T[2] << " " << endl;
            //cout << "wEdge S" << " " << wEdge.S[0] << " " << wEdge.S[1] << " " << wEdge.S[2] << " " << endl;
            //if(i==1)
            //break;  

            rippled.push(sBox);
            
            pQueue.clear();
            bool status = false;
            HadlockNode(wEdge.S, wEdge.T,&status);
            while(true)
            {
                if(pQueue.empty())
                    break;
                if(status)
                    break;
                map::iterator itr = pQueue.lower_bound(0);
                pQueue.erase(itr);
                HadlockNode(itr->second,wEdge.T,&status);
            }

            if(status)
            {
                BTRecursive(wEdge.T,wEdge.T,wEdge.S);
            }
            else
            {
                //cout << "no solution found" << endl;
                notDone++;
            }      
            while(!rippled.empty())
            {   
                rippled.top()->ripple = INT_MAX;
                rippled.pop();          
            }
            PrintGrid();
        }      
        percent = (float(notDone)/float(edgeQueue.size()))*100;

        std::ofstream log;
        log.open("logs/runlog.txt",std::ios::app);
        log     << "routing percentage: "
                << 100 - percent
                << "%"
                << endl;
        log.close();
    }

    void HadlockNode(array<int,3> S, array<int,3> T, bool* status)
    {
        array<array<int,3>,5> coo = {{
                            {   S[0],S[1]+1,S[2]        },
                            {   S[0],S[1]-1,S[2]        },
                            {   S[0],S[1],S[2]+1        },
                            {   S[0],S[1],S[2]-1        },
                            {   (S[0]+1)%2,S[1],S[2]    }
                            }};

        for(int i=0; i<5; i++)
        {
            if(coo[i][1] > 0 && coo[i][1] < n)
                if(coo[i][2] > 0 && coo[i][2] < n)
                {
                    if(coo[i] == T)
                        *status = true;
                    ExpandNode(coo[i],S,T,wGrid[S[0]][S[1]][S[2]].ripple);
                }
        }
        //PrintGrid();
    }
    void ExpandNode(array<int,3> N, array<int,3> S, array<int,3> T, int prevripple)
    {
        Box* tBox = &wGrid[T[0]][T[1]][T[2]];
        Box* sBox = &wGrid[S[0]][S[1]][S[2]];  
        Box* nBox = &wGrid[N[0]][N[1]][N[2]]; 
   
        // do not add occupied cells
        if (nBox->type!=-2)
            return;
        // do not re add cells
        if (nBox->ripple < INT_MAX)
            return;
        // do not add cells with adjecent full cells
        array<array<int,3>,5> coo = {{
                            {   N[0],N[1]+1,N[2]        },
                            {   N[0],N[1]-1,N[2]        },
                            {   N[0],N[1],N[2]+1        },
                            {   N[0],N[1],N[2]-1        }
                            }};
        for(int i=0; i<4; i++)
        {  
            if(coo[i] != S)
                if(coo[i][1] > 0 && coo[i][1] < n)
                    if(coo[i][2] > 0 && coo[i][2] < n)
                       if(wGrid[coo[i][0]][coo[i][1]][coo[i][2]].type != -2)
                            return;
        }

        int modifier = 0;

        //if direction change
        if(N[1] != S[1] && N[2] != S[2])
            modifier++;
        //if on metal 2
        if(N[0] == 1)
            modifier++;
        //if further from node
        if(abs(N[1]-T[1]) > abs(S[1]-T[1]))
            modifier++;
        if(abs(N[2]-T[2]) > abs(S[2]-T[2]))
            modifier++;      

        if(N[2]%(channelMod) > channelSize/2 - channelInterval)
            modifier++;    
        if(N[2]%(channelMod) < channelSize/2 + channelInterval)
            modifier++;  
        if(N[1]%(channelMod) > channelSize/2 - channelInterval)
            modifier++;    
        if(N[1]%(channelMod) < channelSize/2 + channelInterval)
            modifier++;
        nBox->ripple = prevripple + modifier;
        rippled.push(nBox);
        pQueue.insert(index(sBox->ripple,N));
    }

    // Source and Target are inter-changed
    Box temp;  
    array<int,3> indexA;
    int findRipple=INT_MAX;

    void BTRecursive(array<int,3> N, array<int,3> S, array<int,3> T) 
    { 
        if(T == N)
        {
            if(N[0] != S[0])
            {
                wGrid[S[0]][S[1]][S[2]].type = -5; 
                wGrid[N[0]][N[1]][N[2]].type = -5; 
                vias++;
            }
            if(S[0])
            {
                wGrid[S[0]][S[1]][S[2]].type = -3;
                wirelength++;
            }
            else
            {
                wGrid[S[0]][S[1]][S[2]].type = -4;
                wirelength++;
            }
            if(N[0])
            {
                wGrid[N[0]][N[1]][N[2]].type = -3;
                wirelength++;
            }
            else
            {
                wGrid[N[0]][N[1]][N[2]].type = -4;
                wirelength++;
            }
            return;
        }
        array<array<int,3>,5> coo = {{
                            {   N[0],N[1]+1,N[2]        },
                            {   N[0],N[1]-1,N[2]        },
                            {   N[0],N[1],N[2]+1        },
                            {   N[0],N[1],N[2]-1        },
                            {   (N[0]+1)%2,N[1],N[2]    }
                            }};
        bool placed = false;
        for(int i=0; i<5; i++)
        {
            temp = wGrid[coo[i][0]][coo[i][1]][coo[i][2]];
            if(coo[i][1] > 0 && coo[i][0] < n)
                if(coo[i][2] > 0 && coo[i][1] < n)
                    if(coo[i] != S)
                    {   
                            if(i==0)
                            {
                                findRipple = temp.ripple;
                                indexA = coo[i];   
                                placed = true;
                            }                 
                            else if(temp.ripple < findRipple)
                            {
                                findRipple = temp.ripple;
                                indexA = coo[i];
                                placed = true;
                            }
                            else if(temp.ripple == findRipple)
                            {
                                if(IsCloser(coo[i],indexA,T))
                                {
                                    findRipple = temp.ripple;
                                    indexA = coo[i];
                                    placed = true;
                                }
                            }
                     }
        }

        if(!placed)
            return;

        if(N[0] != S[0])
        {
            wGrid[S[0]][S[1]][S[2]].type = -5; 
            vias++;
        }
        else if(S[0])
        {
            wGrid[S[0]][S[1]][S[2]].type = -3;
            wirelength++;
        }
        else
        {
            wGrid[S[0]][S[1]][S[2]].type = -4;
            wirelength++;
        }
        //PrintGrid();
        BTRecursive(indexA,N,T);

    }

    bool IsCloser(array<int,3> N, array<int,3> S, array<int,3> T)
    {
        int condition = 0;
        condition += abs(N[1]-T[1])-abs(S[1]-T[1]);
        condition += abs(N[2]-T[2])-abs(S[2]-T[2]);
        //cout << "condition: " << condition << " " << S[1] << " " << S[2] << " " << T[1] << " " << T[2] << " " << N[1] << " " << N[2] << endl;
        if(condition < 0)
        {
            //cout << " Here we are!" << endl;
            return true;
        }
        return false;
    }

    void PrintGrid()
    {
        system("clear");
        for (int j=0; j<n; j++)
        {
                for (int k=0; k<n; k++)
                    if(true)
                    {
                        if(wGrid[0][j][k].type == -1)
                            cout<<"*";
                        else if(wGrid[0][j][k].type == -5)
                            cout<<"X";
                        else if(wGrid[1][j][k].type == -3)
                            cout<<"o";
                        else if(wGrid[0][j][k].type == -4)
                            cout<<"H";
                        else if(wGrid[0][j][k].type == 2)
                            cout<<"T";
                        else if(wGrid[0][j][k].type == 3)
                            cout<<"S";
                        else if(wGrid[0][j][k].type == 4)
                            cout<<"V";
                        else if(wGrid[0][j][k].type == -2)
                            cout<<" ";
                    }
            cout << endl;
        }
        cout << endl;
    }

    void PrintEdges()
    {
        cout << "Printing Edges " << endl;
        for (int l=0; l < edgeQueue.size(); l++)
        { 
            cout << "S - " << edgeQueue[l].S[0]<< " " << edgeQueue[l].S[1]<< " " << edgeQueue[l].S[2] << endl;
            cout << "T - " << edgeQueue[l].T[0] << " " << edgeQueue[l].T[1] << " " << edgeQueue[l].T[2] << endl;
        }
        
    }

    void PrintQueue()
    {
        map::iterator itr;
        cout << "Printing Queue" << endl;
        for(itr = pQueue.begin(); itr != pQueue.end(); ++itr)
            cout    << setw(5) << itr->first << ": "
                    << setw(5) << itr->second[0] << " , "
                    << setw(5) << itr->second[1] << " , "
                    << setw(5) << itr->second[2] << " , "
                    << endl;
        cout        << endl;        
    }

    void PrintWave()
    {
        cout << "Printing Grid" << endl;
        for (int j=0; j<n; j++)
        {
            for (int i=0; i<2; i++)
            {
                for (int k=0; k<n; k++)
                    if(wGrid[i][j][k].ripple != INT_MAX)
                        cout << setw(2) << wGrid[i][j][k].ripple;
                    else
                        cout << "  ";
                cout << " | ";
            }
            cout << endl;
        }
        cout << endl; 
    }
};
