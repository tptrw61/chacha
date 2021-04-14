#ifndef CHACHA_H_INCLUDED
#define CHACHA_H_INCLUDED

#include <stdint.h>

#define CHACHA_KEY_SIZE         256
#define CHACHA_KEY_SIZE_BYTES   32

// the spec
// https://tools.ietf.org/html/rfc8439

typedef struct chacha_state {
	uint8_t key[32];
	uint8_t nonce[12];
	uint32_t blockNum;

	uint32_t block[16];
	uint64_t pos;
	uint32_t cur[16];
};

void chacha_init_state(struct chacha_state *state, uint8_t key[], uint8_t nonce[], int64_t pos);
void chacha_xor(struct chacha_state *state, void *data, uint32_t size);

#endif //CHACHA_H_INCLUDED
