#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node{
    private:
        ItemType item;
        Node<ItemType>* next;
    public:
        Node(){
        next = nullptr;
        }
        Node(const ItemType& anItem){
            item = anItem;
            next = nullptr;
        }
        Node(const ItemType& anItem, Node<ItemType>* nextNodePtr){
            item = anItem;
            next = nextNodePtr;
        }

        void setItem(const ItemType& anItem){
            item = anItem;
        }
        void setNext(Node<ItemType>* nextNodePtr){
            next = nextNodePtr;
        }
        ItemType getItem() const{
            return item;
        }
        Node<ItemType>* getNext() const{
            return next;
        }
};

#endif