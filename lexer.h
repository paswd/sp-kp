//                 lexer.h 2017
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  ZED		     *
//*             (c)  2017                    *
//********************************************
class tLexer:public tBaseLexer{
public:
// персональный код разработчика
 std::string Authentication()const{
                     return "SPA"
                +std::string("17");}
//конструктор
 tLexer():tBaseLexer(){
//создать автоматы:

//  ноль Azero
    addstr  (Azero,0,"+-", 2);
    addstr  (Azero,0,"0",  1);
    addstr  (Azero,2,"0",  1);
    addstr  (Azero,1,"0",  1);
  Azero.final(1);

//________________________________________

// целое число
	addstr(Aint,0,"+-",1);
	addstr(Aint,0,"0", 2);
	addrange(Aint,0,'1','9',3);
	addstr(Aint,1,"0", 2);
	addrange(Aint,1, '1', '9', 3);
  addstr(Aint,2,"0",2);
	addrange(Aint,2,'1','9',3);
	addrange(Aint,3,'0','9',3);

  	Aint.final(3);
//________________________________________

// вещественное
  //addstr(Afloat,0,"+-",1);
  addrange(Afloat, 0, '0', '9', 1);
  addstr(Afloat,0,"+-",7);
  addrange(Afloat,7,'0','9',1); 
  addrange(Afloat,1,'0','9',1); 
  addstr(Afloat,1,".",2); 
  Afloat.final(2); 
  addrange(Afloat,2,'0','9',3); 
  addrange(Afloat,3,'0','9',3); 
  Afloat.final(3);
  addstr(Afloat,3,"e",4); 
  addstr(Afloat,3,"E",4); 
  addstr(Afloat,4,"+",5); 
  addstr(Afloat,4,"-",5); 
  addrange(Afloat,5,'0','9',6); 
  Afloat.final(6); 
  addrange(Afloat,6,'0','9',6); 

//________________________________________

// строка
//  –≈јЋ»«ќ¬ј“№ escape-последовательности:
// \'  \"  \?  \\  \a  \b  \f  \n  \r  \t  \v
    const char SP=' ';// пробел
    addstr(Astr,0,"\"",1);
    addstr(Astr,1,"\\",2);
    addrange(Astr,1,SP,'!',1);
    addrange(Astr,1,'#','[',1);
    addrange(Astr,1,']','~',1);
    addrange(Astr,1,'\x80','\xff',1);// русские буквы
    addstr(Astr,1,"\"",3);
    addstr(Astr,2,"\' \" ? \\ a b f n r t v",1);
	//addstr(Astr, 3, "t", 1);
    addrange(Astr, 3,'"', '"', 3);

	Astr.final(3);
//________________________________________

// идентификатор
	addrange(Aid,0,'a','z',2);
	addrange(Aid,0,'A','Z',2);
	addstr(Aid,0,"!",3);
	addstr(Aid,0,"-",1);
	addrange(Aid,1,'a', 'z', 2);
	addrange(Aid,1,'A', 'Z', 2);
	addrange(Aid,1,'0', '9', 1);
	addstr(Aid,1,"-", 2);
  addstr(Aid,1,"!", 3);
	addrange(Aid,3,'a', 'z', 2);
	addrange(Aid,3,'A', 'Z', 2);
	addrange(Aid,3,'0', '9', 2);
	addrange(Aid,2,'a', 'z', 2);
	addrange(Aid,2,'A', 'Z', 2);
	addrange(Aid,2,'0', '9', 2);
	addstr(Aid,2,"-", 2);
  addstr(Aid,2,"!", 3);
	addstr(Aid,3,"!", 3);
    Aid.final(2);
	Aid.final(3);
//________________________________________

// идентификатор предиката
    addstr  (Aidq,0,"-",   1);
    addrange(Aidq,0,'a','z',1);
    addrange(Aidq,0,'A','Z',1);
    addstr  (Aidq,0,"?",   2);
    addstr  (Aidq,1,"-",   1);
    addrange(Aidq,1,'a','z',1);
    addrange(Aidq,1,'A','Z',1);
    addrange(Aidq,1,'0','9',1);
    addstr  (Aidq,1,"?",   2);
    addstr  (Aidq,2,"-",   1);
    addrange(Aidq,2,'a','z',1);
    addrange(Aidq,2,'A','Z',1);
    addrange(Aidq,2,'0','9',1);
  Aidq.final(2);
//________________________________________

// оператор
    addstr(Aoper,0,"*+-/=",2);
    addstr(Aoper,0,"<>",1);
    addstr(Aoper,1,"=",2);

	Aoper.final(1);
	Aoper.final(2);
//________________________________________

// булевские константы
    addstr(Abool,0,"#",1);
    addstr(Abool,1,"tf",2);
  Abool.final(2);
//________________________________________
}
};
#endif

