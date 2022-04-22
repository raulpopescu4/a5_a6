#pragma once
#include "Tutorial.h"

template <typename TypeOfElement>
class DynamicVector
{
private:
	void resize(double factor = 2);

public:
	DynamicVector(int capacity = 10);

	DynamicVector(const DynamicVector& copy);

	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& other);

	TypeOfElement& operator[](int index);

	void add(TypeOfElement& element);

	void remove(const TypeOfElement& element);

	int get_length() const;

private:
	TypeOfElement* elements;
	int length;
	int capacity;
};

template <typename TypeOfElement>
DynamicVector<TypeOfElement>::DynamicVector(int capacity)
{
	this->length = 0;
	this->capacity = 10;
	this->elements = new TypeOfElement[capacity];
}

template <typename TypeOfElement>
DynamicVector<TypeOfElement>::DynamicVector(const DynamicVector& copy)
{
	this->length = copy.length;
	this->capacity = copy.capacity;
	this->elements = new TypeOfElement[this->capacity];
	for (int index = 0; index < this->length; index++)
		this->elements[index] = copy.elements[index];
}

template <typename TypeOfElement>
DynamicVector<TypeOfElement>::~DynamicVector()
{
	delete[] this->elements;
}

template <typename TypeOfElement>
DynamicVector<TypeOfElement>& DynamicVector<TypeOfElement>::operator=(const DynamicVector& other)
{
	if (this == &other)
		return *this;

	this->length = other.length;
	this->capacity = other.capacity;

	delete[] this->elements;
	this->elements = new TypeOfElement[this->capacity];
	for (int index = 0; index < this->length; index++)
		this->elements[index] = other.elements[index];

	return *this;
}

template <typename TypeOfElement>
TypeOfElement& DynamicVector<TypeOfElement>::operator[](int index)
{
	return this->elements[index];
}

template <typename TypeOfElement>
void DynamicVector<TypeOfElement>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TypeOfElement* elements = new TypeOfElement[this->capacity];
	for (int index = 0; index < this->length; index++)
		elements[index] = this->elements[index];

	delete[] this->elements;
	this->elements = elements;
}

template <typename TypeOfElement>
void DynamicVector<TypeOfElement>::add(TypeOfElement& element)
{
	if (this->length == this->capacity)
		this->resize();

	this->elements[this->length] = element;
	this->length++;
}

template <typename TypeOfElement>
void DynamicVector<TypeOfElement>::remove(const TypeOfElement& element)
{
	int position = -1;
	for (int index = 0; index < this->length; index++)
		if (this->elements[index] == element) {
			position = index;
			break;
		}

	if (position == -1)
		return;

	for (int index = position; index < this->length - 1; index++)
		this->elements[index] = this->elements[index + 1];

	this->length--;
}

template <typename TypeOfElement>
int DynamicVector<TypeOfElement>::get_length() const
{
	return this->length;
}