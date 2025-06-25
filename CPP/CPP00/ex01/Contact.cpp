#include "Contact.hpp"

Contact::Contact(){}
Contact::~Contact(){}

void Contact::setFirstName(const std::string& firstName_){
	firstName = firstName_;
}

void Contact::setLastName(const std::string& lastName_){
	lastName = lastName_;
}
void	Contact::setNickName(const std::string& nickName_){
	nickName = nickName_;
}

void Contact::setPhoneNumber(const std::string& phoneNumber_){
	phoneNumber = phoneNumber_;
}

void Contact::setDarkestSecret(const std::string& darkestSecret_){
	darkestSecret = darkestSecret_;
}

std::string& Contact::getFirstName() const {
	return (firstName);
}

std::string& Contact::getLastName() const {
	return (lastName);
}

std::string& Contact::getNickName() const {
	return (nickName);
}

std::string& Contact::getPhoneNumber() const {
	return (getPhoneNumber);
}

std::string& Contact::getDarkestSecret() const {
	return (darkestSecret);
}