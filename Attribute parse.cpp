#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;
    string line;
    getline(cin, line); // Clear buffer

    map<string, string> attributeMap;
    vector<string> tagStack; // Store only individual tag names

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        
        if (line.substr(0, 2) == "</") {
            if (!tagStack.empty()) tagStack.pop_back();
        } else {
            // Remove < and > safely
            line.erase(remove(line.begin(), line.end(), '<'), line.end());
            line.erase(remove(line.begin(), line.end(), '>'), line.end());
            
            stringstream ss(line);
            string tagName, attr, eq, val;
            ss >> tagName;
            tagStack.push_back(tagName);

            // Construct the dot-separated path
            string currentPath = "";
            for (size_t j = 0; j < tagStack.size(); j++) {
                currentPath += (j == 0 ? "" : ".") + tagStack[j];
            }

            // Parse attributes: attr = "value"
            while (ss >> attr >> eq >> val) {
                // Remove quotes from "value"
                val = val.substr(1, val.length() - 2);
                attributeMap[currentPath + "~" + attr] = val;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        getline(cin, line);
        if (attributeMap.count(line)) {
            cout << attributeMap[line] << endl;
        } else {
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
