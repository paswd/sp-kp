/*  SPA17   */
#include "mlisp.h"
double SmallestDiv(double n);
bool Divides_Q(double a, double b);
double SPASquare(double n);
double FindDiv(double n, double current);
bool Prime_Q(double n);
//________________ 
double SmallestDiv(double n) {{
return FindDiv(n, (2.));

}}
bool Divides_Q(double a, double b)
{{
return ((remainder(b, a) <= (0.)) && ((0.) <= remainder(b, a)));
}}
double SPASquare(double n) {{
return ((n * n));

}}
double FindDiv(double n, double current) {{
return ((!((SPASquare(current) <= n))) ? (n) :
(true) ? (((Divides_Q(current, n)) ? (current) :
(true) ? (FindDiv(n, ((current + (1.))))) :
_infinity)) :
_infinity);

}}
bool Prime_Q(double n)
{{
return ((n <= SmallestDiv(n)) && (SmallestDiv(n) <= n));
}}
int main(){
display(Prime_Q((1.)));
newline();
display(Prime_Q((2.)));
newline();
display(Prime_Q((3.)));
newline();
display(Prime_Q((4.)));
newline();
display(Prime_Q((5.)));
newline();
display(Prime_Q((6.)));
newline();
display(Prime_Q((7.)));
newline();
display(Prime_Q((8.)));
newline();
display(Prime_Q((9.)));
newline();
display(Prime_Q((10.)));
newline();
 std::cin.get();
 return 0;
}

