
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    long long freq;
    int symbol;
    Node *left, *right;

    Node(long long f, int s) :
        freq(f), symbol(s), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) const {
        if (a->freq != b->freq)
            return a->freq > b->freq;
        return a->symbol > b->symbol;
    }
};

void getLengths(Node* root, int depth, vector<int>& lengths) {
    if (!root) return;

    if (root->symbol != -1) {
        lengths[root->symbol] = max(1, depth);
        return;
    }

    getLengths(root->left, depth + 1, lengths);
    getLengths(root->right, depth + 1, lengths);
}

string incrementBinary(string code) {
    int i = (int)code.size() - 1;

    while (i >= 0 && code[i] == '1') {
        code[i] = '0';
        i--;
    }

    if (i >= 0)
        code[i] = '1';

    return code;
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter number of symbols: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of symbols.\n";
        return 0;
    }

    vector<char> symbols(n);
    vector<long long> freq(n);
    vector<int> lengths(n);

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        cout << "Enter symbol and frequency: ";
        cin >> symbols[i] >> freq[i];

        if (freq[i] <= 0) {
            cout << "Frequencies must be positive.\n";
            return 0;
        }

        pq.push(new Node(freq[i], i));
    }

    while (pq.size() > 1) {
        Node* a = pq.top();
        pq.pop();

        Node* b = pq.top();
        pq.pop();

        Node* parent = new Node(a->freq + b->freq, -1);
        parent->left = a;
        parent->right = b;
        pq.push(parent);
    }

    Node* root = pq.top();
    getLengths(root, 0, lengths);

    vector<int> order(n);
    for (int i = 0; i < n; i++)
        order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b) {
        if (lengths[a] != lengths[b])
            return lengths[a] < lengths[b];
        return symbols[a] < symbols[b];
    });

    string code(lengths[order[0]], '0');

    cout << "\nCanonical Huffman Codebook:\n";
    cout << "Symbol Frequency Length Code\n";

    for (int i = 0; i < n; i++) {
        int id = order[i];

        if (i > 0) {
            code = incrementBinary(code);
            int newLength = lengths[id];

            if (newLength < (int)code.size()) {
                cout << "Invalid Huffman lengths.\n";
                deleteTree(root);
                return 1;
            }

            code.append(newLength - code.size(), '0');
        }

        cout << symbols[id] << "      "
             << freq[id] << "        "
             << lengths[id] << "      "
             << code << '\n';
    }

    deleteTree(root);
    return 0;
}