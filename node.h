/*
 * node.h
 *
 *  Created on: Nov 25, 2015
 *      Author: Matt
 */

#ifndef NODE_H_
#define NODE_H_

#include "Item.h"
#include <vector>
#include <iostream>

using namespace std;

class node {
public:
	vector <Item> pset;
	int lowerBound;
	int UpperBound;
	int csf;
	node(vector <Item>, int costsofar);
	node(const node &aNode);
	int getWeightOfSet();
	int calcLowerBound();
	int calcUpperBound();
	void addItem(Item);
	virtual ~node();
};

#endif /* NODE_H_ */
