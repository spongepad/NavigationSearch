#ifndef SEARCHRESULTMANAGER_H
#define SEARCHRESULTMANAGER_H

#include <vector>
#include "searchresult.h"

class SearchResultManager
{
public:
    SearchResultManager();

    void addResult(const SearchResult& resultItem);
    void sortByDistance();
    void extracted();
    void showResult();
    void showFavorite();

    int searchCount();
    const SearchResult *searchFromId(int id);



private:
    std::vector<SearchResult> searchResult;
};

#endif // SEARCHRESULTMANAGER_H
