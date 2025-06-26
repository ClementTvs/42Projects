#pragma once
#include <iostream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact();
		~Contact();
		void	setFirstName(const std::string& firstName_);
		void	setLastName(const std::string& lastName_);
		void	setNickName(const std::string& nickName_);
		void	setPhoneNumber(const std::string& phoneNumber_);
		void	setDarkestSecret(const std::string& darkestSecret_);
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getNickName() const;
		const std::string& getPhoneNumber() const;
		const std::string& getDarkestSecret() const;
};