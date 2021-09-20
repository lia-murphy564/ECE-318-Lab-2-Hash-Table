Write a program in C++ that reads all the entries from the named-places data file
/home/www/class/een318/named-places.txt. (You will find the format described here:
http://rabbit.eng.miami.edu/class/een318/a318a.txt).

You program should create an object for each named place, containing:
    numeric code (int)
    state abbreviation (string)
    name, with spaces trimmed from the end (string)
    population (int)
    area (float or double)
    latitude (float or double)
    longitude (float or double)
    code for representative road intersection (int)
    distance to that intersection (float or double)

These objects should be stored in a hash table, indexed by their name
    and state jointly.

After reading the data, the program should enter an interactive loop:

    if the user enters 
       S placename state
    the computer provides all information known for the indicated place.

    if the user enters 
       N placename
    the computer provides all information known for all places with the 
    given name in any state.

    if the user enters
       Q
    the program stops

Use C++ i/o and string methods, not the C libraries.
