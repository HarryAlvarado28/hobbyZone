import { Injectable } from '@angular/core';
import { AngularFirestore, AngularFirestoreCollection } from '@angular/fire/firestore';
import { Observable } from 'rxjs';

import { Mensaje } from '../interface/mensaje.interface';
import { map } from 'node_modules/rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class ChatService {

  private itemsCollection: AngularFirestoreCollection<any>;

  public chats: Mensaje[] = [];

  constructor(private afs: AngularFirestore) {

  }

  cargarMensajes(){

    this.itemsCollection = this.afs.collection<Mensaje>(
      'chats',
      ref => ref.orderBy('fecha','desc').limit(5)
    );

    return this.itemsCollection.valueChanges().pipe(
      map((mensajes: Mensaje[]) => {
        console.log(mensajes);
        this.chats = mensajes.reverse();

        return this.chats;
      })
    );
  }

  agregarMensaje(texto: string){

    // TODO falta el UID del usuario
    let mensaje: Mensaje = {
      nombre: 'Demo',
      mensaje: texto,
      fecha: new Date().getTime()
    }

    return this.itemsCollection.add(mensaje);
  }
}
