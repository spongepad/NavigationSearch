#include <iostream>
#include "searchresult.h"


SearchResult::SearchResult()
    : id(0), name(""), address(""), distance(0.0), favorite(false){}

SearchResult::SearchResult(int id, std::string name, std::string address, double distance, bool favorite)
    : id(id), name(name), address(address), distance(distance), favorite(favorite) {}

void SearchResult::toggleFavorite() {
    favorite = !favorite;
}

void SearchResult::printSearchResult() const {
    std::cout<<"id: " << id << " name: " << name << " address: " << address
              << " distance: " << distance << " favorite: " << favorite << "\n";
}