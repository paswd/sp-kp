/* $d17 */
#include "code-gen.h"
using namespace std;
int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}
int tCG::p02(){ //   CALC -> E1
	S1->obj = " display("+S1->obj+"); newline();\n";
	return 0;}
int tCG::p03(){ //   CALC -> BOOL
	S1->obj = " display(" + S1->obj + "); newline();\n";
	return 0;}
int tCG::p04(){ //   CALC -> STR
	S1->obj = " display(" + S1->obj + "); newline();\n";
	return 0;}
int tCG::p05(){ //   CALC -> SET
	S1->obj += ";\n";
	return 0;}
int tCG::p06(){ //   CALC -> DISP
	//S1->obj += "; newline();\n";
	return 0;}
int tCG::p07(){ //   DISP -> ( display E1 )
	S1->obj = "display(" + S3->obj + ");\n";
	return 0;}
int tCG::p08(){ //   DISP -> ( display BOOL )
	S1->obj = "display(" + S3->obj + ");\n";
	return 0;}
int tCG::p09(){ //   DISP -> ( display STR )
	S1->obj = "display(" + S3->obj + ");\n";
	return 0;}
int tCG::p10(){ //   DISP -> ( newline )
	S1->obj = "newline();\n";
	return 0;}
int tCG::p11(){ //   PRED -> HPRED BOOL )
	S1->obj += S2->obj + ";\n}}\n";
	return 0;}
int tCG::p12(){ //  HPRED -> PDPAR )
	S1->obj += ")";
	declarations += S1->obj + ";\n";
	S1->obj += "\n{{\nreturn ";
	return 0;}
int tCG::p13(){ //  PDPAR -> ( define ( $idq
	S1->obj = "bool " + decor(S4->name) + "(";
	S1->count = 0;
	return 0;}
int tCG::p14(){ //  PDPAR -> PDPAR $id
	if (S1->count > 0)
		S1->obj += ", ";

	S1->obj += "double " + decor(S2->name);
	++S1->count;
	return 0;}
int tCG::p15(){ //  CPROC -> HCPROC )
	S1->obj += ")";
	return 0;}
int tCG::p16(){ // HCPROC -> ( $id
	S1->obj = decor(S2->name) + "(";
	S1->count = 0;
	return 0;}
int tCG::p17(){ // HCPROC -> HCPROC E
	if (S1->count > 0) {
		S1->obj += ", ";
	}

	S1->obj += S2->obj;
	++S1->count;
	return 0;}
int tCG::p18(){ //  CPRED -> HCPRED )
	S1->obj += ")";
	return 0;}
int tCG::p19(){ // HCPRED -> ( $idq
	S1->obj = decor(S2->name) + "(";
	S1->count = 0;
	return 0;}
int tCG::p20(){ // HCPRED -> HCPRED E
	if (S1->count > 0)
		S1->obj += ", ";

	S1->obj += S2->obj;
	++S1->count;
	return 0;}
int tCG::p21(){ //  CONST -> $int
	S1->obj = S1->name + ".";
	return 0;}
int tCG::p22(){ //  CONST -> $zero
	S1->obj = "0.";
	return 0;}
int tCG::p23(){ //  CONST -> $float
	S1->obj = S1->name;
	return 0;}
int tCG::p24(){ //      E -> $id
	S1->obj = decor(S1->name);
	return 0;}
int tCG::p25(){ //      E -> CONST
	S1->obj = "(" + S1->obj;
	S1->obj += ")";
	return 0;}
int tCG::p26(){ //      E -> ADD
	S1->obj = "(" + S1->obj;
	S1->obj += ")";
	return 0;}
int tCG::p27(){ //      E -> SUB
	S1->obj = "(" + S1->obj;
	S1->obj += ")";
	return 0;}
int tCG::p28(){ //      E -> DIV
	S1->obj = "(" + S1->obj;
	S1->obj += ")";
	return 0;}
int tCG::p29(){ //      E -> MUL
	S1->obj = "(" + S1->obj;
	S1->obj += ")";
	return 0;}
