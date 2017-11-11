//
// Created by Vlad on 9/2/2017.
//

#ifndef GENERIC_LINKED_LIST_GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_GENERIC_LINKED_LIST_H

#include "string"
#include <typeinfo>


template <class GenericObject>
class GenericLinkedList{
     public: //See linkedObject structure before hand below
        GenericLinkedList(GenericObject Object){ //Constructor if a element is passed during declaration
            LinkedObject *linkedObject = new LinkedObject;
            linkedObject->Object = Object;
            linkedObject->prevObject = 0;
            linkedObject->nextObject = 0;
            lastPointer = linkedObject;
            firstPointer = linkedObject;
            totalItems++;
        }
        GenericLinkedList(){
            //Empty Constructor
        }
        void addObject(GenericObject Object){ //Adding object to the end
            if(totalItems == 0){ //If there are no items, has to be treated differently because firstPoint and lastPointer are null
                LinkedObject *linkedObject = new LinkedObject;
                linkedObject->Object = Object;
                linkedObject->prevObject = 0;
                linkedObject->nextObject = 0;
                lastPointer = linkedObject;
                firstPointer = linkedObject;
                totalItems++;
            }else {
                LinkedObject *linkedObject = new LinkedObject;
                linkedObject->Object = Object;
                linkedObject->prevObject = lastPointer;
                linkedObject->nextObject = 0;
                lastPointer->nextObject = linkedObject;
                lastPointer = linkedObject;
                totalItems++;
            }
        }
        void addObject(int i, GenericObject Object){ //Adding object into any point in the list, puts the item into the listed, puts element currently in the location to be after the new element
            if(totalItems == 0){
                LinkedObject *linkedObject = new LinkedObject;
                linkedObject->Object = Object;
                linkedObject->prevObject = 0;
                linkedObject->nextObject = 0;
                lastPointer = linkedObject;
                firstPointer = linkedObject;
                totalItems++;
            }else {
                LinkedObject *linkedObject = new LinkedObject;
                linkedObject->Object = Object;
                LinkedObject *pointer = firstPointer;
                if (i <= 0) { //Puts item in first location
                    pointer->prevObject = linkedObject;
                    linkedObject->nextObject = pointer;
                    linkedObject->prevObject = 0;
                    firstPointer = linkedObject;
                    totalItems++;
                } else if (i >= totalItems) { //Puts item at the end by calling the regular addObject function that adds to the end
                    addObject(Object);
                } else {
                    for (int j = 0; j < i; j++) { //Finding pointer of the element at i so you can shift it
                        pointer = pointer->nextObject;
                    }
                    pointer->prevObject->nextObject = linkedObject;
                    linkedObject->nextObject = pointer;
                    pointer->prevObject = linkedObject;
                    totalItems++;
                }
            }
        }
        void removeObject(int i){ //Used to delete object at any location
            if(i == 0){ //Deleting object from first location needs special treatment to avoid future errors with pointer lcoations
                if(totalItems == 1){
                    delete lastPointer;
                    lastPointer = 0;
                    firstPointer = 0;
                    totalItems--;
                    return;
                }
                else{
                    firstPointer = firstPointer->nextObject;
                    totalItems--;
                    return;
                }
            }
            //std::cout << "TOTAL ITEMS: " << totalItems << "\tI :" << i << std::endl;
            if(totalItems == i + 1){
                lastPointer->prevObject->nextObject = 0;
                lastPointer = lastPointer->prevObject;
                totalItems--;
                //std::cout << "TEST" << std::endl;
                return;
            }
            LinkedObject *currentPointer = firstPointer;
            LinkedObject *lastPointer;
            LinkedObject *nextPointer = firstPointer->nextObject;
            if(firstPointer == 0){
                std::cout << "No object currently exists in slot " + i;
                std::cout << "First if fail";
                return;
            }
            for(int j = 0; j < i; j++){
                if(nextPointer->nextObject == 0){
                    std::cout << "No object currently exists in slot " << i << std::endl;
                    break;
                }
                lastPointer = currentPointer;
                currentPointer = nextPointer;
                nextPointer = currentPointer->nextObject;
            }
            lastPointer->nextObject = nextPointer;
            delete currentPointer;
        }
        void printAll(){ //print all element, not fully function or useful
            int itemsPrinted = 0;
            if(totalItems == 0){
                std::cout << "No items exist to print" << std::endl;
                return;
            }
            LinkedObject *object = firstPointer;
            while(true){
                std::string dataTypeName = typeid(firstPointer).name();
                std::cout << "Item " << itemsPrinted << ": " << dataTypeName << "@" << &object->Object << std::endl;
                itemsPrinted++;
                if(object->nextObject == 0){
                    break;
                }
                object = object->nextObject;
            }
        }
        GenericObject getItem(int i){ //gets an item from location
            LinkedObject *object = firstPointer;
            for(int j = 0; j < i; j++){ //finds item
                object = object->nextObject;
            }
            return object->Object;
        }
        int size(){ //returns total amount of items
            return totalItems;
        }
        void iterator(){ //must be used to reset or set iterator location
            itLocation = firstPointer;
        }
        GenericObject iteratorNext(){ //returns the item and returns item at iterator location
            LinkedObject *temp = itLocation;
            itLocation = itLocation->nextObject;
            return temp->Object;
        }
        bool iteratorHasNext(){ //checks if there is an item
            if(itLocation == 0){
                return false;
            }else{
                true;
            }
        }
     private:
        struct LinkedObject{ //Used as an item container
            GenericObject Object;
            LinkedObject *prevObject;
            LinkedObject *nextObject;
        };
        LinkedObject *firstPointer = 0;
        LinkedObject *lastPointer = 0;

        LinkedObject *itLocation = 0;
        int totalItems = 0;
};

#endif //GENERIC_LINKED_LIST_GENERIC_LINKED_LIST_H
