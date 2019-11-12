/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Reed Lu
 * Date: January 22, 2019
 */


// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {
    careCard = "0000000000";
    PatientName = "To be entered";
    PatientAddress = "To be entered";
    PatientPhone = "To be entered";
    PatientEmail = "To be entered";

// You need to complete this method.

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
    if (aCareCard.size() == 10){
        careCard = aCareCard;
    }else{
        careCard = "0000000000";
    };

    PatientName = "To be entered";
    PatientAddress = "To be entered";
    PatientPhone = "To be entered";
    PatientEmail = "To be entered";



// You need to complete this method.

}

string Patient::getName() const{
    return PatientName;
}

	// Description: Returns patient's address.
string Patient::getAddress() const{
    return PatientAddress;
}

	// Description: Returns patient's phone.
string Patient::getPhone() const{
    return PatientPhone;
}

	// Description: Returns patient's email.
string Patient::getEmail() const{
    return PatientEmail;
}
	
	// Description: Returns patient's care card.
string Patient::getCareCard() const{
    return careCard;
}

	// Description: Sets the patient's name.
void Patient::setName(const string aName){
    PatientName = aName;
}

	// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress){
    PatientAddress = anAddress;
}

	// Description: Sets the patient's phone.
void Patient::setPhone(const string aPhone){
    PatientPhone = aPhone;
}

	// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail){
    PatientEmail = anEmail;
}



// Getters and setters -> You need to implement these methods.

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	if (this->careCard == rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	if (this->careCard > rhs.getCareCard() ) 
		return true;
	else 
		return false;
	
} // end of operator >

//friend ostream & operator<<(ostream & os, const Patient & p)
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {

    os << p.getCareCard() << " - ";
    os << "Patient: " << p.getName() << ", ";
    os << p.getAddress() << ", ";
    os << p.getPhone() << ", ";
    os << p.getEmail() << endl;
	
// You need to complete this method.   
	     
	return os;

} // end of operator<<

// end of Patient.cpp