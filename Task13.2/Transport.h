//
// Created by a3057 on 3/2/2021.
//

#ifndef TASK13_2_TRANSPORT_H
#define TASK13_2_TRANSPORT_H
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <cassert>

class Stop
{
private:
    std::string _name;
    int _counterOfUse = 0;
    Stop(std::string);
    Stop(std::string, int);
    friend bool operator==(const Stop&, const Stop&);
    friend bool operator!=(const Stop&,const Stop&);

    friend class Transport;
};

class Transport
{
private:
    std::map<std::pair<int, std::string>, std::set<Stop>> _listOfRoutsWithStops;
    std::set<Stop> _listOfStops;
    std::map<int, std::string> _tempCollection;
    std::set<std::string> _unusableStops;
    std::set<Stop>::iterator findStop(std::set<Stop>::iterator, std::set<Stop>::iterator, const Stop&);
public:
    Transport();

    template <typename ITER>
    void addRoute(int numberOfRoute, std::string type, std::pair<ITER, ITER> pairOfIterators)
    {
        assert(numberOfRoute >= 0);
        auto begin = pairOfIterators.first;
        auto end = pairOfIterators.second;
        assert(!(begin == end));
        auto temppair = std::make_pair(numberOfRoute, type);
        while (begin != end)
        {
            _listOfRoutsWithStops[temppair].insert(Stop(*begin));  //total O(n+m*(log(l)+log(k)))
            _listOfStops.insert(Stop(*begin));
            begin++;
        }
        begin = pairOfIterators.first;
        for (auto stop: _listOfStops)
        {
            if (stop._name == (*begin))
                stop._counterOfUse++;
        }
    }

    void deleteRoute(int, std::string);
    void addStop(std::string);
    void deleteStop(std::string);
    int countNumberOfRouts();
    int countNumberOfStops();
    std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator>
    listOfRoutNumbersPassingThroughTheStop(std::string);
    std::pair<std::map<int, std::string>::iterator, std::map <int, std::string>::iterator>
    listOfRoutNumbersWhichAreBetweenTheGivenNumbers(std::string, int, int);
    std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator> listOfUnusableStops();
    std::string mostUsableStop();
    //void enterStopsAndRouts();
};
#endif //TASK13_2_TRANSPORT_H
