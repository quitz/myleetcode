//
//  main.cpp
//  test
//
//  Created by quitz on 2017/3/1.
//  Copyright © 2017年 LDC. All rights reserved.
//

#include "main.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <locale>
#include <ctime>
#include <fstream>

using namespace std;

std::string LogParser::parseFile( const std::string& filename ) {
    std::ifstream ifs( filename.c_str(), std::ios::in );
    if ( !ifs ) { throw "File not found!"; }
    
    std::vector < std::string > lines;
    std::string line;
    while ( std::getline( ifs, line ) ) {
        lines.push_back( line );
    };
    
    return LogParser::parseLines( lines );
}

std::string LogParser::parseLines( const std::vector < std::string >& lines ) {
    double total = 0, online = 0;
    time_t start = 0, end = 0, cur = 0, connect = 0, disconnect = 0;
    bool connected = false;
    
    for(int i=0;i<lines.size();i++){
        string line = lines[i];
        int idx = line.find_last_of("::");
        cur = LogParser::processTime(line.substr(1,19));
        string state = line.substr(idx + 2);
        
        if(state == "START"){
            start = cur;
        }
        else if(state == "SHUTDOWN"){
            end = cur;
        }
        else if(state == "CONNECTED"){
            if(connected)
                continue;		//in case there are two consective connected states
            else{
                connect = cur;
                connected = true;
            }
        }
        else if (state == "DISCONNECTED"){
            if(!connected)
                continue;	//in case there are two consective disconnected states
            else{
                online += difftime(cur, connect);
                connected = false;
                disconnect = cur;
            }
        }
        else
            ;	//do nothing
    }
    
        if(connected)
            online += difftime(end, disconnect);
        
        total = difftime(end,start);
        if(total == 0)
            return "0%";
        
        return to_string(int(online*100/total)) + "%";
        
}

    
time_t LogParser::processTime(string str){
    struct tm t;
    istringstream ss(str);
    int d=1,m=0,y=1900,h=0,mi=0,sec=0;
    sscanf(str.c_str(), "%d/%d/%d-%d:%d:%d", &m,&d,&y,&h,&mi,&sec);
    t.tm_year = y - 1900;
    t.tm_mon = m - 1;
    t.tm_mday = d;
    t.tm_hour = h;
    t.tm_min = mi;
    t.tm_sec = sec;
    return timelocal(&t);
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
