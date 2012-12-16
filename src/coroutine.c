#include "mruby.h"
#include "mruby/coroutine.h"
#include "mruby/class.h"

static mrb_value
mrb_cor_initialize(mrb_state *mrb, mrb_value self)
{
  mrb_value blk;

  mrb_get_args(mrb, "&", &blk);
  if (mrb_nil_p(blk)) {
    /* Calling Coroutine.new without a block is not implemented yet */
    mrb_raise(mrb, E_ARGUMENT_ERROR, "tried to create Coroutine object without a block");
  }

  return self;
}

void
mrb_coroutine_init(mrb_state * mrb)
{
  struct RClass *c;

  c = mrb->coroutine_class = mrb_define_class(mrb, "Coroutine", mrb->object_class);
  MRB_SET_INSTANCE_TT(c, MRB_TT_COROUTINE);

  mrb_define_method(mrb, c, "initialize", mrb_cor_initialize, ARGS_NONE());
}
