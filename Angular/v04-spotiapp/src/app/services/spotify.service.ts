import { Injectable } from '@angular/core';
import {HttpClient, HttpHeaders} from '@angular/common/http';
import { map } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class SpotifyService {

  constructor(private http:HttpClient) {
    console.log('Spotify servicios!!!:...');
  }

  getQuery(query:string){
    const url = `https://api.spotify.com/v1/${query}`;
    const headers = new HttpHeaders({
      'Authorization':'Bearer BQBWlZghCgdGqlBZf36U5LGoNDwmKxEQiOK4KX56_WyqkhWXOZ4--z-PqaXvZnQSVVb47lAI9WCw0C5koliUIpvQBvAKDEVIRSKhDyGsHECeGwb_Q4O52Z_z-nDAVXGQjLJGR1XpXbPURnWdjE4'
    });

    return this.http.get(url,{headers});
  }

  getNewReleases(){
    return this.getQuery('browse/new-releases').pipe(map(data => data['albums'].items));

  }

  getArtista(termino:string){
    return this.getQuery(`search?q=${termino}&type=artist&limit=15`).pipe(map(data => data['artists'].items));
    //this.http.get(`https://api.spotify.com/v1/search?q=${termino}&type=artist&limit=15`,{headers})
  }
}
