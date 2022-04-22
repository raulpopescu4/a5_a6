#pragma once
#include <string>
#include <Windows.h>

class Tutorial {
private:
	std::string title;
	std::string presenter;
	std::string duration;
	int likes;
	std::string link;

public:
	Tutorial();

	Tutorial(std::string, std::string, std::string, int, std::string);

	Tutorial(const Tutorial& copy);

	std::string get_title() const;
	std::string get_presenter() const;
	std::string get_duration() const;
	int get_likes() const;
	std::string get_link() const;

	void set_title(std::string new_title);
	void set_presenter(std::string new_presenter);
	void set_duration(std::string new_duration);
	void set_likes(int new_likes);
	void set_link(std::string new_link);

	bool operator==(const Tutorial& other) const;

	Tutorial& operator=(const Tutorial& new_tutorial);

	void open() const;



};