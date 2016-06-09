/*
 * source.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Matt
 */

#ifndef SOURCE_H_
#define SOURCE_H_

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "minHeap.h"
#include "node.h"
#include "Item.h"

using namespace std;

int getType();
int BadFeasibleFutureCost(int, int);
int guaranteedFutureCost(int, int);
int FeasibleFutureCost(int, int);
vector <Item> list();
int maxWeight();


#endif /* SOURCE_H_ */
