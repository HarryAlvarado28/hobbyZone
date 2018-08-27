// 1º Parte
// Uso de Let y Const
var nombre = "Ricardo Tapia";
var edad = 23;
var PERSONAJE = {
    nombre: nombre,
    edad: edad
};

// Desarrollo de la 1º Parte.
let nombre:string = "Harry Alvarado";
let edad:number = 21;
const PERSONAJE = {
    nombre: nombre,
    edad: edad
}
//-------------------------------------------------------------------

// 2º Parte
// Cree una interfaz que sirva para validar el siguiente objeto
var batman = {
    nombre: "Bruno Díaz",
    artesMarciales: ["Karate","Aikido","Wing Chun","Jiu-Jitsu"]
}

// Desarrollo de la 2º Parte.
interface Batman {
    nombre:string,
    artesMarciales:string[]
}
var batman:Batman = {
    nombre: "Bruno Díaz",
    artesMarciales: ["Karate","Aikido","Wing Chun","Jiu-Jitsu"]
}
//-------------------------------------------------------------------

// 3º Parte
// Convertir esta funcion a una funcion de flecha
function resultadoDoble( a, b ){
    return (a + b) * 2
}

// Desarrollo de la 3º Parte.
let resultadoDoble = (a:number,b:number) => (a + b) * 2;
//-------------------------------------------------------------------

// 4º Parte
// Función con parametros obligatorios, opcionales y por defecto
// donde NOMBRE = obligatorio
//       PODER  = opcional
//       ARMA   = por defecto = "arco"
function getAvenger( nombre, poder, arma ){
    var mensaje;
    if( poder ){
        mensaje = nombre + " tiene el poder de: " + poder + " y un arma: " + arma;
    }else{
        mensaje = nombre + " tiene un " + poder
    }
};
// Desarrollo de la 4º Parte.
function getAvenger(nombre:string, poder?:string, arma:string = "arco"){
    let mensaje:string;
    if(poder){
        mensaje = ` ${nombre} tiene el poder de: ${poder} y un arma: ${arma}`;
    }else{
        mensaje = `${nombre} tiene un ${poder}`;
    }
}
//-------------------------------------------------------------------

// 5º Parte
// Cree una clase que permita manejar la siguiente estructura
// La clase se debe de llamar rectangulo,
// debe de tener dos propiedades:
//   * base
//   * altura
// También un método que calcule el área  =  base * altura,
// ese método debe de retornar un numero.

// Desarrollo de la 5º Parte.
class Rectangulo {
    base:number;
    altura:number;

    getArea():number {
        return this.base * this.altura;
    }
}
//-------------------------------------------------------------------