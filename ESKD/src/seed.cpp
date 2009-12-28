#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
     const int init_lenth = 52;
     bool seed[init_lenth];
          
     ofstream fout(argv[1], ios_base::out);
     srand(time(NULL));

     for (int j = 0; j < init_lenth; j++) {
	  seed[j] = rand()%2;
	  cout << seed[j];
	  fout << seed[j];
     }
	  
     cout << endl;
	  
     fout.close();
}     
