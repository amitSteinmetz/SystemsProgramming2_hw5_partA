#include "MagicalContainer.hpp"
#include <iostream>
#include <algorithm>

/* Ctors */

MagicalContainer::MagicalContainer() // No need to init the vector, it is initialized automatcily to default value
{}

MagicalContainer::AscendingIterator::AscendingIterator()
{}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) 
: pContainer(&container), pRunner(container.vec.data())
{
   std::sort(container.vec.begin(), container.vec.end());
}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
: pContainer(other.pContainer), pRunner(other.pRunner)
{}

MagicalContainer::SideCrossIterator::SideCrossIterator()
{}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) 
: pContainer(&container), pRunner(container.vec.data())
{
   std::sort(container.vec.begin(), container.vec.end());
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
: pContainer(other.pContainer), pRunner(other.pRunner)
{}

MagicalContainer::PrimeIterator::PrimeIterator()
{}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) 
: pContainer(&container), pRunner(container.vec.data())
{
   std::sort(container.vec.begin(), container.vec.end());
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
: pContainer(other.pContainer), pRunner(other.pRunner)
{}

/* Methods */

// MagicalContainer class

void MagicalContainer::addElement(const int element)
{
    vec.emplace_back(element);
}

void MagicalContainer::removeElement(int element)
{
    // If container is empty
    if (vec.size() == 0) throw "Container is empty!";

    // Find the position of the element (assuming element occurs only once in the vector)
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (*it == element) vec.erase(it);
    }
}

int MagicalContainer::size()
{
    return vec.size();
}

/* AscendingIterator inner class */ 

// Access
int& MagicalContainer::AscendingIterator::operator*() const
{
    return *pRunner;
}

// prefix
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
{

    if (pRunner == (&pContainer->vec[0] + pContainer->size() - 1)) pRunner = nullptr;
    else ++pRunner;
    
    return *this;
}

// postfix
const MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int)
{
    return *this;
}

// Comparison
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
{
    return (pRunner == other.pRunner);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
{
    return true;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
{
    return true;
}

// Assignment 
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
{
    pContainer = other.pContainer;
    pRunner = other.pRunner;

    return *this;
}

// Begin, end
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
{
    AscendingIterator it;

    it.pRunner = &pContainer->vec[0];  // the main idea of this function
    it.pContainer = pContainer;

    return it;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    AscendingIterator it;

    //it.pRunner = &rContainer.vec[0] + rContainer.size();  // the main idea of this function
    it.pRunner = nullptr;
    it.pContainer = pContainer;

    return it;
}

/* SideCrossIterator inner class */ 

// Access
int& MagicalContainer::SideCrossIterator::operator*() const
{
    return *pRunner;
}

// prefix
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++()
{

    if (pRunner == (&pContainer->vec[0] + pContainer->size() - 1)) pRunner = nullptr;
    else ++pRunner;
    
    return *this;
}

// postfix
const MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int)
{
    return *this;
}

// Comparison
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
{
    return (pRunner == other.pRunner);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
{
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
{
    return true;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
{
    return true;
}

// Assignment 
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
{
    pContainer = other.pContainer;
    pRunner = other.pRunner;

    return *this;
}

// Begin, end
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
{
    SideCrossIterator it;

    it.pRunner = &pContainer->vec[0];  // the main idea of this function
    it.pContainer = pContainer;

    return it;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    SideCrossIterator it;

    //it.pRunner = &rContainer.vec[0] + rContainer.size();  // the main idea of this function
    it.pRunner = nullptr;
    it.pContainer = pContainer;

    return it;
}

/* PrimeIterator inner class */ 

// Access
int& MagicalContainer::PrimeIterator::operator*() const
{
    return *pRunner;
}

// prefix
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++()
{

    if (pRunner == (&pContainer->vec[0] + pContainer->size() - 1)) pRunner = nullptr;
    else ++pRunner;
    
    return *this;
}

// postfix
const MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int)
{
    return *this;
}

// Comparison
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const
{
    return (pRunner == other.pRunner);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const
{
    return true;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const
{
    return true;
}

// Assignment 
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
{
    pContainer = other.pContainer;
    pRunner = other.pRunner;

    return *this;
}

// Begin, end
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
{
    PrimeIterator it;

    it.pRunner = &pContainer->vec[0];  // the main idea of this function
    it.pContainer = pContainer;

    return it;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    PrimeIterator it;

    //it.pRunner = &rContainer.vec[0] + rContainer.size();  // the main idea of this function
    it.pRunner = nullptr;
    it.pContainer = pContainer;

    return it;
}







