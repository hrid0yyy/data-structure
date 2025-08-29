#include<bits/stdc++.h>
using namespace std;
#define umap unordered_map<string, int>


struct Node {
    string str;
    int freq;
    Node* left;
    Node* right;

    Node(string s, int f) : str(s), freq(f), left(nullptr), right(nullptr) {}
};

umap getFreqMap(string str) {
    umap freqMap;
    for (char c : str) {
        string key(1, c);  
        freqMap[key]++;
    }
    return freqMap;
}

struct comp{
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  
    }
};


void getCodes(Node* root, string code, unordered_map<string, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->str] = code;
    }

    getCodes(root->left, code + "0", huffmanCode);
    getCodes(root->right, code + "1", huffmanCode);
}



struct encoded_output{
	string encoded_s;
	unordered_map<string, string> huffmanCode;
};


encoded_output huffman_encode(string s){
	umap fmap = getFreqMap(s);
	priority_queue<Node*, vector<Node*>, comp> q;
	for (auto &p : fmap) {
		q.push(new Node(p.first, p.second));
    }
     unordered_map<string, string> huffmanCode;
    while(true){
    	Node* leftNode = q.top();
    	q.pop();
    	Node* rightNode = q.top();
    	q.pop();
    	string s = leftNode->str+rightNode->str;
    	int f = leftNode->freq+rightNode->freq;
    	Node* n = new Node(s, f);
    	n->left = leftNode;
    	n->right = rightNode;
    	if(q.empty()){
    		getCodes(n, "", huffmanCode);
    	    break;
    	}
    	q.push(n);
    }
    string encoded_s = "";
	for (auto c : s) {
		    string key(1, c);         
		    encoded_s += huffmanCode[key];
		}
    return {encoded_s, huffmanCode};
	
}


string huffman_decode(encoded_output ec) {
    string decoded_s = "";
    int n = ec.encoded_s.size();
    // Invert the map: code -> character
    unordered_map<string, string> codeToChar;
    for (auto &p : ec.huffmanCode) {
        codeToChar[p.second] = p.first;
    }

    int i = 0;
    while (i < n) {
        string s = "";
        for (int j = i; j < n; j++) {
            s += ec.encoded_s[j];  // build substring
            if (codeToChar.find(s) != codeToChar.end()) {
                decoded_s += codeToChar[s]; // append decoded char
                i = j + 1;                  // move start pointer
                break;
            }
        }
    }

    return decoded_s;
}




int main(){
   string s = "ulala bulala";
   encoded_output ec = huffman_encode(s);
   cout << ec.encoded_s << "\n";
   string decoded_s = huffman_decode(ec);
   cout << decoded_s;
}