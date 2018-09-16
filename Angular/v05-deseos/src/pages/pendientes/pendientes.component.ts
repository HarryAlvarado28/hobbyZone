import {Component} from "@angular/core";
import {DeseosService} from "../../services/deseos.service";
import {Lista} from "../../models";
import {NavController} from "ionic-angular";
import {AgregarPage} from "../agregar/agregar.component";


@Component({
  selector: 'page-pendientes',
  templateUrl: 'pendientes.component.html'
})
export class PendientesPage {
  constructor(public deseosService: DeseosService, private navCtrl: NavController) {

  }

  listaSeleccionada(lista: Lista){
    console.log(lista);
  }

  agregarLista(){
    this.navCtrl.push(AgregarPage);
  }
}
