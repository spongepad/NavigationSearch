#include <iostream>
#include "searchresult.h"


SearchResult::SearchResult() {}

SearchResult::SearchResult(int id, std::string name, std::string address, double distance, bool favorite)
    : id(id), name(name), address(address), distance(distance), favorite(favorite) {}

void SearchResult::toggleFavorite() {
    favorite = !favorite;
}

void SearchResult::printSearchResult() const {
    std::cout<<"id: " << id << "\n";
    std::cout<<"name: " << name << "\n";
    std::cout<<"address: " << address << "\n";
    std::cout<<"distance: " << distance << "\n";
    std::cout<<"favorite: " << favorite << "\n";
}