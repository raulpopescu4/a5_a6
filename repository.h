#include "dynamic_array.h"
#include "tutorial.h"
#pragma once

class Repository {
private:
	DynamicVector<Tutorial> tutorial_repository;

public:
	Repository();

	~Repository() = default;

	DynamicVector<Tutorial> get_all_tutorials();

	int get_length() const;

	void add_tutorial(Tutorial&);
	
	void remove_tutorial(const std::string&);

	void update_tutorial(const std::string&,const std::string&,const std::string&,const int&,const std::string&);

	Tutorial find_tutorial(const std::string&);

	bool has_tutorial(const std::string&);


};