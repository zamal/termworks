#include <iostream>

int main(int argc, char *argv[])
{
     using namespace std;
     const int WORD_SIZE = 21;
     const int SCHEME_SIZE = 10;
     int coding_scheme[SCHEME_SIZE];
     // Информационный блок, поступающий в регистр
     int info_word[WORD_SIZE] = {1,0,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0};

     // Обнуление массива
     for (int i = 0; i < SCHEME_SIZE; i++) {
	  coding_scheme[i] = 0;
     }

     // Регистр КДУ систематического циклического кода,
     // с порождающим многочленом
     // g(x) = x^10 + x^9 + x^8 + x^6 + x^5 + x^3 + 1 
     for (int j = 0; j < WORD_SIZE; j++) {
	  int word_symbol = info_word[j] ^ coding_scheme[9];

	  // Сдвиг массива
	  int k = (SCHEME_SIZE - 1);
     	  for (k; k > 0; k--) {
     	       coding_scheme[k] = coding_scheme[k-1];
     	  }

	  // Запись в ячейки результата сложения по модулю 2
     	  coding_scheme[0] = word_symbol;
     	  coding_scheme[3] = coding_scheme[3] ^ word_symbol;
     	  coding_scheme[5] = coding_scheme[5] ^ word_symbol;
     	  coding_scheme[6] = coding_scheme[6] ^ word_symbol;
     	  coding_scheme[8] = coding_scheme[8] ^ word_symbol;
     	  coding_scheme[9] = coding_scheme[9] ^ word_symbol;

	  for (int m = 0; m < SCHEME_SIZE; m++)
	       cout << coding_scheme[m];
	  cout << endl;
     }
          
}
