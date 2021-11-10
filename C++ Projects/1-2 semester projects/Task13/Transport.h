#ifndef TASK13_TRANSPORT_H
#define TASK13_TRANSPORT_H

#include <list>
#include <string>
#include <set>
#include <map>
#include <algorithm>

enum Type {
    BUS,
    TROLLEYBUS,
    TRAM
};

class Transport {
    std::list<std::multimap<Type, int>> _routesThatGoThroughAStop={};
    std::list<std::list<std::string>> _unusedStops;
    std::map<Type, std::set<int>> _routes;
    std::map<std::pair<Type, int>, std::set<std::string>> _network;
    std::map<std::string, int> _stops;
public:
    template<typename T>
    void addARoute(int number, Type type, T one, T two) {
        std::set<std::string> newRoute;
        newRoute.insert(one, two);
        _network.try_emplace({type, number}, newRoute);
        _routes[type].insert(number);
        for(auto it = one; it!=two; it++) {
            _stops[*it]++;
        }
    }

    void deleteARoute(int, Type);

    void addAStop(std::string stop);

    void removeAStop(std::string);

    int stopQuantity() { return _stops.size(); }

    int routeQuantity() { return _network.size(); }

    std::pair<std::multimap<Type, int>::iterator, std::multimap<Type, int>::iterator>
    routesThatGoThroughThisStop(std::string stop);

    std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> numbersWithGivenTypeFromXToY(Type, int,
                                                                                                         int);

    std::pair<std::list<std::string>::iterator, std::list<std::string>::iterator> unusedStops();

    std::string theMostUsedStop();
};

#endif //TASK13_TRANSPORT_H
