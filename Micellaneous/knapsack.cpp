#include <bits/stdc++.h>
using namespace std;

class Receiver {
    
public:
    vector<int> privateKey;
    vector<int> publicKey;
    int n, m;

    Receiver(vector<int> &SIK) {

        this -> privateKey = SIK;

        //Choose n & m
        this -> n = 31;
        this -> m = 110; 

        //Generate public key
        for(int num : privateKey) {
            publicKey.push_back((n * num) % m);
        }
    }

    void decryptMessage(vector<int> &encryptedMessage) {
        int inverse = multiplicative_inverse(n, m);

        vector<int> temp;
        cout << "Decrypted text : ";
        for(int ele : encryptedMessage) {
            temp.push_back((inverse * ele) % m);
            cout << temp.back() << " ";
        }
        cout << endl;

        //Initialze as zero initially
        string decryptMessage = "";
        for(int x = 0; x < temp.size() * privateKey.size(); x++)
            decryptMessage += "0";

        for(int j = 0; j < temp.size(); j++) {
            int need = temp[j];
            for(int i = privateKey.size() - 1; i >= 0; i--) {
                if(privateKey[i] <= need) {
                    decryptMessage[(j * privateKey.size()) + i] = '1';
                    need -= privateKey[i];
                }
            }
        }
        cout << "Decoded text : " << decryptMessage << endl;
    }

    int multiplicative_inverse(int n, int m) {

        for(int i = 2; i < m; i++) {
            if((n * i) % m == 1) return i;
        }
        return -1;
    } 

};

class Sender {

public:
    vector<int> sendMessage(vector<int> &publicKey, string message) {
    
        int len = publicKey.size();
        int msglen = message.length();
        vector<int> encryptedMessage(ceil(msglen / len), 0);
        
        for(int i = 0; i < msglen; i++) {
            encryptedMessage[i / len] += (message[i] - '0') * publicKey[i % len];
        }

        return encryptedMessage;
    }
};

int main() {

    vector<int> SIK = {1, 2, 4, 10, 20, 40};
    Receiver Alice(SIK); //Receiver object

    Sender Bob; //Sender object
    string message = "100100111100101110";
    vector<int> encryptedMessage = Bob.sendMessage(Alice.publicKey, message);

    Alice.decryptMessage(encryptedMessage);

    return 0;
}
