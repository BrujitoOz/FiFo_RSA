#pragma once
#include <iostream> 
#include <vector> 
#include <string> 
#include <cstdlib> 
#include <sstream>
#define N 100000
using namespace std;
typedef unsigned long long ull;
class RSA {
	string Message;
	struct PublicKey {
		ull e, n;
	} MyPublicKey;
	struct PrivateKey {
		ull d, p, q, fi;
	} MyPrivateKey;
	bool EuclidesAlgorithm(ull d, ull fi) {
		ull r = 1;
		while (r != 0) {
			r = fi % d;
			fi = d;
			d = r;
		}
		return fi == 1;
	}
	ull Calc_e_Value(ull d, ull fi) {
		ull e;
		for (ull i = 2; i < fi; i++) {
			if ((i * d) % fi == 1) {
				e = i;
				break;
			}
		}
		return e;
	}
public:
	RSA() = default;
	~RSA() = default;
	void SetMessage(string input) {
		Message = input;
	}
	string GetMessage() {
		return Message;
	}
	PublicKey GetPublicKey() {
		return MyPublicKey;
	}
	PrivateKey GetPrivateKey() {
		return MyPrivateKey;
	}
	void SetMyPrivateKeyP(string p) {
		MyPrivateKey.p = stoll(p);
	}
	void SetMyPrivateKeyQ(string q) {
		MyPrivateKey.q = stoll(q);
	}	
	ull EncryptOrDecryptFormula(ull code, ull e_or_d_value, ull n) {
		ull ret = 1;
		while (e_or_d_value != 0) {
			if (e_or_d_value % 2 != 0)
				ret = ret * code % n;
			code = code * code % n;
			e_or_d_value /= 2;
		}
		return ret;
	}
	ull encrypt(PublicKey& puk, ull msg) {
		return EncryptOrDecryptFormula(msg, puk.e, puk.n);
	}
	ull decrypt(PrivateKey& prk, PublicKey& puk, ull c) {
		return EncryptOrDecryptFormula(c, prk.d, puk.n);
	}
	void CreateKey(ull d) {
		MyPublicKey.n = MyPrivateKey.p * MyPrivateKey.q;
		MyPrivateKey.fi = (MyPrivateKey.p - 1) * (MyPrivateKey.q - 1);
		while (!EuclidesAlgorithm(d, MyPrivateKey.fi))
			++d;
		MyPrivateKey.d = d;
		MyPublicKey.e = Calc_e_Value(d, MyPrivateKey.fi);
	}
	vector<ull> EncryptationMetodRSA() {
		vector<ull> vcode;
		for (ull character : Message) {
			ull code = encrypt(MyPublicKey, (ull)character);
			vcode.push_back(code);
		}
		return vcode;
	}
	string DecryptationMethod(vector<ull> codes) {
		string DencryptedMessage;
		for (ull code : codes) {
			char c = decrypt(MyPrivateKey, MyPublicKey, code);
			DencryptedMessage += c;
		}
		return DencryptedMessage;
	}
};