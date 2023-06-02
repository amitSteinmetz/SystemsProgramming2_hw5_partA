#include "doctest.h"
#include "sources/MagicalContainer.hpp"

TEST_CASE("Container methods")
{
    MagicalContainer container;

    SUBCASE("Adding elements")
    {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);

        CHECK(container.size() == 4);
    }

    SUBCASE("Subtracting elements")
    {
        container.removeElement(2);
        container.removeElement(3);
        CHECK(container.size() == 2);

        CHECK_NOTHROW(container.removeElement(3)); // Trying to remove an un-exist element has no effect

        container.removeElement(1);
        container.removeElement(4);
        CHECK(container.size() == 0);

        CHECK_THROWS(container.removeElement(4)); // Trying remove an element from an empty container
    }
}

TEST_CASE("Ascending Iterator methods")
{
    MagicalContainer container;
    container.addElement(33);
    container.addElement(22);
    container.addElement(11);
    container.addElement(44);
    
    MagicalContainer::AscendingIterator ascIter(container);

    SUBCASE("Access operator")
    {
        CHECK(*ascIter == 11);    
    }   

    SUBCASE("prefix and postfix operators")
    {
        CHECK(*ascIter == 11);
        ++ascIter;
        CHECK(*ascIter == 22);
        CHECK(*ascIter++ == 22);
        CHECK(*ascIter == 33);
    }

    SUBCASE("Assignment operator")
    {
        auto it = ascIter;

        CHECK(*it == *ascIter);
    }

    SUBCASE("Comparison operators")
    {
        auto it = ascIter;

        CHECK(it == ascIter);
        CHECK(!(it != ascIter));
        CHECK(it != ascIter.begin());
    }

    SUBCASE("begin, end functions")
    {
        MagicalContainer::AscendingIterator ascIter2(container);

        CHECK(ascIter2 == ascIter.begin());
        CHECK(ascIter2 != ascIter.end());

        ++ascIter2;
        ++ascIter2;
        ++ascIter2;

        CHECK(ascIter2 == ascIter.end());
    }
}

TEST_CASE("SideCross Iterator methods")
{
    MagicalContainer container;
    container.addElement(11);
    container.addElement(22);
    container.addElement(33);
    container.addElement(44);

    MagicalContainer::SideCrossIterator crossIter(container);
    
    SUBCASE("Access operator")
    {
        CHECK(*crossIter == 11);    
    }   

    SUBCASE("prefix and postfix operators")
    {
        CHECK(*crossIter == 11);
        ++crossIter;
        CHECK(*crossIter == 44);
        CHECK(*crossIter++ == 44);
        CHECK(*crossIter == 22);
    }

    SUBCASE("Assignment operator")
    {
        auto it = crossIter;

        CHECK(*it == *crossIter);
    }

    SUBCASE("Comparison operators")
    {
        auto it = crossIter;

        CHECK(it == crossIter);
        CHECK(!(it != crossIter));
        CHECK(it != crossIter.begin());
    }

    SUBCASE("begin, end functions")
    {
        MagicalContainer::SideCrossIterator crossIter2(container);

        CHECK(crossIter2 == crossIter.begin());
        CHECK(crossIter2 != crossIter.end());

        ++crossIter2;
        ++crossIter2;
        ++crossIter2;

        CHECK(crossIter2 == crossIter.end());
    }
}

TEST_CASE("Prime Iterator methods")
{
    MagicalContainer container;
    container.addElement(3);
    container.addElement(5);
    container.addElement(8);
    container.addElement(11);

    MagicalContainer::PrimeIterator primeIter(container);
    
    SUBCASE("Access operator")
    {
        CHECK(*primeIter == 3);    
    }   

    SUBCASE("prefix and postfix operators")
    {
        CHECK(*primeIter == 3);
        ++primeIter;
        CHECK(*primeIter == 5);
        CHECK(*primeIter++ == 5);
        CHECK(*primeIter == 11);
    }

    SUBCASE("Assignment operator")
    {
        auto it = primeIter;

        CHECK(*it == *primeIter);
    }

    SUBCASE("Comparison operators")
    {
        auto it = primeIter;

        CHECK(it == primeIter);
        CHECK(!(it != primeIter));
        CHECK(it != primeIter.begin());
    }

    SUBCASE("begin, end functions")
    {
        MagicalContainer::PrimeIterator primeIter2(container);

        CHECK(primeIter2 == primeIter.begin());
        CHECK(primeIter2 != primeIter.end());

        ++primeIter2;
        ++primeIter2;
        ++primeIter2;

        CHECK(primeIter2 == primeIter.end());
    }
}