#include <iostream>
#include "Transport.h"

int main() {
    Transport transport;
    std::set<std::string> firstListOfStops;
    std::set<std::string> secondListOfStops;

    firstListOfStops.insert("Lenin's square");
    firstListOfStops.insert("Pobeda square");
    firstListOfStops.insert("Yakub Kolas square");
    firstListOfStops.insert("h");

    secondListOfStops.insert("y");
    secondListOfStops.insert("g");
    secondListOfStops.insert("i");
    secondListOfStops.insert("Pobeda square");

    auto pair1 = std::make_pair(firstListOfStops.begin(), firstListOfStops.end());
    auto pair2 = std::make_pair(secondListOfStops.begin(), secondListOfStops.end());

    transport.addRoute(1, "bus", pair1);
    transport.addRoute(47, "tram", pair2);
    std::cout << transport.mostUsableStop() << std::endl;
    /*auto p = transport.listOfRoutNumbersPassingThroughTheStop("Pobeda square");

    while (p.first != p.second)
    {
        std::cout << "Route: " << p.first->first << " Type: " << p.first->second << std::endl;
        p.first++;
    }*/
    return 0;
}
