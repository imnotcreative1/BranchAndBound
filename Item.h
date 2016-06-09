/*
 * Item.h
 *
 *  Created on: Nov 25, 2015
 *      Author: Matt
 */

#ifndef ITEM_H_
#define ITEM_H_

class Item {
public:
	int id;
	int value;
	int mass;
	Item();
	Item(int, int, int);
	virtual ~Item();
};

#endif /* ITEM_H_ */
