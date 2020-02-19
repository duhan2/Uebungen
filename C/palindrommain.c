#include <stdio.h>

unsigned is_palindrome(char* s) {

	int count = 0;

	while (s[count] != '\0') {

		count += 1;

	}

	printf("Anzahl der Buchstaben: %d\n", count);

	count -= 1;

	int start = 0;
	int ende = count;

	while (start != ende) {

		if (s[start] != s[ende]) {

			return 0;

		}

		start += 1;
		ende -= 1;

		if (start < ende) {
			return 1;
		}



	}


}



int main(){

	char* s = "TURAN";

	int ergebnis = is_palindrome(s);

	if (ergebnis == 1) {

		printf("%s ist ein Palindrom\n",s);

	}
	else {

		printf("%s ist kein Palindrom\n",s);

	}
	/**/
	char* c = "EFE";

	ergebnis = is_palindrome(c);

	if (ergebnis == 1) {

		printf("%s ist ein Palindrom\n", c);

	}
	else {

		printf("%s ist kein Palindrom\n", c);

	}

	printf("Hello World\n");

	return 0;

}
