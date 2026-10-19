%{
#include "anasin.tab.h" 
#include "stdlib.h" //Esto de aqui es para la funcion atoi
#include "math.h"
#include "string.h"
//Modificacion convocatoria de julio, declaramos como variable externa el booleano error
#include <stdbool.h> //Para los booleanos
extern bool error;
%}
digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+
%option yylineno
%%
void                                            return VOID;
read                                            return READ;
print                                           return PRINT;
var                                             return VAR;
int                                             return INT;
const                                           return CONST;
if                                              return IF;
else                                            return ELSE;
while                                           return WHILE;
do                                              return DO;
break                                           return BREAK;
({letra}|_)({letra}|{digito}|_)*               {
                                                //MODIFICACIONES DE LA CONVOCATORIA DE JULIO
                                                if(yyleng > 32){
                                                    printf("Error lexico en la linea %d: El identificador '%s' supera el maximo de 32 caracteres.\n",yylineno,yytext);
                                                    error = true;
                                                }
                                                yylval.lexema = strdup(yytext);   
                                                return ID;
                                                }
{entero}                                        {if(abs(atoll(yytext)) > pow(2,31)){printf("Error: el entero introducido supera el rango de 2^31\n");
                                                error = true;}
                                                yylval.lexema = strdup(yytext);
                                                return INTLITERAL;
                                                }

\"([^"\n]|\\.)*\"                               {
                                                yylval.lexema = strdup(yytext);
                                                return STRING;
                                                }
"//".*                                           {/*Para ignorar comentarios de una sola linea*/;}
"/*"([^*]|\*+[^*/])*\*+"/"                      {/*Para ignorar comentarios multilinea, la explicacion de esta expresion regular es: todo lo que empieze por "/*" y una de dos o no vaya seguido por un * o vaya seguido por uno o mas asteriscos pero lo siguiente no vaya seguido por un asterisco ni una barra lo primero es util para que si tenemos un salto de linea no se nos pare la deteccion y lo segundo es util por si tenemos dentro del comentario por ejemplo un 3*7 vea que despues del * no va un / y por tanto no pare la deteccion*/;}
"{"                                             return LCORCH;
"}"                                             return RCORCH;
"("                                             return LPAREN;		
")"                                             return RPAREN;
";"                                             return SEMICOLON;
","                                             return COMMA;
"="                                             return ASSIGNOP;
"+"                                             return PLUSOP;
"-"                                             return MINUSOP;
"*"                                             return POR;
"/"                                             return DIV;
"<"                                             return  MENOR;
">"                                             return MAYOR;
"<="                                            return MEQ;         
">="                                            return MAQ;
"=="                                            return EQQ;
"!="                                            return NEQ;
[ \n\t\r]+                                      {/*Queremos que ignore los saltos de linea y espacios"*/}
[^a-zA-Z0-9;,+\-*/"_= \n\t\r()\{ \}<>!]+                          { //Aqui vamos a implementar el modo panico 
    printf("Ha ocurrido un error con los caracteres %s no reconocidos, en la linea %d\n",yytext,yylineno);
    //Cambio convocatoria de julio
    error = true;}
%%

