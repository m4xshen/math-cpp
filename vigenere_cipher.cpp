#include <iostream>
#include <string>
using namespace std;

string input, key;

void cipher(int k_list[], int len, int option) {
    int k, k_position = 0;

    for(int i = 0; i < input.size(); i++, k_position++) {
	k = k_list[k_position % len];

	if(input[i] == ' ') {
	    cout << " ";
	    k_position--;
	}
	else if(input[i] + option*k > 'Z') cout << (char)(input[i] + option*k - 26);
	else if(input[i] + option*k < 'A') cout << (char)(input[i] + option*k + 26);
	else cout << (char)(input[i] + option*k);
    }
}

int main() {
    char option;

    cout << "Encrypt or decrypt the sentence? [E/d] ";
    cin >> option;

    cout << "Please input the sentence:";
    cin.ignore();
    getline(cin, input);
    
    cout << "Please input the key:";
    cin >> key;
    int key_list[key.size()];

    for(int i = 0; i < key.size(); i++) key_list[i] = (int)key[i] - 65;
    cipher(key_list, key.size(), (option == 'd') ? -1 : 1);

    return 0;
}
