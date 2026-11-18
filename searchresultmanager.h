#ifndef SEARCHRESULTMANAGER_H
#define SEARCHRESULTMANAGER_H

#include <vector>
#include <cstddef>
#include "searchresult.h"

class SearchResultManager
{
public:
    SearchResultManager();

    bool addResult(const SearchResult& resultItem);
    void sortByDistance();
    void showResult() const;
    void showFavorite() const;

    std::size_t searchCount() const;
    const SearchResult *searchFromId(int id) const;



private:
    std::vector<SearchResult> searchResult;
};

#endif // SEARCHRESULTMANAGER_H
