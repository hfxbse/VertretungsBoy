//
// Created by StuBIT on 12/20/17.
//

#ifndef VERTRETUNGSBOY_VERTRETUNGSBOY_HPP
#define VERTRETUNGSBOY_VERTRETUNGSBOY_HPP

#include <string>
#include <vector>
#include <sqlite3.h>

namespace VertretungsBoy {

    class plan {

    public:
        plan(std::vector<std::string> urls, long long int timeout, std::string dbPath, bool skipOutdated);

        void update();
        std::vector<std::string> getDates();
        std::vector<std::vector<std::string>> getEntries(size_t tableNumber, std::string searchValue);

        static bool curlGlobalInit;

    private:
        long long int timeout;
        std::vector<std::string> htmls;
        std::vector<std::string> urls;
        void download(size_t urlsIndex);
        static size_t curlWriter(char *ptr, size_t size, size_t n, void *userData);

        std::vector<std::string> dates;
        bool skipOutdated;
        bool upToDate(const std::string &date);

        std::vector<std::vector<std::string>> parser(const std::string &html);
        std::string toUTF8(char token);
        void tableWriter(std::string tokens, std::string &output);
        bool replace = false, styleElement = false;
        size_t replaceCounter = 0;


        std::string dbPath;
        void writeTableToDB(size_t tableNumber, std::vector<std::vector<std::string>> table);
        void writeDatesToDB();
        bool checkTableExistence(std::string tableName);
    };
};

#endif //VERTRETUNGSBOY_VERTRETUNGSBOY_HPP
