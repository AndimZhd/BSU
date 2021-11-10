#include <iostream>
#include "Transport.h"

int main() {
    std::list<std::string> route1 = {"A", "B", "C", "D"};
    std::list<std::string> route2 = {"A", "E", "F", "D"};
    std::list<std::string> route3 = {"A", "B", "G", "H"};
    Transport minsk;
    minsk.addARoute(47, BUS, route1.begin(), route1.end());
    minsk.addARoute(48, BUS, route2.begin(), route2.end());
    minsk.addARoute(46, TRAM, route3.begin(), route3.end());
    minsk.deleteARoute(47, BUS);
    minsk.addAStop("K");
    minsk.removeAStop("D");
    std::cout<<minsk.routeQuantity()<<" "<<minsk.stopQuantity()<<std::endl;
    auto listOfWhatGoesThrough = minsk.routesThatGoThroughThisStop("A");
    for(auto it = listOfWhatGoesThrough.first; it!= listOfWhatGoesThrough.second; it++)
        std::cout<<it->second<<" ";
    auto listOfNumbers = minsk.numbersWithGivenTypeFromXToY(BUS, 45, 49);
    for(auto it = listOfNumbers.first; it!=listOfNumbers.second; it++)
        std::cout<<std::endl<<*it<<" ";
    auto listOfUnusedStops = minsk.unusedStops();
    for(auto it = listOfUnusedStops.first; it!= listOfUnusedStops.second; it++){
        std::cout<<std::endl<<*it<<" ";
    }
    std::cout<<std::endl<<minsk.theMostUsedStop();
    return 0;
}
