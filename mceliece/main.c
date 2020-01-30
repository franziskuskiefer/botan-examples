#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#include <botan-2/botan/ffi.h>

int main()
{
   botan_rng_t rng;
   botan_rng_init(&rng, "user");
   botan_privkey_t sk;
   botan_pubkey_t pk;
   const char* mce_params = "2048,50";

   int sk_result = botan_privkey_create(&sk, "McEliece", mce_params, rng);
   assert(sk_result == BOTAN_FFI_SUCCESS);
   int pk_result = botan_privkey_export_pubkey(&pk, sk);
   assert(pk_result == BOTAN_FFI_SUCCESS);

	return 0;     
}

