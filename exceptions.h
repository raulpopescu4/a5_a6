#pragma once
#include <exception>

class ValueError : public std::exception {
public:
	explicit ValueError(const char* message);

	const char* what() const noexcept override;

private:
	const char* error_message;
};

class RepositoryError : public std::exception {
public:
	explicit RepositoryError(const char* message);

	const char* what() const noexcept override;

private:
	const char* error_message;
};


