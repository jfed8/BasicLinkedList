/*
 * LinkedList.h
 *
 *  Created on: Jan 23, 2016
 *      Author: jjfeddock
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "LinkedListInterface.h"
#include <stdexcept>
#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface<T> {

public:
	LinkedList<T>(void) {
		firstNode = NULL;
		total_nodes = 0;
	}
	~LinkedList<T>(void) {
            clear();
	}
	;

	bool findNode(T data) {

		if (firstNode == NULL)
			return false;

		node* runner;
		runner = firstNode;
                
		if (runner->value == data){
                    return true;
                }
                        
		for (int i = 0; i < total_nodes-1; i++) {
					
                        if (runner->next_node != NULL)
                                runner = runner->next_node;

			if (runner->value == data) {
				return true;
			}

		}
		return false;
	}

	void insertHead(T value) {
            
		if (findNode(value) == false) {
			firstNode = new node(value, firstNode);
			total_nodes++;
		}
	}

	void insertTail(T value) {
		if (findNode(value) == false) {
			
                        if (size() == 0)
                        {
                            node *test;
                            test = new node(value, NULL);
                            firstNode = test;
                            total_nodes++;

                         
                        }
                        else {
                    
                            node *test;
                            test = firstNode;
                            for (int i=0; i<size()-1; i++)
                                    test = test->next_node;

                            test->next_node = new node(value, NULL);
                            total_nodes++;
                        }
		}
	}

	void insertAfter(T value, T insertionNode) {

		if (findNode(value) == false) {
			if (findNode(insertionNode) == true) {
				node* temp1;
				temp1 = firstNode;

				if (firstNode->value == insertionNode) {
					node *temp = new node(value, firstNode->next_node);
					firstNode->next_node = temp;
					total_nodes++;
					return;
					}



				for (int i = 0; i < total_nodes-1; i++) {
					
					if (temp1->next_node != NULL){
						temp1 = temp1->next_node;

					if (temp1->value == insertionNode) {
						node *temporary;
						temporary = new node(value, temp1->next_node);
						temp1->next_node = temporary;
						total_nodes++;
                                                return;
					}}
				}



			}
		}
	}

	void remove(T value) {

		if (findNode(value) == true) {
                    
                    node* seeker;
                    seeker = firstNode;
                    
                    if (firstNode->value == value)
                    {
                        node* dele;
                        dele = firstNode;
                        
                        firstNode = firstNode->next_node;
                        delete dele;
                        total_nodes--;
                        return;
                    }
                    
                    while (seeker->next_node->value != value && seeker->next_node != NULL)
                    {
                        seeker = seeker->next_node;
                    }
                    
                    node* del;
                    del = seeker->next_node;
                    
                    seeker->next_node = seeker->next_node->next_node;
                    total_nodes--;
                    delete del;
                    
		}

	}

	void clear() {
            
            while(firstNode != NULL) {
                remove(firstNode->value); 
            }
            total_nodes = 0;
            return;
            

	/*	for (int i = 0; i < total_nodes; i++) {
			node *temp;
			temp = firstNode;
			firstNode = temp->next_node;
			delete temp;
		}

		firstNode = NULL;
		total_nodes = 0; */
	}

	T at(int index) {

		node* finder;
		finder = firstNode;

		if (index < 0 || index >= total_nodes) {
			throw std::out_of_range("Out of Range");
		}
		
		for(int i = 0; i<index; i++){
                    
                    finder = finder->next_node;
                    
                }
                
                return finder->value;
	}

	int size() {
/*
		node* temp1;
		temp1 = firstNode;

		if (firstNode == NULL)
			return 0;

		int count = 0;

		while (temp1 != NULL) {

			temp1 = temp1->next_node;
			count++;

		}
*/
		return total_nodes;
	}

	

	

private:
    
        struct node {
            
                T value;
		node* next_node;

		node(T data, node* temp = NULL) :
				value(data), next_node(temp) {}
		

	};
	int total_nodes;
	node* firstNode;
};

#endif /* LINKEDLIST_H_ */
