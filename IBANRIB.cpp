// IBANRIB.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <stdio.h>     
#include <stdlib.h>    
#include <time.h> 
#include <string>
using namespace std;

#define ll long long int

string fill2(string n) {

	if (n.length() == 2) {
		return n;
	}
	if (n.length() == 1) {
		return "0" + n;
	}
	return "00";
}

string fill3(string n) {
	if (n.length() == 3) {
		return n;
	}
	if (n.length() == 2) {
		return '0' + n;
	}
	if (n.length() == 1) {
		return "00" + n;
	}
	return "0000";
}

string fill4(string n) {
	if (n.length() == 4) {
		return n;
	}
	if (n.length() == 3) {
		return '0' + n;
	}
	if (n.length() == 2) {
		return "00" + n;
	}
	if (n.length() == 1) {
		return "000" + n;
	}
	return "0000";

}

string ifill4(string n, int &q) {
	if (n.length() == 4) {

		return n;
	}
	if (n.length() == 3) {
		q *= 10;
		return  n+'0';
	}
	if (n.length() == 2) {
		q *= 100;
		return n + "00";
	}
	if (n.length() == 1) {
		q *= 1000;
		return  n + "000";
	}
	return "0000";

}

string getRIB() {

	string rib;

	

	int q1 = rand() % 10000;
	rib += ifill4(to_string(q1), q1);
	int r1 = q1 % 97;
	
	int q2 = r1 * 10000 + rand() % 10000;
	rib += fill4(to_string(q2%10000));
	int r2 = q2 % 97;
	
	int q3 = r2 * 10000 + rand() % 10000;
	rib += fill4(to_string(q3 % 10000));
	int r3 = q3 % 97;
	
	int q4 = r3 * 10000 + rand() % 10000;
	rib += fill4(to_string(q4 % 10000));
	int r4 = q4 % 97;
	
	int q5 = r4 * 10000 + rand() % 10000;
	rib += fill4(to_string(q5 % 10000));
	int r5 = q5 % 97;
	
	int q6 = ceil((double)(r5 * 1000) / 97.0) * 97;
	rib += fill3(to_string(q6 % 1000));
	int r6 = q6 % 97;
	
	return rib;
}

string getIBANFR(string rib) {

	string iban;

	ll n91 = stoll(rib.substr(0, 12));
	ll r1 = n91 % 97;
	ll n92 = r1 * 100000000000 + stoll(rib.substr(12, 11));
	ll r2 = n92 % 97;
	ll n93 = r2 * 1000000 + 152700;
	ll r3 = n93 % 97;
	ll num = 98 - r3;




	return "FR" + fill2(to_string(num)) + rib;

}


int main()
{
	srand(time(NULL));

	int MAX = 50;

	for (int i = 0; i < MAX; i++) {
		string rib = getRIB();
		cout << fill2(to_string(i)) << " rib : " << rib << endl;
		cout << fill2(to_string(i)) << " iban: " << getIBANFR(rib) << endl;
		cout << endl;
	}
	
}


