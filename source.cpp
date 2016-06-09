//============================================================================
// Name        : BnB01.cpp
// Author      : Matthew Sims (10099516)
// Version     : The One & Only :)
// Copyright   : Your copyright notice
// Description : BnB 0/1 Knapsack
//============================================================================
//#pragma once
#include "source.h"

void printNodePath(node nde);

bool compare(const Item &l, const Item &r){
	return l.value/l.mass > r.value/r.mass;
}
bool massCompare(const Item &l, const Item &r){
	if (l.mass == r.mass){
		return l.value > r.value;
	}
	return l.mass < r.mass;
}
int lbCalctype;
int k;
int n;
vector <Item> notSortedCollection;
int globalUpperBound;
vector <Item> collection;
int getType(){
	return lbCalctype;
}
int guaranteedFutureCost(int spaceTaken, int itemsTaken){
	int gfc = 0;
	vector <Item> byMassCollection;
	for (unsigned int i = itemsTaken+1; i < collection.size(); i++){
		if(collection[i].mass + spaceTaken > k){
			gfc += collection[i].value;
		}
		else {
			byMassCollection.push_back(collection[i]);
		}
	}
	if (gfc == 0 && byMassCollection.size() > 0){
		int weightAdded =  0;
		sort(byMassCollection.begin(), byMassCollection.end(), massCompare);
		for (unsigned int k = 0; k < byMassCollection.size(); k++){
			int mass = byMassCollection[k].mass;
			//cout << mass <<  " + " << spaceTaken << " < " << k << endl;
			//cout << "space taken is " << spaceTaken << " trying to take " << mass << endl;
			if (weightAdded < mass && spaceTaken + weightAdded < maxWeight()){
				weightAdded += mass;
				gfc += byMassCollection[k].value;
			}
			else {
				//cout << "added " << gfc << endl;
				break;
			}
		}
	}
	return gfc;
}
int FeasibleFutureCost(int spaceTaken, int itemsTaken){
	int ffc = 0;
	for (unsigned int i = itemsTaken+1; i < collection.size(); i++){
		if(collection[i].mass + spaceTaken <= k){
			spaceTaken += collection[i].mass;
		}
		else {
			ffc += collection[i].value;
			//cout << collection[i].id << " " << collection[i].mass << " " << endl;
		}
	}
	return ffc;
}
int BadFeasibleFutureCost(int spaceTaken, int itemsTaken){
	int ffc = 0;
		for (unsigned int i = itemsTaken+1; i < collection.size(); i++){
			if(collection[i].mass + spaceTaken <= k){
				spaceTaken += collection[i].mass;
			}
			else {
				ffc += collection[i].value;
				//cout << collection[i].id << " " << collection[i].mass << " " << endl;
			}
		}
		return ffc;
}
vector <Item> list (){
	return collection;
}
int maxWeight(){
	return k;
}
void BnB(int);




int main(){
	stringstream fileName;
	string file;
	for (int i = 20; i <= 20/*50*/; i++){
		fileName.str("");
		file= "";
		fileName << "B+B 2015 Data 20151124 1226  Size " << i << ".txt";
		file = fileName.str();
		ifstream read("instance1.txt"/*file.c_str()*/);
		char instance[256];
		//read >> instance >> instance;
		read.getline(instance, 256);
		read >> k >> n;

		cout << instance << endl;
		//cout << k << " " << n << endl;

		int id, value, mass;

		for (int i = 0; i < n; i++){
			read >> id;
			read >> value;
			read >> mass;
			Item temp(id, value, mass);
			collection.push_back(temp);
			notSortedCollection.push_back(temp);
			//byMassCollection.push_back(temp);
			//cout << collection[i].id << " " << collection[i].value << " " << collection[i].mass << endl;
		}

		globalUpperBound = 0;
		//Use Greedy Algorithm to find the items the most value per mass
		sort(collection.begin(), collection.end(), compare);
		//sort(byMassCollection.begin(), byMassCollection.end(), massCompare);

		//check to see if collection was properly sorted
		for (int i = 0; i < n; i++){
			//cout << collection[i].id << " " << collection[i].value << " " << collection[i].mass << endl;
			//cout << byMassCollection[i].id << " " << byMassCollection[i].value << " " << byMassCollection[i].mass << endl;
		}
		int spaceLeft = k;
		vector <bool> choices;
		for (int i = 0; i < n; i++){
			if (collection[i].mass <= spaceLeft){
				spaceLeft -= collection[i].mass;
				choices.push_back(true);
			}
			else{
				globalUpperBound += collection[i].value;
				choices.push_back(false);
			}
		}

		//cout << "The initial Upper Bound is " << globalUpperBound << endl;
		lbCalctype = 0;
		//BnB(lbCalctype);
		lbCalctype = 1;
		BnB(lbCalctype);
		cout << "-----------------------------------------------------------------------" << endl;

		/* Current Status: Complete
		 *
		 */
		/* Things to Note/Remember:
		 * 	-Even after you removeNode, you can still access the element of the minheap
		 * 	but the path will be unexpected and the size will decrease
		 *
		 * 	-Will not work if costs can be larger or equal to 9999999
		 */
	}
	return 0;
}

void printNodePath(node nde){
	cout << "Node has a path ";
	for (unsigned int i = 0; i < nde.pset.size(); i++){
		cout << nde.pset[i].id << " ";
	}
	cout << "LB: " << nde.lowerBound << " UB: " << nde.UpperBound << endl;
	cout << endl;
}

void BnB(int type){
Item emptyItem(0, 0, 0);
	vector <Item> tempSet;
	tempSet.clear();
	tempSet.push_back(emptyItem);
	node emptyNode(tempSet, collection[0].value);
	//declare the min-heap
	//note that node represents a partial solution
	minHeap allPartialSolutions;
	tempSet.clear();
	tempSet.push_back(collection[0]);
	node tempNode(tempSet, 0);//first choice is a greedy one
	allPartialSolutions.addNode(tempNode);
	allPartialSolutions.addNode(emptyNode);
	tempSet.clear();
	//allPartialSolutions.displayPartialSolution();
	//cout << "------------------------------------------------------------------" << endl;

	int currentSize = 0;
	//Done adding initial choices
	for (int i = 0; currentSize < n; i++){
		node chosenNode = (allPartialSolutions.heap[1]);
		node yesNode = chosenNode;
		node noNode = chosenNode;

		//printNodePath(allPartialSolutions.heap[1]);
		//cout << "With a lower bound of " << chosenNode.lowerBound << endl;

		noNode.addItem(Item(0, 0, 0));
		yesNode.addItem(collection[chosenNode.pset.size()]);
		//cout << "Look here: " << yesNode.pset[yesNode.pset.size()-1].id << endl;
		allPartialSolutions.addNode(yesNode);
		allPartialSolutions.addNode(noNode);

		if (yesNode.UpperBound < globalUpperBound) globalUpperBound = yesNode.UpperBound;
		if (noNode.UpperBound < globalUpperBound) globalUpperBound = noNode.UpperBound;
		allPartialSolutions.removeRoot();
		//allPartialSolutions.displayPartialSolution();
		//allPartialSolutions.removeNodes(globalUpperBound);
		//allPartialSolutions.displayPartialSolution();
		//printNodePath(yesNode);
		//cout << "Global Upper Bound is " << globalUpperBound << endl;
		//cout << "------------------------------------------------------------------" << endl;
		currentSize = allPartialSolutions.heap[1].pset.size();
	}
	allPartialSolutions.displayPartialSolution(type);
}
