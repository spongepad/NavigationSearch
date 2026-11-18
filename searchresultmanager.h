#ifndef SEARCHRESULTMANAGER_H
#define SEARCHRESULTMANAGER_H

#include <vector>
#include "searchresult.h"

class SearchResultManager
{
public:
    SearchResultManager();

    bool addResult(const SearchResult& resultItem);
    void sortByDistance();
    void showResult();
    void showFavorite();

    int searchCount() const;
    const SearchResult *searchFromId(int id) const;



private:
    std::vector<SearchResult> searchResult;
};

#endif // SEARCHRESULTMANAGER_H
