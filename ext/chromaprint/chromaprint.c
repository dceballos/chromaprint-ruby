#include <string.h>
#include <ruby.h>
#include "chromaprint.h"

static VALUE decode_fingerprint(VALUE klass, VALUE fingerprint)
{
  VALUE return_array = rb_ary_new();
  char *str = StringValuePtr(fingerprint);
  int len = (int)strlen(str);
  int32_t *raw_fingerprint;
  int fingerprint_size = 0;
  int algorithm = 1;
  int base64 = 1;

  ChromaprintContext *chromaprint_ctx;
  chromaprint_ctx = chromaprint_new(CHROMAPRINT_ALGORITHM_DEFAULT);
  chromaprint_decode_fingerprint(str, len, (void**)&raw_fingerprint, &fingerprint_size, &algorithm, base64);
  chromaprint_free(chromaprint_ctx);

  if (fingerprint_size > 0) {
    int i=0;
    while (i<fingerprint_size) {
      rb_ary_push(return_array, INT2FIX(*(raw_fingerprint+i)));
      i++;
    }
  }

  return return_array;
}

void Init_chromaprint(void)
{
  VALUE mChromaprint = rb_define_class("Chromaprint", rb_cObject);
  rb_define_singleton_method(mChromaprint, "decode", decode_fingerprint, 1);
}
