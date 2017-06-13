/*  SPA17   */
#include "mlisp.h"
double cc(double amount, double largest__coin);
double count__change(double amount);
double next__coin(double coin);
double GR__AMOUNT();
double LAGEST__COIN();
double LAST__DIGIT__OF__GROUP__NUMBER();
//________________ 
double cc(double amount, double largest__coin) {{
return ((!((!(((amount <= (0.)) && ((0.) <= amount))) && !(((largest__coin <= (1.)) && ((1.) <= largest__coin)))))) ? ((1.)) :
(true) ? (((!((!((amount <= (0.))) && !((largest__coin <= (0.)))))) ? ((0.)) :
(true) ? (((cc(amount, next__coin(largest__coin)) + cc(((amount - largest__coin)), largest__coin)))) :
_infinity)) :
_infinity);

}}
double count__change(double amount) {{
return cc(amount, LAGEST__COIN());

}}
double next__coin(double coin) {{
return ((((coin <= (25.)) && ((25.) <= coin))) ? ((15.)) :
(true) ? (((((coin <= (15.)) && ((15.) <= coin))) ? ((5.)) :
(true) ? (((((coin <= (5.)) && ((5.) <= coin))) ? ((2.)) :
(true) ? ((0.)) :
_infinity)) :
_infinity)) :
_infinity);

}}
double GR__AMOUNT() {{
return (((10.) * LAST__DIGIT__OF__GROUP__NUMBER()));

}}
double LAGEST__COIN() {{
double value = 25.;
return value;

}}
double LAST__DIGIT__OF__GROUP__NUMBER() {{
double value = 8.;
return value;

}}
int main(){
display(" SPA variant 17");
newline();
display(" 2-5-15-25");
newline();
display("count__change for 100 \t= ");
display(count__change((100.)));
newline();
display("count__change for ");
display(GR__AMOUNT());
display(" \t= ");
display(count__change(GR__AMOUNT()));
 std::cin.get();
 return 0;
}

