#include "Transport.h"

void Transport::deleteARoute(int number, Type type) {
    auto tempList = _network[{type, number}];
    for(auto stop: tempList){
        _stops[stop]--;
    }
    _network.erase({type, number});
    _routes[type].erase(number);
}

void Transport::addAStop(std::string stop) {
    if(!_stops[stop])
        _stops[stop] = 0;
}

void Transport::removeAStop(std::string stop) {
    _stops.erase(stop);
    for(auto& route: _network){
        route.second.erase(stop);
        if(route.second.size()==0)
            _network.erase(route.first);
    }
}

std::pair<std::multimap<Type, int>::iterator,std::multimap<Type, int>::iterator>Transport::routesThatGoThroughThisStop
        (std::string stop) {
    std::multimap<Type, int> result;
    for(auto route: _network){
        if(route.second.count(stop))
            result.insert({route.first});
    }
    _routesThatGoThroughAStop.push_back(result);
    return std::make_pair(_routesThatGoThroughAStop.rbegin()->begin(),
                          _routesThatGoThroughAStop.rbegin()->end());
}

std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> Transport::numbersWithGivenTypeFromXToY(Type
type,int x, int y) {
    return std::make_pair(std::lower_bound(_routes[type].begin(), _routes[type].end(), x),
                          std::upper_bound(_routes[type].begin(), _routes[type].end(),y));
}

std::pair<std::list<std::string>::iterator, std::list<std::string>::iterator> Transport::unusedStops() {
    std::list<std::string> result;
    for(auto stop:_stops){
        if(stop.second == 0)
            result.push_back(stop.first);
    }
    _unusedStops.push_back(result);
    return std::make_pair(_unusedStops.rbegin()->begin(), _unusedStops.rbegin()->end());
}

std::string Transport::theMostUsedStop() {
    std::pair<std::string, int> theMostUsed = *_stops.begin();
    for(auto stop: _stops){
        if(stop.second > theMostUsed.second)
            theMostUsed = stop;
    }
    return theMostUsed.first;
}

