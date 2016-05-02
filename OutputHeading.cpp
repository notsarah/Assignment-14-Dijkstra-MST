/*************************************************************************
 * AUTHOR          : Connor Peace & Sarah Singletary
 * ASSIGNMENT #14  : Dijkstra & MST
 * CLASS           : CS1C
 * SECTION         : MW: 4:30 - 7:50 PM
 * DUE DATE        : 4/25/16
 *************************************************************************/

#include "Header.h"

string OutputHeading() {

    ostringstream output;

    output << "+-------------------------------------------+\n"
    << "|                                           |\n"
    << "|   ASSIGNMENT #14                          |\n"
    << "|               Dijkstra & MST              |\n"
    << "|                                           |\n"
    << "|                  by:                      |\n"
    << "|            Sarah Singletary               |\n"
    << "|                                           |\n"
    << "+-------------------------------------------+\n\n";

    output << "DESCRIPTION:\n"
    << "---------------------------------------------------\n"
    << "This program implements a graph that performs a    \n"
    << " Dijkstra's algorithm that finds the shortest      \n"
    << " distance from at Atlanta to the cities on the map.\n"
    << " The program also determines the minimum spanning  \n"
    << " tree. It identifies the edges and total mileage.  \n" ;

    return output.str();
}