/*
 * minHeap.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: Matt
 */

#include "minHeap.h"
#include "node.h"



minHeap::minHeap() {
	Item zero(0, 0, 0);
	vector <Item> temp;
	temp.clear();
	temp.push_back(zero);
	node aNode(temp, 0);
	heap.push_back(aNode);
}

void minHeap::displayPartialSolution(int type){
	//cout << endl << "Displaying all Partial Sets...." << endl;
	int numberOfPartialSolutions = heap.size()-1;
	for (unsigned int i = 1; i < heap.size(); i++){
		node thisNode  = heap[i];
		if (i == 1){
			if (type == 0) cout << "Solution Set (Weaker Lower Bound)" << endl;
			else cout << "Solution Set (Stronger Lower Bound)" << endl;
			for (unsigned int j = 0; j < thisNode.pset.size(); j++){
				cout << thisNode.pset[j].id << " ";
			}
			cout << "LB: " << thisNode.lowerBound << " UB: " << thisNode.UpperBound << endl;
		}
		if (thisNode.lowerBound > 9999) numberOfPartialSolutions--;
	}
	cout << numberOfPartialSolutions << " partial solutions were used in the making of this optimal solution" << endl;
}

void minHeap::addNode(node nde){
	heap.push_back(nde); //initially add the node
	int len = heap.size(); //number of elements currently in the heap
	//cout << nde.pset.size() << endl;
	int index = len-1; //index the node was inserted at
	int parentIndex = index/2; //this should always round down
	//cout << "added final id: " << nde.pset[nde.pset.size()-1].id << endl;
	//int nnode =  heap[index].pset[heap[index].pset.size()-1].id;
	//int onode = heap[parentIndex].pset[heap[parentIndex].pset.size()-1].id;
	//cout << "added final id: " << nnode << endl;
	//cout << "comparing to: " << onode << endl;
	//swap if new node has a better lowerBound than its parent
	while (heap[index].lowerBound < heap[parentIndex].lowerBound && parentIndex != 1){
		heap[index] = heap[parentIndex];
		heap[parentIndex] = nde;
		index = parentIndex;
		parentIndex = index/2;
		//cout << "swap when added" << endl;
	}
}

void minHeap::removeNodes(int gUB){
	node bottomElement = heap[heap.size()-1];
	int numOfBottomElements = (heap.size())/2;
	//cout <<  heap.size() << " nobe" << numOfBottomElements << endl;
	for (int i = 1; i <= numOfBottomElements; i++){
		bottomElement = heap[heap.size()-i];
		node nnode =  bottomElement;
		//cout << nnode.pset[heap[i].pset.size()-1].id << " with lb of " << nnode.lowerBound << endl;
		if (bottomElement.lowerBound > gUB){
			heap.erase(heap.end()-i);
			i--;
			//cout << "removed node " << endl;
		}
	}
}

void minHeap::siftDown(int pos){
	int tempPos = pos*2;
	int heapSize = heap.size()-1;
	if (tempPos < heapSize){
		if (heap[tempPos].lowerBound < heap[tempPos+1].lowerBound){
			if (heap[pos].lowerBound > heap[tempPos].lowerBound){
				//cout << "swap" << endl;
				swap(heap[pos], heap[tempPos]);
				//cout << "now compare index " << tempPos << " to index " << tempPos*2 << endl;
				siftDown(tempPos);
			}
		}
		else{
			if (heap[pos].lowerBound > heap[tempPos+1].lowerBound){
				//cout << "swap2" << endl;
				swap(heap[pos], heap[tempPos+1]);
				siftDown(tempPos + 1);
			}
		}
	}
	else if (tempPos <= heapSize){
		if (heap[pos].lowerBound > heap[tempPos].lowerBound){
			//cout << "swap3" << endl;
			swap(heap[pos], heap[tempPos]);
		}
	}
}
void minHeap::removeRoot(){
	node lastElement = heap[heap.size()-1];
	heap[1] = lastElement;
	heap.pop_back();
	//displayPartialSolution();
	siftDown(1);
	//displayPartialSolution();
}


minHeap::~minHeap() {
	// TODO Auto-generated destructor stub
}

