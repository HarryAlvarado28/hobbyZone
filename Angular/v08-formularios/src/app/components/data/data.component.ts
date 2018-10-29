import { Component } from '@angular/core';
import { FormGroup, FormControl, Validators } from '@angular/forms';
import {validate} from 'codelyzer/walkerFactory/walkerFn';

@Component({
  selector: 'app-data',
  templateUrl: './data.component.html',
  styles: []
})
export class DataComponent {

  forma: FormGroup;

  usuario: any = {
    nombrecompleto: {
      nombre: "Harry",
      apellido: "Alvarado"
    },
    correo: "harry.alvarado@up.ac.pa"
  }


  constructor() {

    console.log(this.usuario);

    this.forma = new FormGroup({

      'nombrecompleto': new FormGroup({
          'nombre': new FormControl(
            '',
            [
              Validators.required,
              Validators.minLength(3)
            ]),
          'apellido': new FormControl(
            '',
            Validators.required)
        }),
      'correo': new FormControl('',
              [
                Validators.required,
                Validators.pattern("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,3}$")
              ])
    })

    // setear valores en el formulario
      this.forma.setValue(this.usuario);

  }

  guardarCambios(){
    console.log(this.forma.value);
    console.log(this.forma);

    /*
      forma nº1 de reseterar valores
        this.forma.reset(this.usuario);
    */
    /*
      forma nº2 de reseterar valores, individualmente.
    */
        this.forma.reset({
          nombrecompleto: {
            nombre: "",
            apellido: ""
          }, correo: ""
        });

  }

}
