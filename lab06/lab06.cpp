#include "Header.h"

class Node {
public:
    char c;
    int freq;
    Node* left, * right;
};

class comp {
public:
    bool operator()(Node* left, Node* right) 
    {
        return left->freq > right->freq;
    }
};

Node* CreateNode(char c, int freq, Node* left, Node* right)
{
    Node* t = new Node();
    t->c = c;
    t->freq = freq;
    t->left = left;
    t->right = right;
    return t;
}

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        huffmanCode[root->c] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void Algorithm_Huffman(string text) {

    unordered_map<char, int> freq;

    for (auto c : text)
    {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, comp> tree;

    cout << "\nFrequency of each character in the input string:\n";
    for (auto p : freq) {
        cout << p.first << " : " << p.second << endl;
        tree.push(CreateNode(p.first, p.second, NULL, NULL));
    }

    while (tree.size() != 1)
    {
        Node* left = tree.top(); tree.pop();
        Node* right = tree.top(); tree.pop();

        int sum = left->freq + right->freq;
        tree.push(CreateNode(NULL, sum, left, right));
    }

    Node* root = tree.top();

    unordered_map<char, string> huffmanCode;

    encode(root, "", huffmanCode);

    cout << "\nhuffman codes:" << endl;

    for (auto p : huffmanCode)
    {
        cout << p.first << " : " << p.second << endl;
    }

    cout << "\nSource string: " << text << endl;

    string res = "";

    for (char c : text)
    {
        res += huffmanCode[c];
    }

    cout << "\nEncoded string: " << res << endl;
}

void main()
{
    cout << "Enter the line: ";
    string str;
    getline(cin, str);

    Algorithm_Huffman(str);
}