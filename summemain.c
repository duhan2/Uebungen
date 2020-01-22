#include <stdio.h>

int rekursiv(int n, int summe) {

	

	if (n > 0) {

		summe += n;

		return rekursiv(n-1,summe);

	}

	else {

		return summe;

	}

		
}


int main(){

	int summe = rekursiv(15,0);
	
	printf("Summe = %d\n", summe);
	

	printf("Hello World\n");

	return 0;

}
