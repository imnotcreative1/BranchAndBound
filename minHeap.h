/*
 * minHeap.h
 *
 *  Created on: Nov 25, 2015
 *      Author: Matt
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include "node.h"
#include <vector>
#include <iostream>

using namespace std;

class minHeap {
public:
	vector <node> heap;
	minHeap();
	void addNode(node);
	void removeNodes(int);
	void siftDown(int);
	void removeRoot();
	//node LowestBoundedNode();
	void displayPartialSolution(int);
	virtual ~minHeap();
};

#endif /* MINHEAP_H_ */
