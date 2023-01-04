#include <map>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <vector>
#include <regex>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
void printMap(map<string, string> m);
std::vector<string> getOnePair(std::string, int &);

std::vector<string> captureAll(std::string subject) {
    //capture the tag name, and all attribute names and values
    std::vector<string> ret;
    std::string tmp;
    // finding all the match.
    int i = 1;
    while(!isalpha(subject[i]))
        i ++;
    while(isalnum(subject[i])) {
        tmp += subject[i];
        i ++;
    }
    // name is gone.
    ret.push_back(tmp);
    
    // time to grab the attribute/value pairs.
    while(i < subject.length() && subject[i] != '>') {
        auto pair = getOnePair(subject, i);
        if(pair.size() == 2) {
            ret.push_back(pair[0]);
            ret.push_back(pair[1]);
        }
    }
    return ret;
}

std::vector<string> getOnePair(std::string subject, int &i) {
    std::vector<string> ret;
    std::string tmp;

    // time to grab the attribute/value pairs.
    while(!isalnum(subject[i])) {
        i ++;
        if(subject[i] == '>')
            return ret;
    }
    
    while(isalnum(subject[i]) || subject[i] == '_') {
        tmp += subject[i ++];
    }
    // Got the name of the attribute
    ret.push_back(tmp);

    // Let's get to the equal sign
    while(subject[i] != '=')
        i ++;

    // Now to the attribute value
    while(subject[i] != '\"')
        i ++;
    i ++;

    // Now grab the attribute value
    tmp = "";
    while(subject[i] != '\"')
        tmp += subject[i ++];
    i ++;
    
    // Got the value of the attribute
    ret.push_back(tmp);
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, // Number of lines of tags
        N; // Number of lines of queries
    std::string line, tagLevel;
    std::getline(std::cin, line);
    stringstream(line) >> T >> N;
    tagLevel = "";
    std::map<string, string> tagsAndValues;

    for (int ln = 0; ln < T; ln ++) {
        std::getline(std::cin, line);
        if(!line.length())
            continue;

        // If we have a closing tag:
        if(line.substr(0, 2) == "</") {
            if(tagLevel.find(".") == std::string::npos)
                tagLevel = "";
            else
                tagLevel = tagLevel.substr(0,tagLevel.find_last_of("."));
            continue;
        }

        // It must be, then, an opening tag.
        auto result = captureAll(line);
        if(!result.size()) {
            //something wrong...
            return -1;
        }

        if(tagLevel.length())
            tagLevel += ".";
        tagLevel += result[0];
        if(result.size() == 1) {
            // empty opening tag
            continue;
        }
        for(int i = 1; i < result.size(); i += 2) {
            tagsAndValues[tagLevel + "~" + result[i]] = result[i+1];
        }
    }
    for (std::string line; std::getline(std::cin, line);) {
        auto it = tagsAndValues.find(line);
        std::cout << ((it == tagsAndValues.end()) ? "Not Found!" : it->second) << endl;
    }
    return 0;
}

void printMap(map<string, string> m) {
    map<string, string>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        std::cout << it->first    // string (key)
            << ':'
            << it->second   // string's value 
            << std::endl;
    }
}
