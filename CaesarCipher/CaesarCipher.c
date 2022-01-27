#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *encrypt(char message[], int shift)
{
	int i;
	for (i = 0; i < strlen(message); i++)
	{
		// printf("Debug Original: %c = %d\n", message[i], message[i]);
		if ((int)message[i] == 32)
		{
			message[i] = message[i];
		}
        else if ((int)message[i] + shift > 126)
		{
			message[i] = (char)((((int)message[i] + shift) % 94));
		}
		else
		{
			message[i] = (char)((int)message[i] + shift);
		}
		// printf("Debug Encrypted: %c = %d\n", message[i], message[i]);
	}
	return message;
}

char *decrypt(char message[], int shift)
{
	int i;
	for (i = 0; i < strlen(message); i++)
	{
        // printf("Debug Original: %c = %d\n", message[i], message[i]);
        if ((int)message[i] == 32)
		{
			message[i] = message[i];
		}
		else if ((int)message[i] - shift < 32)
		{
			message[i] = (char)(126 - (32 - ((int)message[i] - shift)));
		}
		else
		{
			message[i] = (char)((int)message[i] - shift);
		}
		// printf("Debug Decrypted: %c = %d\n", message[i], message[i]);
	}
	return message;
}

int main(int argc, char *argv[])
{
	if (strcmp(argv[1], "-e") == 0)
	{
		printf("You chose to encrypt data with a shift of %d\n", atoi(argv[3]));
		printf("Original string: | %s |\n", argv[2]);
		printf("Encrypted string: | %s |\n", encrypt(argv[2], atoi(argv[3])));
	}
	else if (strcmp(argv[1], "-d") == 0)
	{
		printf("You chose to decrypt data with a shift of %d\n", atoi(argv[3]));
		printf("Original string: | %s |\n", argv[2]);
		printf("Decryped string: | %s |\n", decrypt(argv[2], atoi(argv[3])));
	}
	else
	{
		printf("Please enter a valid option.");
	}

	return 0;
}