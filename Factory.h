/*
 * Factory.h
 *
 *  Created on: Jan 23, 2016
 *      Author: jjfeddock
 */

#pragma once
#include "LinkedListInterface.h"

using namespace std;


/*
	getLinkedList()
*/
class Factory
{
	public:
		static LinkedListInterface<int>* getLinkedListInt();
		static	LinkedListInterface<string>* getLinkedListString();
		
};