int tCG::p30(){ //      E -> COND
	//EMPTY
	return 0;}
int tCG::p31(){ //      E -> CPROC
	//EMPTY
	return 0;}
int tCG::p32(){ //    ADD -> HADD E1 )
	S1->obj += S2->obj + ")";
	return 0;}
int tCG::p33(){ //   HADD -> ( +
	S1->obj = "(";
	return 0;}
int tCG::p34(){ //   HADD -> HADD E1
	S1->obj += S2->obj + " + ";
	return 0;}
int tCG::p35(){ //    MUL -> HMUL E1 )
	S1->obj += S2->obj + ")";
	return 0;}
int tCG::p36(){ //   HMUL -> ( *
	S1->obj = "(";
	return 0;}
int tCG::p37(){ //   HMUL -> HMUL E1
	S1->obj += S2->obj + " * ";
	return 0;}
int tCG::p38(){ //    SUB -> HSUB E1 )
	if (S1->count == 1) {
		S1->obj += "-" + S2->obj + ")";
	} else {
		S1->obj += S2->obj + ")";
	}
	return 0;}
int tCG::p39(){ //   HSUB -> ( -
	S1->obj = "(";
	S1->count = 1;
	return 0;}
int tCG::p40(){ //   HSUB -> HSUB E1
	S1->obj += S2->obj + " - ";
	++S1->count;
	return 0;}
int tCG::p41(){ //    DIV -> HDIV E1 )
	if (S1->count == 1) {
		S1->obj += "1 / " + S2->obj + ")";
	} else {
		S1->obj += S2->obj + ")";
	}
	return 0;}
int tCG::p42(){ //   HDIV -> ( / E1
	//?????
	S1->obj = "( " + S3->obj + " / ";
	S1->count = 0;
	return 0;}
int tCG::p43(){ //   COND -> HCOND CLAUS )
	S1->obj += S2->obj + "_infinity)";
	return 0;}
int tCG::p44(){ //  HCOND -> ( cond CLAUS
	S1->obj ="("+S3->obj;
	return 0;}
int tCG::p45(){ //  CLAUS -> HCLAUS E1 )
	S1->obj += "(" + S2->obj + ") :\n";
	return 0;}
int tCG::p46(){ // HCLAUS -> ( BOOL
	S1->obj = "(" + S2->obj + ") ? ";
	return 0;}
int tCG::p47(){ // HCLAUS -> HCLAUS SET
	S1->obj +="(" + S2->obj + "),";
	return 0;}
int tCG::p48(){ // HCLAUS -> HCLAUS DISP
	S1->obj +="(" + S2->obj + "),";
	return 0;}
int tCG::p49(){ //    STR -> $str
	S1->obj = S1->name;
	return 0;}
int tCG::p50(){ //   BOOL -> $bool
	S1->obj = (S1->name=="#t" ? "true" : "false");
	return 0;}
int tCG::p51(){ //   BOOL -> CPRED
	//EMPTY
	return 0;}
int tCG::p52(){ //   BOOL -> REL
	//EMPTY
	return 0;}
int tCG::p53(){ //   BOOL -> AND
	//EMPTY
	return 0;}
int tCG::p54(){ //   BOOL -> ( not BOOL )
	S1->obj = "!(" + S3->obj + ")";
	return 0;}
int tCG::p55(){ //    REL -> HREL E1 )
	S1->obj += S2->obj + ")";
	return 0;}
int tCG::p56(){ //   HREL -> ( <= E
	S1->obj = "(" + S3->obj + " <= ";
	return 0;}
int tCG::p57(){ //    AND -> HAND BOOL )
	S1->obj += S2->obj + ")";
	return 0;}
int tCG::p58(){ //   HAND -> ( and BOOL
	S1->obj = "(" + S3->obj + " && ";
	return 0;}
int tCG::p59(){ //     E1 -> E
	//EMPTY
	return 0;}
int tCG::p60(){ //    SET -> HSET E1 )
	S1->obj += S2->obj;
	return 0;}
int tCG::p61(){ //   HSET -> ( set! $id
	S1->obj = decor(S3->name) + " = ";
	return 0;}
