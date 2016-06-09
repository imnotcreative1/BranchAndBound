/*
 * node.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: Matt
 */

#include "node.h"
#include "source.h"

node::node(vector <Item> itemsTaken, int costsofar) {
	pset = itemsTaken;
	csf = costsofar;
	lowerBound = csf;
	UpperBound = calcUpperBound();
}
node::node(const node &nde){
	UpperBound = nde.UpperBound;
	lowerBound = nde.lowerBound;
	csf = nde.csf;
	for (unsigned int i = 0; i < nde.pset.size(); i++){
		Item temp(0, 0 , 0);
		temp = nde.pset[i];
		pset.push_back(temp);
	}
}
int node::calcLowerBound(){
	int lb;
	if (getType() == 0) lb = csf; //weaker lower bound
	else {lb = csf  + guaranteedFutureCost(getWeightOfSet(),  pset.size()-1);/*stronger lower bound*/}

	return lb;
}

int node::calcUpperBound(){
	int ub = csf;
	int gfc;
	//if (getType() == 0){
		BadFeasibleFutureCost(getWeightOfSet(), pset.size()-1);
	//}
	//else {gfc = FeasibleFutureCost(getWeightOfSet(), pset.size()-1);}
	ub += gfc;
	return ub;
}

void node::addItem(Item add){
	if (add.mass + getWeightOfSet() <= maxWeight()){
		pset.push_back(add);
		if (add.id == 0) csf += list()[pset.size()-1].value;
		lowerBound = calcLowerBound();
		UpperBound = calcUpperBound();
	}
	else {
		pset.push_back(add);
		lowerBound = 9999999;
	}
}

int node::getWeightOfSet(){
	int weight(0);
	for (unsigned int i = 0; i < pset.size(); i++){
		if (pset[i].id != 0)
			weight += pset[i].mass;
	}
	return weight;
}


node::~node() {
	// TODO Auto-generated destructor stub
}

