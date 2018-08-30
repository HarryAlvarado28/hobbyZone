import { Component, OnInit } from '@angular/core';
import { HeroesService, Heroe } from '../../servicios/heroes.service';

@Component({
  selector: 'app-heroes',
  templateUrl: './heroes.component.html',
  styles: []
})
export class HeroesComponent implements OnInit {

  heroes:Heroe[] = [];

  constructor(private _heroesService:HeroesService) {
    console.log("Constructor");
  }

  ngOnInit() {
    this.heroes = this._heroesService.getHeroes();
    console.log (this.heroes);
  }

}
