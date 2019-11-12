/*
 * List.cpp
 * 
 * Class Description: List data collection.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (What other characteristic does our List have?)
 *
 * Author: Reed Lu
 * Date: January 22, 2019
 */
#include <iostream>
#include <string>
#include "List.h"


// Default constructor
List::List() {
    elementCount = 0;
    capacity = MAX_ELEMENTS;
};

	// Description: Returns the total element count currently stored in List.
int List::getElementCount() const{
    return elementCount;
}

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement){
    if(elementCount == 0 && newElement.getCareCard() != "0000000000"){
        //if no elements in the list, add new patient to list
        elements[elementCount] = newElement;
        cout << "The new patient has been added." << endl;
        elementCount++;
        return true;
    }else if(elementCount == capacity){
        //if list reached max capacity, return to main menu
        cout << "List reached max capacity." << endl;
        return false;
    }else if(newElement.getCareCard() == "0000000000"){
        //if care card not entered correctly (as nature of parameterized constructor) or care card is "0000000000", patient will not be added
        cout << "Invalid Care Care Number, patient not added" << endl;
        return false;
    }else{
        //if list is not empty, first check if patient is already in the list
        //if paitient is not in list, add patient to list
        for(int i = 0; i < elementCount; i++){
            if(elements[i] == newElement && elements[i].getCareCard() != "0000000000"){
                cout << "The paitient with the same Care Card number already exists in the system." << endl;
                return false;
            }else{
                elements[elementCount] = newElement;
                cout << "The new patient has been added." << endl;
                elementCount++;
                return true;
            };
        };
    };
    return false;
}


	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ){
    int count = elementCount;
    if(elementCount == 0){
        //check to see if list is empty
        cout << "There are no patients in the system." << endl;
        return false;
    };
    for(int i = 0; i < count; i++){
        if(elements[i] == toBeRemoved && elements[i].getCareCard() != "0000000000"){
            //cycle through the list and find the element to be removed.
            //decrement the element count
            elementCount--;
            for (int j = i; j < elementCount; j++){
                //shifts all following elements "left" by one unit
                elements[j] = elements[j+1];
            };
            cout << "The patient has been removed." << endl;
            return true;
        };
    };
    cout << "There was an error removing the patient, please try again." << endl;
    return false;
}
	
	// Description: Remove all elements.
void List::removeAll(){
    if(elementCount == 0){
        //check to see if list is empty
        cout << "There are no patients in the system." << endl;
    };
    int count = elementCount;
    for(int i = 0; i < count; i++){
        //assign elements with default constructor, decrement element count each time
        elements[i] = Patient();
        elementCount--;
    };
}
   
	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
    Patient* elementLocation = NULL;
    if(elementCount == 0){
        //check to see if list is empty
        cout << "There are no patients in the system." << endl;
        return NULL;
    };

    for(int i = 0; i < elementCount; i++){
        //cycle through the list and see if the target patient exists
        if(elements[i] == target && elements[i].getCareCard() != "0000000000"){
            cout << "Patient found." << endl;
            //returns a pointer to the target patient
            elementLocation = &elements[i];
            cout << "The patient's information is: " << endl;
            cout << elements[i];
            return elementLocation;
        };
    };
    
    //if patient not in the list, return NULL
    cout << "Patient not found." << endl;
    return NULL;
}

// Description: prints all patient info in the system
// Precondition: list is not empty
void List::printAll(){
    if(elementCount == 0){
        cout << "There are no patients in the system to display." << endl;
    };
    for(int i = 0; i < elementCount; i++)
    {
        for(int j = i + 1; j < elementCount; j++)
        {
            //uses the overloaded operator ">" from Patient.h to compare the numerical value of patient's care card number
            if(elements[i] > elements[j])
            {
                Patient temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            };
        };
    };

    for(int i = 0; i < elementCount; i++){
        //prints out all the elements in the system with their new ordered sequence 
        cout << elements[i];
    };
}