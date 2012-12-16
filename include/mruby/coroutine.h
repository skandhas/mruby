#ifndef MRUBY_COROUTINE_H
#define MRUBY_COROUTINE_H

#if defined(__cplusplus)
extern "C" {
#endif

struct RCoroutine {
  MRB_OBJECT_HEADER;
  mrb_state * mrb;
};


#if defined(__cplusplus)
}
#endif

#endif
