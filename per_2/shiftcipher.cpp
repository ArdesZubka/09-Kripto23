/*
  Nama  	: Ardes Zubka Putra
  NPM	    : 140810210009
  Kelas 	: A
  Deskripsi	: Program Shift Cipher (Enkripsi dan Dekripsi) dengan Menggunakan Bahasa Pemrograman C++
*/

#include <iostream>
#include <string>
using namespace std;

string enkripsi(string plainText, int key)
{
	string cipherText = "";
	for (int i = 0; i < plainText.size(); i++)
	{
		if (plainText[i] != ' ')
		{
			if (isupper(plainText[i]))
			{
				cipherText += char(int(plainText[i] + key - 65) % 26 + 65);
			}
			else
			{
				cipherText += char(int(plainText[i] + key - 97) % 26 + 97);
			}
		}
		else
		{
			cipherText += plainText[i];
		}
	}
	return cipherText;
}

string dekripsi(string cipherText, int key)
{
	string plainText = "";
	for (int i = 0; i < cipherText.size(); i++)
	{
		if (cipherText[i] != ' ')
		{
			if (isupper(cipherText[i]))
			{
				plainText += char((int(cipherText[i] - key - 65) % 26 + 26) % 26 + 65);
			}
			else
			{
				plainText += char((int(cipherText[i] - key - 97) % 26 + 26) % 26 + 97);
			}
		}
		else
		{
			plainText += cipherText[i];
		}
	}
	return plainText;
}

int main()
{
	string plainText;
	int key;

	cout << "===== PROGRAM SHIFT CIPHER =====" << endl;

	cout << "Masukkan Plain Text (tanpa spasi): ";
	cin >> plainText;

	cout << "Masukkan Key: ";
	cin >> key;

	string cipherText = enkripsi(plainText, key);

	cout << "\n--- Enkripsi --- \n";
	cout << "Cipher Text : " << cipherText << endl;

	cout << "\n--- Dekripsi ---\n";
	cout << "Plain Text : " << dekripsi(cipherText, key) << endl;
}