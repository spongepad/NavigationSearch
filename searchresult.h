#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <string>
class SearchResult
{
public:
    SearchResult();
    SearchResult(int id, std::string name, std::string address, double distance, bool favorite = false);

    int getId() const {return id;};
    const std::string& getName() const {return name;};
    const std::string& getAddress() const {return address;};
    double getDistance() const {return distance;};
    bool isFavorite() const {return favorite;};

    void toggleFavorite();
    void printSearchResult() const;

private:
    int id;
    std::string name;
    std::string address;
    double distance;
    bool favorite;
};

#endif // SEARCHRESULT_H
