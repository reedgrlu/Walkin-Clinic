/*
 * walkIn.cpp
 * 
 * Class Description: Main program for storing patient's files at a walk in clinic.
 * 
 *
 * Author: Reed Lu
 * Date: January 22, 2019
 */

#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;


//Declares function "user_operation" that contains the program for the walk-in clinic
void user_operation(List& patientList);
//modifies the patient's file
bool modifyFile(List& patientList, Patient* patientLocation);

int main(){
    //main program
    List newlist;    //create the list that holds all patient files
    user_operation(newlist);    //calls the user_operation function using the newList as input
    return 0;
};


void user_operation(List& patientList){
        //Below is the main menu for the user to operate with
        cout << endl << "Please select from the following operations: " << endl;
        cout << "To enter a new patient into the system, please input 'A'"  << endl;
        cout << "To search for an existing patient, please input 'B'" << endl;
        cout << "To print all patient files by ascending order of care card numbers, please input 'C' " << endl;
        cout << "To delete all patient files, please input 'D'" << endl;

        string input;
        getline(cin, input);

        //The user selects their option
        if(input == "A" || input == "a"){       //enter a new patient into the system
        cout << "Please enter the patient's Care Card number: ";
        string card;
        getline(cin, card);
    
        //creates object newPatient and assigns it with the given care card number
        Patient newPatient(card);

        cout << "Please enter the patient's name: ";
        string name;
        getline(cin, name);
        newPatient.setName(name);

        cout << "Please enter the patient's address: ";
        string address;
        getline(cin, address);
        newPatient.setAddress(address);

        cout << "Please enter the patient's phone number: ";
        string phone;
        getline(cin, phone);
        newPatient.setPhone(phone);

        cout << "Please enter the patient's email address: ";
        string email;
        getline(cin, email);
        newPatient.setEmail(email);

        //After all the new patient's information is recorded, the patient's file is inserted into the list of patients by calling the insert function from List.h
        patientList.insert(newPatient);

        //the program calls a recursion to the user_operation function (main menu)
        user_operation(patientList);

        }else if(input == "B" || input == "b"){     //search for an existing patient
            
            if(patientList.getElementCount() == 0){
                //If there are not patients in the list, the program returns to main menu
                cout << "There are no patients in the system." << endl;
                user_operation(patientList);
            };
        
            //The user is prompted to enter the patient's care card number to search for the paitient
            cout << "Please enter the patient's Care Card number: ";
            string card;
            getline(cin, card);
            Patient targetPatient(card);
            Patient* patientLocation = NULL;
            //If the patient is found, the search function from List.h will return a pointer to the target patient.
            patientLocation = patientList.search(targetPatient);

            if(patientLocation == NULL){
                user_operation(patientList);
            };

            select:

            cout << endl << "Please select the operation you would like to make to this file: "<< endl;
            cout << "To modify this patient's file, please select 'A'" << endl;
            cout << "To remove this patient's file, please select 'B'" << endl;
            cout << "To return to the main menu, please select 'C'" << endl;

            string option;
            getline(cin, option);

            if(option == "A" || option == "a"){
                //modifies the patient's file and return to beginning of section to further operate on the current patient's file
                if(modifyFile(patientList, patientLocation)){
                    goto select;
                };
            }else if(option == "B" || option == "b"){
                //removes patient
                patientList.remove(*patientLocation);
                user_operation(patientList);
            }else if(option == "C" || option == "c"){
                //go back to main menu
                user_operation(patientList);
            }else{
                //returns to select desired operation on the current patient file
                cout << "The input does not correspond with a valid operation!" << endl;
                goto select;
            };
            
        }else if(input == "C" || input == "c"){
            //print all its patients by ascending order of care card numbers.
            patientList.printAll();
            user_operation(patientList);
        }else if(input == "D" || input == "d"){
            //deletes everything and return to main menu
            patientList.removeAll();
            user_operation(patientList);
        }else{
            //invalid input, return to main menu
            cout << "The input does not correspond with a valid operation!" << endl;
            user_operation(patientList);
        };
}

bool modifyFile(List& patientList, Patient* patientLocation){
            //Beginning of the section of the program to modify the patient's record
            beginning:

            //Outputs the options for the user to select
            cout << endl << "Please select from the following operations: " << endl;
            cout << "To modify the patient's name, please input 'A'" << endl;
            cout << "To modify the patient's address, please input 'B'" << endl;
            cout << "To modify the patient's email address, please input 'C'" << endl;
            cout << "To modify the patient's phone number, please input 'D'" << endl;
            cout << "To go back to the previous menu, please input 'E'" << endl;

        
            string selection;
            getline(cin, selection);
    
            
            if(selection == "A" || selection == "a"){
                cout << "Please enter the patient's new name: ";
                string newName;
                getline(cin, newName);
                patientLocation->setName(newName);
                
                //Modifies the paitient's name
                cout << endl << "The patient's new information is: " << endl;
                cout << *patientLocation;

            }else if(selection == "B" || selection == "b"){
                cout << "Please enter the patient's new address: ";
                string newAddress;
                getline(cin, newAddress);
                patientLocation->setAddress(newAddress);

                //Modifies the patient's address
                cout << endl << "The patient's new information is: " << endl;
                cout << *patientLocation;

            }else if(selection == "C" || selection == "c"){
                cout << "Please enter the patient's new email address: ";
                string newEmail;
                getline(cin, newEmail);
                patientLocation->setEmail(newEmail);

                //Modifies the patient's email
                cout << endl << "The patient's new information is: " << endl;
                cout << *patientLocation;

            }else if(selection == "D" || selection == "d"){
                cout << "Please enter the patient's phone number: ";
                string newPhone;
                getline(cin, newPhone);
                patientLocation->setPhone(newPhone);

                //Modifies the patient's phone number
                cout << endl << "The patient's new information is: " << endl;
                cout << *patientLocation;

            }else if(selection == "E" || selection == "e"){
                //The user can return to the previous menu to select other operations
                return true;

            }else{
                //If the input selection is no valid, the program returns to beginning of section to modify patient's file
                cout << "The input does not correspond with a valid operation!" << endl;
                goto beginning;
            };

            goto beginning;

            return false;
            //The program returns to beginning of section to modify patient's file,
            //in case the user wants to modify more than one section
    
}
