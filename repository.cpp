#include "repository.h"
#include "exceptions.h"

Repository::Repository() {}

DynamicVector<Tutorial> Repository::get_all_tutorials() {
	return tutorial_repository;
}

int Repository::get_length() const {
	return tutorial_repository.get_length();
}

Tutorial Repository::find_tutorial(const std::string& title) {
	if (this->has_tutorial(title)) {
		auto tutorials = this->get_all_tutorials();
		for (int i = 0; i < tutorials.get_length(); ++i) {
			auto& tutorial = tutorials[i];
			if (tutorial.get_title() == title)
				return tutorial;
		}
	}
	else
		throw RepositoryError("The tutorial doesn't exist !");
	
}

void Repository::add_tutorial(Tutorial& tutorial) {
	if (this->has_tutorial(tutorial.get_title()))
		throw RepositoryError("The tutorial you want to add already exists !");
	tutorial_repository.add(tutorial);
}

bool Repository::has_tutorial(const std::string& title) {
	auto tutorials = this->get_all_tutorials();
	for (int i = 0; i < tutorials.get_length(); ++i) {
		auto& tutorial = tutorials[i];
		if (tutorial.get_title() == title)
			return true;
	}
	return false;
}

void Repository::remove_tutorial(const std::string& title) {
	if (!(this->has_tutorial(title)))
		throw RepositoryError("The tutorial you want to remove doesn't exist !");
	tutorial_repository.remove(this->find_tutorial(title));
}

void Repository::update_tutorial(const std::string& title, const std::string& presenter, const std::string& duration, const int& likes, const std::string& link) {
	if (!(this->has_tutorial(title)))
		throw RepositoryError("The tutorial you want to update doesn't exist !");
	Tutorial tutorial = Tutorial(title, presenter, duration, likes, link);
	this->remove_tutorial(title);
	this->add_tutorial(tutorial);
}


