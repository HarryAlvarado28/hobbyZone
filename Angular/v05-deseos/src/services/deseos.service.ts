import { Injectable } from "@angular/core";
import{ Lista } from "../models";


@Injectable()
export class DeseosService {

  listas: Lista[] = [];

  constructor(){
    console.log('Deseos Services Inicializados!');
    const lista1 = new Lista('Recolectar puiedras del infinito');
    const lista2 = new Lista('Exterminar a thanos');

    this.listas.push(lista1,lista2);
    console.log(this.listas);
  }
}
