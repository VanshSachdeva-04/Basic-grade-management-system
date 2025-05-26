#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list.h"
#include "node.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>{
    private:
        Node<ItemType>* headPtr;
        int itemCount;
        Node<ItemType>* getNodeAt(int position) const{
            // enforce precondition
	        if((position >= 1) && (position <= itemCount)){
		        // Count from the beginning of the chain
		        Node<ItemType>* curPtr = headPtr;
		        for (int skip = 1; skip < position; skip++){
			        curPtr = curPtr->getNext();
		        }
		        return curPtr;
	        }
	        return nullptr;
        }

    public:
        LinkedList(){
            headPtr = nullptr;
            itemCount = 0;
        }

        LinkedList(const LinkedList<ItemType>& aList){
            itemCount = aList.itemCount;
	        if(aList.headPtr == nullptr){
		        headPtr = nullptr;
	        }else{
                headPtr = new Node<ItemType>(aList.headPtr->getItem());
                Node<ItemType>* newChainPtr = headPtr;
                Node<ItemType>* origChainPtr = aList.headPtr->getNext();
                while(origChainPtr != nullptr){
                    newChainPtr->setNext(new Node<ItemType>(origChainPtr->getItem()));
                    newChainPtr = newChainPtr->getNext();
                    origChainPtr = origChainPtr->getNext();
                }
            }
        }

        ~LinkedList(){
            clear();
        }

	    bool isEmpty() const{
            return itemCount == 0;
        }

	    int getLength() const{
            return itemCount;
        }

	    bool insert(int newPosition, const ItemType& newEntry){
            bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
            if(ableToInsert){
                Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
                if(newPosition == 1){
                    newNodePtr->setNext(headPtr);
                    headPtr = newNodePtr;
                }else{
                    Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
                    newNodePtr->setNext(prevPtr->getNext());
                    prevPtr->setNext(newNodePtr);
                }
                itemCount++;
                return true;
            }
            return false;
        }

	    bool remove(int position){
            bool ableToRemove = (position >= 1) && (position <= itemCount);
            if (ableToRemove){
                Node<ItemType>* ptrToDelete = nullptr;
                if (position == 1){
                    // Remove the first node in the chain
                    ptrToDelete = headPtr; // Save pointer to node 
                    headPtr = headPtr->getNext();// save pointer to next node
                }
                else{
                    // Find node that is before the one to remove
                    Node<ItemType>* prevPtr = getNodeAt(position - 1);
                    // Point to node to remove
                    ptrToDelete = prevPtr->getNext();
                    // Disconnect indicated node from chain by connecting the prior node with the one after
                    prevPtr->setNext(ptrToDelete->getNext());
                }

                ptrToDelete->setNext(nullptr);
                delete ptrToDelete;
                ptrToDelete = nullptr;
                itemCount--; // Decrease count of entries
            }
            return ableToRemove;
        }
	    void clear(){
            while(headPtr != nullptr){
                Node<ItemType>* nodeDelete = headPtr;
                headPtr = headPtr->getNext();
                delete nodeDelete;
            }
            itemCount = 0;
        }
	    ItemType getEntry(int position) const{
            bool ableToGet = (position >= 1) && (position <= itemCount);
            if(ableToGet){
                Node<ItemType>* nodePtr = getNodeAt(position);
                return nodePtr->getItem();
            }
            throw "Item not found";
        }
	    ItemType replace(int position, const ItemType& newEntry){
            // enforce precondition
            bool ableToReplace = (position >= 1) && (position <= itemCount);
            if (ableToReplace){
                Node<ItemType>* nodePtr = getNodeAt(position);
                ItemType oldEntry = nodePtr->getItem();
                nodePtr->setItem(newEntry);	
                return oldEntry;	
            } 
            throw "Item not found";
        }
};

#endif