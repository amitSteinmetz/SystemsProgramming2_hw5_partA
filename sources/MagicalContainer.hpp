#pragma once
namespace ariel{};
#include <vector>


// Container should be vector/stack and things like that? or an invantion of mine?
class MagicalContainer
{
    // Attributes
    std::vector<int> vec;

    public:

    // Ctor
    MagicalContainer();
    
    // Methods
    void addElement(const int element);
    void removeElement(int element);
    int size();

    /* Inner classes: */ 

    class AscendingIterator
    {
        // Attributes
        MagicalContainer* pContainer;
        int* pRunner;
        
        public: 

        /* Ctors */
        AscendingIterator(); // default
        AscendingIterator(MagicalContainer& container); // parameterized
        AscendingIterator(const AscendingIterator& other); // copy
        
        /* Methods */

        int& operator*() const; // Access
		AscendingIterator& operator++(); // prefix
		const AscendingIterator operator++(int); // postfix
        AscendingIterator& operator=(const AscendingIterator& other); // Assignment         
        AscendingIterator begin() const; // Begin
        AscendingIterator end(); // End

        // Comparison
		bool operator==(const AscendingIterator& other) const;
		bool operator!=(const AscendingIterator& other) const;
        bool operator<(const AscendingIterator& other) const;
        bool operator>(const AscendingIterator& other) const;
    };

    class SideCrossIterator
    {
        // Attributes
        MagicalContainer* pContainer;
        int* pRunner;
        
        public: 

        /* Ctors */
        SideCrossIterator(); // default
        SideCrossIterator(MagicalContainer& container); // parameterized
        SideCrossIterator(const SideCrossIterator& other); // copy
        
        /* Methods */

        int& operator*() const; // Access
		SideCrossIterator& operator++(); // prefix
		const SideCrossIterator operator++(int); // postfix
        SideCrossIterator& operator=(const SideCrossIterator& other); // Assignment         
        SideCrossIterator begin() const; // Begin
        SideCrossIterator end(); // End

        // Comparison
		bool operator==(const SideCrossIterator& other) const;
		bool operator!=(const SideCrossIterator& other) const;
        bool operator<(const SideCrossIterator& other) const;
        bool operator>(const SideCrossIterator& other) const;
    };

    class PrimeIterator
    {
        // Attributes
        MagicalContainer* pContainer;
        int* pRunner;
        
        public: 

        /* Ctors */
        PrimeIterator(); // default
        PrimeIterator(MagicalContainer& container); // parameterized
        PrimeIterator(const PrimeIterator& other); // copy
        
        /* Methods */

        int& operator*() const; // Access
		PrimeIterator& operator++(); // prefix
		const PrimeIterator operator++(int); // postfix
        PrimeIterator& operator=(const PrimeIterator& other); // Assignment         
        PrimeIterator begin() const; // Begin
        PrimeIterator end(); // End

        // Comparison
		bool operator==(const PrimeIterator& other) const;
		bool operator!=(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        bool operator>(const PrimeIterator& other) const;
    };

};
