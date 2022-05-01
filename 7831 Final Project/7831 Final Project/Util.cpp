#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Util.h"

//string clean(string url_request) {
//    int slow = 0;
//    int fast = 0;
//    char newArray[url_request.length()];
//    while (fast < url_request.length()) {
//        if (url_request.at(fast) == '\r' && url_request.at())
//    }
//}

vector<string> split(string text, char delim) {
    string line;
    vector<string> vec;
    stringstream ss(text);
    while (std::getline(ss, line, delim)) {
        vec.push_back(line);
    }
    return vec;
}

map<string, string> ProcessConfigData(string config_file)
{
    map<string, string> config_map;
    ifstream fin;
    fin.open(config_file, ios::in);
    string line, name, value;
    while (!fin.eof())
    {
        getline(fin, line);
        stringstream sin(line);
        getline(sin, name, ':');
        getline(sin, value);
        config_map.insert(pair<string, string>(name, value));
    }
    return config_map;
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
