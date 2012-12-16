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

static mrb_value
mrb_cor_s_yield(mrb_state *mrb, mrb_value self)
{
}

static mrb_value
mrb_cor_resume(mrb_state *mrb, mrb_value cor)
{

}



void
mrb_init_coroutine(mrb_state * mrb)
{
  struct RClass *c;

  c = mrb->coroutine_class = mrb_define_class(mrb, "Coroutine", mrb->object_class);
  MRB_SET_INSTANCE_TT(c, MRB_TT_COROUTINE);

  mrb_define_class_method(mrb, c, "yield", mrb_cor_s_yield,     ARGS_ANY());  /* 15.2.12.4.1 */

  mrb_define_method(mrb, c, "initialize", mrb_cor_initialize, ARGS_NONE());
  mrb_define_method(mrb, c, "resume",     mrb_cor_resume,     ARGS_NONE());
}
