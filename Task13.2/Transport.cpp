#include <iostream>
#include <string>
#include "Transport.h"
#include <vector>

Stop::Stop(std::string name) : _name(name) {};

Stop::Stop(std::string name, int counter) : _name(name), _counterOfUse(counter) {}

Transport::Transport() {}

bool operator==(const Stop &first, const Stop &second) {
    return first._name == second._name;
}

bool operator!=(const Stop &first, const Stop &second) {
    return first._name != second._name;
}

std::set<Stop>::iterator
Transport::findStop(std::set<Stop>::iterator begin, std::set<Stop>::iterator end, const Stop &stop) {
    while (begin != end) {
        if (begin->_name == stop._name)
            return begin;
        begin++;
    }
    return end;
}

void Transport::deleteRoute(int numberOfRoute, std::string type)  //!!!!!!!
{
    auto route = _listOfRoutsWithStops.find(std::make_pair(numberOfRoute, type)); //total O(2*n)
    if (route != _listOfRoutsWithStops.end()) {
        for (auto stop1 : _listOfStops) {
            for (auto stop2 : route->second) {
                if (stop1 == stop2) {
                    stop1._counterOfUse--;
                    stop2._counterOfUse--;
                }
            }
        }
        _listOfRoutsWithStops.erase(route);
    }
}


void Transport::addStop(std::string stop) {  //total O(n*(log(n)+log(m)))
    //findStop(_listOfStops.begin(), _listOfStops.end(), Stop::Stop(stop))
    if (_listOfStops.find(Stop(stop)) != _listOfStops.end()) {
        _listOfStops.insert(Stop(stop, 0));
    }
}

void Transport::deleteStop(std::string stop) {
    auto iter = _listOfStops.find(Stop(stop));
    if (iter == _listOfStops.end()) //O(k)
        return;
    _listOfStops.erase(iter);  //O(k)
    auto it = _listOfRoutsWithStops.begin();
    while (it != _listOfRoutsWithStops.end())  //O(n)
    {  //O(l)
        it->second.erase(Stop(stop)); //O(l)
        if (it->second.empty()) {
            deleteRoute(it->first.first, it->first.second);  //O(2*n)
        }
        it++;
    }                                                //total O(2*k+m+n*(l^(2)+2*n))
}


int Transport::countNumberOfRouts() {
    return _listOfRoutsWithStops.size();  //total O(1)
}


int Transport::countNumberOfStops() {
    return _listOfStops.size();  //total O(1)
}


std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator>
Transport::listOfRoutNumbersPassingThroughTheStop(std::string stop) {
    _tempCollection.clear();
    for (auto route : _listOfRoutsWithStops)  //O(n)
    {
        if (route.second.find(Stop(stop)) != route.second.end())  //O(m)
        {
            _tempCollection.insert(route.first);  //O(log(k))
        }
    }                                                        //total O(n*(m+log(k)))
    return std::make_pair(_tempCollection.begin(), _tempCollection.end());
}


std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator>
Transport::listOfRoutNumbersWhichAreBetweenTheGivenNumbers(std::string type, int X, int Y) {
    _tempCollection.clear();
    for (auto route : _listOfRoutsWithStops)  //O(n)
    {
        if (route.first.second == type && route.first.first >= X && route.first.first <= Y) {
            _tempCollection.insert(route.first); //O(log(k))
        }
    }                                            //total O(n*log(k))
    return std::make_pair(_tempCollection.begin(), _tempCollection.end());
}


std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator> Transport::listOfUnusableStops() {
    _unusableStops.clear();
    for (auto stop : _listOfStops) {
        if (stop._counterOfUse == 0)
            _unusableStops.insert(stop._name);
    }
    return std::make_pair(_unusableStops.begin(), _unusableStops.end());  //total O(1)
}


std::string Transport::mostUsableStop() {
    std::pair<std::string, int> max;
    max.second = 0;
    for (auto stop : _listOfStops) {
        if (stop._counterOfUse >= max.second) {
            max.second = stop._counterOfUse;
            max.first = stop._name;
        }
    }
    return max.first;                                                    // total O(n*m+k^(2))
}