#include <algorithm>
#include <iostream>
#include "searchresultmanager.h"

SearchResultManager::SearchResultManager() {}

void SearchResultManager::addResult(const SearchResult& resultItem) {
    for(int i = 0; i < searchResult.size(); i++) {
        if(searchResult[i].getId() == resultItem.getId()) {
            return;
        }
    }

    searchResult.push_back(resultItem);
}

void SearchResultManager::sortByDistance() {
    if(searchResult.size() <= 0) {
        return;
    }

    std::sort(searchResult.begin(), searchResult.end(), [](const SearchResult& a, const SearchResult& b) {
        return a.getDistance() < b.getDistance();
    });
}

void SearchResultManager::showResult(){
    for(const auto &item : searchResult) {
        std::cout << "id: " << item.getId() << " name: " << item.getName() << " address: " << item.getAddress()
                  << " distance: " << item.getDistance() << " favorite: " << item.getFavorite() << "\n";
    }
}

void SearchResultManager::showFavorite(){
    for(const auto &item : searchResult) {
        if(item.getFavorite()) {
            std::cout << "id: " << item.getId() << " name: " << item.getName() << " address: " << item.getAddress()
            << " distance: " << item.getDistance() << " favorite: " << item.getFavorite() << "\n";
        }
    }
}

int SearchResultManager::searchCount() {
    if(searchResult.size() >= 0) {
        return searchResult.size();
    }
    return 0;
}

const SearchResult *SearchResultManager::searchFromId(int id) {
    auto searchItem = std::find_if(searchResult.begin(), searchResult.end(), [id](const SearchResult& a) {
        return a.getId() == id;
    });

    if(searchItem != searchResult.end()) {
        return &(*searchItem);
    }
    else {
        return nullptr;
    }
}