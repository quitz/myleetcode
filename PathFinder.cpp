#include "PathFinder.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

using namespace std;

vector < string > PathFinder::parseFile( const string& filename ) {
	ifstream ifs( filename.c_str(), ios::in );
	if ( !ifs ) { throw "File not found!"; }

	vector < string > lines;
	string line;
	while ( getline( ifs, line ) ) {
		lines.push_back( line );
	};

	return PathFinder::parseLines( lines );
}

vector < string > PathFinder::parseLines( const vector < string >& lines ) {
    vector<string>res;
    if (lines.size() == 0) return res;
    unordered_map<string,unordered_set<string> >mp;
    
    int i = lines[0].find_first_of(" ");
    string start = lines[0].substr(0, i);
    string des = lines[0].substr(i+1);
    for (int i=1; i<lines.size(); i++){
        int j = lines[i].find_first_of(":");
        string node = lines[i].substr(0,j-1);
        unordered_set<string> edge;
        stringstream ss(lines[i].substr(j+2));
        string end;
        while(getline(ss, end, ' ')){
            edge.insert(end);
        }
        if(mp.find(node)==mp.end())mp[node]=edge;
        else mp[node].insert(edge.begin(), edge.end());
    }
    string path="";
    unordered_set<string>visited;
    dfs(start, des, path, res, visited, mp);
    return res;
}

void PathFinder::dfs(string start, string des, string path, vector<string> &res,
                     unordered_set<string> &visited, unordered_map<string,
                     unordered_set<string> >& mp){
    visited.insert(start);
    string old_path=path;
    path+=start;
    
    if(start == des) res.push_back(path);
    else{
        for(auto& node:mp[start]){
            if(!visited.count(node)){
                dfs(node, des, path,res, visited, mp);
            }
        }
    }
    path=old_path;
    visited.erase(start);
}


#ifdef USE_MAIN
/**
 * This test code is provided only for your convenience.
 */
int main()
{

    return 0;
}

#endif