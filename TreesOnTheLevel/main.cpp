#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Node
{
public:
    string path;
    int value;
};

void treesort(vector<Node>& nodes)
{
    for (int i = 1; i < nodes.size(); i++)
    {
        for (int j = 0; j < nodes.size() - 1; j++)
        {
            if ((nodes[i].path.length() < nodes[j].path.length()) || (nodes[i].path.length() == nodes[j].path.length() && nodes[i].path < nodes[j].path))
            {
                swap(nodes[i], nodes[j]);
            }
        }
    }
}

bool nodeAlreadyDefined(vector<Node> nodes, Node node)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i].path == node.path)
            return true;
    }
    return false;
}

bool isTreeGood(vector<Node> nodes)
{
    int baseCases = 0;
    for (int i = 0; i < nodes.size(); i++)
    {
        bool fatherFound = false;
        if (nodes[i].path == "" || nodes[i].path == "L" || nodes[i].path == "R")
        {
            baseCases++;
            continue;
        }
        int j;
        for (j = 0; j < nodes.size(); j++)
        {
            if (nodes[j].path == nodes[i].path.substr(0, nodes[i].path.length() - 1))
            {
                fatherFound = true;
                break;
            }
        }
        if (!fatherFound)
        {
            return false;
        }
    }
    if (baseCases > 1)
        return true;
    else
        return false;
}

string computeResultString(string tree)
{
    vector<Node> nodes;
    vector<Node>::iterator it = nodes.begin();

    string s = tree;

    while (s != "()")
    {
        int commaPos = s.find(',');
        int beginNode = s.find('(');
        int endNode = s.find(')');
        Node node;
        node.value = atoi((s.substr(beginNode + 1, commaPos - beginNode)).c_str());
        node.path = s.substr(commaPos + 1, endNode - commaPos -1);

        //check if node whose path is 'path' is already defined
        if (nodeAlreadyDefined(nodes, node))
            return "not complete";
        it = nodes.insert(it, node);

        s = s.substr(s.find('(', endNode));
    }

    if (!isTreeGood(nodes))
        return "not complete";

    treesort(nodes);

    std::ostringstream sstream;
    for (int i = 0; i < nodes.size(); i++)
    {
        sstream << nodes[i].value;
        if (i != nodes.size() - 1)
            sstream << " ";
    }

    return sstream.str();
}

int main()
{
    string line;
    string currentTree;

    while(getline(cin, line))
    {
        currentTree.append(line);
        if (line.substr(line.length()-2, 2) == "()")
        {
            string result = computeResultString(currentTree);

            cout << result << endl;
            currentTree = "";
        }
    }
    return 0;
}