int tCG::p62(){ //    VAR -> VARINI )
	S1->obj += ";\n";
	return 0;}
int tCG::p63(){ // VARINI -> HVAR CONST
	S1->obj += " = " + S2->obj;
	return 0;}
int tCG::p64(){ //   HVAR -> ( define $id
	S1->obj = "double " + decor(S3->name);
	return 0;}
int tCG::p65(){ //   PROC -> PRBODY )
	S1->obj += "\n}}\n";
	return 0;}
int tCG::p66(){ // PRBODY -> HPROC E
	S1->obj += "return " + S2->obj + ";\n";
	return 0;}
int tCG::p67(){ //  HPROC -> PCPAR )
	S1->obj += ")";
	declarations += S1->obj + ";\n";
	S1->obj += " {{\n";
	return 0;}
int tCG::p68(){ //  HPROC -> HPROC SET
	//S1->obj += S2->obj;
	S1->obj+=S2->obj+ ";\n";
	return 0;}
int tCG::p69(){ //  HPROC -> HPROC VAR
	S1->obj += S2->obj;
	return 0;}
int tCG::p70(){ //  HPROC -> HPROC DISP
	S1->obj += S2->obj;
	return 0;}
int tCG::p71(){ //  PCPAR -> ( define ( $id
	S1->obj = "double " + decor(S4->name) + "(";
	S1->count = 0;
	return 0;}
int tCG::p72(){ //  PCPAR -> PCPAR $id
	if (S1->count) {
		S1->obj += ", ";
	}
	S1->obj += "double " + decor(S2->name);
	S1->count++;
	return 0;}
int tCG::p73(){ //    DEF -> PRED
	//EMPTY
	return 0;}
int tCG::p74(){ //    DEF -> PROC
	//EMPTY
	return 0;}
int tCG::p75(){ //   DEFS -> DEF
	//EMPTY
	return 0;}
int tCG::p76(){ //   DEFS -> DEFS DEF
	S1->obj += S2->obj;
	return 0;}
int tCG::p77(){ //  CALCS -> CALC
	//EMPTY
	return 0;}
int tCG::p78(){ //  CALCS -> CALCS CALC
	S1->obj += S2->obj;
	return 0;}
int tCG::p79(){ // CALCS1 -> CALCS
	//EMPTY
	return 0;}
int tCG::p80(){ //   PROG -> CALCS1
	S1->obj = "int main(){\n" + S1->obj
    + " std::cin.get();\n return 0;\n}\n";
	return 0;}
int tCG::p81(){ //   PROG -> DEFS
	S1->obj += "int main(){\n"
    " display(\"No calculations!\");newline();\n"
    " std::cin.get();\nreturn 0;\n}\n";
	return 0;}
int tCG::p82(){ //   PROG -> DEFS CALCS1
	S1->obj += "int main(){\n" + S2->obj
    + " std::cin.get();\n return 0;\n}\n";
	return 0;}
//_____________________
int tCG::p83(){return 0;} int tCG::p84(){return 0;} 
int tCG::p85(){return 0;} int tCG::p86(){return 0;} 
int tCG::p87(){return 0;} int tCG::p88(){return 0;} 
int tCG::p89(){return 0;} int tCG::p90(){return 0;} 
int tCG::p91(){return 0;} int tCG::p92(){return 0;} 
int tCG::p93(){return 0;} int tCG::p94(){return 0;} 
int tCG::p95(){return 0;} int tCG::p96(){return 0;} 
int tCG::p97(){return 0;} int tCG::p98(){return 0;} 
int tCG::p99(){return 0;} int tCG::p100(){return 0;} 
int tCG::p101(){return 0;} int tCG::p102(){return 0;} 
int tCG::p103(){return 0;} int tCG::p104(){return 0;} 
int tCG::p105(){return 0;} int tCG::p106(){return 0;} 
int tCG::p107(){return 0;} int tCG::p108(){return 0;} 
int tCG::p109(){return 0;} int tCG::p110(){return 0;} 


