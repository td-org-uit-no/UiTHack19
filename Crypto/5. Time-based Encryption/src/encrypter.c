#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 32
#define MAX_LEN 1024

/*
 * Generate and return a buffer containing an encryption key.
 */
uint8_t *generate_key(void)
{
	uint8_t *buf = calloc(1, KEY_SIZE);
	for (int i = 0; i < KEY_SIZE; i++) {
		buf[i] = rand();
	}

	return buf;
}

/*
 * Accept the plaintext, key and number of bytes to encrypt, and return
 * a newly allocated buffer with the encrypted data.
 */
uint8_t *encrypt_data(const uint8_t *plain, const uint8_t *key, const size_t num_bytes)
{
	uint8_t *buf = calloc(1, num_bytes);

	for (size_t i = 0; i < num_bytes; i++) {
		buf[i] = plain[i] ^ key[i % KEY_SIZE];
	}

	return buf;
}

int main(void)
{
	uint8_t *plain = calloc(1, MAX_LEN);
	/* Make sure the application is used correctly */
	if (fgets((char*)plain, MAX_LEN, stdin) == NULL) {
		printf("Error reading text to encrypt from stdin\n");
		exit(EXIT_FAILURE);
	}
	char *newline = strchr((char*)plain, '\n');
	if (newline != NULL) {
		*newline = '\0';
	}
	size_t len = strnlen((char*)plain, MAX_LEN);
	printf("Got the input of length %zu, which is the following string: %s\n", len, plain);

	struct timespec time;
	clock_gettime(CLOCK_MONOTONIC, &time);

	/* Output the generated secret key for later decryption */
	printf("GENERATED SECRET KEY: %zu\n", time.tv_nsec);

	srand((uint32_t)time.tv_nsec & 0b1111111111111111111111111111);
	int32_t key_stream[2] = { 0 };
	key_stream[0] = rand();
	key_stream[1] = rand();
	printf("First 8 bytes of key stream: {%u, %u}\n", key_stream[0], key_stream[1]);

	/* Generate key and encrypt the plaintext */
	uint8_t *key = generate_key();
	uint8_t *cipher = encrypt_data(plain, key, len);

	printf("Encrypted data: \"");
	for (size_t i = 0; i < len; i++) {
		printf("%02hhX", cipher[i]);
	}
	printf("\"\n");

	return 0;
}
