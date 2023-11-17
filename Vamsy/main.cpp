#include <bits/stdc++.h>
#include <sys/resource.h>

#include "hadlock.h"
#include "forcepart.h"

using namespace NetToMag;

int main(int argc, char** argv)
{
    system("rm logs/runlog.txt");
    system("touch logs/runlog.txt");
 
    clock_t tStart1 = clock();
    string input, output;
    input = argv[argc-2];
    output = argv[argc-1];

    cout << "Placement Started " << endl;
    Graph wGraph = ParseNetList(input);
    
    // export to Magic
    int dimension = ForcePlace(&wGraph);
    //PrintEdges(wGraph);
    //PrintNodes(wGraph);
    cout << "Placement Ended" << endl;

    ofstream log;
    log.open("logs/runlog.txt",std::ios::app);
    log     << "placement run time on "
            << input
            << ": "
            << (double)(clock()-tStart1)/CLOCKS_PER_SEC
            << endl;
    log.close();

    clock_t tStart2 = clock();
    
    cout << "Routing Started " << endl;
    cubeGrid wGrid;
    wGrid = HadLock(&wGraph,dimension);
    PrintToMagic(wGrid,(double)(clock()-tStart2)/CLOCKS_PER_SEC,output);

    log.open("logs/runlog.txt",std::ios::app);
    log     << "routing run time on "
            << input
            << ": "
            << (double)(clock()-tStart1)/CLOCKS_PER_SEC
            << endl;

    struct rusage r_usage;
    getrusage(RUSAGE_SELF,&r_usage);
    log       << "Memory usage: "
              << r_usage.ru_maxrss
              << endl;
    log.close();
    cout    << "Routing Ended " << endl
            << "Terminating Program" << endl;

    return 0;
}
