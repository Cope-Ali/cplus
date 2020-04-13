/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Br. Helfrich, Ali Cope
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 *    Based on the implementation in the BellLaPudula.cpp file by Br. Helfrich
 ************************************************************************/

#pragma once
#include <iostream>    // for CIN, COUT
#include <string>      // for STRING
#include <map>         // for VECTOR: a collection of Nodes
#include <cassert>     // because I am paranoid
using namespace std;

// levels of secrecy
enum Control { PUBLIC, CONFIDENTIAL, PRIVILIGED, SECRET, TOP_SECRET};


