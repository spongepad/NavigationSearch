#include <algorithm>
#include <iostream>
#include "searchresultmanager.h"

SearchResultManager::SearchResultManager() {}

bool SearchResultManager::addResult(const SearchResult& resultItem) {
    for(const auto &item : searchResult) {
        if(item.getId() == resultItem.getId()) {
            return false;
        }
    }

    searchResult.push_back(resultItem);
    return true;
}

void SearchResultManager::sortByDistance() {
    if(searchResult.empty()) {
        return;
    }

    std::sort(searchResult.begin(), searchResult.end(), [](const SearchResult& a, const SearchResult& b) {
        return a.getDistance() < b.getDistance();
    });
}

void SearchResultManager::showResult(){
    for(const auto &item : searchResult) {
        std::cout << "id: " << item.getId() << " name: " << item.getName() << " address: " << item.getAddress()
                  << " distance: " << item.getDistance() << " favorite: " << item.isFavorite() << "\n";
    }
}

void SearchResultManager::showFavorite(){
    for(const auto &item : searchResult) {
        if(item.isFavorite()) {
            std::cout << "id: " << item.getId() << " name: " << item.getName() << " address: " << item.getAddress()
            << " distance: " << item.getDistance() << " favorite: " << item.isFavorite() << "\n";
        }
    }
}

int SearchResultManager::searchCount() const {
    return searchResult.size();
}

const SearchResult *SearchResultManager::searchFromId(int id) const {
    auto searchItem = std::find_if(searchResult.cbegin(), searchResult.cend(), [id](const SearchResult& a) {
        return a.getId() == id;
    });

    if(searchItem != searchResult.end()) {
        return &(*searchItem);
    }
    else {
        return nullptr;
    }
}