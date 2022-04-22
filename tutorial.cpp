#include "tutorial.h"

Tutorial::Tutorial() : title(""), presenter(""), duration(""), likes(0), link("") {}

Tutorial::Tutorial(std::string _title, std::string _presenter, std::string _duration, int _likes, std::string _link) :
	title(_title), presenter(_presenter), duration(_duration), likes(_likes), link(_link) {}

Tutorial::Tutorial(const Tutorial& copy) : title(copy.title), presenter(copy.presenter), duration(copy.duration), likes(copy.likes), link(copy.link) {}

std::string Tutorial::get_title() const {
	return title;
}

std::string Tutorial::get_presenter() const {
	return presenter;
}

std::string Tutorial::get_duration() const {
	return duration;
}

int Tutorial::get_likes() const {
	return likes;
}

std::string Tutorial::get_link() const {
	return link;
}

void Tutorial::set_title(std::string new_title) {
	title = new_title;
}

void Tutorial::set_presenter(std::string new_presenter) {
	presenter = new_presenter;
}

void Tutorial::set_duration(std::string new_duration) {
	duration = new_duration;
}

void Tutorial::set_likes(int new_likes) {
	likes = new_likes;
}

void Tutorial::set_link(std::string new_link) {
	link = new_link;
}

bool Tutorial::operator==(const Tutorial& other) const {
	return title == other.title;
}

Tutorial& Tutorial::operator=(const Tutorial& new_tutorial) {
	if (this == &new_tutorial)
		return *this;

	this->title = new_tutorial.title;
	this->presenter = new_tutorial.presenter;
	this->duration = new_tutorial.duration;
	this->likes = new_tutorial.likes;
	this->link = new_tutorial.link;

	return *this;
}

void Tutorial::open() const {
	ShellExecuteA(NULL, NULL, "vivaldi.exe", this->get_link().c_str(), NULL, SW_SHOWMAXIMIZED);
}
