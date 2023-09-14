#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define MAXN 100001
#define INF 1e18 + 1
struct Node
{
    Node *links[26];
    bool flag = false;
    // checks if the reference trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    // creating reference trie
    void put(char ch, Node *newNode)
    {
        links[ch - 'a'] = newNode;
    }
    // to get the next node for traversal
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // setting flag to true at the end of the word
    void setEnd()
    {
        flag = true;
    }
    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        // creating new obejct
        root = new Node();
    }

    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *newNode = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!newNode->containKey(word[i]))
            {
                newNode->put(word[i], new Node());
            }
            // moves to reference trie
            newNode = newNode->get(word[i]);
        }
        newNode->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main()
{
    Trie trie;
    int choice;
    do
    {

        cout << "Enter your choice: " << endl;
        cout << "1.Insert " << endl;
        cout << "2.Search " << endl;
        cout << "3.Starts with " << endl;
        cin >> choice;

        string s;
        bool ans = false;
        bool res = false;

        switch (choice)
        {
        case 1:
            cin >> s;
            trie.insert(s);
            break;

        case 2:

            cin >> s;
            ans = trie.search(s);
            if (ans == true)
            {
                cout << "Present";
            }
            else
            {
                cout << "Not Present";
            }
            break;
        case 3:
            cin >> s;
            res = trie.startsWith(s);
            if (res == true)
            {
                cout << "Yes starts with!!";
            }
            else
            {
                cout << "No does not start with!!";
            }
            break;
        }

    } while (choice != 4);
    return 0;
}
