#include "Navigation.h"

// This function reads in the contents of the file _mapName.
// The function can assume that the contents of the specified conform with the specs given in the README.txt file
// Returns true if the file is read in successfully, false otherwise
bool Navigation::readNetwork(string _mapName) {
    ifstream in;
    in.open(_mapName);
    in >> numNodes;
    int num;
    for(int i = 0; i < pow(numNodes,2); ++i) {
        in >> num;
        paths.push_back(num);
    }
    in.close();
    if(paths.size() == pow(numNodes,2)) {
        return true;
    }
    else {
        return false;
    }
}

// This function computes and returns the least-cost path from node indexed _startInd to node indexed as _endInd
// for the map that was last read (in the readMap function).  The resulting path must be stored in an integer queue
// with each entry in the queue denoting the next node in the path.  First front of the queue should be _startInd
// and the back of the queue should be _endInd.
// For example, in map1.txt, solveMap(13, 1) should return the shortest path from node 13 to node 1, which is:
//      13, 9, 10, 7, 3, 2, 1
// You can assume that readNetwork(_mapName) is called before this function and that a path from _startInd to _endInd exists
queue<int> Navigation::computeShortestPath(int _startInd, int _endInd) {
    priority_queue<Node, vector<Node>, Node> myqueue;
    Node current;
    int last;
    Node n;
    n.cost = 0;
    n.path.push(_startInd);
    myqueue.push(n);
    while(myqueue.top().path.back() != _endInd) {
        current = myqueue.top();
        myqueue.pop();
        last = current.path.back();
        for(int i = last; i < paths.size(); i = i + numNodes) {
            Node nn;
            if(paths.at(i) > 0) {
                int location = ((i - last) / (numNodes));
                nn.cost = current.cost + paths.at(i);
                nn.path = current.path;
                nn.path.push(location);
                myqueue.push(nn);
            }
        }
    }
    return myqueue.top().path;
}

// prints out to the console the path stored in _path
void Navigation::printPath(queue<int> _path) {
    cout << _path.front();
    _path.pop();
    while(!_path.empty()) {
        cout << ", " << _path.front();
        _path.pop();
    }
}