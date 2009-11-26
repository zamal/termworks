#include <iostream>
int main(int argc, char *argv[])
{
     using namespace std;
     const int WORD_SIZE = 21;
     const int SCHEME_SIZE = 10;
     int coding_scheme[SCHEME_SIZE];
     int info_word[WORD_SIZE] = {1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0};

     for (int i = 0; i < SCHEME_SIZE; i++) {
	  coding_scheme[i] = 0;
     }

     for (int j = 0; j < WORD_SIZE; j++) {
	  int word_symbol = info_word[j] ^ coding_scheme[9];

	  int k = (SCHEME_SIZE - 1);
     	  for (k; k > 0; k--) {
     	       coding_scheme[k] = coding_scheme[k-1];
     	  }
     	  coding_scheme[0] = word_symbol;
     	  coding_scheme[3] = coding_scheme[3] ^ word_symbol;
     	  coding_scheme[5] = coding_scheme[5] ^ word_symbol;
     	  coding_scheme[6] = coding_scheme[6] ^ word_symbol;
     	  coding_scheme[8] = coding_scheme[8] ^ word_symbol;
     	  coding_scheme[9] = coding_scheme[9] ^ word_symbol;
	  cout << info_word[j] << " | ";
	  for (int m = 0; m < SCHEME_SIZE; m++)
	    cout << coding_scheme[m];
	  cout << endl;
     }     
}
