/*  SPA17   */
#include "mlisp.h"
double good(double temp);
double bad(double temp);
double tolerance();
double half__interval__metod(double a, double b);
double __SPA17__try(double neg__point, double pos__point);
bool close__enough_Q(double x, double y);
double average(double x, double y);
double root(double a, double b);
double fun(double z);
//________________ 
double good(double temp) {{
display("[good]");
return temp;

}}
double bad(double temp) {{
display("[bad]");
return temp;

}}
double tolerance() {{
double value = 0.00001;
return value;

}}
double half__interval__metod(double a, double b) {{
double a__value = 0.;
double b__value = 0.;
a__value = fun(a);
b__value = fun(b);
return (((((a__value <= (0.)) && !(((a__value <= (0.)) && ((0.) <= a__value)))) && !((b__value <= (0.))))) ? (__SPA17__try(a, b)) :
(true) ? ((((!((a__value <= (0.))) && ((b__value <= (0.)) && !(((b__value <= (0.)) && ((0.) <= b__value)))))) ? (__SPA17__try(b, a)) :
(true) ? (((b + (1.)))) :
_infinity)) :
_infinity);

}}
double __SPA17__try(double neg__point, double pos__point) {{
double midpoint = 0.;
double test__value = 0.;
midpoint = average(neg__point, pos__point);
display("+");
return ((close__enough_Q(neg__point, pos__point)) ? (midpoint) :
(true) ? (test__value = fun(midpoint)),(((!((test__value <= (0.)))) ? (__SPA17__try(neg__point, midpoint)) :
(true) ? (((((test__value <= (0.)) && !(((test__value <= (0.)) && ((0.) <= test__value))))) ? (__SPA17__try(midpoint, pos__point)) :
(true) ? (midpoint) :
_infinity)) :
_infinity)) :
_infinity);

}}
bool close__enough_Q(double x, double y)
{{
return ((abs(((x - y))) <= tolerance()) && !(((abs(((x - y))) <= tolerance()) && (tolerance() <= abs(((x - y)))))));
}}
double average(double x, double y) {{
return (( ((x + y)) / (2.)));

}}
double root(double a, double b) {{
double temp = 0.;
temp = half__interval__metod(a, b);
newline();
display("interval=\t[");
display(a);
display(" , ");
display(b);
display("]\n");
display("discrepancy=\t");
display(fun(temp));
newline();
display("root=\t\t");
double dump = 0.;
dump = ((((((temp - b - (1.))) <= (0.)) && ((0.) <= ((temp - b - (1.)))))) ? (bad(temp)) :
(true) ? (good(temp)) :
_infinity);
return temp;

}}
double fun(double z) {{
z = ((z - (( (34.) / (35.))) - (( (1.) / pi))));
return ((((z + sin(z))) + cos(z)));

}}
int main(){
 display(" SPA variant 34"); newline();
 display(root((0.), (1.))); newline();
 std::cin.get();
 return 0;
}

