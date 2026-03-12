#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   int total_bytes = 0;
   for (size_t i = 0; i < integers_len; ++i) {
      uint32_t n = integers[i];
      uint8_t temp[5];
      int count = 0;
      do {
         uint8_t byte = n & 0x7F;
         if (count == 0) {
            temp[count++] = byte;
         }
         else {
            temp[count++] = byte | 0x80;
         }
         n >>= 7;
      } while (n > 0);
      for (int j = count - 1; j >= 0; j--) {
         output[total_bytes++] = temp[j];
      }
   }
   return total_bytes;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   uint32_t value = 0;
   uint32_t count = 0;
   for (size_t i = 0; i < buffer_len; ++i) {
      uint32_t byte = bytes[i];
      value <<= 7;
      value |= (byte & 0x7F);
      if (!(byte & 0x80)) {
         output[count++] = value;
         value = 0;
      }
   }
   if (bytes[buffer_len - 1] & 0x80) return -1;
   return count;
}
