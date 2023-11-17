#include <bits/stdc++.h>

#include "graph.h"

namespace NetToMag
{
    Graph::Graph(int nodesI)
    {
        for(int i=0; i<nodesI; i++)
        {
            node newnode;
            newnode.id = i,
            nodes.push_back(newnode);
        }
    }

    void Graph::AddEdge(int id, int cell0, int term0, int cell1, int term1)
    {
        edge newedge;
        // add elements to the edge
        newedge.id = id;
        newedge.idA = cell0;
        newedge.idB = cell1;
        newedge.termA = term0;
        newedge.termB = term1;
        // add elements to the terminal
        nodes[cell0].terminals[term0] = id;
        nodes[cell1].terminals[term1] = id;
        edges.push_back(newedge);
    }

    Graph ParseNetList(std::string filenameI) 
    {
        using namespace std;
        string filename;

        // add folder name
        filename.append("data/");
        filename.append(filenameI);

        // open file
        ifstream inputnet;
        inputnet.open(filename);

        // get graph construction conditions
        string nodes, edges, line; 
        getline(inputnet,nodes);
        getline(inputnet,edges);

        NetToMag::Graph genGraph(stoi(nodes));

        // read edges
        stringstream stream;
        string id, cell0, cell1, term0, term1;
        for(int i=0; i<stoi(edges); i++)
        {
            getline(inputnet,line);
            stream << line;
            stream >> id;
            stream >> cell0;
            stream >> term0;
            stream >> cell1;
            stream >> term1;
            genGraph.AddEdge(
                    stoi(id)-1,
                    stoi(cell0)-1,
                    stoi(term0)-1,
                    stoi(cell1)-1,
                    stoi(term1)-1);
        }
        return genGraph;
    }

    void PrintNodes(Graph wGraph)
    {
        using namespace std;
        int width = wGraph.nodes.size();
        int j = 1;
        while(true)
        {
            width /= 10;
            j++;
            if(width < 10)
                break;
        }
    
        cout << "Printing Nodes" << endl;
        for(int i=0; i<wGraph.nodes.size(); i++)
        {
            cout    << setw(j) << wGraph.nodes[i].id+1 
                    << setw(j) << wGraph.nodes[i].origin[0] << ","
                    << setw(j) << wGraph.nodes[i].origin[1] << " |"
                    << setw(j) << wGraph.nodes[i].terminals[0]+1 << " " 
                    << setw(j) << wGraph.nodes[i].terminals[1]+1 << " " 
                    << setw(j) << wGraph.nodes[i].terminals[2]+1 << " " 
                    << setw(j) << wGraph.nodes[i].terminals[3]+1 << " " 
                    << endl;
        }
    }

    void PrintEdges(Graph wGraph)
    {
        using namespace std;
        cout << "Print Edges" << endl;
        for(int i=0; i<wGraph.edges.size(); i++)
        {
            cout    << setw(3) << wGraph.edges[i].id+1 << " "
                    << setw(3) << wGraph.edges[i].idA+1 << " "
                    << setw(3) << wGraph.edges[i].termA+1 << " "
                    << setw(3) << wGraph.edges[i].idB+1 << " "
                    << setw(3) << wGraph.edges[i].termB+1 << " "
                    << endl;
        }
    }

    void PrintToMagic(cubeGrid wGrid, double argt, string argw)
    {
        time_t t = time(0);
        long int now = static_cast<long int> (t);

        // open ofstream
        ofstream outMagic("output/" + argw);

        outMagic    << "magic"              << endl
                    << "tech scmos"         << endl
                    << "timestamp "
                    << argt << endl;
        outMagic    << "<< polysilicon >>"  << endl;

            for(int j=0; j<wGrid[0].size(); j++)
                for(int k=0; k<wGrid[0][j].size(); k++)
                    if(wGrid[0][j][k].type==-1)
                    {
                        outMagic    << "rect"   << " "
                                    << j        << " "
                                    << k        << " "
                                    << j+1      << " "
                                    << k+1      << " "

                                    << endl;
                    }
        outMagic    << "<< labels >>"       << endl;

        outMagic    << "<< metal1 >>"       << endl;
            for(int j=0; j<wGrid[0].size(); j++)
                for(int k=0; k<wGrid[0][j].size(); k++)
                    if(wGrid[0][j][k].type==-4)
                    {
                        outMagic    << "rect"   << " "
                                    << j        << " "
                                    << k        << " "
                                    << j+1      << " "
                                    << k+1      << " "
                                    << endl;

                    }

        outMagic    << "<< metal2 >>"       << endl;
            for(int j=0; j<wGrid[1].size(); j++)
                for(int k=0; k<wGrid[1][j].size(); k++)
                    if(wGrid[1][j][k].type==-3)
                    {
                        outMagic    << "rect"   << " "
                                    << j        << " "
                                    << k        << " "
                                    << j+1      << " "
                                    << k+1      << " "
                                    << endl;
                    }
        outMagic    << "<< m2contact >>"    << endl;
            for(int j=0; j<wGrid[1].size(); j++)
                for(int k=0; k<wGrid[1][j].size(); k++)
                    if(wGrid[0][j][k].type==-5)
                    {
                        outMagic    << "rect"   << " "
                                    << j        << " "
                                    << k        << " "
                                    << j+1      << " "
                                    << k+1      << " "
                                    << endl;
                    }
            for(int j=0; j<wGrid[1].size(); j++)
                for(int k=0; k<wGrid[1][j].size(); k++)
                    if(wGrid[1][j][k].type==-5)
                    {
                        outMagic    << "rect"   << " "
                                    << j        << " "
                                    << k        << " "
                                    << j+1      << " "
                                    << k+1      << " "
                                    << endl;
                    }
        outMagic    << "<< end >>"          << endl;
        outMagic    << "3.99seconds."       << endl;

        outMagic.close();
    }

};
