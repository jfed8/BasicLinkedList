/*
 * Factory.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: jjfeddock
 */

#include "Factory.h"
#include "LinkedListInterface.h"
#include "LinkedList.h"

#include <string>

//	getLinkedListInt()


LinkedListInterface<int> * Factory::getLinkedListInt()
{
    return new LinkedList<int>();
}

/*
    getLinkedListString()

*/
LinkedListInterface<string>* Factory::getLinkedListString()
{
    return new LinkedList<string>();
}
