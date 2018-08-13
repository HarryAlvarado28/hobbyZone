import { Component, OnInit } from '@angular/core';
import { Iharry } from './iamharry';

@Component({
  selector: 'app-iamharry',
  templateUrl: './iamharry.component.html',
  styleUrls: ['./iamharry.component.css']
})

export class IamharryComponent implements OnInit {

  iam: Iharry = {
    id: 1,
    name: 'Harry',
    age: 21,
    website: 'https://hackrry.com',
    bio: 'Estudiante de Ingenieria en Informática',
    hobby: 'Aprender Cosas nuevas, Inventar'
  };

  constructor() { }

  ngOnInit() {
  }

}
