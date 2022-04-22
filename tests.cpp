#include "tests.h"
#include "tutorial.h"
#include <cassert>
#include <iostream>
#include "repository.h"
#include "exceptions.h"

void test_getters_and_setters() {
	Tutorial test_tutorial("title", "presenter", "05:42", 14, "link");
	assert(test_tutorial.get_title() == "title");
	assert(test_tutorial.get_presenter() == "presenter");
	assert(test_tutorial.get_duration() == "05:42");
	assert(test_tutorial.get_likes() == 14);
	assert(test_tutorial.get_link() == "link");

	test_tutorial.set_title("other title");
	test_tutorial.set_presenter("other presenter");
	test_tutorial.set_duration("06:42");
	test_tutorial.set_likes(15);
	test_tutorial.set_link("other link");

	assert(test_tutorial.get_title() == "other title");
	assert(test_tutorial.get_presenter() == "other presenter");
	assert(test_tutorial.get_duration() == "06:42");
	assert(test_tutorial.get_likes() == 15);
	assert(test_tutorial.get_link() == "other link");
}

void test_add_repository() {
	Repository test_repo{};
	Tutorial test_tutorial("title", "presenter", "04:20", 24, "link");
	
	assert(test_repo.get_length() == 0);
	
	test_repo.add_tutorial(test_tutorial);

	assert(test_repo.get_length() == 1);

	try {
		test_repo.add_tutorial(test_tutorial);
		assert(false);
	}
	catch (RepositoryError&) {
		assert(true);
	}


}

void test_remove_repository() {
	Repository test_repo{};
	Tutorial test_tutorial("title", "presenter", "04:20", 24, "link");

	test_repo.add_tutorial(test_tutorial);
	assert(test_repo.get_length() == 1);

	test_repo.remove_tutorial(test_tutorial.get_title());
	assert(test_repo.get_length() == 0);

	try {
		test_repo.remove_tutorial(test_tutorial.get_title());
		assert(false);
	}
	catch (RepositoryError&) {
		assert(true);
	}
}

void test_update_repository() {
	Repository test_repo{};
	Tutorial test_tutorial("title", "presenter", "04:20", 24, "link");
	Tutorial test_tutorial_updated("title", "presenter_", "05:20", 27, "link_");

	test_repo.add_tutorial(test_tutorial);
	assert(test_repo.get_length() == 1);

	test_repo.update_tutorial("title", "presenter_", "05:20", 27, "link_");

	auto test_repo_elements = test_repo.get_all_tutorials();
	assert(test_tutorial_updated == test_repo_elements[0]);

	try {
		test_repo.update_tutorial("nonexistent title", "presenter_", "05:20", 27, "link_");
		assert(false);
	}
	catch (RepositoryError&) {
		assert(true);
	}
}


void test_repository() {
	test_add_repository();
	test_remove_repository();
	test_update_repository();
}


void test_all() {
	test_getters_and_setters();
	test_repository();
	std::cout << "Tests ran successfully!";
}