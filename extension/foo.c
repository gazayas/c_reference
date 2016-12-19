#include <stdio.h>
#include <ruby.h>

VALUE cFoo; /* Fooクラス */

/* self はメソッドの呼び出し元オブジェクト */
VALUE bar_func(VALUE self, VALUE i_val, VALUE d_val, VALUE s_val)
{
  /* Rubyの値をCの値に変換して */
  int i = NUM2INT(i_val);
  double d = NUM2DBL(d_val);
  char* s = StringValuePtr(s_val);
  
  /* なんか処理して */
  double x = i + d;
  printf("[%s * %d + %lf = %lf]\n", s, i, d, x);

  /* Cの値をRubyの値にへんかんして返す */
  return DBL2NUM(x);
}

void Init_foo()
{
  /* Fooクラスを定義 */
  cFoo = rb_define_class("Foo", rb_cObject);

  /* Fooクラスに引数0個のbarメソッドを定義
   * barメソッドが呼ばれると、bar_funcが実行される
   */
  rb_define_method(cFoo, "bar", RUBY_METHOD_FUNC(bar_func), 3);
}

