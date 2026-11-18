#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>

#include "searchresult.h"
#include "searchresultmanager.h"

int main(int argc, char *argv[])
{
    SearchResultManager srManager;

    srManager.addResult(SearchResult(0, "testA", "testAddr", 3.1, false));
    srManager.addResult(SearchResult(1, "testB", "testAddr", 5.5, true));
    srManager.addResult(SearchResult(2, "testC", "testAddr", 12.3, false));
    srManager.addResult(SearchResult(3, "testD", "testAddr", 0.8, true));
    srManager.addResult(SearchResult(4, "testE", "testAddr", 37.6, true));

    const SearchResult *searchItem = srManager.searchFromId(3);

    std::cout << "searchItem From ID: ";
    if(nullptr != searchItem) {
        searchItem->printSearchResult();
    }
    else {
        std::cout << "search Result not found\n";
    }

    std::cout << "SearchResult Show ALL \n";
    srManager.showResult();

    std::cout << "SearchResult Show Favorite \n";
    srManager.showFavorite();

    srManager.sortByDistance();

    std::cout << "SearchResult Sort By Distance \n";
    srManager.showResult();

    // QGuiApplication app(argc, argv);

    // QQmlApplicationEngine engine;
    // QObject::connect(
    //     &engine,
    //     &QQmlApplicationEngine::objectCreationFailed,
    //     &app,
    //     []() { QCoreApplication::exit(-1); },
    //     Qt::QueuedConnection);
    // engine.loadFromModule("NavigationSearch", "Main");

    // return QGuiApplication::exec();
    return 0;
}
